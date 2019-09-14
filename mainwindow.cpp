#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include "sha256.h"
#include "jdbc/mysql_connection.h"
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include "notice.h"

using namespace ::sql;

static Driver *driver;
static Connection *con;
static Statement *stmt;

// used to control window
static QMainWindow *WindowPointer;

// Declare & Make pointers *
static QPushButton *m_button;
static QLabel *loginLabel;
static QLabel *passwordLabel;
static QLabel *rememberLabel;
static QCheckBox *rememberBox;
static QLineEdit *usernameBox;
static QLineEdit *passBox;


void connectDatabase() {
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "///");
}

void disconnectDb() {
    con->close();
    delete con;
}

void initFrame(QMainWindow *parent) {
    WindowPointer->setWindowTitle("Login Base C++ x64");
    WindowPointer->setGeometry(50,50,450,300);
    WindowPointer->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint, true);
    // set non resizable
    loginLabel = new QLabel("Username", parent);
    passwordLabel = new QLabel("Password", parent);
    loginLabel->setGeometry(QRect(QPoint(150, 30),QSize(50, 100)));
    passwordLabel->setGeometry(QRect(QPoint(150, 100),QSize(50, 100)));
    rememberBox = new QCheckBox(parent);
    rememberBox->setGeometry(QRect(QPoint(150,170),QSize(50,100)));
    rememberLabel = new QLabel("Remember Me?", parent);
    rememberLabel->setGeometry(QRect(QPoint(170,170),QSize(200,100)));
    usernameBox = new QLineEdit(parent);
    usernameBox->setGeometry(QRect(QPoint(150, 100),QSize(150, 25)));
    passBox = new QLineEdit(parent);
    passBox->setGeometry(QRect(QPoint(150, 170),QSize(150, 25)));
    passBox->setEchoMode(QLineEdit::Password);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    WindowPointer = this;
    ui->setupUi(this);
    initFrame(WindowPointer);
    m_button = new QPushButton("Log In", this);
    m_button->setGeometry(QRect(QPoint(150, 250),
    QSize(150, 30)));
    // Add Listeners
    connect(m_button, SIGNAL (released()), this, SLOT (loginButtonPressed()));
}

std::string hashPasswordProc(std::string enter) {
    return sha256(enter);
}

std::string gulp(std::istream *in)
{
    std::string ret;
    char buffer[4096];
    while (in->read(buffer, sizeof(buffer)))
        ret.append(buffer, sizeof(buffer));
    ret.append(buffer, in->gcount());
    return ret;
}


ResultSet* query(std::string statement) {
    connectDatabase();
    con->setSchema("cpptest");
    ResultSet *newRes;
    stmt = con->createStatement();
    stmt->execute("USE cpptest");
    newRes = stmt->executeQuery(statement);
    return newRes;
}

ResultSet* getPassword(std::string* uname) {
    connectDatabase();
    con->setSchema("cpptest");
    ResultSet *newRes;
    SQLString t = "SELECT password FROM user WHERE un='";
    t.append(uname->c_str());
    t.append("'");
    stmt = con->createStatement();
    stmt->execute("USE cpptest");
    newRes = stmt->executeQuery(t);
    return newRes;
}

bool validate(std::string* username, std::string password) {
    std::string passOfUname;
    if (username->c_str() != nullptr) {
    ResultSet* valSet = getPassword(username);
    while(valSet->next()) {
        std::istream* blob = valSet->getBlob("password");
        std::string s = gulp(blob);
        passOfUname = s.c_str();
    }
        if (password == passOfUname) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void loginproc(std::string *username, std::string password) {
    notice* h;
    m_button->setText("Logging In...");
    std::string hashedPassword = hashPasswordProc(password);
    if (validate(username, hashedPassword))
        h = new notice("Logged In!");
    else
        h = new notice("Incorrect Username/Password!");

    h->show();
    m_button->setText("Log In");

}


void MainWindow::loginButtonPressed() {
    std::string uName = usernameBox->text().toUtf8().constData();
    std::string* locale = &uName;

    loginproc(locale, passBox->text().toUtf8().constData());
}

MainWindow::~MainWindow()
{
    delete ui;
}


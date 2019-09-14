#include "notice.h"
#include "ui_notice.h"
#include "QPushButton"
#include "QLabel"

static QPushButton* okbutton;
static QLabel *noticeText;
static std::string message;

void init(QWidget *parent) {
    okbutton = new QPushButton(parent);
    okbutton->setGeometry(QRect(QPoint(200, 75),QSize(101, 23)));
    okbutton->setText("Okay");
    noticeText = new QLabel(parent);
    noticeText->setGeometry(QRect(QPoint(30,30),QSize(300,15)));
    noticeText->setText(message.c_str());
}

notice::notice(std::string notice, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notice)
{
    ui->setupUi(this);
    this->setWindowTitle("C++ Login MySQL - Notice");
    this->setGeometry(300,300,350,100);
    message = notice;
    init(this);
    connect(okbutton, SIGNAL (released()), this, SLOT (okayButtonPressed()));
}

void notice::okayButtonPressed() {
    this->close();
    delete ui;
}

notice::~notice()
{
    delete ui;
}

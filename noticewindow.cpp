#include "noticewindow.h"
#include <QCoreApplication>
#include <QPushButton>
#include <QLabel>

void init() {

}

NoticeWindow::NoticeWindow(QWidget *parent, std::string notice)
    : QMainWindow(parent)
    , ui(new Ui::NoticeWindow)
{
    ui->setupUi(this);
}

NoticeWindow::~NoticeWindow() {
    delete ui;
}

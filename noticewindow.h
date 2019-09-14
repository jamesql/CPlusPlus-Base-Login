#ifndef NOTICEWINDOW_H
#define NOTICEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class NoticeWindow; }
QT_END_NAMESPACE

class NoticeWindow : public QMainWindow
{
    Q_OBJECT

public:
    NoticeWindow(QWidget *parent = nullptr, std::string text = "Notice");
    ~NoticeWindow();
private slots:
   void okayButtonPressed();
private:
    Ui::NoticeWindow *ui;
};
#endif // NoticeWindow_H

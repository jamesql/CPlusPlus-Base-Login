#ifndef NOTICE_H
#define NOTICE_H

#include <QDialog>

namespace Ui {
class notice;
}

class notice : public QDialog
{
    Q_OBJECT

public:
    explicit notice(std::string notice = "Notice :",QWidget *parent = nullptr);
    ~notice();
private slots:
   void okayButtonPressed();
private:
    Ui::notice *ui;
};

#endif // NOTICE_H

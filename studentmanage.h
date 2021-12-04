#ifndef STUDENTMANAGE_H
#define STUDENTMANAGE_H

#include <QMainWindow>

namespace Ui {
class StudentManage;
}

class StudentManage : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentManage(QWidget *parent = nullptr);
    ~StudentManage();

private slots:
    void on_ButtCalc_clicked();

    void on_ButtAdd_clicked();

    void on_ButtDelete_clicked();

private:
    Ui::StudentManage *ui;
};

#endif // STUDENTMANAGE_H

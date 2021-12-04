#ifndef STUEDENTMANAGE_H
#define STUEDENTMANAGE_H

#include <QMainWindow>

namespace Ui {
class StuedentManage;
}

class StuedentManage : public QMainWindow
{
    Q_OBJECT

public:
    explicit StuedentManage(QWidget *parent = nullptr);
    ~StuedentManage();

private:
    Ui::StuedentManage *ui;
};

#endif // STUEDENTMANAGE_H

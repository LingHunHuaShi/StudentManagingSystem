#include "stuedentmanage.h"
#include "ui_stuedentmanage.h"

StuedentManage::StuedentManage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StuedentManage)
{
    ui->setupUi(this);
}

StuedentManage::~StuedentManage()
{
    delete ui;
}

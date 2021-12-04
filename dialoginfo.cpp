#include "dialoginfo.h"
#include "ui_dialoginfo.h"
#include "mainwindow.h"
#include "mainwindow2.h"
DialogInfo::DialogInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInfo)
{
    ui->setupUi(this);
    setFixedSize(this->width() , this->height());
}

DialogInfo::~DialogInfo()
{
    delete ui;
}

void DialogInfo::on_ButtConfirm_clicked()
{
   MainWindow2 *mainwindow2= new MainWindow2;
   mainwindow2->show();
}


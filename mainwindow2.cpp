#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include"dialoginfo.h"
#include"studentmanage.h"
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    setFixedSize(this->width() , this->height());
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_ButtEdit_clicked()
{
   StudentManage *studentmanage=new StudentManage;
   studentmanage->show();
}


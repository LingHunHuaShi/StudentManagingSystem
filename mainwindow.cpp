#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include"dialoginfo.h"
#include"dialogfail.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width() , this->height());
}



MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ButtLogin_clicked()
{
    QString username = ui->UsernameInput->toPlainText();
    QString password = ui->PasswdInput->toPlainText();
    if (username == "10001" && password == "123")
    {
        DialogInfo *dialog=new DialogInfo;
        dialog->show();
        close();
    }
    else
    {
        DialogFail *dialogfail=new DialogFail;
        dialogfail->show();
    }
}




void MainWindow::on_ButtQuit_clicked()
{

}


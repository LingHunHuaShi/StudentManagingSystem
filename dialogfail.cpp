#include "dialogfail.h"
#include "ui_dialogfail.h"

DialogFail::DialogFail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFail)
{
    ui->setupUi(this);
    setFixedSize(this->width() , this->height());

}

DialogFail::~DialogFail()
{
    delete ui;
}

void DialogFail::on_ButtRetry_clicked()
{

}

void DialogFail::CsetText(QString wenben)
{
    ui->label->setText(wenben);
}

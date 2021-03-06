#include "studentmanage.h"
#include "ui_studentmanage.h"
#include "classdeclare.h"
#include<fstream>
#include<string>
#include"dialogfail.h"
banji abs1;
StudentManage::StudentManage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentManage)
{
    ui->setupUi(this);
    setFixedSize(this->width() , this->height());
    ui->tableWidget->setColumnCount(17);
//    ui->tableWidget->setRowCount(2);
    QStringList header;
    header<<"姓名"<<"学号"<<"班级"<<"作业成绩1"<<"作业成绩2"<<"作业成绩3"<<"作业成绩4"<<"作业成绩5"
         <<"作业成绩"<<"PPT成绩"<<"讲述成绩"<<"代码成绩"<<"上机成绩"<<"基本概念成绩"
        <<"综合应用成绩"<<"笔试成绩"<<"总评成绩";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->setAlternatingRowColors(true);
    string head[17];
    ifstream ifs("sheetTotal.txt",ios::in);
    if(!ifs.is_open())
    {
        DialogFail *dialogfail3=new DialogFail;
        dialogfail3->CsetText("无法打开文件：sheetTotal.txt");
        dialogfail3->show();
        close();
    }
    else
    {
        int i;
        for(i=0;!ifs.eof();i++)
        {
            string name,id,banji_name;
            ifs>>name>>id>>banji_name;
            abs1.a[i].name=QString::fromStdString(name);
            abs1.a[i].id=QString::fromStdString(id);
            abs1.a[i].banji_name=QString::fromStdString(banji_name);
            ifs>>abs1.a[i].wucizy[0]>>abs1.a[i].wucizy[1]>>abs1.a[i].wucizy[2]>>abs1.a[i].wucizy[3]>>abs1.a[i].wucizy[4]>>
                    abs1.a[i].score1>>abs1.a[i].ppt>>abs1.a[i].introduction>>abs1.a[i].daima>>abs1.a[i].score2>>
                    abs1.a[i].basis>>abs1.a[i].work>>abs1.a[i].score3>>abs1.a[i].score;
        }
        ui->tableWidget->setRowCount(i-1);
        for(int j=0;j<=i;j++)
        {
            QString str;
            QTableWidgetItem *item;
             item = new QTableWidgetItem(abs1.a[j].name);
             ui->tableWidget->setItem(j,0,item);
             item = new QTableWidgetItem(abs1.a[j].id);
             ui->tableWidget->setItem(j,1,item);
             item = new QTableWidgetItem(abs1.a[j].banji_name);
             ui->tableWidget->setItem(j,2,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].wucizy[0]));
             ui->tableWidget->setItem(j,3,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].wucizy[1]));
             ui->tableWidget->setItem(j,4,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].wucizy[2]));
             ui->tableWidget->setItem(j,5,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].wucizy[3]));
             ui->tableWidget->setItem(j,6,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].wucizy[4]));
             ui->tableWidget->setItem(j,7,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].score1));
             ui->tableWidget->setItem(j,8,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].ppt));
             ui->tableWidget->setItem(j,9,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].introduction));
             ui->tableWidget->setItem(j,10,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].daima));
             ui->tableWidget->setItem(j,11,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].score2));
             ui->tableWidget->setItem(j,12,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].basis));
             ui->tableWidget->setItem(j,13,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].work));
             ui->tableWidget->setItem(j,14,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].score3));
             ui->tableWidget->setItem(j,15,item);
             item = new QTableWidgetItem(str.setNum(abs1.a[j].score));
             ui->tableWidget->setItem(j,16,item);
        }
    }
}

StudentManage::~StudentManage()
{
    delete ui;
}

void StudentManage::on_ButtCalc_clicked()
{
    banji abs;
    abs.size = 0;
    bool judge = true;   //设置判断变量，当单元格内容不为空时，进行赋值和计算操作
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
        //提取表格中的姓名、学号、班级
        if(ui->tableWidget->item(i,0)&&ui->tableWidget->item(i,0)->text()!=tr("")) abs.a[i].name = ui->tableWidget->item(i,0)->text();else judge=false;
        if(ui->tableWidget->item(i,1)&&ui->tableWidget->item(i,1)->text()!=tr("")) abs.a[i].id = ui->tableWidget->item(i,1)->text();else judge=false;
        if(ui->tableWidget->item(i,2)&&ui->tableWidget->item(i,2)->text()!=tr("")) abs.a[i].banji_name = ui->tableWidget->item(i,2)->text();else judge=false;
        //提取作业成绩1
        if(ui->tableWidget->item(i,3)&&ui->tableWidget->item(i,3)->text()!=tr(""))
        {
            QString zuoye1=ui->tableWidget->item(i,3)->text();
            abs.a[i].wucizy[0]=zuoye1.toDouble();
        }
        else judge=false;
        //提取作业成绩2
        if(ui->tableWidget->item(i,4)&&ui->tableWidget->item(i,4)->text()!=tr(""))
        {
            QString zuoye2=ui->tableWidget->item(i,4)->text();
            abs.a[i].wucizy[1]=zuoye2.toDouble();
        }
        else judge=false;

        //提取作业成绩3
        if(ui->tableWidget->item(i,5)&&ui->tableWidget->item(i,5)->text()!=tr(""))
        {
            QString zuoye3=ui->tableWidget->item(i,5)->text();
            abs.a[i].wucizy[2]=zuoye3.toDouble();
        }
        else judge=false;
        //提取作业成绩4
        if(ui->tableWidget->item(i,6)&&ui->tableWidget->item(i,6)->text()!=tr(""))
        {
            QString zuoye4=ui->tableWidget->item(i,6)->text();
            abs.a[i].wucizy[3]=zuoye4.toDouble();
        }
        else judge=false;
        //提取作业成绩5
        if(ui->tableWidget->item(i,7)&&ui->tableWidget->item(i,7)->text()!=tr(""))
        {
            QString zuoye5=ui->tableWidget->item(i,7)->text();
            abs.a[i].wucizy[4]=zuoye5.toDouble();
        }
        else judge=false;
        //计算作业成绩
        if(judge==true)
        {abs.a[i].score1=(abs.a[i].wucizy[0]+abs.a[i].wucizy[1]+abs.a[i].wucizy[2]+abs.a[i].wucizy[3]+abs.a[i].wucizy[4])/5;
            QString score1=QString::number(abs.a[i].score1);
            QTableWidgetItem *item0 = new QTableWidgetItem(score1);
            ui->tableWidget->setItem(i,8,item0);}
        //提取ppt成绩
        if(ui->tableWidget->item(i,9)&&ui->tableWidget->item(i,9)->text()!=tr(""))
        {
            QString pptScore=ui->tableWidget->item(i,9)->text();
            abs.a[i].ppt=pptScore.toDouble();
        }
        else judge=false;
        //提取讲述成绩
        if(ui->tableWidget->item(i,10)&&ui->tableWidget->item(i,10)->text()!=tr(""))
        {
            QString introduntionScore=ui->tableWidget->item(i,10)->text();
            abs.a[i].introduction=introduntionScore.toDouble();
        }
        else judge=false;
        //提取代码成绩
        if(ui->tableWidget->item(i,11)&&ui->tableWidget->item(i,11)->text()!=tr(""))
        {
            QString daimaScore=ui->tableWidget->item(i,11)->text();
            abs.a[i].daima=daimaScore.toDouble();
        }
        else judge=false;
        //计算上机成绩
        if(judge==true)
        {abs.a[i].score2=abs.a[i].ppt*0.2+abs.a[i].introduction*0.2+abs.a[i].daima*0.6;
            QString score2=QString::number(abs.a[i].score2);
            QTableWidgetItem *item1 = new QTableWidgetItem(score2);
            ui->tableWidget->setItem(i,12,item1);}
        //提取基本概念成绩
        if(ui->tableWidget->item(i,13)&&ui->tableWidget->item(i,13)->text()!=tr(""))
        {
            QString basisScore=ui->tableWidget->item(i,13)->text();
            abs.a[i].basis=basisScore.toDouble();
        }
        else judge=false;
        //提取综合应用成绩
        if(ui->tableWidget->item(i,14)&&ui->tableWidget->item(i,14)->text()!=tr(""))
        {
            QString workScore=ui->tableWidget->item(i,14)->text();
            abs.a[i].work=workScore.toDouble();
        }
        else judge=false;
        //计算笔试成绩
        if(judge==true)
        {abs.a[i].score3=abs.a[i].basis*0.5+abs.a[i].work*0.5;
            QString score3=QString::number(abs.a[i].score3);
            QTableWidgetItem *item2 = new QTableWidgetItem(score3);
            ui->tableWidget->setItem(i,15,item2);}
        //计算总评成绩
        if(judge==true)
        {abs.a[i].score=abs.a[i].score1*0.15+abs.a[i].score2*0.25+abs.a[i].score3*0.6;
            QString score=QString::number(abs.a[i].score);
            QTableWidgetItem *item3 = new QTableWidgetItem(score);
            ui->tableWidget->setItem(i,16,item3);}
    }
    if(judge==true)
    {
        ofstream ofs;
        ofs.open("sheetTotal.txt",ios::trunc|ios::out);
//        ofs<<"姓名\t"<<"学号\t"<<"班级\t"<<"作业成绩1\t\t"<<"作业成绩2\t\t"<<"作业成绩3\t\t"<<"作业成绩4\t\t"<<"作业成绩5\t\t"
//          <<"作业成绩\t\t"<<"PPT成绩\t\t"<<"讲述成绩\t\t"<<"代码成绩\t\t"<<"上机成绩\t\t"<<"基本概念\t\t"
//         <<"综合应用\t\t"<<"笔试成绩\t\t"<<"总评成绩\t\t";
        for(int i=0;i<ui->tableWidget->rowCount();i++)
        {
            ofs<<endl<<abs.a[i].name.toStdString()<<"\t"<<abs.a[i].id.toStdString()<<"\t"<<abs.a[i].banji_name.toStdString()<<"\t"
              <<abs.a[i].wucizy[0]<<"\t\t"<<abs.a[i].wucizy[1]<<"\t\t"<<abs.a[i].wucizy[2]<<"\t\t"<<abs.a[i].wucizy[3]<<"\t\t"<<abs.a[i].wucizy[4]<<"\t\t"
             <<abs.a[i].score1<<"\t\t"<<abs.a[i].ppt<<"\t\t"<<abs.a[i].introduction<<"\t\t"<<abs.a[i].daima<<"\t\t"<<abs.a[i].score2<<"\t\t"
            <<abs.a[i].basis<<"\t\t"<<abs.a[i].work<<"\t\t"<<abs.a[i].score3<<"\t\t"<<abs.a[i].score<<"\t\t";
        }
        ofs.close();
        ofs.open("sheet1.txt",ios::trunc|ios::out);
//        ofs<<"姓名\t"<<"学号\t"<<"班级\t"<<"作业成绩1\t\t"<<"作业成绩2\t\t"<<"作业成绩3\t\t"<<"作业成绩4\t\t"<<"作业成绩5\t\t"
//          <<"作业成绩\t\t";
        for(int i=0;i<ui->tableWidget->rowCount();i++)
        {
            ofs<<endl<<abs.a[i].name.toStdString()<<"\t"<<abs.a[i].id.toStdString()<<"\t"<<abs.a[i].banji_name.toStdString()<<"\t"
              <<abs.a[i].wucizy[0]<<"\t\t"<<abs.a[i].wucizy[1]<<"\t\t"<<abs.a[i].wucizy[2]<<"\t\t"<<abs.a[i].wucizy[3]<<"\t\t"<<abs.a[i].wucizy[4]<<"\t\t"
             <<abs.a[i].score1<<"\t\t";
        }
        ofs.close();
        ofs.open("sheet2.txt",ios::trunc|ios::out);
//        ofs<<"姓名\t"<<"学号\t"<<"班级\t"<<"PPT成绩\t\t"<<"讲述成绩\t\t"<<"代码成绩\t\t"<<"上机成绩\t\t";
        for(int i=0;i<ui->tableWidget->rowCount();i++)
        {
            ofs<<endl<<abs.a[i].name.toStdString()<<"\t"<<abs.a[i].id.toStdString()<<"\t"<<abs.a[i].banji_name.toStdString()<<"\t"
              <<abs.a[i].ppt<<"\t\t"<<abs.a[i].introduction<<"\t\t"<<abs.a[i].daima<<"\t\t"<<abs.a[i].score2<<"\t\t";
        }
        ofs.close();
        ofs.open("sheet3.txt",ios::trunc|ios::out);
//        ofs<<"姓名\t"<<"学号\t"<<"班级\t"<<"基本概念\t\t"
//          <<"综合应用\t\t"<<"笔试成绩\t\t";
        for(int i=0;i<ui->tableWidget->rowCount();i++)
        {
            ofs<<endl<<abs.a[i].name.toStdString()<<"\t"<<abs.a[i].id.toStdString()<<"\t"<<abs.a[i].banji_name.toStdString()<<"\t"
              <<abs.a[i].basis<<"\t\t"<<abs.a[i].work<<"\t\t"<<abs.a[i].score3<<"\t\t";
        }
        ofs.close();
        ofs.open("sheet4.txt",ios::trunc|ios::out);
//        ofs<<"姓名\t"<<"学号\t"<<"班级\t"
//          <<"作业成绩\t\t"<<"上机成绩\t\t"<<"笔试成绩\t\t"<<"总评成绩\t\t";
        for(int i=0;i<ui->tableWidget->rowCount();i++)
        {
            ofs<<endl<<abs.a[i].name.toStdString()<<"\t"<<abs.a[i].id.toStdString()<<"\t"<<abs.a[i].banji_name.toStdString()<<"\t"
              <<abs.a[i].score1<<"\t\t"<<abs.a[i].score2<<"\t\t"
             <<abs.a[i].score3<<"\t\t"<<abs.a[i].score<<"\t\t";
        }
        ofs.close();
        DialogFail *dialogfail2=new DialogFail;
        dialogfail2->CsetText("保存成功！");
        dialogfail2->show();
    }
    else
    {
        DialogFail *dialogfail2=new DialogFail;
        dialogfail2->CsetText("请完整填写表格");
        dialogfail2->show();
    }
}


void StudentManage::on_ButtAdd_clicked()
{
    int row = ui->tableWidget->currentRow();
    int row_count = ui->tableWidget->rowCount();
    int newRow = row+1;            //在选中的行后添加行
    if(row==-1)
    {
        newRow = row_count;
    }
    ui->tableWidget->insertRow(newRow);

}


void StudentManage::on_ButtDelete_clicked()
{
    int row = ui->tableWidget->currentRow();
    if(row != -1)
    {
        ui->tableWidget->removeRow(row);
        ui->tableWidget->setCurrentItem(NULL);  //取消选中的行，即每次删除时需要选择删除哪行
    }

}


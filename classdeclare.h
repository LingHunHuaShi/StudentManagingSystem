#ifndef CLASSDECLARE_H
#define CLASSDECLARE_H
#include<iostream>
#include <QMainWindow>
using namespace std;

class ClassDeclare
{
public:
    ClassDeclare();
};

struct xuesheng
{
    //班级信息
    QString id = "0";
    QString name = "0";
    QString banji_name = "0";
    //五次作业成绩及作业总成绩
    double wucizy[5] = { 0,0,0,0,0 };
    double score1 = 0;
    //ppt，讲述，代码及上机成绩
    double ppt = 0;
    double introduction = 0;
    double daima = 0;
    double score2 = 0;
    //基础概念，综合应用及笔试成绩
    double basis = 0;
    double work = 0;
    double score3 = 0;
    //总成绩
    double score = 0;
};
struct banji
{
    struct xuesheng a[1000];
    int size = 0;
};


#endif // CLASSDECLARE_H

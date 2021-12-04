#ifndef DIALOGINFO_H
#define DIALOGINFO_H

#include <QDialog>

namespace Ui {
class DialogInfo;
}

class DialogInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInfo(QWidget *parent = nullptr);
    ~DialogInfo();

private slots:
    void on_ButtConfirm_clicked();

private:
    Ui::DialogInfo *ui;
};

#endif // DIALOGINFO_H

#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

#include<QtSql\qsqltablemodel.h>
namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

private:
    Ui::MyDialog *ui;
    QSqlTableModel *tableModel;

};

#endif // MYDIALOG_H

#include "mydialog.h"
#include "ui_mydialog.h"
#include<QDebug>

#include<QtSql\qsqltablemodel.h>

#include <QtSql\qsqldatabase.h>
#include<QMessageBox>
#include <QTableWidget>
MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    QSqlDatabase db(QSqlDatabase::addDatabase("QSQLITE"));
       db.setDatabaseName("F:\MCIDatabase.db");

          if (!db.open()) {
              printf("Errordatabase.");
          }


          else
          {
              printf("opend");
             // ui->label->setText("opnd");

              tableModel = new QSqlTableModel();
              tableModel->setTable("ICSI");
              tableModel->select();
              ui->tableView->setModel(tableModel);

   /*
           QSqlQueryModel model;
                  model.setQuery("SELECT * FROM Performance");

                  for (int i = 0; i < model.rowCount(); ++i) {
                      int tim = model.record(i).value("Time").toInt();
                      double dist = model.record(i).value("Distance").toDouble();
                      qDebug() << tim << dist;

                  }

                */



   }
   }


MyDialog::~MyDialog()
{
    delete ui;
}

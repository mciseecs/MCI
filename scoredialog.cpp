#include "scoredialog.h"
#include "ui_scoredialog.h"
#include<QDebug>

#include<QtSql\qsqltablemodel.h>

#include <QtSql\qsqldatabase.h>
#include<QMessageBox>
#include <QTableWidget>
ScoreDialog::ScoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoreDialog)
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
              tableModel->setTable("PERFORMANCE2");
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

ScoreDialog::~ScoreDialog()
{
    delete ui;
}

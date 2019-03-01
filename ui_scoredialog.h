/********************************************************************************
** Form generated from reading UI file 'scoredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREDIALOG_H
#define UI_SCOREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ScoreDialog
{
public:
    QTableView *tableView;

    void setupUi(QDialog *ScoreDialog)
    {
        if (ScoreDialog->objectName().isEmpty())
            ScoreDialog->setObjectName(QStringLiteral("ScoreDialog"));
        ScoreDialog->resize(400, 468);
        tableView = new QTableView(ScoreDialog);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 40, 291, 381));

        retranslateUi(ScoreDialog);

        QMetaObject::connectSlotsByName(ScoreDialog);
    } // setupUi

    void retranslateUi(QDialog *ScoreDialog)
    {
        ScoreDialog->setWindowTitle(QApplication::translate("ScoreDialog", "ScoreDialog", 0));
    } // retranslateUi

};

namespace Ui {
    class ScoreDialog: public Ui_ScoreDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREDIALOG_H

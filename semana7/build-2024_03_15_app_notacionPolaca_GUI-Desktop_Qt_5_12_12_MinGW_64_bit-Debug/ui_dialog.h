/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton_convertir;
    QPushButton *pushButton_solucion;
    QLabel *label_infija;
    QLabel *label_posfija;
    QLabel *label_res;
    QLineEdit *lineEdit_infija;
    QComboBox *comboBox;
    QPushButton *pushButton_vaciar;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 450);
        Dialog->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:repeat, x1:0.292, y1:0.38, x2:0.663, y2:0.699, stop:0 rgba(170, 112, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        pushButton_convertir = new QPushButton(Dialog);
        pushButton_convertir->setObjectName(QString::fromUtf8("pushButton_convertir"));
        pushButton_convertir->setGeometry(QRect(190, 150, 101, 51));
        pushButton_convertir->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.887, fx:0.494, fy:0.5, stop:0 rgba(166, 236, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
"font: 75 12pt \"Miriam Libre\";"));
        pushButton_solucion = new QPushButton(Dialog);
        pushButton_solucion->setObjectName(QString::fromUtf8("pushButton_solucion"));
        pushButton_solucion->setGeometry(QRect(130, 250, 101, 51));
        pushButton_solucion->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.887, fx:0.494, fy:0.5, stop:0 rgba(166, 236, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
"font: 75 12pt \"Miriam Libre\";"));
        label_infija = new QLabel(Dialog);
        label_infija->setObjectName(QString::fromUtf8("label_infija"));
        label_infija->setGeometry(QRect(20, 10, 131, 31));
        label_infija->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.887, fx:0.494, fy:0.5, stop:0 rgba(166, 236, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
"font: 75 12pt \"Miriam Libre\";"));
        label_posfija = new QLabel(Dialog);
        label_posfija->setObjectName(QString::fromUtf8("label_posfija"));
        label_posfija->setGeometry(QRect(230, 400, 151, 31));
        label_posfija->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.887, fx:0.494, fy:0.5, stop:0 rgba(166, 236, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
"font: 75 12pt \"Miriam Libre\";"));
        label_res = new QLabel(Dialog);
        label_res->setObjectName(QString::fromUtf8("label_res"));
        label_res->setGeometry(QRect(260, 363, 121, 20));
        label_res->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);\n"
"font: 75 12pt \"Miriam Libre\";"));
        lineEdit_infija = new QLineEdit(Dialog);
        lineEdit_infija->setObjectName(QString::fromUtf8("lineEdit_infija"));
        lineEdit_infija->setGeometry(QRect(20, 50, 121, 31));
        lineEdit_infija->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 75 12pt \"Miriam Libre\";"));
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 90, 101, 22));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Miriam Libre\";"));
        pushButton_vaciar = new QPushButton(Dialog);
        pushButton_vaciar->setObjectName(QString::fromUtf8("pushButton_vaciar"));
        pushButton_vaciar->setGeometry(QRect(10, 410, 81, 21));
        pushButton_vaciar->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Miriam Libre\";\n"
"background-color: rgb(255, 66, 66);\n"
"color: rgb(0, 0, 0);"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "21130876_LuisBarranco", nullptr));
        pushButton_convertir->setText(QApplication::translate("Dialog", "CONVERTIR", nullptr));
        pushButton_solucion->setText(QApplication::translate("Dialog", "SOLUCION", nullptr));
        label_infija->setText(QApplication::translate("Dialog", "NOTACION INFIJA", nullptr));
        label_posfija->setText(QApplication::translate("Dialog", "NOTACION POSTFIJA", nullptr));
        label_res->setText(QString());
        pushButton_vaciar->setText(QApplication::translate("Dialog", "Vaciar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

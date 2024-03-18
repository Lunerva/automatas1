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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label_aritmetica;
    QLabel *label_res1;
    QLabel *label_res1_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit_num;
    QPushButton *pushButton_set1;
    QPushButton *pushButton_set2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpinBox *spinBox_valor;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_conj_1;
    QLabel *label_conj_2;
    QPushButton *pushButton_vaciar;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(500, 500);
        QFont font;
        font.setFamily(QString::fromUtf8("Nirmala UI"));
        font.setPointSize(10);
        Dialog->setFont(font);
        Dialog->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 0, 0, 255), stop:0.479904 rgba(255, 0, 0, 255), stop:0.522685 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_aritmetica = new QLabel(Dialog);
        label_aritmetica->setObjectName(QString::fromUtf8("label_aritmetica"));
        label_aritmetica->setGeometry(QRect(0, 10, 501, 61));
        label_aritmetica->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));\n"
"font: 24pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        label_aritmetica->setAlignment(Qt::AlignCenter);
        label_res1 = new QLabel(Dialog);
        label_res1->setObjectName(QString::fromUtf8("label_res1"));
        label_res1->setGeometry(QRect(120, 380, 361, 21));
        label_res1->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));
        label_res1->setFrameShape(QFrame::Box);
        label_res1_2 = new QLabel(Dialog);
        label_res1_2->setObjectName(QString::fromUtf8("label_res1_2"));
        label_res1_2->setGeometry(QRect(120, 410, 361, 21));
        label_res1_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));
        label_res1_2->setFrameShape(QFrame::Box);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 80, 111, 154));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit_num = new QTextEdit(layoutWidget);
        textEdit_num->setObjectName(QString::fromUtf8("textEdit_num"));
        textEdit_num->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(textEdit_num);

        pushButton_set1 = new QPushButton(layoutWidget);
        pushButton_set1->setObjectName(QString::fromUtf8("pushButton_set1"));
        pushButton_set1->setStyleSheet(QString::fromUtf8("background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"color: rgb(0, 0, 0);\n"
"font: 75 12pt \"Noto Naskh Arabic\";"));

        verticalLayout->addWidget(pushButton_set1);

        pushButton_set2 = new QPushButton(layoutWidget);
        pushButton_set2->setObjectName(QString::fromUtf8("pushButton_set2"));
        pushButton_set2->setStyleSheet(QString::fromUtf8("background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"color: rgb(0, 0, 0);\n"
"font: 75 12pt \"Noto Naskh Arabic\";"));

        verticalLayout->addWidget(pushButton_set2);

        layoutWidget1 = new QWidget(Dialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 380, 93, 54));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"text-decoration: underline;\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"color: rgb(85, 255, 0);"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"text-decoration: underline;\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));

        verticalLayout_2->addWidget(pushButton_2);

        spinBox_valor = new QSpinBox(Dialog);
        spinBox_valor->setObjectName(QString::fromUtf8("spinBox_valor"));
        spinBox_valor->setGeometry(QRect(130, 90, 91, 51));
        spinBox_valor->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);\n"
"color: rgb(0, 0, 0);"));
        layoutWidget2 = new QWidget(Dialog);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 300, 471, 50));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_conj_1 = new QLabel(layoutWidget2);
        label_conj_1->setObjectName(QString::fromUtf8("label_conj_1"));
        label_conj_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"color: rgb(170, 0, 0);\n"
"font: 16pt \"MS PGothic\";"));

        verticalLayout_3->addWidget(label_conj_1);

        label_conj_2 = new QLabel(layoutWidget2);
        label_conj_2->setObjectName(QString::fromUtf8("label_conj_2"));
        label_conj_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"color: rgb(170, 0, 0);\n"
"font: 16pt \"MS PGothic\";"));

        verticalLayout_3->addWidget(label_conj_2);

        pushButton_vaciar = new QPushButton(Dialog);
        pushButton_vaciar->setObjectName(QString::fromUtf8("pushButton_vaciar"));
        pushButton_vaciar->setGeometry(QRect(369, 120, 91, 41));
        pushButton_vaciar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "CONJUNTOS_21130876", nullptr));
        label_aritmetica->setText(QApplication::translate("Dialog", "ARITMETICA DE CONJUNTOS", nullptr));
        label_res1->setText(QString());
        label_res1_2->setText(QString());
        textEdit_num->setPlaceholderText(QApplication::translate("Dialog", "inserta un numero", nullptr));
        pushButton_set1->setText(QApplication::translate("Dialog", "SET 1", nullptr));
        pushButton_set2->setText(QApplication::translate("Dialog", "SET 2", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "UNION", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog", "INTERSECCION", nullptr));
        label_conj_1->setText(QApplication::translate("Dialog", "CONJUNTO 1:", nullptr));
        label_conj_2->setText(QApplication::translate("Dialog", "CONJUNTO 2:", nullptr));
        pushButton_vaciar->setText(QApplication::translate("Dialog", "vaciar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

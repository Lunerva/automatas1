/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionAnalizar;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionNuevo;
    QWidget *centralwidget;
    QTextEdit *textEdit_code;
    QTextEdit *textEdit_Alexico;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuLexico;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(650, 373);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 11pt \"Noto Serif Armenian\";"));
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QString::fromUtf8("actionAbrir"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAnalizar = new QAction(MainWindow);
        actionAnalizar->setObjectName(QString::fromUtf8("actionAnalizar"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionNuevo = new QAction(MainWindow);
        actionNuevo->setObjectName(QString::fromUtf8("actionNuevo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit_code = new QTextEdit(centralwidget);
        textEdit_code->setObjectName(QString::fromUtf8("textEdit_code"));
        textEdit_code->setGeometry(QRect(20, 20, 311, 281));
        textEdit_code->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        textEdit_Alexico = new QTextEdit(centralwidget);
        textEdit_Alexico->setObjectName(QString::fromUtf8("textEdit_Alexico"));
        textEdit_Alexico->setGeometry(QRect(370, 20, 251, 281));
        textEdit_Alexico->setStyleSheet(QString::fromUtf8("font: 8pt \"MS Mincho\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 650, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuLexico = new QMenu(menubar);
        menuLexico->setObjectName(QString::fromUtf8("menuLexico"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuLexico->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNuevo);
        menuFile->addAction(actionAbrir);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuLexico->addAction(actionAnalizar);
        menuHelp->addAction(actionAbout);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AnalizadorLexico_LuisBarranco", nullptr));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Guardar", nullptr));
        actionSave_as->setText(QApplication::translate("MainWindow", "Guardar como", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Salir", nullptr));
        actionAnalizar->setText(QApplication::translate("MainWindow", "Analizar", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "Acerca de", nullptr));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "Acerca de Qt", nullptr));
        actionNuevo->setText(QApplication::translate("MainWindow", "Nuevo", nullptr));
        textEdit_code->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Serif Armenian'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        textEdit_Alexico->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Mincho'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "Archivo", nullptr));
        menuLexico->setTitle(QApplication::translate("MainWindow", "Lexico", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Ayuda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

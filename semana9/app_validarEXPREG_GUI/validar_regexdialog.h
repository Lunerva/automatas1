#ifndef VALIDAR_REGEXDIALOG_H
#define VALIDAR_REGEXDIALOG_H

#include <QDialog>
#include"validar_regex.h"

class QLineEdit;

class validar_regexDIALOG : public QDialog
{
    Q_OBJECT
public:
    validar_regexDIALOG();
private:
    QLineEdit *lineEdit_regex;
    QLineEdit *lineEdit_entrada;
};

#endif // VALIDAR_REGEXDIALOG_H

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <iostream>
#include "conjunto.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE
using namespace std;


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_set1_clicked();
    void on_spinBox_valor_valueChanged(int arg1);


    void on_pushButton_set2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_vaciar_clicked();

private:
    Ui::Dialog *ui;
    conjunto *set1, *set2, *set3;
    int valor;
};
#endif // DIALOG_H

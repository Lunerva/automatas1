#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "notacionpolaca.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QString eInfija;
    QString res;
    QString posfija;
    NotacionPolaca expresion;

private slots:
    void on_pushButton_solucion_clicked();

    void on_pushButton_convertir_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_vaciar_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H

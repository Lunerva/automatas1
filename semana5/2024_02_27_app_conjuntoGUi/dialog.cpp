#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    set1=new conjunto(10);
    set2=new conjunto(10);
    set3=new conjunto(set1->tam+set2->tam);

    set1->vacio();
    set2->vacio();
    set3->vacio();

    valor=0;

//    connect(ui->spinBox_valor,SIGNAL(valueChanged(int)),ui->textEdit_num,SLOT(setValue(int)));

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_set1_clicked()
{
    string salida="",nombre="conjunto 1";
    string res;

    set1->asignar(valor);
    salida.append(set1->mostrar(nombre));
    ui->label_conj_1->setText(QString::fromStdString(salida));
    ui->label_conj_1->adjustSize();

}


void Dialog::on_spinBox_valor_valueChanged(int arg1)
{
    ui->textEdit_num->setText(QString::number(arg1));
    valor = arg1;
}


void Dialog::on_pushButton_set2_clicked()
{
    string salida="",nombre="conjunto 2";
    string res;

    set2->asignar(valor);
    salida.append(set2->mostrar(nombre));
    ui->label_conj_2->setText(QString::fromStdString(salida));
    ui->label_conj_2->adjustSize();
}


void Dialog::on_pushButton_clicked()
{
    set3->vacio();
    string salida="",nombre="conjunto 3";

    set1->unionn(set2,set3);
    salida.append(set3->mostrar(nombre));
    ui->label_res1->setText(QString::fromStdString(salida));
    ui->label_res1->adjustSize();

}


void Dialog::on_pushButton_2_clicked()
{
    set3->vacio();
    string salida="",nombre="conjunto 3";

    set1->interseccionn(set2,set3);
    salida.append(set3->mostrar(nombre));
    ui->label_res1_2->setText(QString::fromStdString(salida));
    ui->label_res1_2->adjustSize();

}


void Dialog::on_pushButton_vaciar_clicked()
{
    set1->vacio();
    set2->vacio();
    set3->vacio();

    string salida="",nombre="conjunto";

    salida.append(set3->mostrar(nombre));
    ui->label_res1_2->setText(QString::fromStdString(salida));
    ui->label_res1_2->adjustSize();
    ui->label_res1->setText(QString::fromStdString(salida));
    ui->label_res1->adjustSize();
    salida="";


    salida.append(set2->mostrar(nombre));
    ui->label_conj_2->setText(QString::fromStdString(salida));
    ui->label_conj_2->adjustSize();
    salida="";

    salida.append(set1->mostrar(nombre));
    ui->label_conj_1->setText(QString::fromStdString(salida));
    ui->label_conj_1->adjustSize();

}


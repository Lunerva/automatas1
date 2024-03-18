#include "dialog.h"
#include "ui_dialog.h"
#include <QWidget>
#include <QVBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_solucion_clicked()
{

    eInfija = ui->lineEdit_infija->text();

    if(expresion.validarEntrada(eInfija.toStdString())){
        posfija=expresion.convertirAposFija(eInfija);
        ui->comboBox->addItem(eInfija);
        res = QString::fromStdString(std::to_string(expresion.resolverPosFija(posfija.toStdString())));
        ui->label_res->setText(res);
    }
    else{
        //dibuja un panel que describe el error
        //ademas deja un boton para cerrar el panel
        QWidget *error = new QWidget();
        error->setWindowTitle("Error");
        //creamos un layout para organizar los elementos en el widget
        QVBoxLayout *layout = new QVBoxLayout();
        error->setLayout(layout);
        //mostramos el mensaje de error
        QLabel *labelMensaje = new QLabel("no se admite ese tipo de entrada");
        layout->addWidget(labelMensaje);
        //tamaño del widget
        error->setMinimumSize(200, 100);

        error->show();
    }
}


void Dialog::on_pushButton_convertir_clicked()
{

    eInfija = ui->lineEdit_infija->text();
    ui->comboBox->addItem(eInfija);
    res = expresion.convertirAposFija(eInfija);
    ui->label_res->setText(res);
}


void Dialog::on_comboBox_currentIndexChanged(int index)
{
    ui->lineEdit_infija->setText(ui->comboBox->itemText(index));
}


void Dialog::on_pushButton_vaciar_clicked()
{
    ui->comboBox->clear();
}


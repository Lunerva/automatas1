#include "validar_regexdialog.h"
#include<QVBoxLayout>
#include<QGridLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QComboBox>
#include<QIntValidator>
#include<QRegularExpression>
#include<QRegularExpressionValidator>


void crearValidador(QLineEdit *lineEdit_entrada, const QString &regex) {
    QRegularExpression expReg(regex);
    QRegularExpressionValidator *validador = new QRegularExpressionValidator(expReg);
    lineEdit_entrada->setValidator(validador);
}

validar_regexDIALOG::validar_regexDIALOG()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QGridLayout *editLayout = new QGridLayout;
    QHBoxLayout *comboBox = new QHBoxLayout;
    QHBoxLayout *button = new QHBoxLayout;


    /////////ETIQUETAS
    QLabel *label_regex = new QLabel("Expresion regular: ");
    QLabel *label_entrada = new QLabel("Entrada: ");
    QLabel *label_salida = new QLabel("Resultado");

    ///////////LINE EDIT
    lineEdit_regex = new QLineEdit;
    lineEdit_entrada = new QLineEdit;

    //////////////AÑADIMOS LAS PARTES DE ENTRADA DE DATOS
    /// ENTRADA REGEX NUEVA
    /// LAYOUT VISTA EN MATRIZ:
    /// |{0,0} {0,1}|
    /// |{1,0} {1,1}|
    editLayout->addWidget(label_regex,0,0); // POS EN LAYOUT  {0,0}
    editLayout->addWidget(lineEdit_regex,0,1); // POS EN LAYOUT  {0,1}

    /// ENTRADA EJEMPLO CADENA
    editLayout->addWidget(label_entrada,1,0); // POS EN LAYOUT  {1,0}
    editLayout->addWidget(lineEdit_entrada,1,1); // POS EN LAYOUT  {1,1}

    /// MOSTRAMOS SI COINCIDE MEDIANTE ETIQUETA
    editLayout->addWidget(label_salida);
//    editLayout->addWidget(label_salida, 2, 0, 1, 2);

    /*
    //////////// COMBO BOX CON OPCIONES DE REGEX PREDEFINIDAS
    QComboBox *opciones = new QComboBox();
    /// REGEX DE CORREOS
    opciones->addItem("[a-zA-B0-1]+@[empresa]+[//D]{2,}+[//D]{2,}?");
    comboBox->addStretch();
    comboBox->addWidget(opciones);
*/

    /// AÑADIMOS BOTON PARA SALIR DE LA APLIACION
    QPushButton *botonSalir = new QPushButton("salir");
    button->addStretch();
    button->addWidget(botonSalir);


    ////////// AÑADIMOS AL LAYOUT PRINCIPAL
    mainLayout->addLayout(comboBox); // APARECERA HASTA ARRIBA
    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(button); // APARECERA HASTA ABAJO


    // Crear instancia de validar_regex y conectar señales y slots
    validar_regex *val = new validar_regex(this);
    connect(lineEdit_regex, SIGNAL(textChanged(const QString&)), val, SLOT(setRegex(const QString&)));
    connect(lineEdit_entrada, SIGNAL(textChanged(const QString&)), val, SLOT(validarEntrada(const QString&)));
    connect(val, SIGNAL(resChanged(QString)), label_salida, SLOT(setText(QString)));

    // Configurar el validador inicial
    crearValidador(lineEdit_entrada, lineEdit_regex->text());

    connect(botonSalir, SIGNAL(released()), this, SLOT(accept()));

    setWindowTitle("21130876_validar_expresiones_regulares");

}

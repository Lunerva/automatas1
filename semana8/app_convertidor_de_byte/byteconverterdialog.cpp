#include "byteconverterdialog.h"
#include<QVBoxLayout>
#include<QGridLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QIntValidator>
#include<QRegularExpression>
#include<QRegularExpressionValidator>
#include"byteconverter.h"

ByteConverterDialog::ByteConverterDialog()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QGridLayout *editLayout = new QGridLayout;
    QHBoxLayout *button = new QHBoxLayout;

    QLabel *decLabel = new QLabel("Decimal");
    QLabel *hexLabel = new QLabel("Hexadecimal");
    QLabel *binLabel =new QLabel("Binario");

    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;

    editLayout->addWidget(decLabel,0,0);
    editLayout->addWidget(decEdit,0,1);

    editLayout->addWidget(hexLabel,1,0);
    editLayout->addWidget(hexEdit,1,1);

    editLayout->addWidget(binLabel,2,0);
    editLayout->addWidget(binEdit,2,1);

    QPushButton *botonSalir = new QPushButton("salir");
    button->addStretch();
    button->addWidget(botonSalir);

    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(button);

    connect(botonSalir,SIGNAL(released()),this,SLOT(accept()));

    QIntValidator *decimalVal = new QIntValidator(0,255,decEdit);
    decEdit->setValidator(decimalVal);

    QRegularExpressionValidator *hexVal = new QRegularExpressionValidator(QRegularExpression ("[0-9a-fA-F]{1,2}"));
    hexEdit->setValidator(hexVal);

    QRegularExpressionValidator *binVal = new QRegularExpressionValidator(QRegularExpression ("[0-1]{1,8}"));
    binEdit->setValidator(binVal);

    this->setWindowTitle("Conversor de 1 byte");
    ByteConverter *convertidor = new ByteConverter;

    connect(decEdit,SIGNAL(textChanged(QString)),convertidor,SLOT(setDec(QString)));
    connect(convertidor, SIGNAL(hexChanged(QString)),hexEdit,SLOT(setText(QString)));
    connect(convertidor,SIGNAL(binChanged(QString)),binEdit,SLOT(setText(QString)));

    connect(binEdit,SIGNAL(textChanged(QString)),convertidor,SLOT(setBin(QString)));
    connect(convertidor, SIGNAL(hexChanged(QString)),hexEdit,SLOT(setText(QString)));
    connect(convertidor,SIGNAL(decChanged(QString)),decEdit,SLOT(setText(QString)));

    connect(hexEdit,SIGNAL(textChanged(QString)),convertidor,SLOT(setHex(QString)));
    connect(convertidor, SIGNAL(binChanged(QString)),binEdit,SLOT(setText(QString)));
    connect(convertidor,SIGNAL(decChanged(QString)),decEdit,SLOT(setText(QString)));

}

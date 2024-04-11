#include "byteconverter.h"

ByteConverter::ByteConverter(QObject *parent) : QObject(parent)
{

}

void ByteConverter::setDec(const QString &valor)
{
    bool ok;
    int num = valor.toInt(&ok);
    if(ok){
        emit hexChanged(QString::number(num,16));
        emit binChanged(QString::number(num,2));
    }else {
        emit hexChanged("");
        emit binChanged("");
    }

}

void ByteConverter::setHex(const QString &valor)
{
    bool ok;
    int num = valor.toInt(&ok,16);
    if(ok){
        emit decChanged(QString::number(num,10));
        emit binChanged(QString::number(num,2));
    }else {
        emit decChanged("");
        emit binChanged("");
    }

}

void ByteConverter::setBin(const QString &valor)
{
    bool ok;
    int num = valor.toInt(&ok,2);
    if(ok){
        emit decChanged(QString::number(num,10));
        emit hexChanged(QString::number(num,16));
    }else {
        emit decChanged("");
        emit hexChanged("");
    }

}

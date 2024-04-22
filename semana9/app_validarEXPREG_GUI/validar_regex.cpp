#include "validar_regex.h"
#include<QRegularExpression>

using namespace std;

validar_regex::validar_regex(QObject *parent) : QObject(parent) {}

void validar_regex::setRegex(const QString &regex) {
    this->regex = regex;
}

void validar_regex::validarEntrada(const QString &entrada) {
    QRegularExpression expReg(regex);
    QRegularExpressionMatch match = expReg.match(entrada);
    emit resChanged(match.hasMatch() ? "Valido" : "No Valido");
}

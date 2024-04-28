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
    // EL USO DE '?' FUNCIONA COMO OPERADOR TERNARIO PARA ABREVIAR EL USO DE IF
    /*
    if (match.hasMatch()) {
        emit resChanged("<h3 style=\"color: #00ff00;\">Valido</h3>");
    } else {
        emit resChanged("<h3 style=\"color: #ff0000;\">No Valido</h3>");
    }

    */
    emit resChanged(match.hasMatch() ? "<h3 style=\"color: #00ff00;\">Valido</h3>"
                                     : "<h3 style=\"color: #ff0000;\">No Valido</h3>");
}


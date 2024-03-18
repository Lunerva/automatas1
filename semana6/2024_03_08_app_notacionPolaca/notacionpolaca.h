#ifndef NOTACIONPOLACA_H
#define NOTACIONPOLACA_H

#include "pilat.h"
#include "pilat.cpp"

#include <string>
#include <iostream>
#include <QString>

using namespace std;

enum Simbolo{OPERANDO, PIZQ,PDER,POT,SUMRES,MULTDIV,POW};


class NotacionPolaca
{
public:
    NotacionPolaca();

    char *convertirAposfija(string expInfija);

    string convertirAposFija(string expInfija);

    QString convertirAposFija(QString expInfija);

    Simbolo tipoYprocedencia(char c);

    // (1+2) * 3 ==>> 12+3*

    //en la solucion se debe extraer el valor
    //numerico del digito

    //'1'= 1        49-48

    bool validarEntrada(string entrada);

    bool numParentesis(string entrada);

};

#endif // NOTACIONPOLACA_H

#ifndef TABLADESIMBOLOS_H
#define TABLADESIMBOLOS_H

#include<iostream>
#include<string.h>

using namespace std;

typedef int symValue;

struct Simbolo{
    symValue valor;
    char *nombre;
    Simbolo *sig;
};


class TablaDeSimbolos
{
private:
    Simbolo **tabla;
    int size;
    symValue Hash(char*);

public:
    TablaDeSimbolos(int = 10);
    Simbolo *addSym(char *, symValue);
};

#endif // TABLADESIMBOLOS_H

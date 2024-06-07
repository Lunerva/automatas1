#ifndef TABLADESIMBOLOS_H
#define TABLADESIMBOLOS_H

#include<iostream>
#include<string.h>
#include<iomanip>
#include<sstream>

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
    void mostrarTabla();
    string mostrarTabla(string contenedor);
    void mostrar2();
    bool buscar(char *);
    Simbolo buscarSim(char *);
    bool findSym(char *nombre);
    bool borrarSym(char *);
    bool borrarSym2(char *);
};

#endif // TABLADESIMBOLOS_H

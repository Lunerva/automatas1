#ifndef ANALIZADORLEXICO_H
#define ANALIZADORLEXICO_H

#include <iostream>
#include <string>
#include <fstream>
#include "tabladesimbolos.h"

using namespace std;

#include<string.h>
#include <stdlib.h>

class analizadorLexico
{
public:

    //atributos
    int i, inicioToken, estadoInicial, estadoActual;
    string contenido;
    //se usara para tabla de simbolos
    string id;
    int valor;
    string tabla;

    analizadorLexico();
    //declaracion de las funciones o prototipos
    void scanner( char cadena[255]);
    void inicializaEstados();
    void fallo();//se puede cambiar el nombre por cambiaDeEstado
    bool estadoDeAceptacion();
    bool esDelimitador(char c);
    bool esLetra(char c);
    bool esDigito(char c);

};

#endif // ANALIZADORLEXICO_H

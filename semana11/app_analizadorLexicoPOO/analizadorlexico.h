#ifndef ANALIZADORLEXICO_H
#define ANALIZADORLEXICO_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include<string.h>
#include <stdlib.h>


class analizadorLexico
{
public:

    //variables globales que en la clase de rediseño
    //se convertiran en atributos
    int i, inicioToken, estadoInicial, estadoActual;

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

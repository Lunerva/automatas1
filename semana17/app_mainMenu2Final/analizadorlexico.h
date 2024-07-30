#ifndef ANALIZADORLEXICO_H
#define ANALIZADORLEXICO_H

#include <iostream>
#include <string>
#include <QStack>
#include <fstream>
#include "tabladesimbolos.h"

using namespace std;

#include<string.h>
#include <stdlib.h>
#include <stdio.h>

class analizadorLexico
{
public:
    string palRes[8] = {"main","puts","char","int","float","double","boolean","return"};

    string token[29] = {"x","main","puts","char","int","float","double","boolean","id",";","(",")","{","}","return","@","Cte.Lit.","[","]","num","car","real","booleano",",","=","+","-","*","/"};

    string varsint[19]={"x","A","A’","D","L","L’","I","I’",
                        "B","B’","C","C’","G","G’","K","T","F","E","P"};


    //LOS SIGUIENTES VALORES SE VAN BUSCANDO EN token y varsint
                //EL PRIMER VALOR INDICA EL RENGLON
                //EL SEGUNDO INDICA LA COLMNA
                //EL TERCERO INDICA EL PRODUCTOR
                //DEL CUARTO EN ADELANTE ES LO PRODUCIDO
    /*
        EJEMPLO
        LA PRODUCCION {, L'->,IL'} SE REPRESENTA EN CODIGO DE LA SIG FORMA:
        {3, 2, 3, -2, 4, 3, 999, 999}

        DONDE:
        renglon
        1.- 3 se encuentra en varsint y es L'

        columna
        2.- 2 se encuentra en token y es ,

        producciones
        3.- 3 se encuentra en varsint y es L'

        ->
        4.- Cuando un valor es negativo es porque se debe buscar en el arreglo token,
        esto se hace para no confudirse con el arreglo varsint, el proceso se realiza de la siguiente forma.
        -2 se convertira en 2 con ayuda del metodo vanalisis_intactico() y cualquier otro
        valor negativo pasara por el mismo proceso, esto con la finalidad de que sea
        positivo y usarla como posicion para encontrar el valor en el arreglo token.

        -2 pasa a 2 y se encuentra en token y es ,
        4 se encuentra en varsint y es I
        3 se encuentra en varsint y es L'

        los valores restantes son 999 que significa vacio, por lo que aqui termina la produccion


    */
                                                        // e -> cadena vacia
    int tablaM[100][8]= {//{1, 5, 1, 5, 999, -1, 999, 999}, //[ D->I';
                         {1, 1, 1, -1, 2, 999, 999, 999},//main A->main A'
                         {2, 10, 2, -10, -11, 8, 999, 999},//( A'->()B
                         {3, 3, 3, 15, 4, 999, 999, 999},//char D -> TL
                         //{3, 4, 3, ,},//int D -> TL

                       };

    QStack<string> pila;

    string asTokens[100];
    int indiceTokens;

    //atributos
    int i, inicioToken, estadoInicial, estadoActual;
    string contenido;
    //se usara para tabla de simbolos
    string id;
    int valor = 0;
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
    //ANALISIS SINTACTICO
    string vanalisis_sintactico();
    int estoken(char x[]);
    int buscaTabla(char a[], char x[]);
    string vmuestra();

};

#endif // ANALIZADORLEXICO_H

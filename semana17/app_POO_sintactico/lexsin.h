
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "archivo.h"

#include <iostream>
using namespace std;


#ifndef LEXSIN_H
#define LEXSIN_H

////////////////DEFINICIONES///////////////////////////////////
//#define TRUE 1
//#define FALSE 0

#define MAXTOKEN 100
#define NUMPALRES 4



class lexsin
{
    //////////////////ATRIBUTOS///////////////////////////////////////
    pila Pila;
    archivo fl;
    //PALABRAS RESERVADAS
    //OPC 1
    //char *PalRes[]= {"char", "float","int","puts"}; //printf
    //OPC 2
    char PalRes[5][10]= {"char", "float","int","puts"}; //printf

    //si se usa objeto string, cambiar el uso de strcmp
    //string PalRes[10]= {"char", "float","int","puts"}; //printf

    char sLexema[127];
    char sLinea[127];

    //char *non="13579", *par="24680";
    char non[6]="13579", par[6]="24680";

    char asTokens [MAXTOKEN][100];
    int indice=0, edoAct, edoIni, iniToken=0, k, numBytesArch;


    char token[22][8] = {"x", ";", ",", "*", "Id", "[", "]", "Num", "char", "int", "float",
        "puts", "(", ")", "Cte.Lit", "{", "}", "=","+","-","/", "Real"};

    char varsint[15][3]={"x", "D", "L", "L'", "I", "I'", "A", "A'", "K",
        "T", "F", "E", "P"};


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
        2.- 2 se encuentra en varsint y es L

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
    int tablaM[100][8]= {{1, 5, 1, 5, 999, -1, 999, 999}, //[ D->I';
                         {1, 5, 1, 5, 999, -1, 999, 999}, //; D->I';    /////SUS porque se esta repitiendo, es igual al anterior
                         {1, 1, 1, 5, 999, -1, 999, 999}, //id D->PL';  ////SUS porque el codigo hace algo diferente a lo que se explica. ; D->I';
                        {1, 7, 1, 5, 3, -1, 999, 999}, //num D->I'L';
                        {1, 8, 1, 9, 2, -1, 999, 999}, //char D->TL;
                        {1, 9, 1, 9, 2, -1, 999, 999}, //int D->TL;
                        {1, 10, 1, 9, 2, -1, 999, 999}, //float D->TL;
           /* 5 */      {2, 3, 2, 4, 3, 999, 999, 999}, // * L->IL'
                        {2, 4, 2, 4, 3, 999, 999, 999}, //Id L->IL'
                        {3, 1, 3, 5, 999, 999, 999, 999}, //; L'->I'
                        {3, 1, 3, 999, 999, 999, 999, 999},//; L'->e  ////SUS porque ya hay alguien ocupando su espacio, se pondran dos??
                        {3, 2, 3, -2, 4, 3, 999, 999}, //, L'->,IL'
          /* 10 */      {3, 3, 3, -3, 8, 3, 999, 999}, //* L'->*KL'
                        {3, 18, 3, 12, 3, 999, 999, 999}, //+ L'->PL'
                        {3, 19, 3, 12, 3, 999, 999, 999}, //- L'->PL'
                        {3, 20, 3, 12, 3, 999, 999, 999}, // / L'->PL'
                        {3, 14, 3, -14, 5, 999, 999, 999},// cte. Lit. L'->cte Lit. I'
                        {4, 3, 4, -3, -4, 5, 999, 999}, // * I->*Id I'
                        {4, 4, 4, -4, 5, 999, 999, 999},// Id I->Id I'
                        {5, 1, 5, 999, 999, 999, 999, 999},// ; I'->e
         /* 15 */       {5, 2, 5, 999, 999, 999, 999, 999},// , I'->e
                        {5, 5, 5, 6, 999, 999, 999, 999}, // [ I' -> A
                        //{5, 7, 5, -7, 999, 999, 999, 999}, //Num I' -> Num
                        //{5, 12, 5, 7, 8, 11, 999, 999}, //( I' -> Num
                        {5, 14, 5, -14, 999, 999, 999, 999}, //cte lit I'->cte lit
         /* -> */       {5, 17, 5, -17, 8, 999, 999, 999}, //= I'->=K
                        {6, 5, 6, -5, 8, 11, 999, 999}, //[ A->[ KE
         /* 20 */       {7, 1, 7, 999, 999, 999, 999, 999},//; A'->e
                        {7, 2, 7, 999, 999, 999, 999, 999},//, A'->e
                        {7, 5, 7, -5, 8, -6, 7, 999}, //[ A' -> [K]A'
                        {7, 12, 7, -12, 999, 999, 999, 999}, //( A' -> (
                        {8, 4, 8, -4, 999, 999, 999, 999}, //Id K -> Id
                        {8, 5, 8, -5, 8, 11, 999, 999}, //[ K -> [ KE
                        {8, 7, 8, -7, 999, 999, 999, 999}, //Num K -> Num
                        {8, 21, 8, -21, 999, 999, 999, 999}, //Real K -> Num ///SUS en realidad produce Real K -> Real
                        {8, 12, 8, -12, 8, 11, 999, 999}, //( K -> ( KE
                        {8, 15, 8, -15, 8, 10, 999, 999}, //{ K -> { KF
                        {9, 8, 9, -8, 999, 999, 999, 999}, //char T->Char
                        {9, 9, 9, -9, 999, 999, 999, 999}, //int T->int
                        {9, 10, 9, -10, 999, 999, 999, 999},//float T->float
                        /*segunda gramatica */
            /* 25 */    {10, 11, 10, -11, 11, -1, 999, 999},//puts F-> puts E;
                        {10, 16, 10, -16, 999, 999, 999, 999},//} F-> };
                        {11, 6, 11, -6, 1, 999, 999, 999},//]E -> ]D
                        {11, 12, 11, -12, 12, -13, 999, 999},//( E -> (P) ////SUS
                        {11, 13, 11, -13, 999, 999, 999, 999},//)E -> )
                        {12, 14, 12, -14, 999, 999, 999, 999},//cte lit P->cte lit
                        {12, 18, 12, -18, 8, 999, 999, 999},//+ P -> + k
                        {12, 19, 12, -19, 8, 999, 999, 999},//- P -> - k
                        {12, 20, 12, -20, 8, 999, 999, 999},// / P ->/ k
                       };

public:
    lexsin();
    ////////////////////////METODOS////////////////////////////////
    //ANALISIS LEXICO
    void vanalisislexico();
    void viniedos();
    char nextchar();
    void vretract();
    int edoActesacept();
    void falla();
    void recuperaerror();
    int esId();
    //ANALISIS SINTACTICO
    void vanalisis_sintactico();
    int estoken(char x[]);
    int buscaTabla(char a[], char x[]);
    void vmuestra();



    int getNumBytesArch() const;
    void setNumBytesArch(int newNumBytesArch);
};

#endif // LEXSIN_H

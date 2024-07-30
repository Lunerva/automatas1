
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


using namespace std;

#ifndef PILA_H
#define PILA_H
#define MAX 50



class pila
{
    //PILA
    int cima = -1;

public:

    char pilac[MAX][10];
    pila();
    //PILA
    void insertapila(string elem);//(char *elem);  //(char elem[]);
    void eliminapila();

    int getCima() const;
    void setCima(int newCima);
};

#endif // PILA_H

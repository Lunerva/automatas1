#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <iostream>
using namespace std;



class archivo
{
    //ARCHIVO
    bool finarch = false;
    FILE *Fd;


public:
    archivo();
    //ARCHIVOS
    void generararch();
    void vabrirarch();
    int  bytesarch();

    bool getFinarch() const;
    void setFinarch(bool newFinarch);
    FILE *getFd() const;
    void setFd(FILE *newFd);
};

#endif // ARCHIVO_H

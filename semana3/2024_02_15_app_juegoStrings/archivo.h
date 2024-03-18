#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>


using namespace std;

class archivo
{
public:
    archivo();
    void leerArchivo(char *archivo);
    string leerArchivoLinea(char *archivo);
    string leerArchivoLineaRand(char *archivo,int rand);
};

#endif // ARCHIVO_H

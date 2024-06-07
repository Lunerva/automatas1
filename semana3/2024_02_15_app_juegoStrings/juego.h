#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <archivo.h>
#include <palabra.h>
#include <map>

using namespace std;


class juego
{
public:
    juego();
    void iniciarJuego(char *archivo1, char *archivo2);
    palabra palabraAleatoria(char *nomArchivo, char *archivoT);
    void crearPalabras(char *nomArchivoO, char *nomArchivoT, palabra arr[]);
};

#endif // JUEGO_H

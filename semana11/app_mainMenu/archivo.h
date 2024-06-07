#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

using namespace std;

class archivo
{
public:
    archivo();
    void leerArchivo(char *archivo);
    string leerArchivoLinea(char *archivo);
    string leerArchivoLineaRand(char *archivo,int rand);
    void escribirArchivo(string *contenido, int tam);
    void escribirArchivo(string *contenido, int tam, string PATH, string nombre);
    void escribirArchivo(string contenido, string PATH, string nombre);
    QString leerArchivoQt(string path);
    void guardarArchivoQt(string path,string cont);
};

#endif // ARCHIVO_H

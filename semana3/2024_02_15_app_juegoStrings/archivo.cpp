#include "archivo.h"

archivo::archivo()
{

}

void archivo::leerArchivo(char *archivo)
{
    FILE *pArchivo;
    if( (pArchivo=fopen(archivo,"r+t")) == NULL){
        cout<<"ERROR ARCHIVO NO ENCONTRADO";
        exit(1);
    }
    char cadena[100];
    int i=0;
    while(fgets(cadena,sizeof (cadena),pArchivo)){
        printf("%d = %s",i++,cadena);
    }
    fclose(pArchivo);
}

string archivo::leerArchivoLinea(char *archivo)
{
    FILE *pArchivo;
    string res;
    if( (pArchivo=fopen(archivo,"r+t")) == NULL){
        cout<<"ERROR ARCHIVO NO ENCONTRADO";
        exit(1);
    }
    char cadena[20];
    fgets(cadena,sizeof (cadena),pArchivo);
    res=cadena;
    fclose(pArchivo);
    return res;
}

string archivo::leerArchivoLineaRand(char *archivo, int rand)
{
    FILE *pArchivo;
    string res;
    if( (pArchivo=fopen(archivo,"r+t")) == NULL){
        cout<<"ERROR ARCHIVO NO ENCONTRADO";
        exit(1);
    }
    char cadena[100];
    for (int i = 1; i <= rand; ++i) {
        //lee una línea del archivo
        if (fgets(cadena, sizeof(cadena), pArchivo) == NULL) {
            fclose(pArchivo);
            return "";
        }
    }
//    fgets(cadena,rand,pArchivo);
    res=cadena;
    fclose(pArchivo);
    return res;
}

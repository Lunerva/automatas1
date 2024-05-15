#include "tabladesimbolos.h"

symValue TablaDeSimbolos::Hash(char *cadena)
{
    int indice=0;
    int i=0;
    while(cadena[i]){// != '\0'){
        indice += cadena[i++];
    }

    return indice % size;
}

TablaDeSimbolos::TablaDeSimbolos(int tam)
{
    if(tam < 0){
        size = 0;
        tabla = nullptr;
    }
    else if((tabla = new Simbolo*[size=tam])!=nullptr){
        for(int i=0;i<size;i++){
            tabla[i] = NULL;// nullptr;
        }
    }else{
        size = 0;
    }
    /*
    else if(tam>0){
        size = tam;
        tabla = new Simbolo*[size];
        for(int i=0;i<size;i++){
            tabla[i] = nullptr;
        }
    }*/

}

Simbolo *TablaDeSimbolos::addSym(char *variable, symValue valor)
{
    /*
    Simbolo *nodo = new Simbolo();
    nodo->nombre = variable;
    nodo->valor = valor;
    int indice = Hash(variable);
    tabla[indice] = nodo;
    nodo->sig = nullptr;
    */
    Simbolo *simbolo;
    int indice =Hash(variable);
    if((simbolo= new Simbolo())!=nullptr &&
            (simbolo->nombre = new char[strlen(variable)+1]) != nullptr)
    {
        strcpy(simbolo->nombre,variable);
        //strlcpy(simbolo->nombre,variable,strlen(simbolo->nombre));
        //strncpy(simbolo->nombre,variable,strlen(simbolo->nombre));
        simbolo->valor = valor;
        simbolo->sig = tabla[indice];
        tabla[indice] = simbolo;
        return simbolo;
    }
    else{
        delete simbolo;
        simbolo = NULL;
    }
    return simbolo;
}


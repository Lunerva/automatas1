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
    //añadir simbolo
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
        //return simbolo;
    }
    else{
        delete simbolo;
        simbolo = NULL;
    }
    return simbolo;
}

void TablaDeSimbolos::mostrarTabla()
{
    //muestra el arreglo de punteros hacia nodos
    //que se comportan como listas enlazadas
    for(int i=0;i<size;i++){
        cout<<i<<".- ";
        Simbolo *act = tabla[i];
        while(act != nullptr){
           cout<<"|"<<act<<" , "<<act->nombre<<" , "<<act->valor<<" , "<<act->sig<<"| -> ";
           act = act->sig;
        }
        cout<<endl;
    }
}

string TablaDeSimbolos::mostrarTabla(string contenedor)
{
    string res;
    for(int i=0;i<size;i++){
        res.append((to_string(i)).append(".- "));
        //cout<<i<<".- ";
        Simbolo *act = tabla[i];
        while(act != nullptr){
           ostringstream oss;
           oss<<"|"<<act<<" , "<<act->nombre<<" , "<<act->valor<<" , "<<act->sig<<"| -> ";
           res.append(oss.str());
           act = act->sig;
        }
        res.append("\n");
    }
    return contenedor.append(res);
}

void TablaDeSimbolos::mostrar2()
{
    for(int i=0;i<size;i++){
        for(Simbolo *sym = tabla[i]; sym ;sym=sym->sig){
            cout<<sym<<setw(20)<<sym->nombre
               <<setw(10)<<sym->valor<<setw(15)
              <<"sig: "<<sym->sig<<dec<<endl;
        }
    }
}

//tarea
bool TablaDeSimbolos::buscar(char *nombre)
{
    int indice=Hash(nombre);
    Simbolo *act = tabla[indice];

    while(act!=nullptr){
        if(strcmp(act->nombre, nombre)==0){
            return true;
        }
        act= act->sig;
    }

    return false;
}


//Evaluacion
//1) implemente un metodo para encontrar un valor en la tabla de simbolos
//
bool TablaDeSimbolos::findSym(char *nombre)
{
    int indice=Hash(nombre);
    Simbolo *act = tabla[indice];

    while(act!=nullptr){
        if(strcmp(act->nombre, nombre)==0){
            return true;
        }
        act= act->sig;
    }

    return false;
}

bool TablaDeSimbolos::borrarSym(char *cadena)
{
    int slot = Hash(cadena);
          Simbolo *sym = tabla[slot];
          string aux = sym->nombre;
          if(sym && strcmp(sym->nombre,cadena)== 0 )
          {
              tabla[slot] = sym->sig;
              delete sym;
              return true;
          }
          for(sym = tabla[slot]; sym->sig != nullptr ;  sym = sym->sig)
          {
              if(strcmp(sym->sig->nombre, cadena) == 0)
              {
                  Simbolo *temp = sym->sig;
                  sym->sig = sym->sig->sig;
                  delete temp;
                  return true;
              }
          }
          return false;
}

bool TablaDeSimbolos::borrarSym2(char *cadena)
{
    int slot = Hash(cadena);
    Simbolo *sym = tabla[slot];
    for(sym = tabla[slot]; sym->sig != nullptr ;  sym = sym->sig)
    {
        if(sym && strcmp(sym->sig->nombre, cadena) == 0)
        {
            Simbolo *temp = sym->sig;
            sym->sig = sym->sig->sig;
            delete temp;
            return true;
        }
    }
    return false;
}



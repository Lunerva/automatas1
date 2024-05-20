#include <iostream>

#include <string.h>

#include "tabladesimbolos.h"

using namespace std;

int main()
{
    cout<<"tabla de simbolos"<<endl;

    /*
    int val1 = 0;
    int val11 = -1;
    int val2 = 5;
    int val3 = 10;
    int val111 = 0;
    */

    TablaDeSimbolos tabla(5);

    //tabla.addSym("val",2);// 323 % 5 -> su indice sera 3
    //tabla.addSym("val1",1);//372 % 5 -> indice 2
    tabla.addSym("val11",-1);//421 % 5 -> indice 1
    tabla.addSym("val111",0);//470 % 5 -> indice 0
    tabla.addSym("val2",-1);//373 % 5 -> indice 3
    tabla.addSym("a",0);
    tabla.addSym("a1",-1);
    tabla.addSym("val22",0);// 423 % 5 -> indice 3
    tabla.addSym("i",-1);//421 % 5 -> indice 1
    tabla.addSym("ii",0);//470 % 5 -> indice 0
    tabla.addSym("iii",-1);//373 % 5 -> indice 3
    tabla.addSym("j",0);
    tabla.addSym("k",-1);
    tabla.addSym("_a_",0);// 423 % 5 -> indice 3

    //metodo mostrar tabla y eliminar nodo

    tabla.mostrarTabla();

//    tabla.mostrar2();

    cout<<"----------"<<endl;
    char *variable="ii";
    cout<<"Buscar: "<<variable<<endl;
    bool existe = tabla.findSym(variable);
    if(existe){
        cout<<"variable encontrada: "<<variable<<endl;
    }else{
        cout<<"variable no encontrada"<<endl;
    }
    cout<<"----------"<<endl;
//    cout<<"buscar valor: "<<tabla.buscar("ii")<<endl;

    tabla.borrarSym2("ii");
    tabla.mostrarTabla();
    cout<<"----------"<<endl;
    cout<<"Buscar: "<<variable<<endl;
    existe = tabla.findSym(variable);
    if(existe){
        cout<<"variable encontrada: "<<variable<<endl;
    }else{
        cout<<"variable no encontrada"<<endl;
    }
    cout<<"----------"<<endl;


    return 0;
}

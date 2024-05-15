#include <iostream>

#include <string.h>

#include "tabladesimbolos.h"

using namespace std;

int main()
{
    cout<<"tabla de simbolos";

    /*
    int val1 = 0;
    int val11 = -1;
    int val2 = 5;
    int val3 = 10;
    int val111 = 0;
    */

    TablaDeSimbolos tabla(5);

    tabla.addSym("val11",-1);
    tabla.addSym("val111",0);

    //metodo mostrar tabla y eliminar nodo

    return 0;
}

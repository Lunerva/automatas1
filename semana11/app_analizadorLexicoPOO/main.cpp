#include <iostream>
#include <string>
#include <fstream>
#include "analizadorlexico.h"
#include<string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    char cadenaC[255];
    string cadenaS = "i=0";
    char opc='s';
    analizadorLexico lexico;


    do{
        cout<<"cadena a analizar: "<<endl;
        getline(cin,cadenaS,'\n');

        cadenaS += " ";
        cout<<"cadena -> "<<cadenaS<<endl;
        strcpy(cadenaC,cadenaS.c_str());

        lexico.scanner(cadenaC);

        cout<<"Analizar otra cadena s|n: ";
        cin>>opc;
        cin.get();
        //cin.ignore();
        //fflush(stdin);
    }while(strchr("Ss",opc));

    return 0;
}

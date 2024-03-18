#include <iostream>

#include "notacionpolaca.h"

using namespace std;


//validar que almenos los parentesis esten apareados
//O NO ESTE EL PAR CORRESPONDIENTE
int main()
{

    string eInfija="((1-8)+3*5";
    cout<<"cadena: "<<eInfija<<"\nNumero de parentesis es correcto? "<<endl;
    cout<<NotacionPolaca().numParentesis(eInfija)<<endl;

    cout<<"-------------------"<<endl;
    string ecuacion="1+3-4";
    cout<<"cadena: "<<ecuacion<<"\nvalidar entrada:"<<endl;
    cout<<NotacionPolaca().validarEntrada(ecuacion)<<endl;


    cout<<"-------------------"<<endl;
    ecuacion="1?4";
    cout<<"cadena: "<<ecuacion<<"\nvalidar entrada:"<<endl;
    cout<<NotacionPolaca().validarEntrada(ecuacion)<<endl;


    cout<<"\n--------------------"<<endl;
    cout<<"CHAR ARRAY"<<endl;
    string eInfija2="a+b-c";
    cout<<"Expresion infija: "<<eInfija2<<endl;

    NotacionPolaca *expresion = new NotacionPolaca();

    char *resultado = new char[eInfija2.size()];//puede ser size() o length()

    resultado = expresion->convertirAposfija(eInfija2);

    cout<<"\n EXPRESION POSFIJA\n"<<resultado<<endl;

    cout<<"\n--------------------"<<endl;
    cout<<"STRING"<<endl;
    string eInfija3="(a)+c*b";
    cout<<"Expresion infija: "<<eInfija3<<endl;

    string res;
    res = expresion->convertirAposFija(eInfija3);
    cout<<"\n EXPRESION POSFIJA\n"<<res<<endl;

    cout<<"\n--------------------"<<endl;
    cout<<"QSRING"<<endl;
    QString eInfija4="(a*f)/c-b*j";
    cout<<"Expresion infija: "<<eInfija4.toStdString()<<endl;

    res = expresion->convertirAposFija(eInfija4).toStdString();
    cout<<"\n EXPRESION POSFIJA\n"<<res<<endl;




    //delete expresion;
    //delete []resultado;











    return 0;
}

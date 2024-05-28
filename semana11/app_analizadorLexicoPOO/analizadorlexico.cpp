#include "analizadorlexico.h"

//uso de macros
#define leerCar(i) cadena[i++]
#define retrocedeCar i-- //representa el * en el diagrama de transiciones

analizadorLexico::analizadorLexico()
{
    inicializaEstados();
}

void analizadorLexico::scanner(char cadena[])
{
    char caracter;
    inicializaEstados();
    i = inicioToken = 0;
    while( (i < (int)strlen(cadena)) || (estadoDeAceptacion()) )
    {
        switch(estadoActual){
        case 0:
            caracter = leerCar(i);
            if(esDelimitador(caracter)){
                estadoActual = 1;
            }else{
                fallo();//cambio de estado
                //break;
            }
            break;
        case 1:
            caracter=leerCar(i);
            if(esDelimitador(caracter)){
                estadoActual=1;
                //caracter=leerCar(i);
            }else{
                estadoActual=2;
            }
            break;
        case 2:
            retrocedeCar;//seria el * del diag. de transiciones
            cout<<"\nDelimitador"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 3:caracter=leerCar(i);{
            if(esLetra(caracter)){
                estadoActual=4;
            }else{
                fallo();
                break;
            }
        }
        case 4:
            caracter=leerCar(i);{
            if(esLetra(caracter)||esDigito(caracter)){
                    estadoActual=4;
                }else{
                    estadoActual=5;
                }
            }
            break;
        case 5:{
            retrocedeCar;
            cout<<"\nIdentificador"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
            }
        case 6:caracter=leerCar(i);{
            if(esDigito(caracter)){
                estadoActual=7;
            }else{
                fallo();
                //break;
            }
            break;
        }
        case 7:caracter=leerCar(i);{
            if(esDigito(caracter)){
                estadoActual=7;
            }else if(caracter=='.'){
                estadoActual=9;
            }else{
                estadoActual=8;
            }
        }
            break;
        case 8:{
            retrocedeCar;
            cout<<"\nNumero entero"<<endl;
            inicializaEstados();
            inicioToken=i;
        }
            break;
        case 9:caracter=leerCar(i);{
            if(esDigito(caracter)){
                estadoActual=9;
            }else{
                estadoActual=10;
            }
        }
            break;
        case 10:{
            retrocedeCar;
            cout<<"\nNumero real"<<endl;
            inicializaEstados();
            inicioToken=i;
        }
            break;
        case 11:caracter=leerCar(i);//continua los operadores relaciones, logicos y aritmeticos
        {
            if(caracter=='='){
                estadoActual=12;
            }else{
                fallo();
            }
        }
            break;
        case 12:caracter=leerCar(i);
        {
            if(caracter=='='){
                estadoActual=14;
            }else{
                estadoActual=13;
            }
        }
            break;
        case 13:
            retrocedeCar;
            cout<<"\nAsignar"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 14:
            estadoActual=15;
            break;
        case 15:
            retrocedeCar;
            cout<<"\nIgual"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 16:caracter=leerCar(i);
        {
            if(caracter=='>'){
                estadoActual=17;
            }else{
                fallo();
            }
        }
            break;
        case 17:caracter=leerCar(i);
        {
            if(caracter=='='){
                estadoActual=18;
            }else{
                estadoActual=20;
            }
        }
            break;
        case 18:
            estadoActual=19;
            break;
        case 19:
            retrocedeCar;
            cout<<"\nMayor o igual que"<<endl;
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 20:
            retrocedeCar;
            cout<<"\nMayor que"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 21:caracter=leerCar(i);
        {
            if(caracter=='<'){
                estadoActual=22;
            }else{
                fallo();
            }
        }
            break;
        case 22:caracter=leerCar(i);
        {
            if(caracter=='='){
                estadoActual=24;
            }else{
                estadoActual=23;
            }
        }
            break;
        case 23:
            retrocedeCar;
            cout<<"\nMenor que"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 24:
            estadoActual=25;
            break;
        case 25:
            retrocedeCar;
            cout<<"\nMenor o igual que"<<endl;
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 26:caracter=leerCar(i);
        {
            if(caracter=='!'){
                estadoActual=27;
            }else{
                fallo();
            }
        }
            break;
        case 27:caracter=leerCar(i);
        {
            if(caracter=='='){
                estadoActual=29;
            }else{
                estadoActual=28;
            }
        }
            break;
        case 28:
            retrocedeCar;
            cout<<"\nOpuesto que"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 29:
            estadoActual=30;
            break;
        case 30:
            retrocedeCar;
            cout<<"\nDiferente que"<<endl;
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 31:caracter=leerCar(i);
        {
            if(caracter=='+'){
                estadoActual=32;
            }else{
                fallo();
            }
        }
            break;
        case 32:caracter=leerCar(i);
        {
            if(caracter=='+'){
                estadoActual=33;
            }else{
                estadoActual=34;
            }
        }
            break;
        case 34:
            retrocedeCar;
            cout<<"\nSuma"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 33:
            estadoActual=35;
            break;
        case 35:
            retrocedeCar;
            cout<<"\nIncrementar en uno"<<endl;
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 36:caracter=leerCar(i);
        {
            if(caracter=='-'){
                estadoActual=37;
            }else{
                fallo();
            }
        }
            break;
        case 37:caracter=leerCar(i);
        {
            if(caracter=='-'){
                estadoActual=39;
            }else{
                estadoActual=38;
            }
        }
            break;
        case 38:
            retrocedeCar;
            cout<<"\nResta"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 39:
            estadoActual=40;
            break;
        case 40:
            retrocedeCar;
            cout<<"\nDecrementar en uno"<<endl;
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 41:
            caracter = leerCar(i);
            if(caracter=='*'){
                estadoActual = 42;
            }else{
                fallo();
            }
            break;
        case 42:
            caracter=leerCar(i);
            estadoActual=43;
            break;
        case 43:
            retrocedeCar;
            cout<<"\nMultiplicacion"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 44:
            caracter = leerCar(i);
            if(caracter=='/'){
                estadoActual = 45;
            }else{
                fallo();
            }
            break;
        case 45:
            caracter=leerCar(i);
            estadoActual=46;
            break;
        case 46:
            retrocedeCar;
            cout<<"\nDivision"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 47:
            caracter = leerCar(i);
            if(caracter=='%'){
                estadoActual = 48;
            }else{
                fallo();
            }
            break;
        case 48:
            caracter=leerCar(i);
            estadoActual=49;
            break;
        case 49:
            retrocedeCar;
            cout<<"\nModulo"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 50:
            caracter = leerCar(i);
            if(caracter=='^'){
                estadoActual = 51;
            }else{
                fallo();
            }
            break;
        case 51:
            caracter=leerCar(i);
            estadoActual=52;
            break;
        case 52:
            retrocedeCar;
            cout<<"\nXOR"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 53:caracter=leerCar(i);
        {
            if(caracter=='&'){
                estadoActual=54;
            }else{
                fallo();
            }
        }
            break;
        case 54:caracter=leerCar(i);
        {
            if(caracter=='&'){
                estadoActual=55;
            }else{
                estadoActual=56;
            }
        }
            break;
        case 56:
            retrocedeCar;
            cout<<"\nand incompleto,agregue otro &"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 55:
            estadoActual=57;
            break;
        case 57:
            retrocedeCar;
            cout<<"\nOperador AND"<<endl;
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 58:caracter=leerCar(i);
        {
            if(caracter=='|'){
                estadoActual=59;
            }else{
                fallo();
            }
        }
            break;
        case 59:caracter=leerCar(i);
        {
            if(caracter=='|'){
                estadoActual=60;
            }else{
                estadoActual=61;
            }
        }
            break;
        case 61:
            retrocedeCar;
            cout<<"\nor incompleto,agregue otro |"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        case 60:
            estadoActual=62;
            break;
        case 62:
            retrocedeCar;
            cout<<"\nOperador OR"<<endl;
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 63:
            caracter = leerCar(i);
            if(caracter==';'){
                estadoActual = 64;
            }else{
                fallo();
            }
            break;
        case 64:
            caracter=leerCar(i);
            estadoActual=65;
            break;
        case 65:
            retrocedeCar;
            cout<<"\nFin de instruccion"<<endl;
            inicializaEstados();
            inicioToken=i;
            break;
        default:
            break;
        }
    }
}

void analizadorLexico::inicializaEstados()
{
    estadoInicial = estadoActual = 0;
}

void analizadorLexico::fallo()
{
    switch(estadoActual){
    case 0:{
        estadoActual=3;
        i=inicioToken;
        }
        break;
    case 3:
        estadoActual=6;
        i=inicioToken;
        break;
    case 6:
        estadoActual=11;
        i=inicioToken;
        break;
    case 11:
        estadoActual=16;
        i=inicioToken;
        break;
    case 16:
        estadoActual=21;
        i=inicioToken;
        break;
    case 21:
        estadoActual=26;
        i=inicioToken;
        break;
    case 26:
        estadoActual=31;
        i=inicioToken;
        break;
    case 31:
        estadoActual=36;
        i=inicioToken;
        break;
    case 36:
        estadoActual=41;
        i=inicioToken;
        break;
    case 41:
        estadoActual=44;
        i=inicioToken;
        break;
    case 44:
        estadoActual=47;
        i=inicioToken;
        break;
    case 47:
        estadoActual=50;
        i=inicioToken;
        break;
    case 50:
        estadoActual=53;
        i=inicioToken;
        break;
    case 53:
        estadoActual=58;
        i=inicioToken;
        break;
    case 58:
        estadoActual=63;
        i=inicioToken;
        break;
    }
}

bool analizadorLexico::estadoDeAceptacion()
{
    switch(estadoActual){
    case 2:
    case 5:
    case 8:
    case 10:
    case 15:
    case 20:
    case 25:
    case 30:
    case 35:
    case 40:
    case 43:
    case 46:
    case 49:
    case 52:
    case 57:
        return true;
    default:
        return false;
    }
}

bool analizadorLexico::esDelimitador(char c)
{
    switch(c){
    case '\n':
    case '\t':
    case ' ':
        return true;
        break;
    default:
        return false;
        break;
    }
}

bool analizadorLexico::esLetra(char c)
{
    if((c>=65 && c<=90)||(c>=97 && c<=122)||(c==95)){
        return true;
    }else{
        return false;
    }
}

bool analizadorLexico::esDigito(char c)
{
    if((c>=48 && c<=57)){
        return true;
    }else{
        return false;
    }
}

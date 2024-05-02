#include <iostream>
#include<string>
#include<string.h>

using namespace std;


// MI SOLUCION
bool analizarCadPar(string valor){
    bool val = false;
    for(int i=0;i<valor.size();i++){
        switch(valor.at(i)){
            case '0':
            case '2':
            case '4':
            case '6':
            case '8':
                //cout << "Valido par" << endl;
                val = true;
                break;
            default:
                //cout << "No valido par" << endl;
                val= false;
                break;
        }
    }
    return val;
}

// SOLUCION 2 USANDO AUTOMATA

bool validarPar(string cadena){
    const char par[6] = "02468";
//    const char non[6] ="13579";
    // Definición de variables
    char carEntrada; // Carácter de entrada actual
    int edoActual = 0; // Estado actual del autómata
    int i = 0; // Índice para recorrer la cadena
    bool band = false; // Bandera para indicar si se encontró un número par

    for(i =0;i<cadena.length();i++){
        switch(edoActual){
        case 0:
            carEntrada=cadena.at(i);
            if(strchr(par, carEntrada)){
                edoActual=1;
                band=true;
            }
            break;
        case 1:
            carEntrada=cadena.at(i);
            if(strchr(par, carEntrada)){
                band=true;
            }else{
                edoActual=0;
                band=false;
            }
            break;
        }
    }

    return band;
}


// SOLUCION EN CLASE
const char par[6] = "02468";
const char non[6] ="13579";

bool analizarNumero(char *cadena) {
    // Definición de variables
    char carEntrada; // Carácter de entrada actual
    int edoActual = 0; // Estado actual del autómata
    int i = 0; // Índice para recorrer la cadena
    bool band = false; // Bandera para indicar si se encontró un número par

    // Ciclo while para recorrer la cadena
    while (i < strlen(cadena)) {
        // Switch para manejar los diferentes estados del autómata
        switch (edoActual) {
            case 0: {
                // Estado 0: Inicial, se determina si el carácter es par o impar
                carEntrada = cadena[i++];
                if (strchr(par, carEntrada)) {
                    edoActual = 1; // Si es par, pasa al estado 1
                } else if (strchr(non, carEntrada)) {
                    edoActual = 2; // Si es impar, pasa al estado 2
                }
            }
            break;
            case 1: {
                // Estado 1: Carácter anterior era par, se verifica el siguiente carácter
                carEntrada = cadena[i++];
                if (strchr(par, carEntrada)) {
                    edoActual = 1; // Si es par, se mantiene en el estado 1
                } else if (strchr(non, carEntrada)) {
                    edoActual = 2; // Si es impar, pasa al estado 2
                } else {
                    edoActual = 3; // Si es otro carácter, pasa al estado 3
                }
            }
            break;
            case 2: {
                // Estado 2: Carácter anterior era impar, se verifica el siguiente carácter
                carEntrada = cadena[i++];
                if (strchr(par, carEntrada)) {
                    edoActual = 1; // Si es par, pasa al estado 1
                } else if (strchr(non, carEntrada)) {
                    edoActual = 2; // Si es impar, se mantiene en el estado 2
                }
            }
            break;
            case 3: {
                // Estado 3: Se ha encontrado un número par
                cout << "Número par" << endl;
                band = true; // Se marca la bandera como verdadera
            }
            break;
        }
    }
    return band; // Devuelve la bandera que indica si se encontró un número par
}


int main()
{

    //IMPLEMENTAR LA APLICACION PARA EL DOMING 28 DE ABRIL 2024
    //USANDO LA PROPUESTA EN CLASE
/*
    bool salir=false;
    do{
        cout<<"seleccione una opcion"<<endl;
        cout<<"a)opcion 1 \n b)opcion 2 \n c)opcion 3 \n d)salir"<<endl;
        char opc;
        cin>>opc;

        switch(opc){
        case 'a':{
            char *cad = new char[10];
            cout<<"\nApp para determinar si la cadena de caracteres es par o impar, "
                  "usando un automata finito determinista.\nIngrese el valor: "<<endl;
            cin>>cad;
            cout<<"el valor: "<<cad
               <<"\nSi es 0 es impar, si es 1 es par: "<<analizarNumero(cad)<<endl;
            }
            break;
        case 'b':{
            string valor;
            cout<<"\nApp para determinar si la cadena de caracteres es par o impar, "
                  "\nIngrese el valor: "<<endl;
            cin>>valor;
            cout<<"el valor: "<<valor
               <<"\nSi es 0 es impar, si es 1 es par: "<<analizarCadPar(valor)<<endl;
            }
            break;
        case 'c':{
            string valor;
            cout<<"\nApp para determinar si la cadena de caracteres es par o impar, "
                      "usando un automata finito determinista.\nIngrese el valor: "<<endl;
            cin>>valor;
            cout<<"el valor: "<<valor
                   <<"\nSi es 0 es impar, si es 1 es par: "<<validarPar(valor)<<endl;
            }
            break;
        case 'd':
            salir=true;
            break;
        default:{
            cout<<"seleccione una opcion valida >:("<<endl;
            }
            break;
        }
    }while(salir!=true);

*/

    char opc2;
    string cadenaEntrada;
    cout<<"AFD PARA DETERMINAR NUMEROS PARES EN UNA CADENA DE ENRADA";

    do{
        cout<<"numero: ";
        getline(cin,cadenaEntrada,'\n');
        cadenaEntrada += ";";
        char *cadenaAux = new char[cadenaEntrada.length()];

        strcpy(cadenaAux,cadenaEntrada.c_str());

        //strncpy();

        if(!analizarNumero(cadenaAux)){
            cout<<"NUMERO NON"<<endl;
        }
        cout<<"ANALIZAR OTRO NUMERO(s/n)";
        cin>>opc2;
        cin.get();
//        opc2 = cin.get();

    }while(strchr("Ss",opc2));



/*
///////////PROPUESTA 1
    char *cad = new char[10];
    cout<<"App para determinar si la cadena de caracteres es par o impar, "
          "usando un automata finito determinista.\nIngrese el valor: "<<endl;
    cin>>cad;
    cout<<"el valor: "<<cad
       <<"\nSi es 0 es impar, si es 1 es par: "<<analizarNumero(cad)<<endl;

///////////PROPUESTA 2
    string valor;
    cout<<"\n\n\nApp para determinar si la cadena de caracteres es par o impar, "
          "\nIngrese el valor: "<<endl;
    cin>>valor;
    cout<<"el valor: "<<valor
       <<"\nSi es 0 es impar, si es 1 es par: "<<analizarCadPar(valor)<<endl;

///////////PROPUESTA 3

    cout<<"\n\n\nApp para determinar si la cadena de caracteres es par o impar, "
              "usando un automata finito determinista.\nIngrese el valor: "<<endl;
    //cin>>valor;
    cout<<"el valor: "<<valor
           <<"\nSi es 0 es impar, si es 1 es par: "<<validarPar(valor)<<endl;
*/

    return 0;
}

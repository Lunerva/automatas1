#include <iostream>
#include<string>
#include<string.h>

using namespace std;

const char par[6] = "02468";
const char non[6] ="13579";

bool analizarNumero(char *cadena){
    char carEntrada;
    int edoActual =0;
    int i=0;
    bool band = false;
    while(i<strlen(cadena)){
        switch(edoActual){
            case 0:{
                carEntrada = cadena[i++];
                if(strchr(par,carEntrada)){
                    edoActual=1;
                }else if(strchr(non,carEntrada)){
                    edoActual=2;}
            }
            break;
            case 1:{
                carEntrada=cadena[i++];
                if(strchr(par,carEntrada)){
                    edoActual=1;
                }else if(strchr(non,carEntrada)){
                    edoActual=2;
                }else{
                    edoActual=3;
                    //reprensenta el asterisco o el retroceso
                }
            }
            break;
            case 2:{
                carEntrada=cadena[i++];
                if(strchr(par,carEntrada)){
                    edoActual=1;
                }else if(strchr(non,carEntrada)){
                    edoActual=2;
                }
            }
            break;
            case 3:
            {
                cout<<"numero par"<<endl;
                band=true;
            }break;
        }
    }
    return band;
}


int main()
{

    //IMPLEMENTAR LA APLICACION PARA EL DOMING 28 DE ABRIL 2024



    string cad="";
    cin>>cad;


    for(int i=0;i<cad.length();i++){
        switch(cad.at(i)){
            case ( "0" | "2" | "4" | "6" | "8" ):
            cout<<"valido par"<<endl;
            break;
            deafult:
            cout<<"no valido no numero"<<endl;
            break;
        }
    }

    return 0;
}

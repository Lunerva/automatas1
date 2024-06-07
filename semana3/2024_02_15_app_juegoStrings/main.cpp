#include <iostream>
#include <string>
#include <archivo.h>
#include <windows.h>
#include <juego.h>

using namespace std;

int main() {
//hace que la consola acepte utf 8
#ifdef _WIN32
    if(!SetConsoleOutputCP(CP_UTF8)){
        cerr<<"Error"<<endl;
        return 1;
    }
#endif

    //programa
    int opcion;
    boolean salir=false;
    char nomArchivo[]="C:/Users/Admin/Documents/6to_semestre/automatas/qt/semana3/2024_02_15_app_juegoStrings/verbos.txt";
    char archivoTraduccion[]="C:/Users/Admin/Documents/6to_semestre/automatas/qt/semana3/2024_02_15_app_juegoStrings/verbosRes.txt";
    while(salir==false){
        cout<<"Juego de palabras"<<endl;
        cout<<"Instrucciones:"<<endl;
        cout<<"escribe la traduccion del verbo en español"<<endl;
        cout<<"Menu"<<endl;
        cout<<"1 -> jugar"<<endl;
        cout<<"2 -> lista palabras"<<endl;
        cout<<"3 -> lista traduccion"<<endl;
        cout<<"4 -> salir"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                juego().iniciarJuego(nomArchivo,archivoTraduccion);
                break;
            case 2:
                archivo().leerArchivo(nomArchivo);
                break;
            case 3:
                archivo().leerArchivo(archivoTraduccion);
                break;
            case 4:
                salir=true;
                break;
            default:
                cout<<"ingrese un caracter valido"<<endl;
                break;

        }
    }


    return 0;
}

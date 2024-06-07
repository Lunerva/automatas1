#include "juego.h"

juego::juego()
{

}
void juego::iniciarJuego(char *archivo1, char *archivo2)
{
    char *nomArchivo="C:/Users/Admin/Documents/6to_semestre/automatas/qt/semana3/2024_02_15_app_juegoStrings/verbos.txt";
    char *archivoTraduccion="C:/Users/Admin/Documents/6to_semestre/automatas/qt/semana3/2024_02_15_app_juegoStrings/verbosRes.txt";

    string origen,destino;
    map <string,string> palabras;
    for(int i=0;i<25;i++){
        origen = archivo().leerArchivoLineaRand(nomArchivo,i);
        destino = archivo().leerArchivoLineaRand(archivoTraduccion,i);
        palabras[origen]=destino;
    }
    string res;

    bool dentro=true;
    while(dentro==true){
    cout<<"El juego ha comenzado"<<endl;

    palabra test=palabraAleatoria(archivo1,archivo2);
    cout<<test.cont<<endl;


    cout<<"ingresa la traduccion"<<endl;
    cin>>res;

    if(palabras[test.cont].compare(res)==true){
        cout<<"ganaste :)"<<endl;
    }else{
        cout<<"perdiste"<<endl;
        cout<<"la respuesta correcta es: "<<palabras[test.cont]<<endl;
    }
    cout<<"otra partida?"<<endl;
    cout<<"1 -> si\n"<<"2 -> no"<<endl;
    int cont;
    cin>>cont;
    if(cont==1){
        //iniciarJuego(archivo1,archivo2);
        dentro=true;
    }else if(cont==2){
        dentro=false;
    }else{
        cout<<"ingrese un valor valido"<<endl;
        dentro =true;
    }
    }
}

palabra juego::palabraAleatoria(char *nomArchivo, char *archivoT)
{
    int aleatorio = rand()%24+1;
    string res, tra;
    res=archivo().leerArchivoLineaRand(nomArchivo,aleatorio);
    tra=archivo().leerArchivoLineaRand(archivoT,aleatorio);
    palabra final(res,aleatorio,tra,aleatorio);

    return final;
}

void juego::crearPalabras(char *nomArchivoO, char *nomArchivoT, palabra arr[])
{
    for(int i=0;i<25;i++){
        string cont = archivo().leerArchivoLineaRand(nomArchivoO,i);
        string trad = archivo().leerArchivoLineaRand(nomArchivoT,i);
        arr[i] = palabra(cont,i,trad,i);
//        cout<<"valor: "<<i<<arr[i].cont<<" "<<arr[i].traduccion<<endl;
    }
}

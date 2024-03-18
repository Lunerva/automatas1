#include "juego.h"

juego::juego()
{

}
void juego::iniciarJuego(char *archivo, char *archivo2)
{
    string res;
    //string palabra;
    class palabra contenedor[25];
    crearPalabras(archivo,archivo2,contenedor);

    cout<<"El juego ha comenzado"<<endl;
    palabra test=palabraAleatoria(archivo,archivo2);
    cout<<test.cont<<endl;


//    cout<<test.traduccion;
    cout<<"ingresa la traduccion"<<endl;
    cin>>res;
    if(test.traduccion.compare(res)){
        cout<<"ganaste :)"<<endl;
    }else{
        cout<<"perdiste"<<endl;
    }
    cout<<"otra partida?"<<endl;
    cout<<"1 -> si\n"<<"2 -> no"<<endl;
    int cont;
    cin>>cont;
    if(cont==1){
        iniciarJuego(archivo,archivo2);
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

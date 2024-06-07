#include "archivo.h"

archivo::archivo()
{

}

void archivo::leerArchivo(char *archivo)
{
    FILE *pArchivo;
    if( (pArchivo=fopen(archivo,"r+t")) == NULL){
        cout<<"ERROR ARCHIVO NO ENCONTRADO";
        exit(1);
    }
    char cadena[100];
    int i=0;
    while(fgets(cadena,sizeof (cadena),pArchivo)){
        printf("%d = %s",i++,cadena);
    }
    fclose(pArchivo);
}

string archivo::leerArchivoLinea(char *archivo)
{
    FILE *pArchivo;
    string res;
    if( (pArchivo=fopen(archivo,"r+t")) == NULL){
        cout<<"ERROR ARCHIVO NO ENCONTRADO";
        exit(1);
    }
    char cadena[20];
    fgets(cadena,sizeof (cadena),pArchivo);
    res=cadena;
    fclose(pArchivo);
    return res;
}

string archivo::leerArchivoLineaRand(char *archivo, int rand)
{
    FILE *pArchivo;
    string res;
    if( (pArchivo=fopen(archivo,"r+t")) == NULL){
        cout<<"ERROR ARCHIVO NO ENCONTRADO";
        exit(1);
    }
    char cadena[100];
    for (int i = 1; i <= rand; ++i) {
        //lee una línea del archivo
        if (fgets(cadena, sizeof(cadena), pArchivo) == NULL) {
            fclose(pArchivo);
            return "";
        }
    }
//    fgets(cadena,rand,pArchivo);
    res=cadena;
    fclose(pArchivo);
    return res;
}

void archivo::escribirArchivo(string *contenido, int tam)
{
    FILE *fichero;
    //la w indica que abre el archivo para escritura(si no existe lo crea, si existe lo sobreescribe)
    fichero = fopen("C:/Users/Admin/Desktop/archivoTexto.txt", "w");
    if((fichero)==NULL){
        printf("no hay archivo\n");
        exit(1);
    }else{

        fichero = fopen("C:/Users/Admin/Desktop/archivoTexto.txt", "w");
        for(int i=0;i<tam;i++){
            fputs(contenido[i].c_str(),fichero);
            fputs("\n",fichero);
        }
        //char *cadena = fichero->_base;
        //printf("contenido del archivo:\n");
        //printf("%s \n",cadena);


    }
    fclose(fichero);
}

void archivo::escribirArchivo(string *contenido, int tam, string PATH, string nombre)
{
    FILE *fichero;
    fichero = fopen((PATH+"/"+nombre).c_str(), "w");
    if((fichero)==NULL){
        printf("no hay archivo\n");
        exit(1);
    }else{

        fichero = fopen((PATH+"/"+nombre).c_str(), "w");
        for(int i=0;i<tam;i++){
            fputs(contenido[i].c_str(),fichero);
            fputs("\n",fichero);
        }
    }
    fclose(fichero);
}

void archivo::escribirArchivo(string contenido, string PATH, string nombre)
{
    FILE *fichero;
    fichero = fopen((PATH+"/"+nombre).c_str(), "w");
    if((fichero)==NULL){
        printf("no hay archivo\n");
        exit(1);
    }else{

        fichero = fopen((PATH+"/"+nombre).c_str(), "w");
        fputs(contenido.c_str(),fichero);
    }
    fclose(fichero);
}

QString archivo::leerArchivoQt(string path)
{
    QString contenido;
    QFile archivo(path.c_str());
    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&archivo);
        contenido = in.readAll();
        archivo.close();
    }
    return contenido;
}

void archivo::guardarArchivoQt(string path,string cont)
{
    QFile arch(path.c_str());
    if (arch.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&arch);
        out<<cont.c_str();
        arch.close();
    }
}

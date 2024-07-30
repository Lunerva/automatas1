
#include "archivo.h"

bool archivo::getFinarch() const
{
    return finarch;
}

void archivo::setFinarch(bool newFinarch)
{
    finarch = newFinarch;
}

FILE *archivo::getFd() const
{
    return Fd;
}

void archivo::setFd(FILE *newFd)
{
    Fd = newFd;
}

archivo::archivo()
{

}

void archivo:: generararch()
{
    char car;
    char nomArch[100];

    // char *nombre = new char[100];
    //cin.getline(nombre,100,'\n');
    string nombre;
    printf("Nombre del Archivo a GENERAR (sin extension): ");
    //gets(Nombre);  //<--- ERROR CON ESTE METODO
    cin>>nombre;
    cin.get();    //ELIMINAR ENTER

    //PATH APP. QT
    // /Users/martinos/Documents/MATERIAS/AUTOMATAS\ I/MATERIAL/UNIDAD\ IV\ SINTACTICO/ANALIZADOR\ SINTACTICO\ REVISADO/appAnalizadorSintactico_

    //PATH APP. XCODE
    //sprintf(nomArch,"/Users/martinos/Desktop/appASintactico_XCode/%s.dat",nombre.c_str());  //,'\0');
    sprintf(nomArch,"%s.dat",nombre.c_str());
    Fd = fopen(nomArch,"w+b");
    if(Fd == nullptr)
    {
        cout<<"NO SE PUEDE ABRIR EL ARCHIVO : "<<nomArch;
        exit(-1);
    }
    //puts("teclea el archivo (<ESC> para terminar el archivo): ");
    printf("teclea el archivo (<@> para terminar el archivo): \n");
    //cin.get();  //eliminar el enter
    //printf("Tecela <ESC> para terminar el archivo \n");
    //LA INFO ESTA EN EL BUFFER
    do
    {          //CHECAR
        // car = getchar();    //getche();
        car = cin.get();
        //cin>>car;
        if( car == '\n')  //13)
        {
            car = '\n';
            printf("\n");
        }
        //if(car == 0)  //NULL
        //  car = cin.get();    //getch();
        if(car != 64 && car != 8)
            fwrite(&car,sizeof(car),1,Fd);

    }while(car != 64);

    fclose(Fd);

}

void archivo:: vabrirarch()
{
    char nomArch[100];
    //char nombre[100];
    char *nombre = new char[100];

    printf("\n\n Nombre del Archivo a ABRIR(sin extension): ");
    //gets(nombre);
    //cin>>nombre;
    cin.get();  //ELIMINAR EL ENTER
    cin.getline(nombre,100,'\n');

    //sprintf(nomArch,"/Users/martinos/Desktop/appASintactico_XCode/%s.dat",nombre);  //,'\0');
    sprintf(nomArch,"%s.dat",nombre);


    Fd = fopen(nomArch,"r+b");

    if(Fd==NULL)
    {
        printf("NO SE PUEDE ABRIR EL ARCHIVO");
        exit(-1);    //cin.get();

    }
    else
    {
        printf("EL ARCHIVO SE ENCUENTRA ABIERTO \n");

    }

}

int archivo:: bytesarch()
{
    int aux;
    fseek(Fd,0L,SEEK_END);
    aux = (int) ftell(Fd);
    fseek(Fd,0L,SEEK_SET);
    return aux;
}


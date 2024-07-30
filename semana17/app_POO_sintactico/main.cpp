//
//  main.cpp
//
//  Created by Martin Valdes
//  Upgraded by Luis Barranco
//

#include "archivo.h"
#include "lexsin.h"
#include <iostream>

using namespace std;

//////////////////MAIN//////////////////////////////////
int main(void)
{
    archivo fl;
    char resp;
    lexsin ls;
    do
    {
        puts("Desea Generar el Archivo (s/n) : ");

        //cout<<"Desea Generar el Archivo (s/n) : ";
        //resp = getchar();
        //cin>>resp;

        resp = cin.get();
        //cin.get();  //USAR CUANDO SE REQUIERA ELIMINAR EL ENTER


        // if(resp==0)  //NULL
        //   cin.get();// getch();

        if(strchr("Ss",resp))
            fl.generararch();

        fl.vabrirarch();

        ls.setNumBytesArch(fl.bytesarch());

        if(ls.getNumBytesArch()==0)
        {
            printf("El archivo NO Tiene Datos. Pulse una tecla");
            if(cin.get() == 0) //  getch()==0)
            { cin.get();//getch();
                exit(-1);
            }
        }
        //fclose(Fd);

        else
            ls.vanalisislexico();


        fclose(fl.getFd());


        printf("Salida del Analizador Lexico (asTokens)");
        ls.vmuestra();


        printf("Pulse una tecla para continuar");
        if(cin.get() == 0) //getch()==0)
            cin.get();     //getch();


        ls.vanalisis_sintactico();
        cin.get();

        printf("Presiona (sS) para continuar ? : " );
        cin>>resp;
        cin.get();

    }while (strchr("Ss",resp));

    return 0;
}



#include "pila.h"

int pila::getCima() const
{
    return cima;
}

void pila::setCima(int newCima)
{
    cima = newCima;
}

pila::pila()
{

}


///////////////////////////////PILA//////////////////////////////////////////
void pila:: insertapila(string elem)//(char *elem) //(char elem[])
{
    if(cima == -1){
        cima = 0;
        strcpy(pilac[cima],elem.c_str());
    }
    else{
        if(cima == MAX - 1)
            puts("Pila LLena");
        else{
            cima++;
            strcpy(pilac[cima],elem.c_str());
        }
    }
}
void pila::eliminapila()//elimina el valor de la cima
{
    if(cima == -1)
        puts("Pila Vacia");
    else{
        strcpy(pilac[cima],"");
        cima--;
    }
}

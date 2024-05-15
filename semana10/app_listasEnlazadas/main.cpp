#include <iostream>

using namespace std;

class nodo{
    int dato;
    nodo *sig;
public:
    nodo(int d);
    void inserta(nodo *nodo);
    void muestra();
};
nodo::nodo(int d){
    dato = d;
    sig = NULL;
}
void nodo::inserta(nodo *nodo){
    if(sig == NULL){
        sig =nodo;
        nodo->sig=NULL;
    }else{
        nodo->sig = sig;
        sig = nodo;
    }
}
void nodo::muestra(){
    nodo *pl;
    pl = this;
    while(pl!=0){
        cout<<pl->dato<<"";
        pl = pl->sig;
    }
    cout<<'\n';
}



int main(int argc, char **argv)
{
    nodo *p= new nodo(5);
    nodo *n = p;
    for(int i=0;i<5;i++){
        nodo *o = new nodo(i);
        n->inserta(o);
        n = o;
    }
    p->muestra();
    n->muestra();


    return 0;
}

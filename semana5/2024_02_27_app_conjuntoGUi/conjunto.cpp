#include "conjunto.h"


conjunto::conjunto(int n)
{
//    nelem=n;
    tam =n;
    elementos = new int[tam];

    for(int i=0;i<tam;i++){
        elementos[i]= -1;
    }
}

conjunto::conjunto(conjunto *t)
{
    nelem=t->nelem;
    for(int i=0;i<nelem;i++)
        elementos[i] = t->elementos[i];
}

codigo conjunto::asignar(int valor)
{
    if(pertenece(valor)){
        return existe;
    }
    if(nelem<MAX){
        elementos[nelem++]=valor;
        //nelem++;
        return ok;
    }
    return overflow;
}

conjunto conjunto::operator+=(int valor)
{
    return asignar(valor);
}

void conjunto::copiar(conjunto *set)
{
    for(int i=0;i<nelem;i++){
        set->elementos[i]=this->elementos[i];
    }
    set->nelem=nelem;

}

void conjunto::agregar(int valor)
{
    if(!pertenece(valor)){
        int pos = this->posVacia();
        this->elementos[pos]=valor;
    }
}

bool conjunto::pertenece(const int valor)
{
    for(int i=0;i<nelem;++i){
        if(elementos[i]==valor){
            return true;
        }
    }
    return false;
}

int conjunto::perteneceValor(int valor)
{
    for(int i=0;i<nelem;i++){
        if(elementos[i]==valor){
            return i;
        }else {
            return -1;
        }
    }
}

void conjunto::borrarElemento(int valor)
{
    for ( int i = 0; i < nelem; i++ ) {
        if ( elementos[i] == valor ) {
            for ( ; i < nelem; i++ ){
                elementos[i] = elementos[i+1];
            }
            ~nelem;
        }
    }
}

void conjunto::operator-=(int valor)
{
    borrarElemento(valor);
}

int conjunto::posVacia()
{
    for(int i=0;i<this->nelem;++i){
        if(elementos[i]==0){
            return i;
        }
    }
    return -1;
}

bool conjunto::esIgual(conjunto *conj)
{
    int cont=0;

    for(int i=0;i<conj->nelem;i++){
        if(pertenece(conj->elementos[i])){
            cont++;
        }
    }

    if(cont>=nelem){
        return true;
    }
    return false;
}

bool conjunto::esIgual(conjunto *A, conjunto *B)
{
    if(A->nelem != B->nelem){
        return false;
    }
    for(int i=0;i<A->nelem;i++){
        if(! B->pertenece(A->elementos[i]) ){
            return false;
        }
    }
    return true;
}

bool conjunto::operator==(conjunto *B)
{
    return esIgual(this,B);
}

void conjunto::mostrar()
{
    cout<<"{";
    for(int i=0;i<nelem;i++){
        cout<<elementos[i];
    }
}
/*
void conjunto::mostrar(string set)
{
    cout<<endl<<set<<" = {";
    int i;
    for(i=0;i<this->nelem-1;i++){
        cout<<this->elementos[i]<<" , ";
    }
    if(nelem > 0){
        cout<<elementos[nelem-1];
    }
    cout<<"}";

}*/

string conjunto::mostrar(string set)
{
    QString res;
    res.append(QString::fromStdString(set));
    res.append(" = {");
    int i;

    for(i=0;i<this->nelem-1;i++){
        res+=(QString::number(this->elementos[i]));
        res+=+" , ";
    }
//    if(nelem > 0){
//        res+=elementos[nelem-1];
//    }
    res+="}";
    return res.toStdString();
}

conjunto conjunto::unionC(conjunto *otro)
{
    int nnelem=this->nelem+otro->nelem;
    conjunto res = new conjunto(nnelem);

    for(int i=0;i<this->nelem;i++){
        res.agregar(this->elementos[i]);
    }
    for(int i=0;i<otro->nelem;i++){
        res.agregar(otro->elementos[i]);
    }
    return res;
}

codigo conjunto::unionn(conjunto *set2, conjunto *set3)
{
    set2->copiar(set3);
    for(int i=0;i<this->nelem;++i){
        if(set3->asignar(this->elementos[i])){
            return overflow;
        }
    }
    return ok;
}

conjunto conjunto::interseccionC(conjunto *otro)
{
    int nnelem=0;
    for(int i=0;i<otro->nelem;i++){
        if(this->pertenece(otro->elementos[i])){
            nnelem++;
        }
    }
    conjunto res = new conjunto(nnelem);
    for(int i=0;i<otro->nelem;i++){
        if(this->pertenece(otro->elementos[i])){
            res.agregar(otro->elementos[i]);
        }
    }
    return res;
}

void conjunto::interseccionn(const conjunto *set2, conjunto *set3)
{
    set3->nelem=0;
    for(int i=0;i<this->nelem;i++){
        for(int j=0;j<set2->nelem;++j){
            if(elementos[i]==set2->elementos[j]){
                set3->elementos[set3->nelem++]=this->elementos[i];
                break;
            }
        }
    }

}


ostream& operator << (ostream & os, const conjunto &conj)
{
    /*
    string cad = "";
    for (int i = 0; i < conj.nelem; i++) {
        cad += to_string(conj.elementos[i]);
        if (i < conj.nelem - 1) {
            cad += ", ";
        }
    }
    os << "conjunto: { " << cad << " }" << endl;
    return os;*/
    os <<endl<<"conjunto --->"<<" = { ";
    int i=0;
    for(i=0;i<conj.nelem-1;i++){
        os<<conj.elementos[i]<<" , ";
    }
    if(conj.nelem>0){
        os<<conj.elementos[i];
    }
    os<<" } ";
    return os;
}


























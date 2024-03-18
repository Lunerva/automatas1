#ifndef CONJUNTO_H
#define CONJUNTO_H

#include<iostream>
#include <QString>

using namespace std;

//#define MAX 10

//const int MAX=10;

//enumero o doy nombre a los enteros
enum{MAX = 10};//por default inicia en cero

enum codigo{overflow=0, ok, existe};
enum frutas{fresa=100,naranja,platano,manzana,guanabana};

class conjunto
{
public:
    //    int elementos[10];
    //    int elementos[MAX];
        int *elementos;
        int nelem;
        int tam;
//    conjunto();
    conjunto(int n=5);//constructor con argumentos por defecto

    //implemente elmetodo copiar un conjunto en otro
    conjunto(conjunto *t);//copiar

//    ~conjunto(){cout<<"\t \a \nENTRA EL DESTRUCTOR\t"<<endl;}
    ~conjunto(){cout<<"\t\n\t"<<endl;}
    void vacio(){nelem=0;}
    //inline void vacio(){nelem=0;}


    //UTILIZAR LA SOBRECARGA DE OPERADORES DONDE APLIQUE
    codigo asignar(int valor);

    conjunto operator += (int );

    void copiar(conjunto *);

    void agregar(int valor);

    bool pertenece(const int);
    int perteneceValor(int valor);
    void borrarElemento(int);

    void operator-=(int );

    int posVacia();

    bool esIgual(conjunto *);
    bool esIgual(conjunto *A, conjunto *B);
    bool operator==(conjunto *);

    void mostrar();
    ///void mostrar(string);
    string mostrar(string);

    friend ostream& operator<<(ostream&, const conjunto &);

    class conjunto unionC(conjunto *otro);
    codigo unionn(conjunto *, conjunto *);
    class conjunto interseccionC(conjunto *otro);
    void interseccionn(const conjunto *, conjunto *);

    inline int Tam(){return tam;}


};

#endif // CONJUNTO_H













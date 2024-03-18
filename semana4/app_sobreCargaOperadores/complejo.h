#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>

using namespace std;

class complejo
{
public:
    complejo(double =1.0,double=1.0);
    //sumar
    complejo operator+(complejo &)const;
    //implementar resta y multiplicacion
    complejo operator-(complejo &)const;
    complejo operator*(complejo &)const;
    friend ostream& operator<<(ostream& os, const complejo &);
    void mostrar();

private:
    double real;
    double img;
};


#endif // COMPLEJO_H

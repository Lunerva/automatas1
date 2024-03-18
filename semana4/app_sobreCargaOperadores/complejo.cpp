#include "complejo.h"

complejo::complejo(double r, double i)
{
    real = r;
    img = i;
}

//nc es numero complejo
complejo complejo::operator+(complejo &nc) const
{
    double cr,ci;
    cr = this->real + nc.real;
    ci = this->img + nc.img;
    return complejo(cr,ci);
}

complejo complejo::operator-(complejo &nc) const
{
    double cr,ci;
    cr = this->real - nc.real;
    ci = this->img - nc.img;
    return complejo(cr,ci);
}


void complejo::mostrar()
{
    cout<<" { "<<real<<" , "<<img<<"i } "<<endl;
}

ostream& operator<<(ostream& os, const complejo &nc){

    os <<" { "<<nc.real<<" , "<<nc.img<<"i } "<<endl;
    return os;
}

//#include <iostream>

//using namespace std;

#include "complejo.h"
#include <complex>//ESCRIBIR UNA APLICACION QUE USE LA CLASE COMPLEX

using namespace std;


int main()
{
    cout << "NUMEROS COMPLEJOS" << endl;


    complejo c1 = {10,32};
    complejo c2 = {21,35};
    complejo res;
//    c1.mostrar();
    cout<<c1<<endl;
//    c2.mostrar();
    cout<<c2<<endl;
    res = c1+c2;
//    res.mostrar();
    cout<<res<<endl;
    return 0;
}

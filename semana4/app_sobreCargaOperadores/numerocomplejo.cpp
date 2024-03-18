#include <iostream>

using namespace std;

class numeroComplejo {

    double real;
    double imaginario;

public:
    numeroComplejo(double real, double imaginario) {
        this->real=real;
        this->imaginario=imaginario;
    }

    numeroComplejo operator+(numeroComplejo otro){
        return numeroComplejo(real + otro.real, imaginario + otro.imaginario);
    }

    numeroComplejo operator-(numeroComplejo otro){
        return numeroComplejo(real - otro.real, imaginario - otro.imaginario);
    }

};

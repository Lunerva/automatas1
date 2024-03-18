#ifndef CONJ_H
#define CONJ_H


class conj
{
public:
    //atributos
    int *arr;
    int length;
    //metodos
    conj();
    conj(int *arr, int length);
    conj unionConj(conj arr1, conj arr2);
    void imprimirConjunto(conj arr);
};

#endif // CONJ_H

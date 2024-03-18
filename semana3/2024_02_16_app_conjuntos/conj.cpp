#include "conj.h"
#include <iostream>

using namespace std;

conj::conj()
{
}

conj::conj(int *arr, int length)
{
    this->arr=arr;
    this->length=length;
}

conj conj::unionConj(conj arr1, conj arr2){
    int length = arr1.length+arr2.length;
    int arrAux[length];
    for(int i=0;i<arr1.length;i++){
        arrAux[i]=arr1.arr[i];}
    for(int i=0;i<arr2.length;i++){
        arrAux[i+arr2.length]=arr2.arr[i];}
    conj conjuntoRes(arrAux,length);
    return conjuntoRes;}


void conj::imprimirConjunto(conj arr){
    for(int i=0;i<arr.length;i++)
        cout<<"pos: "<<i<<", valor: "<<arr.arr[i]<<endl;}

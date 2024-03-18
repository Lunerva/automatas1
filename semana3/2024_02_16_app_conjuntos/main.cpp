#include <iostream>
#include<conj.h>

using namespace std;

int main()
{
    //creamos conjunto 1
    int arr1[4]={1,2,3,4};
    conj conjunto1(arr1,4);

    //creamos conjunto 2
    int arr2[4]={5,6,7,8};
    conj conjunto2(arr2, 4);

    //creamos conjunto 3
    conj *conjunto3;

    //ejemplo de dos conjuntos
    cout<<"conjunto 1"<<endl;
    conj().imprimirConjunto(conjunto1);
    cout<<"conjunto 2"<<endl;
    conj().imprimirConjunto(conjunto2);

    //unimos conjunto 1 y conjunto 2

    conjunto3=conj().unionConj(conjunto1,conjunto2);

    //mostramos conjunto 3
    cout<<"conjunto 3"<<endl;
//    conj().imprimirConjunto(conjunto3);

    cout<<"";
    return 0;
}

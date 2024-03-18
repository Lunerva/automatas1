#include <iostream>
#include "conjunto.h"


using namespace std;

int genRand(){
    return rand()%89+10;
}

int main()
{
    /*
    cout << "aplicacion conjuntos\t" << endl;
    conjunto *setA,*setB,*setC,*setD;

    setA = new conjunto();
    setA->vacio();

    setA->asignar(17);
//    setA->agregar(17);
    setA->asignar(3);
//    setA->agregar(3);
    setA->asignar(5);
//    setA->agregar(5);
    setA->asignar(9);
//    setA->agregar(9);

    setA->mostrar("setA");
    cout<<endl;
    //setA->borrarElemento(5);
    setA->mostrar("setA");
    cout<<"\a\a\a\a\a\a\a"<<endl;

    setB = new conjunto();
    setB->vacio();

    setB->asignar(9);
//    setA->agregar(9);
    setB->asignar(3);
//    setA->agregar(3);
    setB->asignar(7);
//    setA->agregar(7);
    setB->asignar(0);
//    setA->agregar(0);

    setB->mostrar("setB");

    cout<<"\n"<<setA->esIgual(setB)<<endl;

    cout<<"PRUEBA UNION E INTERSECCION"<<endl;
    cout<<"union"<<endl;
    setA->mostrar("setA");
    setB->mostrar("setB");
    setC = new conjunto(setA->unionC(setB));
    setC->mostrar("setC");
    cout<<"\ninterseccion"<<endl;
    setA->mostrar("setA");
    setB->mostrar("setB");
    setD = new conjunto(setA->interseccionC(setB));
    setD->mostrar("setD");


//////////////////////////////////////
/// //////////////////////////////////
///
///

    cout << "\n\n\naplicacion conjuntos\t" << endl;
    conjunto *conA,*conB,*conC,*conD;

    conA= new conjunto();
    conA->vacio();

    for(int i=0;i<conA->nelem;i++){
//        conA += 5;//genRand();
    }

//    cout<<conA<<endl;
//    conA->mostrar("conA");
//    cout<<endl;

*/
/////////////////////////////////////
///

    cout<<"///////SET 1,2,3/////////"<<endl;

    conjunto *set1, *set2, *set3;
    set1 = new conjunto(3);
    set2 = new conjunto(5);

    set1->vacio();
    set2->vacio();

    //AGREGAR LOS 3 ELEMENTOS AL CONJUNTO 1
    //USANDO LOS 2 METODOS IMPLMENTADOS

    //set1+=5;
    set1->asignar(5);
    *set1+=3;
    *set1+=8;

    cout<<"conjunto set1: "<<*set1<<endl;


    set2->asignar(9);
    *set2+=3;
    *set2+=8;
    cout<<"conjunto set 2: ";
    set2->mostrar("Set 2");
    cout<<endl;

    //CHECAR SI LOS CONJUNTOS SON IGUALES

    //EN SET 3 DEJAR LA UNION Y LA INTERSECCION

    //BORRAMOS UN ELEMENTO DE CADA CONJUNTO

    //VOLVEMOS A CREAR LA UNION Y LA INTERSECCION
    set3 = new conjunto(set1->tam+set2->tam);
    set3->vacio();

    cout<<"\nUNION"<<endl;
    set1->unionn(set2,set3);
    cout<<"\nconjunto set 3: "<<*set3<<endl;

    set3->vacio();
    cout<<"\n\nconjunto set 3 vacio: "<<*set3<<endl;

    cout<<"\nINTERSECCION"<<endl;
    set1->interseccionn(set2,set3);
    cout<<"\nconjunto set 3: "<<*set3<<endl;

    *set2-=3;
    cout<<"\nconjunto set 2 con elemento borrado: "<< *set2;
    *set1-=3;
    cout<<"\nconjunto set 1 con elemento borrado: "<< *set1;

    cout<<"\nSEGUNDA VUELTA"<<endl;

    cout<<"\nUNION"<<endl;
    set1->unionn(set2,set3);
    cout<<"\nconjunto set 3: "<<*set3<<endl;

    set3->vacio();
    cout<<"\n\nconjunto set 3 vacio: "<<*set3<<endl;

    cout<<"\nINTERSECCION"<<endl;
    set1->interseccionn(set2,set3);
    cout<<"\nconjunto set 3: "<<*set3<<endl;

    return 0;
}

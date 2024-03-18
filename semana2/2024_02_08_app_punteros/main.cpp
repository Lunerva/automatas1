#include <iostream>

using namespace std;

const int TAM=500;

void burbuja(int *arreglo,int length){
    int aux;
    for(int i=0;i<length;i++){
        for(int j=0;j<length-1;j++){
            if(arreglo[j] > arreglo[j+1]){
                aux=arreglo[j];
                arreglo[j]=arreglo[j+1];
                arreglo[j+1]=aux;
            }
        }
    }
}

void burbuja(int *arreglo){
    int aux;
    int length=sizeof (arreglo)/sizeof (arreglo[0]);
    for(int i=0;i<length;i++){
        for(int j=0;j<length-1;j++){
            if(arreglo[j] > arreglo[j+1]){
                aux=arreglo[j];
                arreglo[j]=arreglo[j+1];
                arreglo[j+1]=aux;
            }
        }
    }
}

void Sburbuja(int v[TAM]){
    int aux;
    int ncomp,nint;
    ncomp=nint=0;

    for(int i=0;i<TAM;i++){
        for(int j=TAM-1;j>i;j--){
            if(v[j-1] > v[j]){
                aux = v[j-1];
                v[j-1] = v[j];
                v[j] = aux;
                ncomp++;
            }
            nint++;
        }
    }
    cout<<"No. Comparaciones: "<<ncomp<<endl;
    printf("No. Intercambios: %i\n",nint);
}
int numAleatorios(){
    //srand((unsigned)time_t(NULL));
    return (rand()%90+10);
}

void imprimirArreglo(int *arreglo, int length){
    for(int i=0;i<length;i++){
        cout<<arreglo[i]<<endl;
    }
}

int main()
{
    //DISEÑE UNA APLICACION PARA ORDENAR UN ARREGLO UNIDIMENSIONAL
    //DE 10 NUMEROS ENTEROS ALEATORIOS
    //USE EL METODO INDICADO: burbuja
    int *vector;
    cout<<" SIN ORDENAR "<<endl;
    vector = new int[10];
    for(int i=0;i<10;i++){
        vector[i] = numAleatorios();
    }
    imprimirArreglo(vector,10);

    cout << "ORDENAMIENTO BURBUJA" << endl;
    burbuja(vector,10);
    imprimirArreglo(vector,10);

    //////////
    ///
    ///
    ///
    cout<<"EN CLASE"<<endl;
    int vec[TAM];
    for(int i=0;i<TAM;i++){
        //srand((unsigned)time_t(NULL));
        vec[i]=(rand()%9000+1000);
    }
    imprimirArreglo(vec,TAM);
    cout<<"ordenado"<<endl;
    Sburbuja(vec);
    imprimirArreglo(vec,TAM);
    cout<<""<<endl;

    return 0;
}

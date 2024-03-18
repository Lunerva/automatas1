

class conjuntos
{
    int TAM=0;

    void setTAM(int valor)
    {
        TAM=valor;
    }

    void conjUnion(int *conjunto1, int *conjunto2, int *conjunto3)
    {
        int length = tamArr(conjunto1)+tamArr(conjunto2);
        int arrAux[length];

        for(int i=0;i<tamArr(conjunto1);i++){
            arrAux[i]=conjunto1[i];
        }
        for(int i=0;i<tamArr(conjunto2);i++){
            arrAux[i+tamArr(conjunto2)]=conjunto2[i];
        }
        conjunto3=arrAux;
    }

    int tamArr(int *arr){
        return (int)(sizeof (arr)/ sizeof (arr[0]));
    }
};

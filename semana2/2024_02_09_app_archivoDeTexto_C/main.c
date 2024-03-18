#include <stdio.h>
#include <stdlib.h>


void burbuja(int arreglo[],int length){
    int aux;
    int arrAux[length];
    for(int i=0;i<length;i++){
        for(int j=0;j<length-1;j++){
            if(arrAux[j] > arrAux[j+1]){
                aux=arrAux[j];
                arrAux[j]=arrAux[j+1];
                arrAux[j+1]=aux;
            }
        }
    }
    for(int i=0;i<length;i++){
        arreglo[i]=arrAux[i];
    }

}

int numAleatorio(){
   return (rand()%9+1);
}

int llenarVector(int length){
    int arregloAux[length];
    for(int i=0;i<length;i++){
        arregloAux[i]=numAleatorio();
    }
    return arregloAux;
}

char enteroACaracter(int numero){
    return numero + '0';
}

int main(int argc, char *argv[])
{
   FILE *fichero = NULL;
   char *cadena = NULL;
   //int *vector=NULL;
   srand(time(NULL));


   //la w indica que abre el archivo para escritura(si no existe lo crea, si existe lo sobreescribe)
   fichero =fopen("C:/Users/Admin/Desktop/VectorOrdenado.txt", "w");
   if((fichero)==NULL){
       printf("no hay archivo\n");
       exit(1);
   }else{

       fichero = fopen("C:/Users/Admin/Desktop/VectorOrdenado.txt", "w");
       int vector[10];

       for(int i=0;i<10;i++){
           vector[i]=numAleatorio();
       }

       char aux[20];
       for(int i=0;i<10;i++){
           aux[i]=enteroACaracter(vector[i]);
       //    sprintf(aux,"%i",vector);
       }
       fputs("Vector desordenado: ",fichero);
       for(int i=0;i<10;i++){
        fputc(aux[i],fichero);
        fputc(',',fichero);
       }

       burbuja(vector,10);
       for(int i=0;i<10;i++){
           aux[i]=enteroACaracter(vector[i]);
       }
       fputs("\n",fichero);
       fputs("Vector ordenado: ",fichero);
       for(int i=0;i<10;i++){
        fputc(aux[i],fichero);
        fputc(',',fichero);
       }
       cadena = fichero->_base;
       printf("contenido del archivo:\n");
       printf("%s \n",cadena);

   }
   fclose(fichero);
   return 0;
}

#include <iostream>
using namespace std;

//metodo para calcular el factorial
unsigned long int factorial(unsigned char num){
    unsigned long int resultado = 1;
    
    for(unsigned int i=1; i<=num; i++){
        resultado *= i;
    }
    return resultado;
}
   
int main()
{
	unsigned int numero;
	cout<<"Ingrese numero: "<<endl;
	cin>>numero;
	cout<<"Resultado: "<<endl;
	cout<<factorial(numero);
    return 0;
}


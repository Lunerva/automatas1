#include <iostream>
using namespace std;



int main(int argc, char** argv) {
	unsigned int primos[50];
	cout<<"numeros de 100 a 150: "<<endl;
	for(unsigned char i=0;i<50;i++){
		primos[i]=i+100;
		cout<<primos[i]<<", ";	
	}
	cout<<endl<<endl<<endl;
	
	cout<<"numeros primos: "<<endl;
	for(unsigned char i=0;i<50;i++){
		if(10%primos[i]==0){
			cout<<primos[i]<<", ";	
		}
	}

	return 0;
}

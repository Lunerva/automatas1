#include <iostream>
#include <string>

using namespace std;




//implementar un metodo que simule find de c++
//cad1 es la cadena principal
//cad2 es la cadena a buscar
bool encontrar(string cad1, string cad2){
    int tamCad1 = cad1.length();
    int tamCad2 = cad2.length();
    //herramienta para debugear
    //string cadAux;
    //resultado
    bool res=false;
    /*
    USAR SUBSTRING Y COMPARAR DE TAMAÑO DE CAD2 RESPECTO A CAD1
    DEBE RECORRER PARA CUBRIR TODA LA CADENA
    */
    for(int i=0;i<tamCad1;i++){
        //salida a consola para ver cadAux
        //cadAux = cad1.substr(i,tamCad2);
        //cout<<cadAux<<endl;
        //condicion para ver si cad1 contiene cad2
        if((cad1.substr(i,tamCad2)).compare(cad2)){
            res=true;
        }
    }
    return res;
}



int main()
{
    string cad1("tec laguna");
    string cad2(cad1);
    string cad3(5,'#');

    string cad4(cad1,4,6);

    //utlizando un iterado
    string cad5(cad2.begin(),cad2.begin()+3);

    cout<<cad1<<endl<<cad2<<endl<<cad3<<endl<<cad4<<endl<<cad5<<endl;

    string cad6 = cad4;
    int tam1 = cad6.size();
    int tam2 = cad6.length();
    cout<<"Longitud cadena 6 con size: "<<cad6<<tam1<<endl;
    cout<<"Longitud cadena 6 con length: "<<cad6<<tam2<<endl;

    //imprimir la cadena vertical y horizontal

    //opcion 1(personal)
    //cadena en vertical
/*    int tam=sizeof(cad6);
    for(int i=0;i<tam;i++){
        cout<<cad6.at(i)<<'\n';
    }
    //cadena en diagonal
    for(int i=0;i<tam;i++){
        cout<<cad6.at(i)<<'t'<<'\n';
    }
*/
    //opcion 2(en clase)
    char ch1 = cad6.at(2);
    char ch2 = cad6[2];

    cout<<"tercer caracter de lagunacon at(): "<<ch1<<endl;
    cout<<"tercer caracter de lagunacon []: "<<ch2<<endl;

    char chFrente = cad6.front();
    char chUltimo = cad6.back();

    cout<<"primer caracter de laguna con at(): "<<chFrente<<endl;
    cout<<"primer caracter de laguna con []: "<<chUltimo<<endl;

    cad6.append("Coahuila");
    cout<<cad6<<endl;

    cad4.append(cad6,0,3);
    cout<<cad4<<endl;

    string cad7(cad6);
    if(cad6.find(cad7)!=string::npos){
        cout<<"cad7 encontrada detro de cad6"<<endl;
    }else{
        cout<<"cad7 no encontrada dentro de cad6"<<endl;
    }

    //obtener una subcadena de la cadena1

    cout<<cad1.substr(4,2)<<endl;

    cout<<"prueba find"<<endl;
    cout<<"cadena 6: "<<cad6<<"\n"<<"cadena 7: "<<cad7<<endl;
    cout<<"buscar cad7 en cad6 resultado: "<<encontrar(cad6,"lagunas")<<endl;

    cad6.erase(12,4);
    cout<<"cadena 6: "<<cad6<<endl;

    cad6.erase(cad6.begin()+6,cad6.end()-4);
    cout<<"cadena 6: "<<cad6<<endl;


    cad6.erase(cad6.begin()+8,cad6.end());
    cout<<"cadena 6: "<<cad6<<endl;

    cad6.erase(cad6.begin()+6,cad6.end());
    cout<<"cadena 6: "<<cad6<<endl;

    string cad8 = "Este es un examen";
    cout<<cad8<<endl;
    //cad8.replace(2,5,"o era");
    cad8.replace(cad8.begin()+2,cad8.begin()+7,"o era");
    cout<<cad8<<endl;

    //DISEÑAR E IMPLEMENTAR UNA APLICACION (consola) PARA CREAR UN JUEGO
    //DE PALABRAS, CARACTERES, NUMEROS string



    return 0;
}


















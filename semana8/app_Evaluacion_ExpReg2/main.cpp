#include<QRegularExpression>
#include<QRegularExpressionValidator>

#include<iostream>
using namespace std;

int main(int argc, char *argv[]){
    QString cadena = "1010";
    QRegularExpression patron("^[0-1]{1,8}$");

    QRegularExpressionMatch match = patron.match(cadena);

    if(match.hasMatch()){
        cout<<"numero binario valido"<<endl;
    }else{
        cout<<"numero binario invalido"<<endl;
    }



    return 0;
}









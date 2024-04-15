#include<QRegularExpression>
#include<QRegularExpressionValidator>

#include<iostream>
using namespace std;

int main(int argc, char *argv[]){
    /*
    QString cadena = "1010";
    QRegularExpression patron("^[0-1]{1,8}$");
    QRegularExpressionMatch match = patron.match(cadena);

    if(match.hasMatch()){
        cout<<"numero binario valido"<<endl;
    }else{
        cout<<"numero binario invalido"<<endl;
    }
    */

    cout<<"\n21130876 Luis Barranco\n";

    QString cad_opc[] = {
            "jose@correo.es",
            "john.pherez@gmail.co.uk",
            "jose.jose@outlook.com",
            "josefan@mx",
            "joss@localhost"
        };

    for (int i = 0; i < sizeof(cad_opc) / sizeof(cad_opc[0]); ++i) {
        cout<<"\ncadena de entrada: "<<cad_opc[i].toStdString()<<endl;

        QString qstr_patron_opc1 = "^[\\w-]+(\\.?[\\w-]+)@[A-Za-z0-9]+(\\.[A-Za-z0-9]+)(\\.[A-Za-z]{2,})?$";
        QRegularExpression patron_opc1(qstr_patron_opc1);
        cout<<"\nOPCION 1\npatron 1: "<<qstr_patron_opc1.toStdString()<<endl;
        QRegularExpressionMatch match_opc1 = patron_opc1.match(cad_opc[i]);

        if(match_opc1.hasMatch()){
            cout<<"correo valido "<<i+1<<endl;
        }else{
            cout<<"correo invalido "<<i+1<<endl;
        }

        QString qstr_patron_opc2 = "^[\\w-]+(\\.[\\w-_]+)*@[A-Za-z0-9]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$";
        QRegularExpression patron_opc2(qstr_patron_opc2);
        cout<<"\nOPCION 2\npatron 2: "<<qstr_patron_opc2.toStdString()<<endl;
        QRegularExpressionMatch match_opc2 = patron_opc2.match(cad_opc[i]);
        if (match_opc2.hasMatch()) {
            cout<<"correo valido "<<i+1<<endl;
        }else{
            cout<<"correo invalido "<<i+1<<endl;
        }

        QString qstr_patron_opc3 = "[A-Z0-9._%+-]+@[A-Z0-9-]+.+.[A-Z]{2,4}";
        QRegularExpression patron_opc3(qstr_patron_opc3);
        cout << "\nOPCION 3\npatron 3: " << qstr_patron_opc3.toStdString() << endl;
        QRegularExpressionMatch match_opc3 = patron_opc3.match(cad_opc[i]);
        if(match_opc3.hasMatch()){
            cout<<"correo valido "<<i+1<<endl;
        }else{
            cout<<"correo invalido "<<i+1<<endl;
        }
    }

    return 0;

}








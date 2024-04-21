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

////////////////////////////////////////////////////////////////////////////////////
    //del archivo de texto a analizar

    QRegularExpression expReg1("^[\\w-]+(\\.?[\\w-]+)@[A-Za-z0-9]+(\\.[A-Za-z0-9]+)(\\.[A-Za-z]{2,})?$");
    cout<<"\n\nregex1.-"<<endl;
    if(expReg1.isValid()){
        cout<<"regex valida"<<endl;
    }else{
        cout<<"regex no valido"<<endl;
    }
    QString correo1ExpReg1 = "1-gumaru-473a@hotmail.com";
    QString correo2ExpReg1 = "gumaro-.gumaro-gumaro-@12345.12345.tec";
    QString correo3ExpReg1 = "hola@correo.edu.mx";

    QRegularExpressionMatch match1ER1 = expReg1.match(correo1ExpReg1);
    QRegularExpressionMatch match2ER1 = expReg1.match(correo2ExpReg1);
    QRegularExpressionMatch match3ER1 = expReg1.match(correo3ExpReg1);


    if(match1ER1.hasMatch()){
        cout<<"correo valido"<<endl;
    }else{cout<<"correo no valido"<<endl;}
    if(match2ER1.hasMatch()){
        cout<<"correo valido"<<endl;
    }else{cout<<"correo no valido"<<endl;}
    if(match3ER1.hasMatch()){
        cout<<"correo valido"<<endl;
    }else{cout<<"correo no valido"<<endl;}

///////////////////////////////////////////////////////////////////////////


    QRegularExpression expReg2("^[\\w]+[.-_]*@[A-Za-z0-9]+(\\.[A-Za-z0-9]{2,})$");
    cout<<"\n\nregex2.-"<<endl;
    if(expReg2.isValid()){
        cout<<"regex valida"<<endl;
    }else{
        cout<<"regex no valido"<<endl;
    }
    QString correo1ExpReg2 = "user123@ejemplo.22";
    QString correo2ExpReg2 = "gatos_negros@00.12";
    QString correo3ExpReg2 = "s_5@Z.net";

    QRegularExpressionMatch match1ER2 = expReg2.match(correo1ExpReg2);
    QRegularExpressionMatch match2ER2 = expReg2.match(correo2ExpReg2);
    QRegularExpressionMatch match3ER2 = expReg2.match(correo3ExpReg2);


    if(match1ER2.hasMatch()){
        cout<<"correo valido"<<endl;
    }else{cout<<"correo no valido"<<endl;}
    if(match2ER2.hasMatch()){
        cout<<"correo valido"<<endl;
    }else{cout<<"correo no valido"<<endl;}
    if(match3ER2.hasMatch()){
        cout<<"correo valido"<<endl;
    }else{cout<<"correo no valido"<<endl;}

//////////////////////////////////////////////////////////////////////


    QRegularExpression expReg3("[A-Z0-9._%+-]+@[A-Z0-9-]+.+.[A-Z]{2,4}");
    cout<<"\n\nregex3.-"<<endl;
    if(expReg3.isValid()){
        cout<<"regex valida"<<endl;
    }else{
        cout<<"regex no valido"<<endl;
    }

    QString correo1ExpReg3 = "77@77..RR";
    QString correo2ExpReg3 = "FF7_%+-@-.AX.BX";
    QString correo3ExpReg3 = "____@---------.ZZ";

    QRegularExpressionMatch match1ER3 = expReg3.match(correo1ExpReg3);
    QRegularExpressionMatch match2ER3 = expReg3.match(correo2ExpReg3);
    QRegularExpressionMatch match3ER3 = expReg3.match(correo3ExpReg3);


    if(match1ER3.hasMatch()){
        cout<<"correo valido"<<endl;
    }else{cout<<"correo no valido"<<endl;}
    if(match2ER3.hasMatch()){
        cout<<"correo valido"<<endl;
    }else{cout<<"correo no valido"<<endl;}
    if(match3ER3.hasMatch()){
        cout<<"correo valido"<<endl;
    }else{cout<<"correo no valido"<<endl;}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    QRegularExpression expReg4("[a-zA-Z0-9]{1,}+[._+-]*@[empresapatito]+\\.+[a-z]{2,}+");
    cout<<"\n\nregex4.-"<<endl;
    if(expReg4.isValid()){
        cout<<"regex valida"<<endl;
    }else{
        cout<<"regex no valido"<<endl;
    }

    QString correo1ExpReg4 = "ara_ara@empresapatito.es";
    QString correo2ExpReg4 = "12+1@empresapatito.com";
    QString correo3ExpReg4 = "a_@empresapatito.mx";

    QRegularExpressionMatch match1ER4 = expReg4.match(correo1ExpReg4);
    QRegularExpressionMatch match2ER4 = expReg4.match(correo2ExpReg4);
    QRegularExpressionMatch match3ER4 = expReg4.match(correo3ExpReg4);


    if(match1ER4.hasMatch()){
        cout<<"correo valido"<<endl;
    }else{cout<<"correo no valido"<<endl;}
    if(match2ER4.hasMatch()){
        cout<<"correo valido"<<endl;
    }else{cout<<"correo no valido"<<endl;}
    if(match3ER4.hasMatch()){
        cout<<"correo valido"<<endl;
    }else{cout<<"correo no valido"<<endl;}

/////////////////////////////////////////////////////////////////////////////






/*
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
*/
    return 0;

}








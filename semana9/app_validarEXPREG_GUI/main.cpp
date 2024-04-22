#include<QApplication>
#include"validar_regexdialog.h"

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    validar_regexDIALOG dialog;
    dialog.setAttribute(Qt::WA_QuitOnClose);
    dialog.show();

    return app.exec();
}

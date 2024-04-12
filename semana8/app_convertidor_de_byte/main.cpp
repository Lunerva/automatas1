#include <QApplication>
#include "byteconverterdialog.h"

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    ByteConverterDialog dialogo;
    dialogo.setAttribute(Qt::WA_QuitOnClose);
    dialogo.show();

    return app.exec();
}

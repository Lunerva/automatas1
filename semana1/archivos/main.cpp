// copia.cpp: Copia de ficheros
// Uso: copia <fichero_origen> <fichero_destino>

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {
    ifstream entrada;
    ofstream salida;

    char buffer[2048]; // Buffer de 2 Kbytes
    int bytesLeidos;

    if(argc != 3) {
       printf("Usar: copia <ejemplo1.txt> <dest1.txt>\n");
       return 1;
    }

    // Abrir el fichero de entrada en lectura y binario
    entrada.open(argv[1]);
    if(!entrada.good()) {
       printf("El fichero %s no existe o no puede ser abierto.\n", argv[1]);
       return 1;
    }
    // Crear o sobreescribir el fichero de salida en binario
    salida.open(argv[2]);
    if(!salida.good()) {
       printf("El fichero %s no puede ser creado.\n", argv[2]);
       entrada.close();
       return 1;
    }
    // Bucle de copia:
    do {
       entrada.read(buffer, 2048);
       bytesLeidos = entrada.gcount();
       salida.write(buffer, bytesLeidos);
    } while(bytesLeidos > 0);
    // Cerrar ficheros:
    entrada.close();
    salida.close();
    return 0;
}

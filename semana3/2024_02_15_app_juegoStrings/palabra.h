#ifndef PALABRA_H
#define PALABRA_H

#include <string>

using namespace std;

class palabra
{
public:
    //atributos
    string cont;
    int posCont;
    string traduccion;
    int posTrad;
    //metodos
    palabra();
    palabra(string cont, int posCont, string traduccion, int posTrad);
};

#endif // PALABRA_H

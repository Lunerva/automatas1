#include "palabra.h"

palabra::palabra()
{
    cont="";
    posCont=0;
    traduccion="";
    posTrad=0;
}

palabra::palabra(string cont, int posCont, string traduccion, int posTrad)
{
    this->cont = cont;
    this->posCont = posCont;
    this->traduccion = traduccion;
    this->posTrad = posTrad;
}

#include "lexsin.h"

int lexsin::getNumBytesArch() const
{
    return numBytesArch;
}

void lexsin::setNumBytesArch(int newNumBytesArch)
{
    numBytesArch = newNumBytesArch;
}

lexsin::lexsin()
{

}

///////////ANALISIS LEXICO//////////////////////////////
void lexsin:: vanalisislexico()
{
    char cCarent;

    indice = iniToken = k = 0;
    viniedos();

    while(indice < numBytesArch || edoActesacept())
    {
        switch(edoAct)
        {
            case 0: cCarent=nextchar();
                if (strchr(non,cCarent))
                    edoAct = 1;
                else
                    if(strchr(par,cCarent))
                        edoAct = 2;
                    else
                        if(cCarent == '.')
                            edoAct = 37;
                    else
                        falla();
                break;

            case 1: cCarent=nextchar();
                if(strchr(non,cCarent))
                    edoAct=1;
                else
                    if(strchr(par,cCarent))
                        edoAct = 2;
                else if(cCarent== '.')
                        edoAct = 37;
                    else
                        falla();
                break;

            case 2: cCarent=nextchar();
                if(strchr(non,cCarent))
                    edoAct=1;
                else
                    if (strchr(par,cCarent))
                        edoAct=2;
                    else if(cCarent== '.')
                            edoAct = 37;
                    else
                        edoAct=3;
                break;

            case 3: vretract();
                strcpy(asTokens[k++],"Num");
                if (indice >= numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 4: cCarent=nextchar();
                switch(cCarent)
                {
                    case '+': edoAct=5; break;
                    case '-': edoAct=6; break;
                    case '*': edoAct=7; break;
                    case '/': edoAct=8; break;
                    default: falla();
                }
                break;

            case 5: strcpy(asTokens[k++], "+");
                if (indice >= numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 6: strcpy(asTokens[k++], "-");
                if (indice>=numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 7: strcpy(asTokens[k++], "*");
                if (indice>=numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 8: strcpy(asTokens[k++], "/");
                if (indice>=numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;


            case 9: cCarent=nextchar();
                if (strchr(par,cCarent))
                    edoAct=10;
                else
                    if(strchr(non,cCarent))
                        edoAct=11;
                    else if(cCarent== '.')
                            edoAct = 37;
                    else
                        falla();
                break;

            case 10: cCarent=nextchar();
                if (strchr(par,cCarent))
                    edoAct=10;
                else
                    if(strchr(non,cCarent))
                        edoAct=11;
                    else if(cCarent== '.')
                            edoAct = 37;
                    else
                        falla();
                break;

            case 11 : cCarent=nextchar();
                if (strchr(non,cCarent))
                    edoAct=11;
                else
                    if(strchr(par,cCarent))
                        edoAct=10;
                    else if(cCarent== '.')
                            edoAct = 37;
                    else
                        edoAct=12;
                break;

                // NON - PAR
            case 12: vretract();
                strcpy(asTokens[k++],"Num");
                if (indice>=numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 13: cCarent=nextchar();
                if ((isalpha(cCarent)|| cCarent=='_'))
                    edoAct=14;
                else
                    falla();
                break;

            case 14: cCarent=nextchar();
                if ((isalpha(cCarent)|| cCarent=='_') || isdigit(cCarent))
                    edoAct=14;
                else
                    edoAct= 15;
                break;

            case 15: vretract();
                if(esId())
                    strcpy(asTokens[k++], "Id");
                else
                    strcpy(asTokens[k++],sLexema);

                if(indice>=numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;


            case 16: cCarent=nextchar();
                if(cCarent==';')
                    edoAct=17;
                else
                    falla();
                break;

                /* Al encontrar el caracter ';' , que indica fin de linea,
                 Se copia el caracter '$' al fin del arreglo astokens
                 */
            case 17: strcpy(asTokens[k++], ";");
                strcpy(asTokens[k], "$");
                if (indice >= numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 18: cCarent=nextchar();
                if(cCarent=='[')
                    edoAct=19;
                else
                    falla();
                break;

            case 19: strcpy(asTokens[k++], "[");
                if (indice >= numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 20: cCarent=nextchar();
                if(cCarent==']')
                    edoAct=21;
                else
                    falla();
                break;

            case 21: strcpy(asTokens[k++], "]");
                if (indice >= numBytesArch)
                    return;
                iniToken = indice;
                viniedos();
                break;

            case 22: cCarent = nextchar();
                if(cCarent == ',')
                    edoAct=23;
                else
                    falla();
                break;

            case 23: strcpy(asTokens[k++], ",");
                if (indice >= numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 24: cCarent = nextchar();
                if (('"' == cCarent) && cCarent)
                    edoAct=25;
                else
                    falla();
                break;

            case 25: cCarent=nextchar();
                if (('"' != cCarent) && cCarent)
                    edoAct=25;
                else
                    if(cCarent)
                        edoAct=26;
                break;

            case 26: strcpy(asTokens[k++],"Cte.Lit");
                if (indice >= numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 27: cCarent=nextchar();
                if(cCarent == '(')
                    edoAct=28;
                else
                    falla();
                break;

            case 28: strcpy(asTokens[k++], "(");
                if (indice>=numBytesArch)
                    return;
                iniToken = indice;
                viniedos();
                break;

            case 29:cCarent=nextchar();
                if(cCarent == ')')
                    edoAct=30;
                else
                    falla();
                break;

            case 30: strcpy(asTokens[k++], ")");
                if (indice>=numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 31: cCarent = nextchar();
                if(cCarent == '{')
                    edoAct = 32;
                else
                    falla();
                break;

            case 32: strcpy(asTokens[k++], "{");
                if (indice >= numBytesArch)
                    return;
                iniToken = indice;
                viniedos();
                break;

            case 33: cCarent = nextchar();
                if(cCarent == '}')
                    edoAct = 34;
                else
                    falla();
                break;

            case 34: strcpy(asTokens[k++], "}");
                if (indice >= numBytesArch)
                    return;
                iniToken = indice;
                viniedos();
                break;

            case 35: cCarent = nextchar();
                if(cCarent == '=')
                    edoAct = 36;
                else
                    falla();
                break;

            case 36: strcpy(asTokens[k++], "=");
                if (indice >= numBytesArch)
                    return;
                iniToken = indice;
                viniedos();
                break;

        case 37: cCarent=nextchar();
            if (strchr(non,cCarent))
                edoAct = 38;
            else
                if(strchr(par,cCarent))
                    edoAct = 39;
                else
                    falla();
            break;
        case 38: cCarent=nextchar();
            if(strchr(non,cCarent))
                edoAct=38;
            else
                if(strchr(par,cCarent))
                    edoAct = 39;
                else
                    edoAct=40;
            break;

        case 39: cCarent=nextchar();
            if(strchr(non,cCarent))
                edoAct=38;
            else
                if (strchr(par,cCarent))
                    edoAct=39;
                else
                    edoAct=40;
            break;
        case 40: vretract();
            strcpy(asTokens[k++],"Real");
            if (indice >= numBytesArch)
                return;
            iniToken=indice;
            viniedos();
            break;
        }/*switch*/
    } /*while*/
}
void lexsin:: viniedos()//iniciar estados
{
    edoAct=0;
    edoIni=0;
}
char lexsin:: nextchar()//siguiente caracter
{
    char cAux;
    fread(&cAux,sizeof(cAux),1,fl.getFd());
    indice++;
    return cAux;
}
void lexsin:: vretract()//retroceder actual
{
    indice--;
    fseek(fl.getFd(),(long)indice,SEEK_SET);
}
int lexsin:: edoActesacept()//estado actual es aceptacion
{
    switch (edoAct){
    case 8: case 5: case 7: case 6: case 3:
    case 12: case 15: case 17: case 19: case 21:
    case 23 : case 26: case 28: case 30: case 32:
    case 34: case 36: case 40:
        return true;
        default : return false;
    }
}
void lexsin:: falla()
{
    switch (edoIni)
    {
        case 0 : edoIni=4;
            indice=iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 4 : edoIni=9;
            indice=iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 9 : edoIni=13;
            indice=iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 13 : edoIni=16;
            indice = iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 16 : edoIni=18;
            indice = iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 18 : edoIni=20;
            indice=iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 20 : edoIni=22;
            indice = iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 22 : edoIni=24;
            indice = iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 24 : edoIni=27;
            indice = iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 27 : edoIni=29;
            indice = iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 29: edoIni = 31;
            indice = iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 31: edoIni = 33;
            indice = iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 33: edoIni = 35;
            indice = iniToken;
            fseek(fl.getFd(), (long)iniToken, SEEK_SET);
            break;

        case 35: recuperaerror();
    }

    edoAct=edoIni;
}
void lexsin:: recuperaerror()
{
    iniToken = indice;
    viniedos();
}
int lexsin:: esId()
{
    int n,m,found = false;//false equivale a 0
    fseek(fl.getFd(),(long)iniToken,SEEK_SET);
    for (m=iniToken, n=0; m<indice ; m++, n++)
        fread(&sLexema[n],sizeof(char),1, fl.getFd());
    sLexema[n]= '\0';
    for (m=0 ; m < NUMPALRES && !found ;)
        if (strcmp(PalRes[m], sLexema)==0)
            found = true;
        else
            m++;
    return (found ? 0 : 1);
}


//////////////ANALISIS SINTACTICO
void lexsin:: vanalisis_sintactico()
{
    int ip=0, i, j;
    int renglon, iast;
    char x[10], a[10];

    Pila.insertapila("$");

    //COMPARA EL PRIMER ARREGLO DE CHAR EN asTokens con "puts"
    if(strcmp(asTokens[ip], "puts") == 0)
        Pila.insertapila("F");
    else
        Pila.insertapila("D");

    printf("\nSalida del Analizador Sintactico (asTokens): \n");
    printf("Arreglo de Tokens: \n");

    //se realizara el ciclo hasta que asTokens sea "$"
    //ira recorriendo toda la pila, porque "$" se encuentra al fondo
    for(i=0; strcmp(asTokens[i], "$") != 0; i++)
        printf("%s ", asTokens[i]);//va mostrando la pila

    printf("\n\n Producciones: \n");

    do
    {
        strcpy(x, Pila.pilac[Pila.getCima()]);//se copia el valor del tope de la pila hacia x
        strcpy(a, asTokens[ip]);//se copia el valor de asTokens en 0 hacia a

        //si tenemos un token o si es $
        if(estoken(x) || (strcmp(x, "$") == 0))
        {
            //si son iguales se eliminan
            if(strcmp(x, a) == 0)
            {
                Pila.eliminapila();
                ip++;
            }
            else
            {
                if(strcmp(asTokens[ip], "puts") == 0)
                    Pila.insertapila("F");
                else //Sino
                    Pila.insertapila("D");

                strcpy(x, Pila.pilac[Pila.getCima()]);//se copia el valor del tope de la pila hacia x

            }
        }
        else
        {
            //el resultado encontrado se guarda en renglon
            renglon = buscaTabla(a, x);

            //en estge codigo por lo general el numero 999
            //se refiere a epsilon | lambda | vacio

            //si encontro el valor entonces
            if(renglon != 999)
            {
                Pila.eliminapila();
                iast = 0;
                //////////////////////////teblaM retorna el primer valor que
                /// encuentre en el renglon especificado
                /// el valor retornado se usara para identificar el valor en
                /// las variables sintacticas
                printf("%-3s -> ", varsint[tablaM[renglon][0]]);

                //mientra iast no sea 999
                for(j= 3; iast!=999; j++)
                {
                    iast = tablaM[renglon][j];  //999
                    if(iast < 0)//si iast es menor que cero, por ejemplo que sea negativo
                    {
                        iast *= -1;//se multiplica por -1 para invertir el signo
                        printf("%s ",token[iast]);
                    }
                    else
                    {
                        if(iast != 999)//o mientras no sea 999
                            printf("%s", varsint[iast]);
                    }
                }

                printf("\n");

                //i comenzara en dos posiciones antes de donde termino j
                //se realizara mientras i sea mayor que 2
                //ira de dereche a izquierda
                for(i=j-2; i>2; i--)
                {
                    iast = tablaM[renglon][i];
                    if(iast < 0)
                    {
                        iast *= -1;
                        Pila.insertapila(token[iast]);//inserta en la pila el token de la posicon en iast
                    }
                    else
                        Pila.insertapila(varsint[iast]);//inserta en la pila la variable sintactica de la posicion en iast
                }
            }
            else
            {
                //si devuelve 999 entonces es un error de sintaxis
                printf("\n\n Error de Sintaxis");
                return;
            }
        }
     }while(strcmp(x, "$") != 0);//esto se ejecutara mientras x no sea "$"
    printf("\n");
}
int lexsin:: estoken(char x[])
{
    int i;
    //comprueba si el valor x se encuentra en el arreglo token
    for(i=0; i<23; i++)
    {
        if(strcmp(x, token[i]) == 0)
            return 1;
    }

    return 0;
}
//retornara el entero sobre donde se encuentra
int lexsin:: buscaTabla(char a[], char x[])
{
    //indice en x y en a
    int indx=0, inda=0, i;

    ////////LOS SIGUIENTES CICLOS RECORREN TODO token Y varsint PARA ENCONTRAR
    /// a Y x, SE DEVOLVERA EL INDICE O LA POSICION DONDE ESTOS SE ENCUENTREN

    //tope en 23 porque token continene 22

    //supongo que PORQUE FALTA SUMAR $ QUE NO SE ENCUENTRA EN token PERO TAMBIEN
    //SE DEBE TENER EN CUENTA
    for(i=0; i<23; i++)
        if(strcmp(a, token[i]) == 0)//compara a con el token en pos i
            inda = i;//9 int

    //tope en 15 porque varsint contiene 15
    for(i=0; i<15; i++)
        if(strcmp(x, varsint[i]) == 0)
            indx=i; //1 D

    //en este ultimo se recorre la tablaM
    for(i=0; i<44; i++)
    {
        if(indx == tablaM[i][0])
            if(inda == tablaM[i][1])
                return i;
    }

    return 999;
}
void lexsin:: vmuestra()
{
    int iJ;

    puts("\nTOKENS RECONOCIDOS : \n");
    for(iJ=0; iJ < k; iJ++)  //,Ren++)
    {
        puts(asTokens[iJ]);

    }
}


#include "analizadorlexico.h"

//uso de macros
#define leerCar(i) cadena[i++]
#define retrocedeCar i-- //representa el * en el diagrama de transiciones

analizadorLexico::analizadorLexico()
{
    inicializaEstados();
}

void analizadorLexico::scanner(char cadena[])
{
    contenido.append("\nSalida analizador Lexico\n");

    char caracter;
    inicializaEstados();
    i = inicioToken = 0;
    TablaDeSimbolos ts(5);
    bool agregar = false;
    bool agregarV = false;
    string num;
    indiceTokens=0;
    while( (i < (int)strlen(cadena)) || (estadoDeAceptacion()) )
    {
        if(agregar && agregarV){
            char *cad;
            strcpy(cad,id.c_str());
            cout<<"\nagregarSym"<<endl;
            ts.addSym(cad,valor);
            id.clear();
            num.clear();
            agregar=false;
            agregarV=false;
        }
        switch(estadoActual){
        case 0:
            caracter = leerCar(i);
            if(esDelimitador(caracter)){
                estadoActual = 1;
            }else{
                fallo();//cambio de estado
                //break;
            }
            break;
        case 1:
            caracter=leerCar(i);
            if(esDelimitador(caracter)){
                estadoActual=1;
                //caracter=leerCar(i);
            }else{
                estadoActual=2;
            }
            break;
        case 2:
            retrocedeCar;//seria el * del diag. de transiciones
            cout<<"\nDelimitador"<<endl;
            contenido.append("\nDelimitador");
            inicializaEstados();
            inicioToken=i;
            break;
        case 3:caracter=leerCar(i);{
            if(esLetra(caracter)){
                id+=caracter;
                estadoActual=4;
            }else{
                fallo();
                break;
            }
        }
        case 4:
            caracter=leerCar(i);{
            if(esLetra(caracter)||esDigito(caracter)){
                    id+=caracter;
                    estadoActual=4;
                }else{
                    estadoActual=5;
                }
            }
            break;
        case 5:{
            retrocedeCar;
            cout<<"\nel contenido de id es: "<<id<<endl;

            if(palRes->find(id)){
                //cout<<"\n"<<id<<endl;
                for(int rec=0;rec<palRes->length();rec++){
                    if(strcmp(palRes[rec].c_str(),id.c_str())){
                        contenido.append("\n"+id);
                        asTokens[indiceTokens++] = id;
                        id.clear();
                    }
                }
            }else{
                cout<<"\nIdentificador"<<endl;
                contenido.append("\nIdentificador");
                asTokens[indiceTokens++] = "Id";
                agregar=true;
            }
            inicializaEstados();
            inicioToken=i;
            break;
            }
        case 6:caracter=leerCar(i);{
            if(esDigito(caracter)){
                num+=caracter;
                estadoActual=7;
            }else{
                fallo();
            }
            break;
        }
        case 7:caracter=leerCar(i);{
            if(esDigito(caracter)){
                num+=caracter;
                estadoActual=7;
            }else if(caracter=='.'){
                num+=caracter;
                estadoActual=9;
            }else{
                estadoActual=8;
            }
        }
            break;
        case 8:{
            retrocedeCar;
            //convertimos de string a int
            valor = stoi(num);
            cout<<"\nNumero entero"<<endl;
            contenido.append("\nNumero entero");
            asTokens[indiceTokens++] = "Num";
            inicializaEstados();
            inicioToken=i;
            agregarV=true;
        }
            break;
        case 9:caracter=leerCar(i);{
            if(esDigito(caracter)){
                num+=caracter;
                estadoActual=9;
            }else{
                estadoActual=10;
            }
        }
            break;
        case 10:{
            retrocedeCar;
            valor = stof(num);
            cout<<"\nNumero real"<<endl;
            contenido.append("\nNumero real");
            asTokens[indiceTokens++] = "Real";
            inicializaEstados();
            inicioToken=i;
            agregarV=true;
        }
            break;
        case 11:caracter=leerCar(i);//continua los operadores relaciones, logicos y aritmeticos
        {
            if(caracter=='='){
                estadoActual=12;
            }else{
                fallo();
            }
        }
            break;
        case 12:caracter=leerCar(i);
        {
            if(caracter=='='){
                estadoActual=14;
            }else{
                estadoActual=13;
            }
        }
            break;
        case 13:
            retrocedeCar;
            cout<<"\nAsignar"<<endl;
            contenido.append("\nAsignar");
            asTokens[indiceTokens++] = "=";

            inicializaEstados();
            inicioToken=i;
            break;
        case 14:
            estadoActual=15;
            break;
        case 15:
            retrocedeCar;
            cout<<"\nIgual"<<endl;
            contenido.append("\nIgual");
            asTokens[indiceTokens++] = "==";
            inicializaEstados();
            inicioToken=i;
            break;
        case 16:caracter=leerCar(i);
        {
            if(caracter=='>'){
                estadoActual=17;
            }else{
                fallo();
            }
        }
            break;
        case 17:caracter=leerCar(i);
        {
            if(caracter=='='){
                estadoActual=18;
            }else{
                estadoActual=20;
            }
        }
            break;
        case 18:
            estadoActual=19;
            break;
        case 19:
            retrocedeCar;
            cout<<"\nMayor o igual que"<<endl;
            contenido.append("\nMayor o igual que");
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 20:
            retrocedeCar;
            cout<<"\nMayor que"<<endl;
            contenido.append("\nMayor que");
            inicializaEstados();
            inicioToken=i;
            break;
        case 21:caracter=leerCar(i);
        {
            if(caracter=='<'){
                estadoActual=22;
            }else{
                fallo();
            }
        }
            break;
        case 22:caracter=leerCar(i);
        {
            if(caracter=='='){
                estadoActual=24;
            }else{
                estadoActual=23;
            }
        }
            break;
        case 23:
            retrocedeCar;
            cout<<"\nMenor que"<<endl;
            contenido.append("\nMenor que");
            inicializaEstados();
            inicioToken=i;
            break;
        case 24:
            estadoActual=25;
            break;
        case 25:
            retrocedeCar;
            cout<<"\nMenor o igual que"<<endl;
            contenido.append("\nMenor o igual que");
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 26:caracter=leerCar(i);
        {
            if(caracter=='!'){
                estadoActual=27;
            }else{
                fallo();
            }
        }
            break;
        case 27:caracter=leerCar(i);
        {
            if(caracter=='='){
                estadoActual=29;
            }else{
                estadoActual=28;
            }
        }
            break;
        case 28:
            retrocedeCar;
            cout<<"\nOpuesto que"<<endl;
            contenido.append("\nOpuesto que");
            inicializaEstados();
            inicioToken=i;
            break;
        case 29:
            estadoActual=30;
            break;
        case 30:
            retrocedeCar;
            cout<<"\nDiferente que"<<endl;
            contenido.append("\nDiferente que");
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 31:caracter=leerCar(i);
        {
            if(caracter=='+'){
                estadoActual=32;
            }else{
                fallo();
            }
        }
            break;
        case 32:caracter=leerCar(i);
        {
            if(caracter=='+'){
                estadoActual=33;
            }else{
                estadoActual=34;
            }
        }
            break;
        case 34:
            retrocedeCar;
            cout<<"\nSuma"<<endl;
            contenido.append("\nSuma");
            asTokens[indiceTokens++] = "+";
            inicializaEstados();
            inicioToken=i;
            break;
        case 33:
            estadoActual=35;
            break;
        case 35:
            retrocedeCar;
            cout<<"\nIncrementar en uno"<<endl;
            contenido.append("\nIncrementar en uno");
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 36:caracter=leerCar(i);
        {
            if(caracter=='-'){
                estadoActual=37;
            }else{
                fallo();
            }
        }
            break;
        case 37:caracter=leerCar(i);
        {
            if(caracter=='-'){
                estadoActual=39;
            }else{
                estadoActual=38;
            }
        }
            break;
        case 38:
            retrocedeCar;
            cout<<"\nResta"<<endl;
            contenido.append("\nResta");
            asTokens[indiceTokens++] = "-";
            inicializaEstados();
            inicioToken=i;
            break;
        case 39:
            estadoActual=40;
            break;
        case 40:
            retrocedeCar;
            cout<<"\nDecrementar en uno"<<endl;
            contenido.append("\nDecrementar en uno");
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 41:
            caracter = leerCar(i);
            if(caracter=='*'){
                estadoActual = 42;
            }else{
                fallo();
            }
            break;
        case 42:
            caracter=leerCar(i);
            estadoActual=43;
            break;
        case 43:
            retrocedeCar;
            cout<<"\nMultiplicacion"<<endl;
            contenido.append("\nMultiplicacion");
            asTokens[indiceTokens++] = "*";
            inicializaEstados();
            inicioToken=i;
            break;
        case 44:
            caracter = leerCar(i);
            if(caracter=='/'){
                estadoActual = 45;
            }else{
                fallo();
            }
            break;
        case 45:
            caracter=leerCar(i);
            estadoActual=46;
            break;
        case 46:
            retrocedeCar;
            cout<<"\nDivision"<<endl;
            contenido.append("\nDivision");
            asTokens[indiceTokens++] = "/";
            inicializaEstados();
            inicioToken=i;
            break;
        case 47:
            caracter = leerCar(i);
            if(caracter=='%'){
                estadoActual = 48;
            }else{
                fallo();
            }
            break;
        case 48:
            caracter=leerCar(i);
            estadoActual=49;
            break;
        case 49:
            retrocedeCar;
            cout<<"\nModulo"<<endl;
            contenido.append("\nModulo");
            inicializaEstados();
            inicioToken=i;
            break;
        case 50:
            caracter = leerCar(i);
            if(caracter=='^'){
                estadoActual = 51;
            }else{
                fallo();
            }
            break;
        case 51:
            caracter=leerCar(i);
            estadoActual=52;
            break;
        case 52:
            retrocedeCar;
            cout<<"\nXOR"<<endl;
            contenido.append("\nXOR");
            inicializaEstados();
            inicioToken=i;
            break;
        case 53:caracter=leerCar(i);
        {
            if(caracter=='&'){
                estadoActual=54;
            }else{
                fallo();
            }
        }
            break;
        case 54:caracter=leerCar(i);
        {
            if(caracter=='&'){
                estadoActual=55;
            }else{
                estadoActual=56;
            }
        }
            break;
        case 56:
            retrocedeCar;
            cout<<"\nand incompleto,agregue otro &"<<endl;
            contenido.append("\nand incompleto, agregue otro &");
            inicializaEstados();
            inicioToken=i;
            break;
        case 55:
            estadoActual=57;
            break;
        case 57:
            retrocedeCar;
            cout<<"\nOperador AND"<<endl;
            contenido.append("\nOperador AND");
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 58:caracter=leerCar(i);
        {
            if(caracter=='|'){
                estadoActual=59;
            }else{
                fallo();
            }
        }
            break;
        case 59:caracter=leerCar(i);
        {
            if(caracter=='|'){
                estadoActual=60;
            }else{
                estadoActual=61;
            }
        }
            break;
        case 61:
            retrocedeCar;
            cout<<"\nor incompleto,agregue otro |"<<endl;
            contenido.append("\nor incompleto, agregue otro |");
            inicializaEstados();
            inicioToken=i;
            break;
        case 60:
            estadoActual=62;
            break;
        case 62:
            retrocedeCar;
            cout<<"\nOperador OR"<<endl;
            contenido.append("\nOperador OR");
            caracter=leerCar(i);
            inicializaEstados();
            inicioToken=i;
            break;
        case 63:
            caracter = leerCar(i);
            if(caracter==';'){
                estadoActual = 64;
            }else{
                fallo();
            }
            break;
        case 64:
            caracter=leerCar(i);
            estadoActual=65;
            break;
        case 65:
            retrocedeCar;
            cout<<"\nFin de instruccion"<<endl;
            contenido.append("\nFin de instruccion\n");
            asTokens[indiceTokens++] = ";";
            inicializaEstados();
            inicioToken=i;
            break;
        }
    }
    contenido.append("\n\n");
    contenido=ts.mostrarTabla(contenido);
    ts.mostrarTabla();
}

void analizadorLexico::inicializaEstados()
{
    estadoInicial = estadoActual = 0;
}

void analizadorLexico::fallo()
{
    switch(estadoActual){
    case 0:{
        estadoActual=3;
        i=inicioToken;
        }
        break;
    case 3:
        estadoActual=6;
        i=inicioToken;
        break;
    case 6:
        estadoActual=11;
        i=inicioToken;
        break;
    case 11:
        estadoActual=16;
        i=inicioToken;
        break;
    case 16:
        estadoActual=21;
        i=inicioToken;
        break;
    case 21:
        estadoActual=26;
        i=inicioToken;
        break;
    case 26:
        estadoActual=31;
        i=inicioToken;
        break;
    case 31:
        estadoActual=36;
        i=inicioToken;
        break;
    case 36:
        estadoActual=41;
        i=inicioToken;
        break;
    case 41:
        estadoActual=44;
        i=inicioToken;
        break;
    case 44:
        estadoActual=47;
        i=inicioToken;
        break;
    case 47:
        estadoActual=50;
        i=inicioToken;
        break;
    case 50:
        estadoActual=53;
        i=inicioToken;
        break;
    case 53:
        estadoActual=58;
        i=inicioToken;
        break;
    case 58:
        estadoActual=63;
        i=inicioToken;
        break;
    }
}

bool analizadorLexico::estadoDeAceptacion()
{
    switch(estadoActual){
    case 2:
    case 5:
    case 8:
    case 10:
    case 15:
    case 20:
    case 25:
    case 30:
    case 35:
    case 40:
    case 43:
    case 46:
    case 49:
    case 52:
    case 57:
    case 61:
    case 62:
    case 65:
        return true;
    default:
        return false;
    }
}

bool analizadorLexico::esDelimitador(char c)
{
    switch(c){
    case '\n':
    case '\t':
    case ' ':
        return true;
        break;
    default:
        return false;
        break;
    }
}

bool analizadorLexico::esLetra(char c)
{
    if((c>=65 && c<=90)||(c>=97 && c<=122)||(c==95)){
        return true;
    }else{
        return false;
    }
}

bool analizadorLexico::esDigito(char c)
{
    if((c>=48 && c<=57)){
        return true;
    }else{
        return false;
    }
}


//////////////ANALISIS SINTACTICO
string analizadorLexico:: vanalisis_sintactico()
{
    string res;

    int ip=0, i, j;
    int renglon, iast;
    char x[10], a[10];

    pila.push("$");
    //insertapila("$");

    //COMPARA EL PRIMER ARREGLO DE CHAR EN asTokens con "puts"
    if(strcmp(asTokens[ip].c_str(), "puts") == 0)
        pila.push("F");
        //insertapila("F");
    else
        pila.push("D");
        //insertapila("D");

    res.append("\nSalida del Analizador Sintactico (asTokens): \n");
    res.append("Arreglo de Tokens: \n");

    //se realizara el ciclo hasta que asTokens sea "$"
    //ira recorriendo toda la pila, porque "$" se encuentra al fondo
    for(int ind=0; ind<asTokens->length(); ind++){
        res.append("\n"+asTokens[ind]);//va mostrando el contenido de asTokens
    }
    res.append("\n\n Producciones: \n");

    do
    {
        strcpy(x, pila.front().c_str());//se copia el valor del tope de la pila hacia x
        strcpy(a, asTokens[ip].c_str());//se copia el valor de asTokens en 0 hacia a

        //si tenemos un token o si es $
        if(estoken(x) || (strcmp(x, "$") == 0))
        {
            //si son iguales se eliminan
            if(strcmp(x, a) == 0)
            {
                pila.pop();
                ip++;
            }
            else
            {
                if(strcmp(asTokens[ip].c_str(), "puts") == 0)
                    pila.push("F");
                    //insertapila("F");
                else //Sino
                    pila.push("D");
                    //insertapila("D");

                strcpy(x, pila.front().c_str());//se copia el valor del tope de la pila hacia x

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
                pila.pop();
                iast = 0;
                //////////////////////////teblaM retorna el primer valor que
                /// encuentre en el renglon especificado
                /// el valor retornado se usara para identificar el valor en
                /// las variables sintacticas
                res.append("\n");
                res.append(varsint[tablaM[renglon][0]]);

                //mientra iast no sea 999
                for(j= 3; iast!=999; j++)
                {
                    iast = tablaM[renglon][j];  //999
                    if(iast < 0)//si iast es menor que cero, por ejemplo que sea negativo
                    {
                        iast *= -1;//se multiplica por -1 para invertir el signo
                        res.append(token[iast]);
                        //printf("%s ",token[iast]);
                    }
                    else
                    {
                        if(iast != 999)//o mientras no sea 999
                            res.append(varsint[iast]);
                            //printf("%s", varsint[iast]);
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
                        pila.push(token[iast]);
                        //insertapila(token[iast]);//inserta en la pila el token de la posicon en iast
                    }
                    else
                        pila.push(varsint[iast]);
                        //insertapila(varsint[iast]);//inserta en la pila la variable sintactica de la posicion en iast
                }
            }
            else
            {
                //si devuelve 999 entonces es un error de sintaxis
                res.append("\n\n Error de Sintaxis");
                //printf("\n\n Error de Sintaxis");

            }
        }
     }while(strcmp(x, "$") != 0);//esto se ejecutara mientras x no sea "$"
    //printf("\n");
    return res;
}
int analizadorLexico::estoken(char x[])
{
    int i;
    //comprueba si el valor x se encuentra en el arreglo token
    for(i=0; i<23; i++)
    {
        if(strcmp(x, token[i].c_str()) == 0)
            return 1;
    }

    return 0;
}
//retornara el entero sobre donde se encuentra
int analizadorLexico:: buscaTabla(char a[], char x[])
{
    //indice en x y en a
    int indx=0, inda=0, i;

    ////////LOS SIGUIENTES CICLOS RECORREN TODO token Y varsint PARA ENCONTRAR
    /// a Y x, SE DEVOLVERA EL INDICE O LA POSICION DONDE ESTOS SE ENCUENTREN

    //tope en 23 porque token continene 22

    //supongo que PORQUE FALTA SUMAR $ QUE NO SE ENCUENTRA EN token PERO TAMBIEN
    //SE DEBE TENER EN CUENTA
    for(i=0; i<23; i++)
        if(strcmp(a, token[i].c_str()) == 0)//compara a con el token en pos i
            inda = i;//9 int

    //tope en 15 porque varsint contiene 15
    for(i=0; i<15; i++)
        if(strcmp(x, varsint[i].c_str()) == 0)
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
string analizadorLexico:: vmuestra()
{
    string res;
    int iJ;

    res.append("\nTOKENS RECONOCIDOS : \n");
    for(iJ=0; iJ < asTokens->length(); iJ++)  //,Ren++)
    {
        res.append(asTokens[iJ]);
        //puts(asTokens[iJ]);
    }
    return res;
}

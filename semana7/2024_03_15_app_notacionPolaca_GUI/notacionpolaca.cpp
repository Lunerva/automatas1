#include "notacionpolaca.h"

NotacionPolaca::NotacionPolaca()
{

}

//IMPLEMENTAR METODO PARA CONTAR LA CANTIDAD DE PARENTESIS

char *NotacionPolaca::convertirAposfija(string expInfija)
{
    //cadena resultado, ya en posfija
    char *expPosFija = new char[expInfija.length()];

    //IMPLEMENTAR UN METODO PARA DETERMINAR
    //LA CANTIDAD DE OPERADORES ENLA EXPRESION INFIJA
    pilaT <char> *stack = new pilaT<char>(expInfija.length());

    int pos=0;

    //recorremos la cadena infija
    for(int i=0;i<(int)expInfija.length();i++){
        //caracter actual, sea operador u operando
        char car=expInfija[i];
        //determinar el tipo de caracter y su prioridad
        Simbolo actual = tipoYprocedencia(car);


        switch(actual){
        case OPERANDO: expPosFija[pos++]=car;
            break;
        case SUMRES:{
            while((!stack->estaVacia())  && (tipoYprocedencia(stack->Tope())>=actual)){
                expPosFija[pos++]= stack->pop();
            }
            stack->push(car);
            break;}
        case MULTDIV:{
            while((!stack->estaVacia())  && (tipoYprocedencia(stack->Tope())>=actual)){
                expPosFija[pos++]= stack->pop();
            }
            stack->push(car);
            break;}
        case POW:{
            while((!stack->estaVacia())  && (tipoYprocedencia(stack->Tope())>=actual)){
                    expPosFija[pos++]= stack->pop();
            }
            stack->push(car);
            break;}
        case PIZQ: stack->push(car);
                break;
        case PDER: {
            char x = stack->pop();
            while(tipoYprocedencia(x) != PIZQ){
                expPosFija[pos++]=x;
            }
            stack->pop();
            break;
        }
        default:
            break;
        }
    }
    while(!stack->estaVacia()){
        if(pos < (int) expInfija.length()){
            expPosFija[pos++]= stack->pop();
        }else{
            break;
        }
    }
    expPosFija[pos]='\0';
    //las cadenas de c++ terminan en nulo
    return expPosFija;
}

string NotacionPolaca::convertirAposFija(string expInfija)
{

    string expPosFija="";

    pilaT <char> *stack = new pilaT<char>(expInfija.length());

    int pos=0;

    //recorremos la cadena infija
    for(int i=0;i<(int)expInfija.length();i++){
        //caracter actual, sea operador u operando
        char car=expInfija[i];
        //determinar el tipo de caracter y su prioridad
        Simbolo actual = tipoYprocedencia(car);


        switch(actual){
        case OPERANDO: expPosFija.push_back(car);
            break;
        case SUMRES:
        case MULTDIV:
        case POW:{
            while((!stack->estaVacia())  && (tipoYprocedencia(stack->Tope())>=actual)){
                expPosFija.push_back(stack->pop());
            }
            stack->push(car);
            break;}
        case PIZQ: stack->push(car);
                break;
        case PDER: {
            char x = stack->pop();
            while(tipoYprocedencia(x) != PIZQ){
                expPosFija.push_back(x);
                x=stack->pop();
            }
            break;
        }
        default:
            break;
        }
    }
    while(!stack->estaVacia()){
        if(pos < (int) expInfija.length()){
            expPosFija.push_back(stack->pop());
        }else{
            break;
        }
    }
    delete stack;
    //expPosFija[pos]='\0';
    //las cadenas de c++ terminan en nulo
    return expPosFija;
}

QString NotacionPolaca::convertirAposFija(QString expInfija)
{
    QString expPosFija="";
    pilaT <char> *stack = new pilaT<char>(expInfija.length());
    int pos=0;

    //recorremos la cadena infija
    for(int i=0;i<(int)expInfija.length();i++){
        //caracter actual, sea operador u operando
        char car=expInfija.at(i).toLatin1();
        //determinar el tipo de caracter y su prioridad
        Simbolo actual = tipoYprocedencia(car);


        switch(actual){
        case OPERANDO: expPosFija.append(car);
            break;
        case SUMRES:
        case MULTDIV:
        case POW:{
            while((!stack->estaVacia())  && (tipoYprocedencia(stack->Tope())>=actual)){
                expPosFija.append(stack->pop());
            }
            stack->push(car);
            break;}
        case PIZQ: stack->push(car);
                break;
        case PDER: {
            char x = stack->pop();
            while(tipoYprocedencia(x) != PIZQ){
                expPosFija.append(x);
                x=stack->pop();
            }
            break;
        }
        default:
            break;
        }
    }
    while(!stack->estaVacia()){
        if(pos < (int) expInfija.length()){
            expPosFija.append(stack->pop());
        }else{
            break;
        }
    }
    delete stack;
    return expPosFija;
}

float NotacionPolaca::resolverPosFija(string expPosfija)
{
    //variable para almacenar el resultado
    float res=0;
    //pila para almacenar los numeros de la expresion
    pilaT<float>*pila=new pilaT<float>;
    //dos variables para dejar los valores que vamos a ir sacando de la pila
    float num1,num2;


    //recorremos la cadena de expresion posFija
    for(char car : expPosfija){
        //caracter actual, sea operador u operando
        //determinar el tipo de caracter y su prioridad
        Simbolo actual = tipoEspecifico(car);

        //operacion que hara en cada caso
        switch(actual){
        case OPERANDO:
            //'0' es 48 en ASCII
            pila->push(car-'0');
            break;
        //posteriormente quitamos los ultimos dos caracteres de la pila
        //y añadimos el valor resultado de la operacion como ultimo caracter a la pila
        case sum:
            num1= pila->pop();
            num2= pila->pop();
            pila->push(num1+num2);
            break;
        case rest:
            num1= pila->pop();
            num2= pila->pop();
            pila->push(num1-num2);
            break;
        case mult:
            num1= pila->pop();
            num2= pila->pop();
            pila->push(num1*num2);
            break;
        case divi:
            num1= pila->pop();
            num2= pila->pop();
            pila->push(num1/num2);
            break;
        case POW:
            num1= pila->pop();
            num2= pila->pop();
            pila->push(pow(num1,num2));
            break;
        default:
            break;
        }
        //esto se repetira hasta que termine de recorrer toda la expresion
        //y realice los calculos necesarios con los valores de la pila
    }

    //devolvemos el resultado final de la operacion
    return res=pila->pop();
}

Simbolo NotacionPolaca::tipoYprocedencia(char c)
{
    Simbolo simbolo;
    switch(c)
    {
    case '+':
    case '-':simbolo=SUMRES;
        break;
    case '*':
    case '/':simbolo=MULTDIV;
       break;
    case '^':simbolo=POW;
       break;
    case '(':simbolo=PIZQ;break;
    case ')':simbolo=PDER;break;
    default:simbolo=OPERANDO;break;
    }
    return simbolo;
}

Simbolo NotacionPolaca::tipoEspecifico(char c)
{
    Simbolo simbolo;
    switch(c)
    {
    case '+':simbolo = sum;
        break;
    case '-':simbolo = rest;
        break;
    case '*':simbolo = mult;
        break;
    case '/':simbolo = divi;
       break;
    case '^':simbolo = POW;
       break;
    case '(':simbolo=PIZQ;break;
    case ')':simbolo=PDER;break;
    default:simbolo=OPERANDO;break;
    }
    return simbolo;
}

bool NotacionPolaca::validarEntrada(string entrada)
{
    int cont=0;
    int contOp=0;
    if(numParentesis(entrada)){
        for(int i=0;i<(int)entrada.length();i++){
            if((entrada.at(i)>=42) && (entrada.at(i)<=45)){
                contOp++;
            }
            if((entrada.at(i)>=48) && (entrada.at(i)<=57)){
                cont++;
            }
            if(entrada.at(i)==94){
                contOp++;
            }
        }
    }
    cout<<"numero operadores: "<<contOp<<endl;
    cont+=contOp;
    if(cont==(int)entrada.length()){
        return true;
    }
    cout<<"Entrada con valores no esperados, se esperaba numeros u operadores"<<endl;
    return false;
}

bool NotacionPolaca::numParentesis(string entrada)
{
    int contIzq=0;
    int contDer=0;
    int contGen=0;

    for(int i=0;i<entrada.length();i++){
        if((entrada.at(i)==')') && (contIzq==0)){
            cout<<"falta parentesis izquierdo"<<endl;
            return false;
        }else{
            if(entrada.at(i)=='('){
                contIzq++;
                contGen++;
            }
            if(entrada.at(i)==')'){
                contDer++;
                contGen--;
                if(contGen<0){
                    cout<<"falta parentesis derecho"<<endl;
                    return false;
                }
            }
        }
    }
    if(contIzq == contDer){
        return true;
    }
    cout<<"no hay balance en parentesis"<<endl;
    return false;
}

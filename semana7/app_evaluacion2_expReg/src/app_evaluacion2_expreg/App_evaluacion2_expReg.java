package app_evaluacion2_expreg;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class App_evaluacion2_expReg {
    
    //LUIS BARRANCO 21130876
    
    //expresion regular -> delimita con \b y busca la palabra 'cat'
    private static final String REGEX = "\\bcat\\b";
    //cadena de texto de entrada
    private static final String INPUT = "cat cat cat cattie cat";

    public static void main(String[] args) {
        Pattern p = Pattern.compile(REGEX); // expresion regular asignada
        Matcher m = p.matcher(INPUT);   // get a matcher object
        int count = 0; // creamos e inicializamos contador

        while (m.find()) {
            //va mostrando la posicion de inicio y fin de donde se encuentra 
            //la palabra que cumple la condicion
            //ademas cuenta el numero de palabras que coinciden
            count++;
            System.out.println("Match number " + count);
            System.out.println("start(): " + m.start());
            System.out.println("end(): " + m.end());
        }
    }

}

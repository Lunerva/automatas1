package app_evaluacion1_expreg;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class App_evaluacion1_expReg {

    //LUIS BARRANCO 21130876
    
    public static void main(String[] args) {
        
        // cadena de entrada a comparar con la expresion regular
        String line = "This order was placed for QT3000! OK?";
        //expresion regular -> busca un digito y un texto/caracter que le continue
        String pattern = "(.*)(\\d+)(.*)";

        //se asigna la expresion regular
        Pattern r = Pattern.compile(pattern);

        //se asigna la coincidencia con la cadena
        Matcher m = r.matcher(line);
        if (m.find()) {
            //muestra la primer coincidencia con la cadena completa
            System.out.println("Found value: " + m.group(0));
            //muestra antes de la de la expresion regular
            System.out.println("Found value: " + m.group(1));
            System.out.println("Found value: " + m.group(2));
        } else {
            System.out.println("NO MATCH");
        }
    }

}

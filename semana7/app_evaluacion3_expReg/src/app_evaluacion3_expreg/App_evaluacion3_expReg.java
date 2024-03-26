package app_evaluacion3_expreg;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class App_evaluacion3_expReg {

    public static void main(String[] args) {

        //diseñe una expresion regular para determinar
        //la cantidad de las vocales y las consonantes 
        //que hay en una cadena de entrada
        //tomar en consideracion las vocales con acento
        
        int contC=0;
        String expReg = "[a-zA-Z|áéíóú]";
//        String expReg = "[a-z]";
        String cadena = "las vocales con acento áéíóú";
        Pattern pc = Pattern.compile(expReg);
        Matcher mc = pc.matcher(cadena);
        
//        
//        if(mc.matches()){
//            System.out.println("funciona");
//        }else{
//            System.out.println("no funciona");
//        }
        
        while (mc.find()){
            contC++;
        }
        
        System.out.println("contador "+ contC);
        
        
    
    
    
    
    }

}

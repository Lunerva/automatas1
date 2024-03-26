package app_expresionesregulares1;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class App_expresionesRegulares1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        //validar si una cadena de entrada contiene letras 
        //mayusculas, minusculas, digitos de entre 5 y 10 caracteres
        //"[A-Za-z0-9]{5,10}"
        Scanner teclado = new Scanner(System.in);

        String expRegular = "^ABC.*|^abc.*";
        expRegular = "a{3,10}";

        System.out.println("Cadena a analizar: ");
        String cadena = teclado.nextLine();

        Pattern patron1 = Pattern.compile(expRegular);
        Matcher matcher1 = patron1.matcher(cadena);

        if (matcher1.matches()) {
            System.out.println("LA CADENA, CUMPLE CON LOS REQUISITOS");
        } else {
            System.out.println("LA CADENA NO CUMPLE CON LOS REQUISITOS");
        }

        String texto1 = "abcCEfFGg esto es una prueba, "
                + "Cabreara se vio muy mal con su comentario";

        System.out.println("COMPROBAR SI LA CADENA EMPIEZA CON "
                + "\"ABC\" O \"abc\": " + texto1);
        //[abc]
        Pattern patronTexto1 = Pattern.compile(expRegular);
        Matcher matcherTexto1 = patronTexto1.matcher(texto1);

        if (matcherTexto1.matches()) {
            System.out.println("LA CADENA, CUMPLE CON LOS REQUISITOS");
        } else {
            System.out.println("LA CADENA NO CUMPLE CON LOS REQUISITOS");
        }
    }

    /*
    DISEÑE UN PATRON PARA VALIDAR NUMEROS
    HEXADECIMALES DE 8 DIGITOS
     */
    //"[a-f0-9-A-F]{1,8}";
    ///////////////
    /*
    DISEÑE UN PATRON PARA VALIDAR NUMEROS
    binarios DE 8 DIGITOS
     */
    //[0-1]{1,8}
    ///////////////
}

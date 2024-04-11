package playingregex;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PlayingREGEX {

    public static void main(String[] args) {
        String regex=".";
        Pattern patron = Pattern.compile(regex);
        Matcher coincidencia = patron.matcher("jos@hotmail.com");
        
        System.out.println(coincidencia.replaceAll(" |*| "));
        
        
        
    }
    
}

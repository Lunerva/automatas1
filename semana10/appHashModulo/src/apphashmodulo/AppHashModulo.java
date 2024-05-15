/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package apphashmodulo;

import java.util.Scanner;

/**
 *
 * @author martinovaldes
 */
public class AppHashModulo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
       // CUANTOS DATOS VAS A ALMACENAR
       // ESPRIMO(N), SI ES SI ADELANTE, SINO BUSCA EL MÁS CERCANO
        
        int []claves = {17,27,34,44,26,37,11};
        
        int []vecHash = new int [7];
        System.out.println("CLAVES : ");
        for(int i = 0; i < vecHash.length; i++)
        {
           int key = claves[i];
            System.out.println("Key : "+key);
           int indice = HashModulo.hashUbicarClave(vecHash, key,vecHash.length);
           vecHash[indice]=key;
        }
        
        System.out.println("CLAVES UBICADAS EN EL AREGLO");
        for(int i = 0; i < vecHash.length; i++)
        {
            System.out.println("Vec["+i+" ] = "+vecHash[i]);
        }
        System.out.println("\nBusqueda de Datos : ");
        char resp;
        Scanner scanner = new Scanner(System.in);
        do{
             System.out.println("Dato a Buscar : ");
             int dato = scanner.nextInt();
             int pos = HashModulo.hashBuscar(vecHash, dato, vecHash.length);
             if(pos == -1)
                 System.out.println("DATO NO EXISTE ");
             else
                 System.out.println("DATO ENCONTRADO EN LA POS : "+pos);
             System.out.println("Buscar Otro (s|n) : ");
             resp = Character.toLowerCase(scanner.next().charAt(0));
            
        }while(resp == 's');
        
        
        
    }
    
}


package apphashmodulo;

/**
 *
 * @author martinovaldes
 */
public class HashModulo {
    
    static public int hashUbicarClave(int []vec, int clave, int n)
    {
       int pos;
       //EL VALOR DE N (TAM. DEL ARREGLO) DEBE SER PRIMO
       // POR LO TANTO VALIDAR SI ES O NO PRIMO, SINO ES
       // DETERMINAR EL PRIMO MÁS CERCANO
       pos = clave % n;
       for( ;  ;)
       {
          if(vec[pos] != 0) // la celda esta ocupada
              pos++;
          else
              break;
          if(pos >= n)
              pos = 0;
       }
       return pos;
    }
    
    // METODO PARA BUSCAR UNA CLAVE
    public static int hashBuscar(int []vec, int clave, int n)
    {
       int pos, band = 0;
       pos = clave % n;
       for( ;  ; )
       {
           if(vec[pos] != clave)
               pos++;
           else
               break;
           if(pos >= n)
               pos = 0;
           band++;
           if(band > n)// SE RECORRIO TODO EL ARREGLO Y NO LO ENCONTRO
               return -1;
       }
       return pos;
    }
    
}

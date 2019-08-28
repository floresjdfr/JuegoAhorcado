/* 
 * File:   Manejador_Archivos.cpp
 * Author: Jose David
 * 
 * Created on August 22, 2019, 3:33 PM
 */

#include "Manejador_Archivos.h"

int Manejador_Archivos::contador_total_palabras(ifstream& diccionario){
    
    int contador = 0;
    string palabra;
    
    if(!diccionario.is_open()){
        cout << "No se pudo abrir el diccionario \n";
    }
    else {
        while(getline(diccionario, palabra, ',')){
            contador++;
        }
    }
    return contador;
    
    
}



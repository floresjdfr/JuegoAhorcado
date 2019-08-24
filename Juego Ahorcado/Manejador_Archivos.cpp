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







/*void Manejador_Archivos::leer_palabras(ifstream& diccionario, Palabras* palabras){
    string palabra;
    if(!diccionario.is_open()){
        cout << "No fue posible abrir el archivo \n";
    }
    else{
        while(getline(diccionario, palabra, ',')){
            palabras->agregar_palabra(palabra);
        } 
    }
}*/

/*Manejador_Archivos::guarda_juego(ofstream& archivo, Juego* juego){   **Hasta que juego este hecho lo implemento
    if(!archivo.is_open()){
        cout << "No fue posible abrir el archivo \n";
    }
    else{
        
        }
}*/


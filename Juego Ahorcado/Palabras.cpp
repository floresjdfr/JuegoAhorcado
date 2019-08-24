/* 
 * File:   Arreglo_Palabra.cpp
 * Author: Jose David
 * 
 * Created on August 22, 2019, 1:20 AM
 */

#include "Palabras.h"


Palabras::Palabras(ifstream& diccionario) {
    tamano = Manejador_Archivos::contador_total_palabras(diccionario);
    cantidad = 0;
    palabras = new string[tamano];
    for(int i = 0; i < tamano; i++){
        palabras[i] = "Nada";
    }
}


Palabras::~Palabras() {
}


string Palabras::to_string_palabras() const{
    
    stringstream s;
    s << "**PALABRAS: **" << endl;
    for(int i = 0; i < cantidad; i++){
        s << palabras[i] << "  ";
    }
    return s.str();
}

string Palabras::get_palabra(int posicion) const{
    return palabras[posicion];
}

string* Palabras::get_vector_palabras() const{
    return palabras;
}

int Palabras::get_cantidad() const{
    return cantidad;
}

int Palabras::get_tamano() const{
    return tamano;
}

void Palabras::agregar_palabra(ifstream& diccionario){
    string palabra;
    if(!diccionario.is_open()){
        cout << "No fue posible abrir el archivo \n";
    }
    else{
        while(getline(diccionario, palabra, ',')){
            
            palabras[cantidad++] = palabra;
        } 
    }
}
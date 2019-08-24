/* 
 * File:   Arreglo_Palabra.cpp
 * Author: Jose David
 * 
 * Created on August 22, 2019, 1:20 AM
 */

#include "Arreglo_Palabra.h"

Arreglo_Palabra::Arreglo_Palabra() {
    arreglo = new Palabra[50];
    tamano = 50;
    cantidad = 0;
    for (int i = 0; i < tamano; i++){
        arreglo[i] = Palabra("Sin definir");
    }
}
Arreglo_Palabra::Arreglo_Palabra(int tam) {
    tamano = tam;
    cantidad = 0;
    arreglo = new Palabra[tamano];
    for(int i = 0; i < tamano; i++){
        arreglo[i] = Palabra("Sin definir");
    }
}


Arreglo_Palabra::~Arreglo_Palabra() {
    delete[] arreglo;
    arreglo = NULL;
}

void Arreglo_Palabra::agregar_palabra(Palabra pal){
    if(cantidad < tamano){
        arreglo[cantidad++] = pal;
    }
    else {
        cout << "No es posible agregar mas palabras" << endl;
    }
}

string Arreglo_Palabra::to_string_arreglo_palabra() const{
    
    stringstream s;
    s << "**PALABRAS: **" << endl;
    for(int i = 0; i < cantidad; i++){
        s << arreglo[i].toStringPalabra();
    }
    return s.str();
}

int Arreglo_Palabra::get_tamano() const{
    return tamano;
}
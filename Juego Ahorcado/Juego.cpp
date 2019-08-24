/* 
 * File:   Juego.cpp
 * Author: Jose David
 * 
 * Created on August 22, 2019, 7:38 PM
 */

#include "Juego.h"

Juego::Juego() {
    jugadores = NULL;
    palabra = "Sin palabra";
}

Juego::Juego(Jugadores** jugad) {
    jugadores = jugad;
    palabra = "Sin palabra";
}

//Juego::~Juego() {
//}

Jugadores** Juego::get_jugadores() const{
    return jugadores;
}

string Juego::get_palabra() const{
    return palabra;
}


void Juego::jugar(int jugador){
    cout << jugadores->get_jugadores()[jugador - 1]->toStringPersona();
    adivina = palabra;
    string adivina_copia = palabra;
    int tamano;
    
    for(int i = 0; palabra[i] != '\0'; i++){
        adivina[i] = '*';
        adivina_copia[i] = '*';
        tamano++;
    }
    
    
    
}
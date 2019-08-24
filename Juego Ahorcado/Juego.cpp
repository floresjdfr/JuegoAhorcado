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
    adivina = "**";
    adivina_copia = "**";
}

//Juego::~Juego() {
//}

Jugadores** Juego::get_jugadores() const{
    return jugadores;
}

string Juego::get_palabra() const{
    return palabra;
}

void Juego::set_palabra(string pal){
    palabra = pal;
    for (int i = 0; palabra[i] != '\0' ; i++){
        adivina[i] = '_';
        adivina_copia[i] = '_';
        largo_palabra++;
    }
}

int Juego::get_largo_palabra() const{
    return largo_palabra;
}

string Juego::get_adivina() const{
    return adivina;
}

string Juego::get_adivina_copia() const{
    return adivina_copia;
}

void Juego::set_adivina(string ad){
    adivina = ad;
}

void Juego::set_adivina_copia(string ad){
    adivina = ad;
}
/*void Juego::jugar(int jugador){
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
 * 
 * */ 
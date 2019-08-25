/* 
 * File:   Juego.cpp
 * Author: Jose David
 * 
 * Created on August 22, 2019, 7:38 PM
 */

#include "Juego.h"
#include "Jugadores.h"

Juego::Juego() {
    jugadores = NULL;
    palabra = "Sin palabra";
}

Juego::Juego(Jugadores* jugad) {
    jugadores = jugad;
    palabra = "Sin palabra";
    adivina = "**";
    adivina_copia = "**";
}

//Juego::~Juego() {
//}

Jugadores* Juego::get_jugadores() const{
    return jugadores;
}

string Juego::get_palabra() const{
    return palabra;
}

void Juego::set_palabra(string pal){
    palabra = pal;
    for (int i = 0; palabra[i] != '\0' ; i++){
        adivina[i] = '*';
        adivina_copia[i] = '*';
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
bool Juego::jugar(string input, int posicion_jugador){ 
    for(int i = 0; i < largo_palabra; i++){
        if(palabra[i] == tolower(input[0]))
            adivina[i] = tolower(input[0]);
    }
    if(adivina == adivina_copia){
        jugadores->get_jugadores()[posicion_jugador]->set_nuevo_intento(); //intentos--
        return 0;
    }
    else 
        return 1;
    
}

bool Juego::verifica_palabra(string input){ //Si el jugador toma la desicion de adivinar palabra completa
    if(palabra == Utiles::to_lower(input))
        return 1;
    return 0;
}

bool Juego::ya_gano(){
    if(adivina == palabra)
        return 1;
    return 0;
}
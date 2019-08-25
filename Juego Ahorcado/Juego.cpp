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

Juego::Juego(int cant) {
    jugadores = new Jugadores(cant);
}

//Juego::~Juego() {
//}

Jugadores* Juego::get_jugadores() const{
    return jugadores;
}

string Juego::get_palabra() const{
    return palabra;
}

void Juego::set_palabra(Palabras palabras){
    
    palabra = palabras.get_palabra(rand() % palabras.get_tamano());
    adivina = palabra;
    adivina_copia = palabra;
    for (int i = 0; palabra[i] != '\0' ; i++){
        adivina[i] = '*';
        adivina_copia[i] = '*' ;
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
    adivina_copia = adivina;
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
   
    if(Utiles::to_lower(input) == this->get_palabra()){
        return true;
    }
    else{
        return false;
    }
}

bool Juego::ya_gano(){
    if(adivina == palabra)
        return 1;
    return 0;
}
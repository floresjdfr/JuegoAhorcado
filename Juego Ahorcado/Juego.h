/* 
 * File:   Juego.h
 * Author: Jose David
 *
 * Created on August 22, 2019, 7:38 PM
 */

#ifndef JUEGO_H
#define	JUEGO_H

#include "Jugadores.h"
#include "Arreglo_Palabra.h"
#include "Manejador_Archivos.h"
#include "Utiles.h"

class Juego {
public:
    Juego();
    Juego(Jugadores**);
    //virtual ~Juego();
    Jugadores** get_jugadores() const;
   string get_palabra() const;
   void jugar(int jugador);
private:
    Jugadores** jugadores;
    string palabra;
    string adivina;
    
};

#endif	/* JUEGO_H */


/* 
 * File:   Juego.h
 * Author: Jose David
 *
 * Created on August 22, 2019, 7:38 PM
 */

#ifndef JUEGO_H
#define	JUEGO_H


#include "Palabras.h"
#include "Manejador_Archivos.h"
#include "Utiles.h"

class Jugadores;

class Juego {
public:
    Juego();
    Juego(Jugadores**);
    //virtual ~Juego();
    Jugadores** get_jugadores() const;
   string get_palabra() const;
   string get_adivina() const;
   strig get_adivina_copia() const;
   //void jugar(int jugador);
   void set_palabra(string);
   void set_adivina(string);
   void set_adivina_copia(string);
   int get_largo_palabra() const;
private:
    Jugadores** jugadores;
    string palabra;
    string adivina;
    string adivina_copia;
    int largo_palabra;
    
};

#endif	/* JUEGO_H */


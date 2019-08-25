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
#include <string>
#include <stdlib.h>

class Jugadores;

class Juego {
public:
    Juego();
    Juego(int);
    //virtual ~Juego();
    Jugadores* get_jugadores() const;
   string get_palabra() const;
   string get_adivina() const;
   string get_adivina_copia() const;
   void set_palabra(Palabras);
   void set_adivina(string);
   void set_adivina_copia(string);
   int get_largo_palabra() const;
   bool verifica_palabra(string);
   bool ya_gano();
   bool jugar(string, int);
private:
    Jugadores* jugadores;
    string palabra;
    string adivina;
    string adivina_copia;
    int largo_palabra;
    
};

#endif	/* JUEGO_H */


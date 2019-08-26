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
#include "Jugadores.h"
#include <string>
#include <stdlib.h>

class Jugadores;

class Juego {
public:
    //Juego();
    Juego(int, ifstream&);
    virtual ~Juego();
    Jugadores* get_jugadores() const;
   string get_palabra() const;
   string get_adivina() const;
   string get_adivina_copia() const;
   void set_palabra();
   void set_adivina(string);
   void set_adivina_copia(string);
   int get_largo_palabra() const;
   bool verifica_palabra(string);
   bool ya_gano();
   bool jugar(string, int);
   bool ya_perdio(int);
   void preguntar_nombre(int); //Recibe cantidad jugadores
   string get_nombre_jugador(int); //Rertorna nombre jugador, recibe posicion jugador como parametro;
   Palabras* get_vector_palabras() const;
   void iniciar_palabras(ifstream&);
   string mostrar_dibujo(int); //Recibe como parametro la posicion del jugador en el arreglo
   string get_ganador(int); //Recibe posicion jugador en vector
   bool salir();
   void reporte_ganador(ofstream&, int);
   //void reporte_empate(ofstream&);
   void reporte_no_gane(ofstream&);
private:
    Jugadores* jugadores;
    Palabras* vector_palabras;
    string palabra;
    string adivina;
    string adivina_copia;
    int largo_palabra;
    
};

#endif	/* JUEGO_H */


/*
 * File:   Jugador.h
 * Author: Aslehy
 *
 * Created on 19 de agosto de 2019, 09:21 PM
 */

#ifndef PERSONA_H
#define	PERSONA_H
#include <iostream>
#include <sstream>
#include "Dibujo.h"



using namespace std;

class Persona {
    
private:
    string Nombre;
    int partidas_ganadas;
    int intentos;
    Dibujo* dibujo;
    
public:
    
    Persona(string);
    Persona();
    virtual ~Persona();
    void set_nombre(string);
    string get_nombre() const;
    int get_partidas_ganadas() const;
    void set_gane();
    int get_intentos() const;
    void set_nuevo_intento();
    string toStringPersona() const;
    Dibujo* get_dibujo() const;
    
    
    
    
    
    
    
    
    //Fecha* RetornaTiempoDisponible(int);
    
    

};


#endif	/* PERSONA_H */


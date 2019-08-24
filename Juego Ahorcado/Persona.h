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
using namespace std;


class Persona {
    
private:
    string Nombre;
    int partidas_ganadas;
    int intentos;
    
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
    //void jugar(string, char);
    //int verificar_posicion(string, char);
    
    
    
    
    
    
    
    //Fecha* RetornaTiempoDisponible(int);
    
    

};


#endif	/* PERSONA_H */


/*
 * File:   Jugador.h
 * Author: Jose David
 *
 * Created on 19 de agosto de 2019, 09:21 PM
 */

#ifndef PERSONA_H
#define	PERSONA_H
#include <iostream>
#include <sstream>
#include "Dibujo.h"



using namespace std;

class Usuario {
    
private:
    string nombre; //nombre de usuario
    string contrasena; //contrasena de usuario
    int intentos;
    Dibujo* dibujo;
    
public:
    Usuario(string, string, int, Dibujo*);
    Usuario();
    virtual ~Usuario();
    
    //Sets
    void set_nombre(string);
    void set_nuevo_intento(); //AUMENTA EN UNO EL ATRIBUTO INTENTOS
    void set_nuevo_intento(int);
    void setContrasena(string);
    
    //Gets
    string get_nombre() const;
    int get_intentos() const;
    Dibujo* get_dibujo() const;
    string getContrasena() const;
    
    
    //Otros
    string toString() const;
    
    
    
    
    
    
    
    
    
    //Fecha* RetornaTiempoDisponible(int);
    
    

};


#endif	/* PERSONA_H */


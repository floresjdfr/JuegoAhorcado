/* 
 * File:   Dibujo.h
 * Author: Jose David
 *
 * Created on August 24, 2019, 7:09 PM
 */

#ifndef DIBUJO_H
#define	DIBUJO_H
#include <iostream>
#include <sstream>

using namespace std;

class Dibujo {
public:
    Dibujo();
    string get_vector_dibujo() const; //RETORNA EL VECTOR QUE ES EL DIBUJO DEL AHORCADO
    string to_string_dibujo() const; //MUESTRA EL DIBUJO
    void set_vector(int); //el parametro es la cantidad de intentos restantes del jugador
private:
    string vector[6];
    string cabeza;
    string manos;
    string torzo;
    string pies;
};

#endif	/* DIBUJO_H */


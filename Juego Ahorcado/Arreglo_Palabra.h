/* 
 * File:   Arreglo_Palabra.h
 * Author: Jose David
 *
 * Created on August 22, 2019, 1:20 AM
 */

#ifndef ARREGLO_PALABRA_H
#define	ARREGLO_PALABRA_H

#include "Palabra.h"

class Arreglo_Palabra {
public:
    Arreglo_Palabra();
    Arreglo_Palabra(int);
    ~Arreglo_Palabra();
    void agregar_palabra(Palabra);
    string to_string_arreglo_palabra() const;
    int get_tamano() const;
private:
    Palabra* arreglo;
    int cantidad;
    int tamano;

};

#endif	/* ARREGLO_PALABRA_H */


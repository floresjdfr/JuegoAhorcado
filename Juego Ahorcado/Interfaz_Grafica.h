/* 
 * File:   Interfaz_Grafica.h
 * Author: Jose David
 *
 * Created on August 19, 2019, 2:45 PM
 */

#ifndef INTERFAZ_GRAFICA_H
#define	INTERFAZ_GRAFICA_H

#include "Jugadores.h"
#include <windows.h>

class Interfaz_Grafica {
public:
    virtual string to_string() const = 0;
    

};

#endif	/* INTERFAZ_GRAFICA_H */


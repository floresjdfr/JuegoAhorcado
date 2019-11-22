/* 
 * File:   Arreglo_Palabra.h
 * Author: Jose David
 *
 * Created on August 22, 2019, 1:20 AM
 */

/*CLASE QUE SE ENCARGA DE CREAR EL VECTOR DE PALABRAS Y ALMACENARLAS
 DEJANDOLAS DISPONIBLES PARA SER USADAS EN EL JUEGO*/

#ifndef PALABRAS_H
#define	PALABRAS_H
#include <fstream>
#include <sstream>
#include "Manejador_Archivos.h"



class Palabra {
public:
    Palabra(string);
    Palabra();
    ~Palabra();
    void setPalabra(string);
    string to_string() const;
    string get_palabra() const;
    
private:
    string palabra;
};

#endif	/* PALABRAS_H */


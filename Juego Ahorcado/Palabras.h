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



class Palabras {
public:
    Palabras(ifstream&);
    ~Palabras();
    string to_string_palabras() const;
    int get_cantidad() const;
    int get_tamano() const;
    string get_palabra(int) const;
    string* get_vector_palabras() const;
    void agregar_palabras(string);
private:
    string *palabras;
    int cantidad;
    int tamano;

};

#endif	/* PALABRAS_H */


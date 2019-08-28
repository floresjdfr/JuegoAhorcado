/* 
 * File:   Manejador_Archivos.h
 * Author: Jose David
 *
 * Created on August 22, 2019, 3:33 PM
 */


/*PEQUEÑA CLASE QUE SE ENCARGA DE SOLO RETORNAR EL TOTAL DE PALABRAS QUE SE ENCUENTRAN EN EL 
 ARCHIVO DE TEXTO DICCIONARIOS.TXT*/


#ifndef MANEJADOR_ARCHIVOS_H
#define	MANEJADOR_ARCHIVOS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Palabras;

class Manejador_Archivos {
    
public:
   
    static int contador_total_palabras(ifstream&);

 
};

#endif	/* MANEJADOR_ARCHIVOS_H */


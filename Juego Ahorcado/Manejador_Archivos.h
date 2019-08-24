/* 
 * File:   Manejador_Archivos.h
 * Author: Jose David
 *
 * Created on August 22, 2019, 3:33 PM
 */

#ifndef MANEJADOR_ARCHIVOS_H
#define	MANEJADOR_ARCHIVOS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Juego.h"
//#include "Palabras.h"

class Palabras;

class Manejador_Archivos {
    
public:
   
    //static void leer_palabras(ifstream&, Palabras*);
    static int contador_total_palabras(ifstream&);
    
    
    
    
    
    
 //   static void guarda_juego(ofstream&, Juego*);  Hasta que juego este hecho lo implemento
    


};

#endif	/* MANEJADOR_ARCHIVOS_H */


/* 
 * File:   Interfaz.h
 * Author: Jose David
 *
 * Created on August 19, 2019, 2:45 PM
 */

#ifndef INTERFAZ_H
#define	INTERFAZ_H

#include "Juego.h"
#include <windows.h>
#include <fstream>

class Interfaz {
public:
    void jugando();
    void agregar_palabras(ofstream&); //AGREGA UNA NUEVA PALABRA AL DICCIONARIO
    string leer_palabras_diccionario(ifstream&); //MUESTRA LAS PALABRAS DEL DICCIONARIO
    string reporte_ganadas_solo(ifstream&); //MUERTRA REPORTE DE PARTIDAS GANADAS DE UN JUGADOR
    string reporte_perdidas_solo(ifstream&); //MUERSTRA PARTIDAS PERDIDAS DE UN JUGADOR
    string reporte_ganadas(ifstream&); //MUERTRA REPORTE DE PARTIDAS GANADAS DE DOS JUGADORES
    string reporte_perdidas(ifstream&); //MUERSTRA PARTIDAS PERDIDAS DE DOS JUGADORES
    string mostrar_bienvenido();
    
    
};

#endif	/* INTERFAZ_GRAFICA_H */


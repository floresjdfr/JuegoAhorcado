/* 
 * File:   main.cpp
 * Author: Jose David
 *
 * Created on August 19, 2019, 2:09 PM
 */


#include <Windows.h>
#include <fstream>
#include "Interfaz_Grafica.h"
#include "Jugadores.h"
#include "Menu.h"
#include "Utiles.h"
#include "Manejador_Archivos.h"
#include "Arreglo_Palabra.h"

using namespace std;

/*
 * 
 */
int main() {

 
    Menu* menu = new Menu(5); 
    cout << menu->mostrar_menu();
    cout << menu->to_string();
    
    cout << "--------------------------------------------- \n \n";
    
    Jugadores* jugadores = new Jugadores(2);
    cout << jugadores->toString();
    cout << "Ojo jugador 1: " << endl;
    cout << jugadores->get_jugadores()[0]->get_nombre();

    
    delete menu, jugadores;
    
    cout << endl << "/////////////////////////////////////////////// \n \n";
    
    ifstream Diccionario;
    
    Diccionario.open("Diccionario.txt");
    Arreglo_Palabra* palabras = new Arreglo_Palabra(Manejador_Archivos::contador_total_palabras(Diccionario));
    Diccionario.close();
    
    Diccionario.open("Diccionario.txt");
    Manejador_Archivos::leer_palabras(Diccionario, palabras);
    
    
    
    Diccionario.close();
    
   cout << palabras->to_string_arreglo_palabra();
    
    
    
    
    
    cout << ("\n\nPresione enter para limpiar pantalla ");
    cin.get();
    
    Utiles::limpiar_pantalla();
    return 0;
}


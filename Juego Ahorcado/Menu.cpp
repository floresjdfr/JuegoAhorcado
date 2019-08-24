/* 
 * File:   Menu.cpp
 * Author: Jose David
 * 
 * Created on August 19, 2019, 2:49 PM
 */

#include "Menu.h"

Menu::Menu() {
    menu = new string[50];
    for(int i = 0; i < 50; i++){
        menu[i] = "Unknown";
    }
    cantidad_opciones = 0;
}
Menu::Menu(int n) { //Parametro sera cantidad de opciones en el menu
    cantidad_opciones = n;
    menu = new string[n];
    for(int i = 0; i < n; i++){
        menu[i] = "Unknown";
    }
    cantidad_opciones = n;
}


Menu::~Menu() {
    delete[] menu;
}

void Menu::set_cantidad_opciones(int n){
    cantidad_opciones = n;
}

Menu::get_cantidad_opciones() const{
    return cantidad_opciones;
}

string Menu::mostrar_menu() const { /*****************          FALTA AGREGAR LAS OPCIONES AL MENU               *****************/
    
    HANDLE color_consola;
    color_consola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color_consola, 11);
    
    stringstream s;
    
    s<< "           0000       0000        0000000       0000        00  00   00                 \n";
    s<< "          00 00      00  00       00           00  00      00   00   00                 \n";
    s<< "         00   00    00    00      00000       00    00    00    00   00                 \n";
    s<< "        00     00  00      00     00         00      00  00     00   00                 \n";
    s<< "       00       00000       00    0000000   00        0000      0000000                 \n";
    s << endl << endl;
    
    return s.str();
}

string Menu::to_string() const{
    HANDLE color_consola;
    color_consola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color_consola, 13);
    
    stringstream s;
    
    for (int i = 0; i < cantidad_opciones; i++){
        s << i + 1 << " " << menu[i] << endl;
    }
    
    
    
    return s.str();
}


void Menu::set_opcion(int posicion, string opcion){
    menu[posicion-1] = opcion;
}

/* 
 * File:   Menu.h
 * Author: Jose David
 *
 * Created on August 19, 2019, 2:49 PM
 */

#ifndef MENU_H
#define	MENU_H
#include "Interfaz_Grafica.h"

class Menu{
public:
    Menu();
    Menu(int); //Parametro es cantidad de opciones en el menu
    virtual ~Menu();
    string mostrar_menu() const;
    string to_string() const;
    void set_cantidad_opciones(int);
    int get_cantidad_opciones() const;
    void set_opcion(int, string); //Sirve para cambiar una a una las opciones del menu
    
private:
    string* menu;
    int cantidad_opciones;
};

#endif	/* MENU_H */


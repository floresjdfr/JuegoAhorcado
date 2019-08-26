/* 
 * File:   main.cpp
 * Author: Jose David
 *
 * Created on August 19, 2019, 2:09 PM
 */


#include "Interfaz.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main() {
    srand(time(0));
    Interfaz juego;
    
    juego.jugando();
    
    cout << "Presione enter para salir \n";
    cin.get();
    return 0;
}


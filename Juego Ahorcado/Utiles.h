/* 
 * File:   Utiles.h
 * Author: Jose David
 *
 * Created on August 19, 2019, 6:07 PM
 */

#ifndef UTILES_H
#define	UTILES_H
#ifdef _WIN32
#endif


#include "windows.h"

#include <iostream>

using namespace std;



class Utiles {
public:
    static void limpiar_pantalla();
    static string to_lower(string);
};

#endif


/* 
 * File:   Utiles.cpp
 * Author: Jose David
 * 
 * Created on August 19, 2019, 6:07 PM
 */

#include "Utiles.h"

void Utiles::limpiar_pantalla(){
#ifdef _WIN32  
    system("cls");
#else
    system("clear");
#endif
}
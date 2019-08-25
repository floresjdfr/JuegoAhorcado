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

string Utiles::to_lower(string palabra){
    string nueva_palabra;
    for(int i = 0; palabra[i] != '\0'; i++){
        nueva_palabra[i] = tolower(palabra[i]);
    }
    return nueva_palabra;
}
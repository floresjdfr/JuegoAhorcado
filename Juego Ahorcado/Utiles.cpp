/* 
 * File:   Utiles.cpp
 * Author: Jose David
 * 
 * Created on August 19, 2019, 6:07 PM
 */

#include "Utiles.h"
#include <ctype.h>
#include "string.h"

void Utiles::limpiar_pantalla(){
#ifdef _WIN32  
    system("cls");
#else
    system("clear");
#endif
}

string Utiles::to_lower(string palabra){
    
    for(int i = 0; palabra[i] != '\0'; i++){
        palabra[i] = tolower(palabra[i]);
    }
    return palabra;
}

bool Utiles::es_digito(string input){
    
    int verificacion = 0;
    int total_caracteres = 0;
    
    for (int i = 0; input[i] != '\0'; i++){
        total_caracteres++;
    }
    
    for(int i = 0; i < total_caracteres; i++){
        if(isdigit(input[i])){
            verificacion++;
        } 
    }
    
    if(total_caracteres == verificacion){
        return true;
    }
    else{
        return false;
    }
}
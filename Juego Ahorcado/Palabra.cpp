/* 
 * File:   Palabra.cpp
 * Author: Jose David
 * 
 * Created on August 19, 2019, 4:45 PM
 */

#include "Palabra.h"

Palabra::Palabra() {
    
}

Palabra::Palabra(string pal) {
    palabra = pal;
}

string Palabra::toStringPalabra() const{
    stringstream s;
    s << palabra << " ";
    return s.str();
}


string Palabra::get_palabra() const{
    return palabra;
}

void Palabra::set_palabra(string pal){
    palabra = pal;
}

Palabra::~Palabra() {
    
}


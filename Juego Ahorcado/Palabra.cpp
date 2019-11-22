/* 
 * File:   Arreglo_Palabra.cpp
 * Author: Jose David
 * 
 * Created on August 22, 2019, 1:20 AM
 */

#include "Palabra.h"


Palabra::Palabra(string pal) {
    palabra = pal; 
}
Palabra::Palabra() {
    palabra = " "; 
}
Palabra::~Palabra() {

}
string Palabra::to_string() const{
    
    stringstream s;
    s << palabra << endl;
    return s.str();
}
string Palabra::get_palabra() const{
    return palabra;
}

/* 
 * File:   Dibujo.cpp
 * Author: Jose David
 * 
 * Created on August 24, 2019, 7:09 PM
 */

#include "Dibujo.h"

Dibujo::Dibujo() {
    vector[0] = "       ------";
    vector[1] = "      |      |";
    vector[2] = "      |     ";
    vector[3] = "      |     ";
    vector[4] = "      |     ";
    vector[5] = "      |     ";
    cabeza = " 0 ";
    manos = "/|\\";
    torzo = " | ";
    pies = "/|\\";
}



string Dibujo::get_vector_dibujo() const{
    return vector[6];
}

string Dibujo::to_string_dibujo() const{
    stringstream s;
        for (int i = 0; i < 6; i++){
            s << vector[i] << endl;
        }
        return s.str();
}

void Dibujo::set_vector(int intento){
    if(intento == 1){
            vector[2] = vector[2] + cabeza;
        }
        if(intento == 2){
            vector[3] = vector[3] + manos;
        }
        if(intento == 3){
            vector[4] = vector[4] + torzo;
        }
        if(intento == 4){
            vector[5] = vector[5] + pies + "\n         Game Over";
        }
}


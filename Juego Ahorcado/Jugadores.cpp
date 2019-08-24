#include "Jugadores.h"


Jugadores::Jugadores(int t){  //Recive como parametro el total de personas que jugaran
    //El metodo es bastante general, si solo se quiere que hayan dos jugadores
    //Se verificara en la clase juego que el parametro sea el numero dos
    tam = t;
    this->vec = new Persona*[tam]; //Nuevo vector dinamico de jugadores dinamicos
    
    
    for(int i =0; i < tam;i++){
    
        vec[i] = new Persona("Sin nombre"); //Crea e inicializa cada jugador dinamico
    }
}

Jugadores::~Jugadores(){

    delete[] vec; //Borra vector dinamico
    vec = NULL; //Asegurandonos que memoria no esta en uso
}


int Jugadores::getTam(){
    return tam;
}

string Jugadores::toString() const{
    stringstream J;
    
    J << "Jugadores: " << endl;
    
    for (int i = 0; i < tam; i++){
        J << vec[i]->toStringPersona() << endl;
    }
    
    return J.str();
}
    
      
Persona** Jugadores::get_jugadores() const{
    return vec;
}
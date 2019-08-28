#include"Persona.h"

Persona::Persona(string nom)
{
    Nombre = nom;
    intentos = 0;
    dibujo = new Dibujo;
}
    
Persona::Persona(){
    Nombre = " ";
    intentos = 0;
    dibujo = new Dibujo;
}


Persona::~Persona(){
    delete dibujo;
}

void Persona::set_nombre(string nom){
    Nombre = nom;
}

string Persona::get_nombre() const{
    return Nombre;
}

void Persona::set_nuevo_intento() //Aumenta en uno el atributo intentos
{
    intentos++;
}

int Persona::get_intentos() const{
    return intentos;
}

string Persona::toStringPersona()const {
    stringstream r;
    r<<"El Nombre del Jugador es: "<< Nombre <<'\n';
    r << "Intentos fallidos: " << intentos << endl;
    return r.str();

}

Dibujo* Persona::get_dibujo() const{
    return dibujo;
}


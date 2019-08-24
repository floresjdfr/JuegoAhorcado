#include"Persona.h"

Persona::Persona(string nom)
{
    Nombre = nom;
    partidas_ganadas = 0;
    intentos = 0;
}
    
Persona::Persona(){
    Nombre = " ";
    partidas_ganadas = 0;
    intentos = 0;
}


Persona::~Persona(){}

void Persona::set_nombre(string nom){
    Nombre = nom;
}

string Persona::get_nombre() const{
    return Nombre;
}

void Persona::set_gane() //Aumenta en uno el atributo partidas_ganadas
{
    partidas_ganadas++;
}

int Persona::get_partidas_ganadas()const{
    return partidas_ganadas;
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
    r << "Partidas ganadas: " << partidas_ganadas << endl;
    r << "Intentos: " << intentos << endl;
    return r.str();

}

/*void Persona::jugar(string palabra, char letra){
    
}
/*int Persona::verificar_posicion(string palabra, char letra){
    for(int i = 0; i < strlen(palabra); i++ ){
        if(palabra[i] == letra)
            return i;
    }
}*/
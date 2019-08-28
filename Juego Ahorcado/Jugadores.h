/* 
 * File:  Jugadores.h
 * Author: Jose David
 *
 * Created on 19 de agosto de 2019, 09:47 PM
 */

#ifndef JUGADORES_H
#define	JUGADORES_H


#include  "Persona.h"


using namespace std;

class Jugadores{
private:
    int tam;
    Persona **vec;
    
public:
    Jugadores(int);
    void agregar(Persona *); 
    std::string toString()const;
    ~Jugadores();
    int getTam();
    Persona** get_jugadores() const; //RETORNA EL VECTOR DINAMICO DE PERSONAS

        
    

};


#endif	/* JUGADORES_H */


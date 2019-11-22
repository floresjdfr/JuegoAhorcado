#include"Usuario.h"

Usuario::Usuario(string nom, string contra, int inten, Dibujo* dib)
{
    nombre = nom;
    contrasena = contra;
    intentos = inten;
    dibujo = dib;
}
    
Usuario::Usuario(){
    nombre = " ";
    contrasena = " ";
    intentos = 0;
    dibujo = new Dibujo;
}


Usuario::~Usuario(){
    delete dibujo;
}


//Sets
void Usuario::set_nombre(string nom){
    nombre = nom;
}
void Usuario::set_nuevo_intento() //Aumenta en uno el atributo intentos
{
    intentos++;
}
void Usuario::set_nuevo_intento(int inten) //Aumenta en uno el atributo intentos
{
    intentos = inten;
}
void Usuario::setContrasena(string contra){
    contrasena = contra;
}



//Gets
string Usuario::get_nombre() const{
    return nombre;
}
int Usuario::get_intentos() const{
    return intentos;
}
Dibujo* Usuario::get_dibujo() const{
    return dibujo;
}
string Usuario::getContrasena() const{
    return contrasena;
}

//Otros
string Usuario::toString()const {
    stringstream r;
    r<<"Usuario: "<< Nombre <<'\n';
    r << "Intentos fallidos: " << intentos << endl;
    return r.str();
}




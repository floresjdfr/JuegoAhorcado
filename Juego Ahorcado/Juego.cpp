/* 
 * File:   Juego.cpp
 * Author: Jose David
 * 
 * Created on August 22, 2019, 7:38 PM
 */

#include "Juego.h"

/*Juego::Juego() {
    jugadores = new Jugadores(2);
    palabra = " ";
    adivina = " ";
    adivina_copia = " ";
    largo_palabra = 0;
}*/

Juego::Juego(int cant, ifstream& diccionario) {
    jugadores = new Jugadores(cant);
    vector_palabras = new Palabras(diccionario);
    palabra = " ";
    adivina = " ";
    adivina_copia = " ";
    largo_palabra = 0;
}

Juego::~Juego() {
    delete jugadores;
    delete vector_palabras;
    jugadores = NULL;
    vector_palabras = NULL;
}

Jugadores* Juego::get_jugadores() const{
    return jugadores;
}

string Juego::get_palabra() const{
    return palabra;
}

void Juego::set_palabra(){
    
    this->palabra = vector_palabras->get_palabra(rand() % vector_palabras->get_tamano());
    adivina = palabra;
    adivina_copia = palabra;
    for (int i = 0; palabra[i] != '\0' ; i++){
        adivina[i] = '*';
        adivina_copia[i] = '*' ;
        largo_palabra++;
    }
}

int Juego::get_largo_palabra() const{
    return largo_palabra;
}

string Juego::get_adivina() const{
    return adivina;
}

string Juego::get_adivina_copia() const{
    return adivina_copia;
}

void Juego::set_adivina(string ad){
    adivina = ad;
}

void Juego::set_adivina_copia(string ad){
    adivina = ad;
}
bool Juego::jugar(string input, int posicion_jugador){ 
    adivina_copia = adivina;
    for(int i = 0; i < largo_palabra; i++){
        if(palabra[i] == tolower(input[0]))
            adivina[i] = tolower(input[0]);
    }
    if(adivina == adivina_copia){
        jugadores->get_jugadores()[posicion_jugador]->set_nuevo_intento(); //intentos--
        cout << "Mal!!! \n";
        return 0;
        
    }
    else 
        cout << "Bien \n";
        return 1;
    
}

bool Juego::verifica_palabra(string input){ //Si el jugador toma la desicion de adivinar palabra completa
   
    if(Utiles::to_lower(input) == this->get_palabra()){
        return true;
    }
    else{
        return false;
    }
}

bool Juego::ya_gano(){
    if(adivina == palabra)
        return 1;
    return 0;
}

bool Juego::ya_perdio(int posicion){
    if(jugadores->get_jugadores()[posicion]->get_intentos() >= 4){
        return 1;
    }
    else{
        return 0;
    }
}

void Juego::preguntar_nombre(int cantidad){
    for(int i = 0; i < cantidad; i++){
        cout << "Nombre de jugador " << i + 1 << " " << endl;
        string nombre;
        getline(cin, nombre);
        jugadores->get_jugadores()[i]->set_nombre(nombre);
    }
}

string Juego::get_nombre_jugador(int posicion){
    return jugadores->get_jugadores()[posicion]->get_nombre();
}

Palabras* Juego::get_vector_palabras() const{
    return vector_palabras;
}


void Juego::iniciar_palabras(ifstream& diccionario){
    string palabra;
    while(getline(diccionario, palabra, ',')){
        vector_palabras->agregar_palabras(palabra);
    }
}


string Juego::mostrar_dibujo(int posicion){
    return jugadores->get_jugadores()[posicion]->get_dibujo()->to_string_dibujo();
}

string Juego::get_ganador(int posicion){
    return jugadores->get_jugadores()[posicion]->get_nombre();
}

bool Juego::salir(){
    string input;
    while(1){
        cout << "Desea salir ------------> presione 1" << endl;
        cout << "Desea continuar --------> presione 0" << endl;
        getline(cin, input);
        if(input == "1"){
            return true;
        }
        if(input == "0"){
            return false;
        }
        else{
            continue;
        }
    }
}

void Juego::reporte_ganador(ofstream& records, int posicion){
    //records.open("Records.txt");
    char delim_dato = '\t';
    char delim_final = '\n';
    if(records.is_open()){
        if(posicion == 0){
            
            records << jugadores->get_jugadores()[posicion]->get_nombre() << delim_dato << palabra << delim_dato <<  jugadores->get_jugadores()[posicion + 1]->get_nombre() << delim_final;
        }
        else{
            records << jugadores->get_jugadores()[posicion]->get_nombre() << delim_dato << palabra << delim_dato <<  jugadores->get_jugadores()[posicion - 1]->get_nombre() << delim_final;
        }
    }
    else{
        cout << "Error abriendo archivo rerpotes " << endl;
    }
    
    //records.close();
}

void Juego::reporte_no_gane(ofstream& records){
    char delim_dato = '\t';
    char delim_final = '\n';
    if(records.is_open()){
        records <<  jugadores->get_jugadores()[0]->get_nombre() << delim_dato << palabra << delim_dato <<  jugadores->get_jugadores()[1]->get_nombre() << delim_final;
    }
    else{
        cout << "Error abriendo archivo reportes" << endl;
    }
}
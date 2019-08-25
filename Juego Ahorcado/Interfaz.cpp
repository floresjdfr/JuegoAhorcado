/* 
 * File:   Interfaz_Grafica.cpp
 * Author: Jose David
 * 
 * Created on August 19, 2019, 2:45 PM
 */

#include "Interfaz.h"
#include "Jugadores.h"




bool Interfaz::jugando(){
    
bool salir = false;
srand (time(NULL));
    while(!salir){

        int intMenu;
        while(true){

            Utiles::limpiar_pantalla();
            cout << "Bienvenido \n \n";
            cout << "Que desea hacer: \n";
            cout << "1. Jugar \n";
            cout << "2. Agregar palabras al diccionario \n";
            cout << "3. Hacer trampa y ver las palabras del diccionario \n";
            cout << "4. Ver records \n";
            cout << "5. Salir \n";
            string opcion_menu;
            getline(cin, opcion_menu);
            if(Utiles::es_digito(opcion_menu)){
                stringstream s;
                s.str(opcion_menu);
                s >> intMenu;
                
                break;
            }
            else{
                Utiles::limpiar_pantalla();
                cout << "La opcion seleccionada no estaba dentro de las opciones disponibles \n";
                Sleep(2000);
                continue;
            }
        }
        cin.clear();
        switch(intMenu){
            case 1:{
                int cantidad_jug;
                while(1){
                    string cant_jugadores;

                    cout << "Cuantos jugadores: ";
                    getline(cin, cant_jugadores);
                    if(Utiles::es_digito(cant_jugadores)){
                        stringstream s;
                        s.str(cant_jugadores);
                        s >> cantidad_jug;
                        if(cantidad_jug > 0 && cantidad_jug < 3){
                            break;
                        }
                    }
                    else{
                        continue;
                    }

                }
                cin.clear();
                Juego* juego = new Juego(cantidad_jug);
                ifstream diccionario("Diccionario.txt");
                Palabras palabras(diccionario);
                diccionario.close();
                diccionario.open("Diccionario.txt");
                palabras.agregar_palabra(diccionario);
                diccionario.close();
                juego->set_palabra(palabras);
                Utiles::limpiar_pantalla();
                cout << "Empezando..." << endl;
                Sleep(2000);
                Utiles::limpiar_pantalla();
                while(juego->get_jugadores()->get_jugadores()[0]->get_intentos() <= 4){
                    if(!juego->ya_gano()){
                        
                        
                        

                        cout << juego->get_adivina() << endl;
                        cout << "Digite caracter: ";
                        string car;
                        cin >> car;
                        if(!juego->jugar(car,0)){
                            juego->get_jugadores()->get_jugadores()[0]->get_dibujo()->set_vector(juego->get_jugadores()->get_jugadores()[0]->get_intentos());
                        }

                        cout << juego->get_jugadores()->get_jugadores()[0]->toStringPersona() << endl;
                        cout << juego->get_jugadores()->get_jugadores()[0]->get_dibujo()->to_string_dibujo() << endl;
                        cin.ignore();
                        cin.get();
                        Utiles::limpiar_pantalla();
                    }
                    else{
                        cout << "Ha ganado!" << endl;
                        break;
                    }
                }
                cout << "Perdio" << endl;
                salir = true;
                break;
            }
        }



        /*stringstream s;
        string jugadores_string;
        int jugad;
        cout << "Maximo dos jugadores \n";
        cout << "Cuantos jugadores: ";
        cin.ignore();
        getline(cin, jugadores_string);
        Utiles::es_digito(jugadores_string);


        stringstream ent(jugadores_string);
        ent >> jugad;


        Jugadores* jugadores = new Jugadores(jugad);
        Juego* juego = new Juego(jugadores);
        juego->set_palabra("botella");

        juego->set_adivina("botella");

        if(juego->ya_gano()){
            cout << "Ganoooo \n";
        }
        else{
            cout << "Perdioooo \n";
        }

        if(juego->verifica_palabra("botella")){
            cout << "Usted gano" << endl;
        }
        else{
            cout <<"Perdio" << endl;
        }

        s  << juego->get_adivina() << endl;
        s << juego->get_palabra() << endl;

        */





    }

}
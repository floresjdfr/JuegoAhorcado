/* 
 * File:   Interfaz_Grafica.cpp
 * Author: Jose David
 * 
 * Created on August 19, 2019, 2:45 PM
 */

#include "Interfaz.h"




int Interfaz::jugando(){
    
bool salir = false;






    while(!salir){

        int intMenu;/*     ***MENU DE INICIO****/
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
                cout << "Presione enter ";
                cin.get();
                continue;
            }
        }
        
        
        
        switch(intMenu){
            case 1:{
                int cantidad_jug;
                while(1){ //ciclo para verificar que solo se introducen de 1 a dos jugadores
                    string cant_jugadores;
                    Utiles::limpiar_pantalla();
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
                
                switch(cantidad_jug){ //Uno o dos jugadores
                    
                    
                    /*****************************      CUANDO UN JUGADOR   ***************************************************/
                    
                    
                    case 1:{ //Un jugador inicio
                        //srand (time(NULL));//Se inicializa el random para que las palabras escogidas sean al azar
                        ifstream diccionario("Diccionario.txt");
                        Juego* juego = new Juego(cantidad_jug, diccionario); //Se crea juego
                        diccionario.close();
                        //diccionario.close();
                        diccionario.open("Diccionario.txt");
                        juego->iniciar_palabras(diccionario);
                        diccionario.close();
                        
                        
                        
                        Utiles::limpiar_pantalla();
                        
                        juego->preguntar_nombre(1); // Metodo para ingresar el nombre de los jugadores, recibe cantidad jugadores como parametro
                        cout << "Empezando..." << endl;
                        Sleep(2000);
                        juego->set_palabra(); //Se escoge una palabra al azar
                        
                        diccionario.open("Diccionario.txt");
                        juego->iniciar_palabras(diccionario);
                        diccionario.close();
                        Utiles::limpiar_pantalla();

                        while(!juego->ya_perdio(0)){ //Se verifica que jugador no haya perdido
                            
                            if(!juego->ya_gano()){ //Se verifica que no haya ganado
                                
                                cout << juego->mostrar_dibujo(0) << endl;
                                cout << juego->get_adivina() << endl;
                                cin.clear();
                                cout << "Digite letra " << juego->get_nombre_jugador(0) << " ";
                                string car;
                                getline(cin, car);
                                if(!juego->jugar(car,0)){
                                    juego->get_jugadores()->get_jugadores()[0]->get_dibujo()->set_vector(juego->get_jugadores()->get_jugadores()[0]->get_intentos());
                                }
                                Utiles::limpiar_pantalla();
                                cout << juego->get_jugadores()->get_jugadores()[0]->get_dibujo()->to_string_dibujo() << endl;
                                if(juego->salir()){ //****Si elige salir y no continuar
                                    cout << "Usted no gano" << endl;
                                    cout << "Presione enter ";
                                    cin.get();
                                    break;
                                    
                                }
                                
                                Utiles::limpiar_pantalla();
                            }
                            else{ //Si gano se ejecuta este codigo
                                //juego->get_jugadores()->get_jugadores()[0]->set_gane();
                                cout << "Jugador ganador: " << juego->get_ganador(0) << endl;
                                cout << "Adivino: " << juego->get_palabra() << endl;
                                cout << "Digite enter para continuar \n";
                                cin.get();
                                break;
                            }
                            
                        }
                        delete juego; // Se borra el objeto de juego
                        cin.clear();
                        break; //Final un jugador
                    }
                    
                    
                    
                    
                    /*****************************      CUANDO SON DOS JUGADORES   ***************************************************/
                    
                    
                    case 2:{
                        
                         
                        ifstream diccionario("Diccionario.txt");
                        Juego* juego = new Juego(cantidad_jug, diccionario); //Se crea juego
                        diccionario.close();
                        diccionario.open("Diccionario.txt");
                        juego->iniciar_palabras(diccionario);
                        diccionario.close();
                        
                        Utiles::limpiar_pantalla();
                        
                        
                        juego->preguntar_nombre(2); //Pregunta nombre jugudores
                        cout << "Empezando..." << endl;
                        Sleep(2000);
                        juego->set_palabra(); //Se escoge una palabra al azar
                        Utiles::limpiar_pantalla();

                        while(!juego->ya_perdio(0) || !juego->ya_perdio(1)){ //Lleva el control del juego, si ambos perdieron sale de la partida
                            
                            
                            
                            
                            
                            
                            
                            if(!juego->ya_perdio(0)){ //SI JUGADOR 1 NO HA PERDIDO ENTRA EN EL CODIGO
                                
                                    
                                    cout << juego->mostrar_dibujo(0) << endl; //Muestra dibujo
                                    cout << endl <<juego->get_adivina() << endl; // Se muestra la palabra que se tiene que adivinar
                                    cin.clear();
                                    cout << "Digite letra " << juego->get_nombre_jugador(0) << " ";
                                    string car;
                                    getline(cin, car);
                                    if(!juego->jugar(car,0)){
                                        juego->get_jugadores()->get_jugadores()[0]->get_dibujo()->set_vector(juego->get_jugadores()->get_jugadores()[0]->get_intentos());
                                    }

                                    
                                    Utiles::limpiar_pantalla();
                                    cout << juego->mostrar_dibujo(0) << endl;
                                    
                                    if(juego->ya_gano()){
                                        cout << "El ganador es: " << juego->get_ganador(0) << endl;
                                        cout << "Digite enter para salir ";
                                        cin.get();
                                        break;
                                    }
                                    else {
                                        if (juego->salir()){
                                            cout <<"El ganador sera su oponente, ya que usted se rindio" << endl;
                                            cout << "Ganador --> " << juego->get_ganador(1) << endl;
                                            cout << "Digite enter para salir ";
                                            cin.get();
                                            break;
                                        }
                                    }
    
                                    Utiles::limpiar_pantalla();
                                
                            }

                            
                            
                            
                            
                            
                            
                            if(!juego->ya_perdio(1)){ //SI JUGADOR DOS NO HA PERDIDO ENTRA EN EL CODIGO
                                
                                    cout << juego->mostrar_dibujo(1) << endl;
                                    cout << endl << juego->get_adivina() << endl;
                                    cout << "Digite letra " << juego->get_nombre_jugador(1) << " ";
                                    string car;
                                    getline(cin, car);
                                    if(!juego->jugar(car,1)){
                                        juego->get_jugadores()->get_jugadores()[1]->get_dibujo()->set_vector(juego->get_jugadores()->get_jugadores()[1]->get_intentos());
                                    }

                                    
                                    Utiles::limpiar_pantalla();
                                    cout << juego->mostrar_dibujo(1) << endl;
                                    
                                    if(juego->ya_gano()){
                                        cout << "El ganador es: " << juego->get_ganador(1) << endl;
                                        cout << "Digite enter para salir ";
                                        cin.get();
                                        break;
                                    }
                                    else {
                                        if (juego->salir()){
                                            cout <<"El ganador sera su oponente, ya que usted se rindio" << endl;
                                            cout << "Ganador --> " << juego->get_ganador(1) << endl;
                                            cout << "Digite enter para salir ";
                                            cin.get();
                                            break;
                                        }
                                    }
                                    Utiles::limpiar_pantalla();
                                }   
                        } //SALE DEL WHILE SI AMBOS PERDIENDON O SI ALGUNO GANO
                        //SI AMBOS PERDIERON ENTRA EN EL IF DE ABAJO
                        
                        if(juego->ya_perdio(0) && juego->ya_perdio(1)){
                            cout << "Ninguno de los jugadores ganaron" << endl;
                            cout << "La palabra era: " << juego->get_palabra() << endl;
                            cout << "Presione enter para salir ";
                            cin.get();
                        }
                        
                        
                        
                        //FINALIZA EL JUEGO
                        delete juego;
                        break; 
                    }
                }
                
                
 
            break; //FINALIZA OPCION JUGAR
            } 
            
            
            
            
    
            
            case 2:{ //OPCION DOS DEL MENU PRINCIPAL
                
                cout << "No disponible de momento \n";
                cout << "Presione enter \n";
                cin.get();
                break;
            }
            
            
            
            
            
            
            
            
            
            case 3:{ //OPCION TRES DEL MENU PRINCIPAL
                
                cout << "No disponible de momento \n";
                cout << "Presione enter \n";
                cin.get();
                break;
            }
            
            
            
            case 4: { //OPCION CUATRO DEL MENU PRINCIPAL
                cout << "No disponible de momento \n";
                cout << "Presione enter \n";
                cin.get();
                break;
            }
            
            
            
            
            case 5:{ //OPCION CINCO DEL MENU PRINCIPAL
                return 1; 
                break;
            }
        }



        



    }

}
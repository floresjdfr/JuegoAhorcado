/* 
 * File:   Interfaz_Grafica.cpp
 * Author: Jose David
 * 
 * Created on August 19, 2019, 2:45 PM
 */

#include "Interfaz.h"




void Interfaz::jugando(){
    
bool salir = false;






    while(!salir){

        int intMenu;/*     ***MENU DE INICIO****/
        while(true){
             
            Menu: //ESTA OPCION NOS AYUDA A SALIR DE LOS SWITCHES
            
            cout <<this->mostrar_bienvenido();
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
                while(1){ //ciclo para verificar que solo se introducen de uno a dos jugadores
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
                       
                        ifstream diccionario("Diccionario.txt");
                        Juego* juego = new Juego(cantidad_jug, diccionario); //Se crea juego
                        diccionario.close();
                        
                        diccionario.open("Diccionario.txt");
                        juego->iniciar_palabras(diccionario); //METODO PARA INDRODUCIR LAS PALABRAS DEL ARCHIVO AL VECTOR DE PALABRAS
                        diccionario.close();
                        
                        
                        Utiles::limpiar_pantalla();
                        
                        juego->preguntar_nombre(1); // Metodo para ingresar el nombre de los jugadores, recibe cantidad jugadores como parametro
                        cout << "Empezando..." << endl;
                        Sleep(2000);
                        juego->set_palabra(); //METODO PARA ESCOGER UNA PALABRA AL AZAR
                        
                        
                        Utiles::limpiar_pantalla();

                        while(!juego->ya_perdio(0)){ //Se verifica que jugador no haya perdido
                            
                            if(!juego->ya_gano()){ //Se verifica que no haya ganado
                                
                                cout << juego->mostrar_dibujo(0) << endl;
                                cout << juego->get_adivina() << endl;
                                cin.clear();
                                cout << "Digite letra " << juego->get_nombre_jugador(0) << " ";
                                string car;
                                getline(cin, car);
                                
                                Utiles::limpiar_pantalla();
                                
                                
                                if(!juego->jugar(car,0)){
                                    juego->get_jugadores()->get_jugadores()[0]->get_dibujo()->set_vector(juego->get_jugadores()->get_jugadores()[0]->get_intentos());
                                }
                                
                                
                                cout << juego->get_jugadores()->get_jugadores()[0]->get_dibujo()->to_string_dibujo() << endl;  //MUESTRA DIBUJO
                                
                                if(juego->salir()){ //****Si elige salir y no continuar
                                    
                                    
                                    //OBJETO OFSTREAM PARA CREAR EL REPORTE                       **Nota: por alguna razon ios::app no sirve
                                    ofstream reporte_solo("Perdidas_un_jugador.txt"/*,ios::app*/);
                                    juego->reporte_no_gane_solo(reporte_solo);
                                    reporte_solo.close();
                                    
                                    
                                    cout << "Usted no gano porque se rindio" << endl;
                                    cout << "La palabra oculta era: " << juego->get_palabra() << endl;
                                    cout << "Intentos fallidos: " << juego->get_jugadores()->get_jugadores()[0]->get_intentos() << endl;
                                    cout << "Presione enter ";
                                    cin.get();
                                    Utiles::limpiar_pantalla();
                                    break;
                                    
                                }
                                
                                Utiles::limpiar_pantalla();
                            }
                            else{ //Si gano se ejecuta este codigo
                                
                                //CREO UN OBJETO OFSTREAM PARA REPORTAR GANE
                                ofstream gane_solo("Reporte_ganadas_solo.txt");
                                juego->reporte_solo(gane_solo);
                                gane_solo.close();
                                
                                cout << "Jugador ganador: " << juego->get_ganador(0) << endl;
                                cout << "Adivino: " << juego->get_palabra() << endl;
                                cout << "Intentos fallidos: " << juego->get_jugadores()->get_jugadores()[0]->get_intentos() << endl;
                                cout << "Presione enter para salir ";
                                cin.get();
                                Utiles::limpiar_pantalla();
                                break;
                            }
                            
                        }
                        
                        if(juego->ya_perdio(0)){
                            ofstream reporte_solo("Perdidas_un_jugador.txt"/*,ios::app*/);
                            juego->reporte_no_gane_solo(reporte_solo);
                            reporte_solo.close(); 
                            
                            cout << "Usted perdio, no pudo adivinar la palabra oculta" << juego->get_palabra() << endl;
                            cout << "Intentos fallidos: " << juego->get_jugadores()->get_jugadores()[0]->get_intentos() << endl;
                            cout << "Presione enter para salir ";
                            cin.get();
                            Utiles::limpiar_pantalla();
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
                        juego->iniciar_palabras(diccionario); //SE INICIALIZAN LAS PALABRAS
                        diccionario.close();
                        
                        Utiles::limpiar_pantalla();
                        
                        
                        juego->preguntar_nombre(2); //Pregunta nombre jugudores
                        cout << "Empezando..." << endl;
                        Sleep(2000);
                        juego->set_palabra(); //Se escoge una palabra al azar
                        Utiles::limpiar_pantalla();

                        while(!juego->ya_perdio(0) || !juego->ya_perdio(1)){ //Lleva el control del juego, si ambos perdieron sale de la partida
                            
                            
                            
                            
                            
                            
                            
                            if(!juego->ya_perdio(0)){ //SI JUGADOR 1 NO HA PERDIDO ENTRA EN EL CODIGO
                                
                                
                                     
                                    cout << juego->mostrar_dos_dibujos(); //Muestra dibujo
                                    cout << endl <<juego->get_adivina() << endl; // Se muestra la palabra que se tiene que adivinar
                                    cin.clear();
                                    cout << "Digite letra " << juego->get_nombre_jugador(0) << " ";
                                    string car;
                                    getline(cin, car);
                                    Utiles::limpiar_pantalla();
                                    if(!juego->jugar(car,0)){
                                        juego->get_jugadores()->get_jugadores()[0]->get_dibujo()->set_vector(juego->get_jugadores()->get_jugadores()[0]->get_intentos());
                                    }
                                    
                                    cout << juego->mostrar_dos_dibujos(); //Muestra dibujo
                                    
                                    
                                    
                                    
                                    if(juego->ya_gano()){
                                        Utiles::limpiar_pantalla();
                                        cout << "El ganador es: " << juego->get_ganador(0) << endl;
                                        cout << "Adivino la palabra: " << juego->get_palabra() << endl;
                                        cout << "Intentos fallidos: " << juego->get_jugadores()->get_jugadores()[0]->get_intentos() << endl;
                                        
                                        //GENERANDO REPORTE DEL GANE
                                           
                                        ofstream reporte_ganador("Ganadas_dos_jugadores.txt"/*, ios::app*/);
                                        juego->reporte_ganador(reporte_ganador, 0);
                                        reporte_ganador.close();
                                        
                                        
                                        cout << "Digite enter para salir ";
                                        cin.get();
                                        break;
                                    }
                                    else {
                                        if (juego->salir()){
                                            Utiles::limpiar_pantalla();
                                            cout <<"El ganador sera su oponente, ya que usted se rindio" << endl;
                                            cout << "Ganador --> " << juego->get_ganador(1) << endl;
                                            
                                            //GENERANDO REPORTE DE GANADOR
                                            ofstream reporte_ganador("Ganadas_dos_jugadores.txt"/*, ios::app*/);
                                            juego->reporte_ganador(reporte_ganador, 1);
                                            reporte_ganador.close();
                                            
                                            cout << "Digite enter para salir ";
                                            cin.get();
                                            break;
                                        }
                                    }
                                    
    
                                    Utiles::limpiar_pantalla();
                                
                            }

                            
                           
                            
                            
                             //SI JUGADOR 2 NO HA PERDIDO ENTRA EN EL CODIGO
                            
                            if(!juego->ya_perdio(1)){ 
                                
                                    cout << juego->mostrar_dos_dibujos();
                                    cout << endl << juego->get_adivina() << endl;
                                    cout << "Digite letra " << juego->get_nombre_jugador(1) << " ";
                                    string car;
                                    getline(cin, car);
                                    Utiles::limpiar_pantalla();
                                    if(!juego->jugar(car,1)){
                                        juego->get_jugadores()->get_jugadores()[1]->get_dibujo()->set_vector(juego->get_jugadores()->get_jugadores()[1]->get_intentos());
                                    }

                                    
                                    
                                    cout << juego->mostrar_dos_dibujos();
                                    
                                    if(juego->ya_gano()){
                                        Utiles::limpiar_pantalla();
                                        cout << "El ganador es: " << juego->get_ganador(1) << endl;
                                        cout << "Palabra adivinada: " << juego->get_palabra() << endl;
                                        cout << "Digite enter para salir ";
                                        
                                        
                                        //GENERANDO REPORTE DEL GANE
                                           
                                        ofstream reporte_ganador("Ganadas_dos_jugadores.txt"/*, ios::app*/);
                                        juego->reporte_ganador(reporte_ganador, 1);
                                        reporte_ganador.close();
                                        
                                        
                                        cin.get();
                                        break;
                                    }
                                    else {
                                        if (juego->salir()){
                                            Utiles::limpiar_pantalla();
                                            cout <<"El ganador sera su oponente, ya que usted se rindio" << endl;
                                            cout << "Ganador --> " << juego->get_ganador(0) << endl;
                                            
                                            
                                             //GENERANDO REPORTE DEL GANE
                                           
                                            ofstream reporte_ganador("Ganadas_dos_jugadores.txt"/*, ios::app*/);
                                            juego->reporte_ganador(reporte_ganador, 0);
                                            reporte_ganador.close();
                                            
                                            
                                            
                                            cout << "Digite enter para salir ";
                                            cin.get();
                                            break;
                                        }
                                    }
                                    Utiles::limpiar_pantalla();
                                }   
                        } 
                        
                        
                        
                        
                        //SI AMBOS PERDIERON ENTRA EN EL IF DE ABAJO
                        
                        if(juego->ya_perdio(0) && juego->ya_perdio(1)){
                            
                            Utiles::limpiar_pantalla();
                            cout << "Ninguno de los jugadores ganaron" << endl;
                            cout << "La palabra era: " << juego->get_palabra() << endl;
                            
                            
                            //GENERANDO REPORTE DE PARTIDA
                            
                            ofstream reporte("Ningun_gane.txt"/*, ios::spp*/);
                            juego->reporte_no_gane(reporte);
                            reporte.close();
                            
                            
                            cout << "Presione enter para salir ";
                            cin.get();
                            Utiles::limpiar_pantalla();
                        }
                        
                        
                        
                        
                        //FINALIZA EL JUEGO
                        delete juego;
                        break; 
                    }
                }
                
                
 
            break; //FINALIZA OPCION JUGAR
            } 
            
            
            
            
    
            
            //****************************************************OPCION DOS DEL MENU PRINCIPAL AGREGAR PALABRA AL DICCIONARIO**************************************************

            case 2:{ 
                
                ofstream diccionario("Diccionario.txt"/*, ios::app*/);
                this->agregar_palabras(diccionario);
                diccionario.close();
                cout << "Palabra agregada" << endl;
                cout << "Presione enter \n";
                cin.get();
                break;
            }
            
            
            
            
            
            //******************************** OPCION TRES DEL MENU PRINCIPAL, HACER TRAMPA Y VER LAS PALABRAS DEL DICCIONARIO
        
            case 3:{ 
                Utiles::limpiar_pantalla();
                ifstream diccionario("Diccionario.txt");
                cout << this->leer_palabras_diccionario(diccionario);
                diccionario.close();
                cout << "Presione enter \n";
                cin.get();
                Utiles::limpiar_pantalla();
                break;
            }
            
            
            //***************************** LA OPCION CUATRO MUESTRA LOS RECORDS DE LAS PARTIDAS*******************************
            case 4: { 
                
                while(1){
                    Utiles::limpiar_pantalla();
                    cout << "1. Reporte de partidas ganadas de un jugador" << endl;
                    cout << "2. Reporte de partidas perdidas de un jugador" << endl;
                    cout << "3. Reporte de partidas ganadas de dos jugadores" << endl;
                    cout << "4. Reporte de partidas perdidas de dos jugadores" << endl;
                    cout << "5. Salir" << endl;
                    cout << "Que desea hacer: ";
                    string opcion;
                    int int_opcion;
                    getline(cin, opcion);
                    if(Utiles::es_digito(opcion)){
                        stringstream s;
                        s.str(opcion);
                        s >> int_opcion;
                        
                    }
                    else{
                        continue;
                    }
                    
                    switch(int_opcion){
                        case 1:{
                            
                            ifstream reporte("Reporte_ganadas_solo.txt");
                            cout << this->reporte_ganadas_solo(reporte);
                            reporte.close();
                            
                            cout << "Presione enter " ;
                            cin.get();
                            break;
                        }
                        case 2:{
                            ifstream reporte("Perdidas_un_jugador.txt");
                            cout << this->reporte_perdidas_solo(reporte);
                            reporte.close();
                            
                            cout << "Presione enter " ;
                            cin.get();
                            break;
                        }
                        
                        case 3:{
                            
                            ifstream reporte("Ganadas_dos_jugadores.txt");
                            cout << this->reporte_ganadas(reporte);
                            reporte.close();
                            
                            
                            cout << "Presione enter " ;
                            cin.get();
                            break; 
                        }
                        
                        case 4: {
                            ifstream reporte("Ningun_gane.txt");
                            cout << this->reporte_perdidas(reporte);
                            reporte.close();
                            
                            
                            cout << "Presione enter " ;
                            cin.get();
                            break; 
                        }
                        case 5:{
                            Utiles::limpiar_pantalla();
                            goto Menu;
                        }
                        break;
                        
                        default:{
                            cout << "Opcion invalida" << endl;
                            break;
                        }
                            
                    }
                }
                cin.get();
                break;
            }
            
            
            
            
            case 5:{ //OPCION CINCO DEL MENU PRINCIPAL ---> SALIR
                exit (EXIT_SUCCESS);
                break;
            }
        }



        



    }

}



void Interfaz::agregar_palabras(ofstream& diccionario){
    if(diccionario.is_open()){
        string palabra;
        cout << "Que palabra desea agregar: ";
        getline(cin, palabra);
        diccionario << palabra << ',';
    }
    else{
        cout << "No se pudo abrir el diccionario" << endl;
    }
}


string Interfaz::leer_palabras_diccionario(ifstream& diccionario){
    if(diccionario.is_open()){
        string palabra;
        stringstream s;
        s << "**Palabras**" << endl;
        while(getline(diccionario, palabra, ',')){
            s << palabra << endl;
        }
        return s.str();
    }
    else{
        cout << "Error abriendo el diccionario" << endl;
    }
}


string Interfaz::reporte_ganadas_solo(ifstream& reporte){
    stringstream s;
    if(reporte.is_open()){
        string nombre;
        string palabra;
        
        while(!reporte.fail()&&!reporte.eof()){
            getline(reporte, nombre, '\t');
            getline(reporte, palabra, ',');
            s << "Ganador: " << nombre << "     ---> adivino: " << palabra << endl;
        }
    }
    else{
        s << "No se pudo abrir el reporte" << endl;
    }
    return s.str();
}

string Interfaz::reporte_perdidas_solo(ifstream& reporte){
    stringstream s;
    if(reporte.is_open()){
        string nombre;
        string palabra;
        
        while(!reporte.fail()&&!reporte.eof()){
            getline(reporte, nombre, '\t');
            getline(reporte, palabra, ',');
            s << "Perdedor: " << nombre << "     ---> no adivino: " << palabra << endl;
        }
    }
    else{
        s << "No se pudo abrir el reporte" << endl;
    }
    return s.str();
}

string Interfaz::reporte_ganadas(ifstream& reporte){
    stringstream s;
    if(reporte.is_open()){
        string nombre;
        string nombre2;
        string palabra;
        
        while(!reporte.fail()&&!reporte.eof()){
            getline(reporte, nombre, '\t');
            getline(reporte, palabra, '\t');
            getline(reporte, nombre2, ',');
            s << "Ganador: " << nombre << "     ---> adivino: " << palabra << "      ---> Perdedor: " << nombre2 << endl;
        }
    }
    else{
        s << "No se pudo abrir el reporte" << endl;
    }
    return s.str();
}

string Interfaz::reporte_perdidas(ifstream& reporte){
    stringstream s;
    if(reporte.is_open()){//so el reporte esta abierto es porque el archivo sirve, por lo tanto no lo ocupa verificar en el while
      //recuerde siempre cerrar el archivo fisico
      
        string nombre;
        string nombre2;
        string palabra;
        
        
        while(!reporte.fail()&&!reporte.eof()){
        getline(reporte, nombre, '\t');
        getline(reporte, nombre2, '\t');
        getline(reporte, palabra, ',');
            
        s << nombre << "  y  " << nombre2 << "  --->  empataron, y no puedieron adivinar la palabra: " << palabra << endl;
        }
    }
    else{
        s << "No se pudo abrir el reporte" << endl;
    }
    return s.str();
}


string Interfaz::mostrar_bienvenido(){
    stringstream s;
    s << "****************************** BIENVENIDO AL JUEGO DEL AHORCADO ********************************" << endl;
    s << "                              ***********************************" << endl;
    s << "                              * Por Jose David Flores Rodriguez *" << endl;
    s << "                              ***********************************" << endl;
    return s.str();
    
}
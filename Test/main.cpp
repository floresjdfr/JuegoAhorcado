/* 
 * File:   main.cpp
 * Author: Jose David
 *
 * Created on August 23, 2019, 9:45 PM
 */
 


/*
 * 

 * 
 * 
 * */


#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;


int main()
{
   
    
    int intentos = 5;
    string palabra = "calculadora";
    string adivinar = palabra;
    string adivinar_copia = palabra;
    
    int largo_palabra = 0; 
    
    for (int i = 0; palabra[i] != '\0' ; i++){
        adivinar[i] = '_';
        adivinar_copia[i] = '_';
        largo_palabra++;
    }
    while(intentos != 0){
        system("clear");
        cout << "Palabra a adivinar:              " << adivinar << endl;
        cout << "Digite caracter: ";
        string caracter;
        getline(cin, caracter);
        
        for(int i = 0; i < largo_palabra; i++){
            if(palabra[i] == tolower(caracter[0])){
                adivinar[i] = tolower(caracter[0]);
            }
        }
        if(adivinar == palabra){
            system("clear");
            cout << "Usted adivino la palabra: --->  " << palabra << endl;
            break;
        }
        if(adivinar == adivinar_copia){
            intentos--;
        }
        else{
            adivinar_copia = adivinar;
        }
    }
    
    if(intentos == 0){
        system("clear");
        cout << "No pudo adivinar la palabra, perdedor \n";
    }
    
   
   return 0;
}

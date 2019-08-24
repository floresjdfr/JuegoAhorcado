/* 
 * File:   main.cpp
 * Author: Jose David
 *
 * Created on August 24, 2019, 12:40 AM
 */

#include <iostream>
#include <sstream>
#include <windows.h>
using namespace std;

class Dibujo{
private:
    string vector[6];
    string cabeza;
    string manos;
    string torzo;
    string pies;
    
public:
    Dibujo(){
    vector[0] = "       ------";
    vector[1] = "      |      |";
    vector[2] = "      |     ";
    vector[3] = "      |     ";
    vector[4] = "      |     ";
    vector[5] = "      |     ";
    cabeza = " 0 ";
    manos = "/|\\";
    torzo = " | ";
    pies = "/|\\";
    }
    
    string get_vector() {
        return vector[6];
    }
    string to_string() const{
        stringstream s;
        for (int i = 0; i < 6; i++){
            s << vector[i] << endl;
        }
        return s.str();
    }
    void set_vector(int intento){
        if(intento == 3){
            vector[2] = vector[2] + cabeza;
        }
        if(intento == 2){
            vector[3] = vector[3] + manos;
        }
        if(intento == 1){
            vector[4] = vector[4] + torzo;
        }
        if(intento == 0){
            vector[5] = vector[5] + pies + "\n         Game Over";
        }
    }
    
};

int main(int argc, char** argv) {

    
    
    
     
    int intentos = 4;
    Dibujo dibujo;
    
    
    while(intentos >= 0){
        system("clear");
        intentos--;
        dibujo.set_vector(intentos);
        cout << dibujo.to_string();
        Sleep(1000);
        
       
        
    }
    
    
    return 0;
}






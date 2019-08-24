/* 
 * File:   Palabra.h
 * Author: Jose David
 *
 * Created on August 19, 2019, 4:45 PM
 */

#ifndef PALABRA_H
#define	PALABRA_H

#include <iostream>
#include <sstream>

using namespace std;


class Palabra {
public:
    Palabra();
    Palabra(string);
    ~Palabra();
    string get_palabra() const;
    void set_palabra(string);
    string toStringPalabra() const;
    
private:
    string palabra;
};

#endif	/* PALABRA_H */


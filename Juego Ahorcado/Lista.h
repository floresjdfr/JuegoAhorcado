/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: Jose David
 *
 * Created on November 21, 2019, 6:41 PM
 */


#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <iostream>

template <class T>
class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void agregar(T*);
private:
    Nodo<T>* actual;
    Nodo<T>* primero;
};

#endif /* LISTA_H */


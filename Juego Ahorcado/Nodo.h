/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Jose David
 *
 * Created on November 21, 2019, 6:38 PM
 */

#ifndef NODO_H
#define NODO_H

template <class T>
struct Nodo {
public:
    T* info; //elemento
    Nodo* sig; //Nodo siguiente
};

#endif /* NODO_H */


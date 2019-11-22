/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: Jose David
 * 
 * Created on November 21, 2019, 6:41 PM
 */

#include "Lista.h"

Lista::Lista() {
    primero = NULL;
    actual = NULL;
}
Lista::Lista(const Lista& orig) {
    primero = orig.primero;
    actual = orig.actual;
}
Lista::~Lista() {
}
void Lista::agregar(T* elem){
    actual = primero;
    Nodo<T>* aux;
    aux->info = elem;
    
    if(actual == NULL){
        primero = aux;
    }
    else{
        while(actual->sig != NULL){
            actual = actual->sig;
        }
        actual->sig = aux;
    }
}



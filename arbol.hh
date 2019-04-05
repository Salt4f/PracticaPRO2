/** @file arbol.hh
 * 
*/

#ifndef ARBOL_HH
#define ARBOL_HH

#include <iostream>
using namespace std;

/**
 * 
*/
struct Nodo
{
    string str; ///Carácter
    int freq;   ///Frecuencia
};

/**
 * 
*/
class Arbol
{
private:
    Nodo nodo;
    Arbol & izq;
    Arbol & der;
public:
    Arbol(Nodo & nodo);

    Arbol(Nodo & nodo, Nodo & izquierda, Nodo & derecha);

    void modificar_izquierda(Arbol & nodo);

    void modificar_derecha(Arbol & nodo);

    Arbol consultar_izquierda() const;

    Arbol consultar_derecha() const;
};

#endif

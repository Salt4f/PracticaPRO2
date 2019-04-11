/** @file idioma.hh
 * 
*/

#ifndef IDIOMA_HH
#define IDIOMA_HH

#include "arbol.hh"

#include <iostream>
#include <list>
using namespace std;

/**
 * 
*/
class Idioma
{
private:
    string nombre;
    list< pair<char,int> > tabla;
    Arbol treecode;

    void rehacer_arbol();
    void leer_tabla();

public:
    Idioma(string nombre);

    void modificar_idioma();

    string consultar_nombre() const;

    void escribir_tabla() const;

    void escribir_codigos() const;

    bool es_del_idioma(char c) const;

    string codificar_caracter(char c) const;

    string descodificar(string texto) const;
};


#endif
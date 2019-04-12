/** @file idioma.hh
 * 
*/

#ifndef IDIOMA_HH
#define IDIOMA_HH

#include "treecode.hh"
#include "freqtable.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
#endif

using namespace std;

/**
 * 
*/
class Idioma
{
private:
    FreqTable tabla;
    Treecode treecode;

    void rehacer_arbol();
    void leer_tabla();

public:
    Idioma();

    void modificar_idioma();

    void escribir_tabla() const;

    void escribir_codigos() const;

    bool es_del_idioma(char c) const;

    string codificar_caracter(char c) const;

    string descodificar(string texto) const;
};


#endif
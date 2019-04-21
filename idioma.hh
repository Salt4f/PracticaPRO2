/** @file Idioma.hh
 * 
*/

#ifndef IDIOMA_HH
#define IDIOMA_HH

#include "Codigo.hh"
#include "FreqTable.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/**
 * 
*/
class Idioma
{
private:
    FreqTable tabla;
    Codigo codigos;

    void rehacer_codigos();
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
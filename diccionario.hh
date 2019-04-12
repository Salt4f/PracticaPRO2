/** @file diccionario.hh
 * 
*/

#ifndef DICCIONARIO_HH
#define DICCIONARIO_HH

#include "idioma.hh"

#include <map>
using namespace std;

class Diccionario {
private:
    map<string, Idioma> diccionario;
    
    map<string, Idioma>::iterator buscar_idioma(string nombre);

public:
    Diccionario();

    void anadir_idioma(string nombre);

    void modificar_idioma(string nombre);

    bool esta_idioma(string nombre) const;

    void escribir_tabla_frecuencias(string nombre) const;

    void escribir_treecode(string nombre) const;

    void escribir_codigos(string nombre) const;

    string codifica(string nombre, string texto) const;

    string descodifica(string nombre, string texto) const;

};

#endif
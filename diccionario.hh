/** @file diccionario.hh
 * 
*/

#ifndef DICCIONARIO_HH
#define DICCIONARIO_HH

#include "idioma.hh"
#include "arbol.hh"

#include <map>
using namespace std;

class Diccionario {
private:
    map<string, Idioma> dic;
    
    map<string, Idioma>::const_iterator buscar_idioma(string nombre);

public:
    Diccionario();

    void anadir_idioma(Idioma & idioma);

    void eliminar_idioma(string nombre);

    bool esta_idioma(string nombre) const;

    Idioma consultar_idioma(string nombre);

    string codifica(string nombre, string texto) const;

    string descodifica(string nombre, string texto) const;

};

#endif
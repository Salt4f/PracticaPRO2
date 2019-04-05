/** @file idioma.hh
 * 
*/

#ifndef IDIOMA_HH
#define IDIOMA_HH

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
public:
    Idioma(string nombre);

    void leer_tabla();

    void escribir_tabla() const;
};


#endif
/** @file Codigo.hh
 * 
*/

#ifndef CODIGO_HH
#define CODIGO_HH

#include "BinTree.hh"
#include "FreqTable.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
using namespace std;
#endif

class Codigo {
private:
    BinTree< pair<string, int> > treecode;

    map<string, string> codetable;

    /**@brief Codifica el carácter <b>c</b>
    * 
    * Recorre el <b>treecode</b>
    */
    void codifica_caracter(char c);

public:
    Codigo();

    Codigo(const FreqTable & tabla);

    string codifica(string texto) const;

    string descodifica(string texto) const;

    void escribir_arbol() const;

    void escribir_codigos() const;
};


#endif
/** @file Codigo.hh
 *  @brief Especificación de la clase FreqTable
*/

#ifndef CODIGO_HH
#define CODIGO_HH

#include "FreqTable.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#endif

/** @class Codigo
    @brief Representa el <b>TreeCode</b> y la <b>codeTable</b> de un Idioma
*/
class Codigo {
private:
    BinTree< pair<string, int> > treecode;

    map<string, string> codetable;

    /** @brief Codifica el carácter <b>c</b>
    * 
    * Recorre el <b>treecode</b>
    */
    string codifica_caracter(string c, const BinTree< pair<string, int> >& tree) const;

public:
    /** @brief Constructora por defecto

      Se ejecuta automáticamente al declarar un Codigo
      \pre <b>true</b>
      \post El resultado es un Codigo vacío (<em>treecode</em> y <em>codetable</em> vacío)
    */ 
    Codigo();

    /** @brief Constructora

      Se ejecuta automáticamente al declarar un Codigo
      \pre La FreqTable <em>tabla</em> no está vacía
      \post El resultado es un Codigo con <em>treecode</em> y <em>codetable</em>
    */ 
    Codigo(const FreqTable & tabla);

    /** @brief Codifica un texto
      \pre El Codigo no está vacío
      \return El texto codificado
      \param texto - Texto a codificar
    */
    string codifica(string texto) const;

    /** @brief Descodifica un texto
      \pre El Codigo no está vacío
      \return El texto descodificado
      \param texto - Texto a descodificar
    */
    string descodifica(string texto) const;

    /** @brief Escribe el <b>treecode</b>
      \pre <b>true</b>
      \post Escribe por el canal de salida el <b>treecode</b>
    */
    void escribir_arbol() const;

    /** @brief Escribe la <b>codetable</b>
      \pre <b>true</b>
      \post Escribe por el canal de salida la <b>codetable</b>
    */
    void escribir_codigos(string c) const;
};


#endif

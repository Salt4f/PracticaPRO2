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
    @brief Representa el <b>TreeCode</b> y la <b>codetable</b> de un Idioma
*/
class Codigo {
private:
    ///El <b>TreeCode</b> en sí
    BinTree< pair<string, int> > treecode;

    ///La <b>codetable</b> en sí
    map<string, string> codetable;

    /** @brief Codifica los carácteres y rellena la <b>codeTable</b>
     * \pre El <b>TreeCode</b> no está vacío
     * \post La <b>codetable</b> está rellena con las codificaciones
     * \param path - Camino actual
     * \param tree - Árbol actual
    */
    void codifica_caracteres(string& path, const Arbol& tree);

    ///Escribe un árbol en preorden
    void escribe_preorden(const Arbol& tree) const;

    ///Escribe un árbol en inorden
    void escribe_inorden(const Arbol& tree) const;

    /** @brief Recorre el <b>TreeCode</b> y descodifica
     * \pre El <b>TreeCode</b> no está vacío
     * \return <b>true</b> + texto descodificado o <b>false</b> + última posición descodificable
     * \param texto - Texto a descodificar
     * \param descodificado - Texto descodifacado por el momento
     * \param tree - Árbol el que se está mirando
     * \param i - Posición del texto
     * \param pos - Última posición descodificable por el momento
    */
    pair<bool,string> descodifica_recursiva(const string& texto, string& descodificado, const Arbol& tree, int i, int pos) const;

public:
    /** @brief Constructora por defecto

      Se ejecuta automáticamente al declarar un Codigo
      \pre <b>true</b>
      \post El resultado es un Codigo vacío (<em>TreeCode</em> y <em>codetable</em> vacío)
    */ 
    Codigo();

    /** @brief Constructora

      Se ejecuta automáticamente al declarar un Codigo
      \pre La FreqTable <em>tabla</em> no está vacía
      \post El resultado es un Codigo con <em>TreeCode</em> y <em>codetable</em>
    */ 
    Codigo(const FreqTable & tabla);

    /** @brief Codifica un texto
      \pre <b>true</b>
      \return El texto codificado o un mensaje de error
      \param texto - Texto a codificar
    */
    string codifica(const string& texto) const;

    /** @brief Descodifica un texto
      \pre <b>true</b>
      \return El texto descodificado o un mensaje de error
      \param texto - Texto a descodificar
    */
    pair<bool,string> descodifica(const string& texto) const;

    /** @brief Escribe el <b>treecode</b>
      \pre <b>true</b>
      \post Escribe por el canal de salida el <b>treecode</b>
    */
    void escribir_arbol() const;

    /** @brief Escribe la <b>codetable</b>
      \pre <b>true</b>
      \post Escribe por el canal de salida la <b>codetable</b> o un mensaje de error
      \param c - Carácter a escribir su código o la palabra <em>todos</em>
    */
    void escribir_codigos(string c) const;
};


#endif

/** @file FreqTable.hh
 *  @brief Especificación de la clase FreqTable
*/

#ifndef FREQTABLE_HH
#define FREQTABLE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <set>
#include "BinTree.hh"
using namespace std;
#endif

///Árbol
typedef BinTree<pair<string,int> > Arbol;

///@brief Necesaria para ordenar la Lista
struct Comp {
	bool operator()(const Arbol& a, const Arbol& b) const {
        if (a.value().second == b.value().second) return a.value().first < b.value().first;
        return a.value().second < b.value().second;
    }
};

///Lista de Árboles ordenada según las condiciones para hacer el <b>TreeCode</b>
typedef set<Arbol,Comp> Lista;

/** @class FreqTable
    @brief Representa una tabla de frecuencias de un Idioma
*/
class FreqTable {
private:
    
    ///La FreqTable en sí
    map<string, int> table;

public:
    /** @brief Constructora

      Se ejecuta automáticamente al declarar una FreqTable
      \pre <b>true</b>
      \post El resultado es una FreqTable vacía
    */
    FreqTable();

    /** @brief Lee la FreqTable
      \pre En el canal de entrada se encuentran los datos de la FreqTable
      \post Cambia la FreqTable
    */
    void leer_tabla();

    /** @brief Escribe la FreqTable
      \pre <b>true</b>
      \post Escribe por el canal de salida la FreqTable
    */
    void escribir_tabla() const;
    
    /** @brief Devuelve los elementos de la tabla en una lista ordenada (set)
     * \pre <b>true</b>
     * \return Lista ordenada con los elementos de la FreqTable
    */
    Lista elementos() const;
};


#endif

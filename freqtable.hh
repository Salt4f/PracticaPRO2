/** @file FreqTable.hh
 *  @brief Especificación de la clase FreqTable
*/

#ifndef FREQTABLE_HH
#define FREQTABLE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
using namespace std;
#endif

/** @class FreqTable
    @brief Representa una tabla de frecuencias de un Idioma
*/
class FreqTable {
private:
    
    map<string, int> table;

public:
    /** @brief Constructora

      Se ejecuta automáticamente al declarar una FreqTable
      \pre <b>true</b>
      \post El resultado es una FreqTable vacía
    */
    FreqTable();

    /** @brief Modifica el Idioma
      \pre En el canal de entrada se encuentran los datos de la FreqTable
      \post Cambia la FreqTable
    */
    void leer_tabla();

    /** @brief Escribe la FreqTable
      \pre <b>true</b>
      \post Escribe por el canal de salida la FreqTable
    */
    void escribir_tabla() const;

    /**
      \pre <b>true</b>
      \return La frecuencia de <em>c</em> si está en la FreqTable, <b>-1</b> si no está
      \param c - string a mirar su frecuencia
    */
    int frecuencia(string c) const;
};


#endif
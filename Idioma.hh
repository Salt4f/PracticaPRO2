/** @file Idioma.hh
 *  @brief Especificación de la clase Idioma
*/

#ifndef IDIOMA_HH
#define IDIOMA_HH

#include "Codigo.hh"
#include "FreqTable.hh"

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @class Idioma
    @brief Representa un Idioma

    Contiene la tabla de frecuencias (FreqTable) y el <em>Treecode</em> de dicho Idioma
*/
class Idioma
{
private:
    ///La FreqTable del Idioma
    FreqTable tabla;

    ///Los Codigo del Idioma
    Codigo codigos;

    ///Rehace los Codigo
    void rehacer_codigos();

public:
    /** @brief Constructora

      Se ejecuta automáticamente al declarar un Idioma
      \pre En el canal de entrada se encuentran los datos de la FreqTable
      \post El resultado es un Idioma con la FreqTable y el Treecode
    */ 
    Idioma();

    /** @brief Modifica el Idioma
      \pre En el canal de entrada se encuentran los datos de la FreqTable
      \post Cambia la FreqTable y calcula un nuevo <em>Treecode</em>
    */
    void modificar_idioma();

    /** @brief Escribe la FreqTable del Idioma
      \pre <b>true</b>
      \post Escribe por el canal de salida la FreqTable
    */
    void escribir_tabla() const;

    /** @brief Escribe el <b>Treecode</b> del Idioma
      \pre <b>true</b>
      \post Escribe por el canal de salida el <b>Treecode</b>
    */
    void escribir_treecode() const;

    /** @brief Escribe la tabla de códigos del Idioma
      \pre <b>true</b>
      \post Escribe por el canal de salida la tabla de códigos
    */
    void escribir_codigos(string c) const;

    /** @brief Codifica un texto
      \pre <b>true</b>
      \return El texto codificado o un mensaje de error
      \param texto - Texto a codificar
    */
    string codificar(const string& texto) const;

    /** @brief Descodifica un texto
      \pre <b>true</b>
      \return El texto descodificado o un mensaje de error
      \param texto - El texto a descodificar
    */
    pair<bool,string> descodificar(const string& texto) const;
};


#endif

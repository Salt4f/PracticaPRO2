/** @file Diccionario.hh
 *  @brief Especificación de la clase Diccionario
*/

#ifndef DICCIONARIO_HH
#define DICCIONARIO_HH

#include "Idioma.hh"

#ifndef NO_DIAGRAM
#include <map>
using namespace std;
#endif

/** @class Diccionario
    @brief Representa un conjunto de Idioma

    Contiene distintos Idioma
*/
class Diccionario {
private:
    ///El Diccionario en sí
    map<string, Idioma> diccionario;

public:
    /** @brief Constructora

      Se ejecuta automáticamente al declarar un Diccionario
      \pre <b>true</b>
      \post El resultado es un Diccionario vacío
    */ 
    Diccionario();

    /** @brief Modifica/Añade un Idioma del Diccionario
      \pre <b>true</b>
      \post Modifica/Añade el Idioma del/al Diccionario
      \param nombre - Nombre del Idioma a modificar/añadir
      \param inicio - Necesario para evitar un output al inicio del programa
    */
    void modificar_idioma(string nombre, bool inicio);

    /** @brief Escribe la FreqTable de un Idioma del Diccionario
      \pre <b>true</b>
      \post Escribe por el canal de salida la FreqTable si el Idioma está en el Diccionario, si no escribe un mensaje de error
      \param nombre - Nombre del Idioma a escribir su FreqTable
    */
    void escribir_tabla_frecuencias(string nombre) const;

    /** @brief Escribe el <b>Treecode</b> de un Idioma del Diccionario
      \pre <b>true</b>
      \post Escribe por el canal de salida el <b>Treecode</b> si el Idioma está en el Diccionario, si no escribe un mensaje de error
      \param nombre - Nombre del Idioma a escribir su <b>Treecode</b>
    */
    void escribir_treecode(string nombre) const;

    /** @brief Escribe la lista de códigos de un Idioma del Diccionario
      \pre En el canal de entrada se encuentra el código a escribir o la palabra <em>todos</em>
      \post Escribe por el canal de salida la lista de códigos si el Idioma está en el Diccionario, si no escribe un mensaje de error
      \param nombre - Nombre del Idioma a escribir su lista de códigos
    */
    void escribir_codigos(string nombre) const;

    /** @brief Codifica un texto
      \pre <b>true</b>
      \return Texto codificado según el <b>Treecode</b> del Idioma o mensaje de error
      \param nombre    - Nombre del Idioma a usar para codificar
      \param texto     - Texto a codificar
    */
    string codifica(string nombre, string texto) const;

    /** @brief Codifica un texto
      \pre <b>true</b>
      \return Texto descodificado según el <b>Treecode</b> del Idioma o mensaje de error
      \param nombre    - Nombre del Idioma a usar para descodificar
      \param texto     - Texto a descodificar
    */
    string descodifica(string nombre, string texto) const;

};

#endif

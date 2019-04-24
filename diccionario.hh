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
    @brief Representa un conjunto de Idioma. 

    Contiene distintos Idioma
*/
class Diccionario {
private:
    map<string, Idioma> diccionario;
    
    map<string, Idioma>::iterator buscar_idioma(string nombre);

public:
    /** @brief Constructora

      Se ejecuta automáticamente al declarar un Diccionario
      \pre <b>true</b>
      \post El resultado es un Diccionario vacío
    */ 
    Diccionario();

    /** @brief Añade un Idioma al Diccionario
      \pre El Idioma a añadir no está en el Diccionario
      \post Añade un idioma al Diccionario
      \param nombre - Nombre del Idioma a añadir
    */
    void anadir_idioma(string nombre);

    /** @brief Modifica un Idioma del Diccionario
      \pre El Idioma a modificar está en el Diccionario
      \post Modifica el Idioma del Diccionario
      \param nombre - Nombre del Idioma a modificar
    */
    void modificar_idioma(string nombre);

    /** @brief Escribe la FreqTable de un Idioma del Diccionario
      \pre El Idioma a escribir su FreqTable está en el Diccionario
      \post Escribe por el canal de salida la FreqTable
      \param nombre - Nombre del Idioma a escribir su FreqTable
    */
    void escribir_tabla_frecuencias(string nombre) const;

    /** @brief Escribe el <b>Treecode</b> de un Idioma del Diccionario
      \pre El Idioma a escribir su <b>Treecode</b> está en el Diccionario
      \post Escribe por el canal de salida el <b>Treecode</b>
      \param nombre - Nombre del Idioma a escribir su <b>Treecode</b>
    */
    void escribir_treecode(string nombre) const;

    /** @brief Escribe la lista de códigos de un Idioma del Diccionario
      \pre El Idioma a escribir su lista de códigos está en el Diccionario
      \post Escribe por el canal de salida la lista de códigos
      \param nombre - Nombre del Idioma a escribir su lista de códigos
    */
    void escribir_codigos(string nombre) const;

    /** @brief Codifica un texto
      \pre El Idioma a usar para codificar está en el Diccionario
      \return Texto codificado según el <b>Treecode</b> del Idioma
      \param nombre    - Nombre del Idioma a usar para codificar
      \param texto     - Texto a codificar
    */
    string codifica(string nombre, string texto) const;

    /** @brief Codifica un texto
      \pre El Idioma a usar para descodificar está en el Diccionario
      \return Texto descodificado según el <b>Treecode</b> del Idioma
      \param nombre    - Nombre del Idioma a usar para descodificar
      \param texto     - Texto a descodificar
    */
    string descodifica(string nombre, string texto) const;

};

#endif
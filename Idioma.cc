/** @file Idioma.cc
 *  @brief Implementación de la clase Idioma
*/

#include "Idioma.hh"
using namespace std;

Idioma::Idioma() {
    tabla.leer_tabla();
    rehacer_codigos();
}

void Idioma::modificar_idioma() {
    tabla.leer_tabla();
    rehacer_codigos();
}

void Idioma::escribir_tabla() const {
    tabla.escribir_tabla();
}

void Idioma::escribir_treecode() const {
    codigos.escribir_arbol();
}

void Idioma::escribir_codigos(string c) const {
    codigos.escribir_codigos(c);
}

bool Idioma::es_del_idioma(string c) const {
    return tabla.esta(c);
}

string Idioma::codificar(const string& texto) const {
    return codigos.codifica(texto);
}

string Idioma::descodificar(const string& texto) const {
    return codigos.descodifica(texto);
}

void Idioma::rehacer_codigos() {
    Codigo nuevo_codigo(tabla);
    codigos = nuevo_codigo;
}


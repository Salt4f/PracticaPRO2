/** @file Diccionario.cc
 *  @brief Implementación de la clase Diccionario
*/

#include "Diccionario.hh"
using namespace std;

Diccionario::Diccionario() {}

void Diccionario::modificar_idioma(string nombre) {
    map<string,Idioma>::iterator it = diccionario.find(nombre);
    if (it != diccionario.end()) {
        it->second.modificar_idioma();
    }
    else {
        Idioma idioma_nuevo;
        diccionario.insert(make_pair(nombre, idioma_nuevo));
    }
}

void Diccionario::escribir_tabla_frecuencias(string nombre) const {
    map<string,Idioma>::const_iterator it = diccionario.find(nombre);
    if (it != diccionario.end()) {
        it->second.escribir_tabla();
    }
    else cout << "El idioma " << nombre << " no existe" << endl;
}

void Diccionario::escribir_treecode(string nombre) const {
    map<string,Idioma>::const_iterator it = diccionario.find(nombre);
    if (it != diccionario.end()) {
        it->second.escribir_treecode();
    }
    else cout << "El idioma " << nombre << " no existe" << endl;
}

void Diccionario::escribir_codigos(string nombre) const {
    map<string,Idioma>::const_iterator it = diccionario.find(nombre);
    if (it != diccionario.end()) {
        it->second.escribir_codigos();
    }
    else cout << "El idioma " << nombre << " no existe" << endl;
}

string Diccionario::codifica(string nombre, string texto) const {
    map<string,Idioma>::const_iterator it = diccionario.find(nombre);
    if (it != diccionario.end()) {
        return it->second.codificar(texto);
    }
    return "El idioma " + nombre + " no existe";
}

string Diccionario::descodifica(string nombre, string texto) const {
    map<string,Idioma>::const_iterator it = diccionario.find(nombre);
    if (it != diccionario.end()) {
        return it->second.descodificar(texto);
    }
    return "El idioma " + nombre + " no existe";
}
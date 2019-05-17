/** @file Diccionario.cc
 *  @brief Implementación de la clase Diccionario
*/

#include "Diccionario.hh"
using namespace std;

Diccionario::Diccionario() {}

void Diccionario::modificar_idioma(string nombre, bool inicio) {
    map<string,Idioma>::iterator it = diccionario.find(nombre);
    if (it != diccionario.end()) {
        it->second.modificar_idioma();
        cout << "Modificado " << nombre << endl << endl;
    }
    else {
        Idioma idioma_nuevo;
        diccionario.insert(make_pair(nombre, idioma_nuevo));
        if (!inicio) cout << "Anadido " << nombre << endl << endl;
    }
}

void Diccionario::escribir_tabla_frecuencias(string nombre) const {
    map<string,Idioma>::const_iterator it = diccionario.find(nombre);
    cout << "Tabla de frecuencias de " << nombre << ":" << endl;
    if (it != diccionario.end()) {
        it->second.escribir_tabla();
    }
    else cout << "El idioma no existe" << endl;
    cout << endl;
}

void Diccionario::escribir_treecode(string nombre) const {
    map<string,Idioma>::const_iterator it = diccionario.find(nombre);
    cout << "Treecode de " << nombre << ":" << endl;
    if (it != diccionario.end()) {
        it->second.escribir_treecode();
    }
    else cout << "El idioma no existe" << endl;
    cout << endl;
}

void Diccionario::escribir_codigos(string nombre) const {
    map<string,Idioma>::const_iterator it = diccionario.find(nombre);
    string c;
    cin >> c;
    if (c == "todos") cout << "Codigos de " << nombre << ":" << endl;
    else cout << "Codigo de " << c << " en " << nombre << ":" << endl;
    if (it != diccionario.end()) {
        it->second.escribir_codigos(c);
    }
    else if (c == "todos") cout << "El idioma no existe" << endl;
    else cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
    cout << endl;
}

string Diccionario::codifica(string nombre, string texto) const {
    cout << "Codifica en " << nombre << " el texto:" << endl << texto << endl;
    map<string,Idioma>::const_iterator it = diccionario.find(nombre);
    if (it != diccionario.end()) {
        return it->second.codificar(texto);
    }
    return "El idioma no existe";
}

string Diccionario::descodifica(string nombre, string texto) const {
    cout << "Decodifica en " << nombre << " el texto:" << endl << texto << endl;
    map<string,Idioma>::const_iterator it = diccionario.find(nombre);
    if (it != diccionario.end()) {
        string descodificado = it->second.descodificar(texto);
        if (descodificado.substr(0, 2) == "-1") return "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " + descodificado.substr(2);
        return descodificado;
    }
    return "El idioma no existe";
}
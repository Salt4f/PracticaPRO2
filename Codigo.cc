/** @file Codigo.hh
 *  @brief Implementación de la clase FreqTable
*/

#include "Codigo.hh"
using namespace std;

bool comp(pair<string,int>& a, pair<string,int>& b) {
    return a.second <= b.second;
}

void insercion(list<pair<string,int> >& lista, pair<string,int>& elemento) {
    bool completado = false;
    for (list<pair<string,int> >::iterator it = lista.begin(); !completado; ++it) {
        if (elemento.second <= it->second) {
            lista.insert(it, elemento);
            completado = true;
        }
        else if (it == lista.end()) {
            lista.insert(it, elemento);
            completado = true;
        }
    }
}

Codigo::Codigo() {}

Codigo::Codigo(const FreqTable & tabla) {
    list<pair<string, int> > lista = tabla.elementos();
    sort(lista.begin(), lista.end(), comp);
    while (lista.size != 1) {
        list<pair<string,int> >::iterator it = lista.begin();
        string str = it->first;
        int f = it->second;
        BinTree<pair<string,int> > left(*it);
        it = lista.erase(it);
        str += it->first;
        f += it->second;
        BinTree<pair<string,int> > right(*it);
        it = lista.erase(it);
        BinTree<pair<string,int> > aux(make_pair(str, f), left, right);
        insercion(lista, make_pair(str, f));
    }
}

string Codigo::codifica(string texto) const {
    string codificado;
    bool invalid = false;
    for (int i = 0; i != texto.length() and !invalid; ++i) {
        map<string,string>::const_iterator it = codetable.find(texto.substr(i,1));
        if (it != codetable.end()) codificado += it->second;
        else invalid = true;
    }
    if (invalid) return texto + " no es del idioma";
    return codificado;
}

string Codigo::descodifica(string texto) const {
    string descodificado;
    return texto;
}

void Codigo::escribir_arbol() const {

}

void Codigo::escribir_codigos() const {
    for (map<string,string>::const_iterator it = codetable.begin(); it != codetable.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

string Codigo::codifica_caracter(string c, const BinTree< pair<string, int> >& tree) const {
    if (tree.value().first == c) return "";
    if (!tree.left().empty() and tree.left().value().first.find(c) != string::npos) return "0" + codifica_caracter(c, tree.left());
    return "1" + codifica_caracter(c, tree.right());
}

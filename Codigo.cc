/** @file Codigo.hh
 *  @brief Implementación de la clase FreqTable
*/

#include "Codigo.hh"
using namespace std;

string next_symbol(const string& s, int& i) {
    if (s[i] >= 0) {
        ++i;
        return string(1, s[i-1]);
    }
    i += 2;
    return string(s, i-2, 2);
}

Codigo::Codigo() {}

Codigo::Codigo(const FreqTable & tabla) {
    set<Arbol, Comp> listaTree = tabla.elementos();
    while (listaTree.size() > 1) {
        set<Arbol,Comp>::iterator it = listaTree.begin();
        Arbol left = *it;
        it = listaTree.erase(it);
        string str1 = left.value().first;
        int f = left.value().second;
        Arbol right = *it;
        string str2 = right.value().first;
        f += right.value().second;
        it = listaTree.erase(it);
        string str;
        if (str1 < str2) str = str1 + str2;
        else str = str2 + str1;
        Arbol aux(make_pair(str, f), left, right);
        listaTree.insert(aux);
    }
    treecode = *listaTree.begin();
    listaTree.clear();

    string str = "";
    codifica_caracteres(str,treecode);
}

string Codigo::codifica(const string& texto) const {
    string codificado;
    bool invalid = false;
    int i = 0;
    string _char;
    while (i < texto.length() and !invalid) {
        _char = next_symbol(texto, i);
        map<string,string>::const_iterator it = codetable.find(_char);
        if (it != codetable.end()) codificado += it->second;
        else invalid = true;
    }
    if (invalid) return "El texto no pertenece al idioma; primer caracter que falla: " + _char;
    return codificado;
}

string Codigo::descodifica(const string& texto) const {
    string descodificado;
    return texto;
}

void Codigo::escribir_arbol() const {
    cout << "recorrido en preorden:" << endl;
    escribe_preorden(treecode);
    cout << "recorrido en inorden:" << endl;
    escribe_inorden(treecode);
}

void Codigo::escribir_codigos(string c) const {
    if (c == "todos") {
        for (map<string,string>::const_iterator it = codetable.begin(); it != codetable.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
    }
    else {
        map<string,string>::const_iterator it = codetable.find(c);
        if (it != codetable.end()) cout << it->first << " " << it->second << endl;
        else cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
    }
}

void Codigo::codifica_caracteres(string& path, const Arbol& tree) {
    if (tree.left().empty() and tree.right().empty()) {
        codetable.insert(make_pair(tree.value().first, path));
        return;
    }
    else if (!tree.left().empty()) {
        string new_path = path + "0";
        codifica_caracteres(new_path, tree.left());
    }
    string new_path = path + "1";
    codifica_caracteres(new_path, tree.right());
}

void Codigo::escribe_preorden(const Arbol& tree) const {
    if (!tree.empty()) {
        cout << tree.value().first << " " << tree.value().second << endl;
        escribe_preorden(tree.left());
        escribe_preorden(tree.right());
    }
}

void Codigo::escribe_inorden(const Arbol& tree) const {
    if (!tree.empty()) {
        escribe_inorden(tree.left());
        cout << tree.value().first << " " << tree.value().second << endl;
        escribe_inorden(tree.right());
    }
}

/** @file Codigo.hh
 *  @brief Implementación de la clase FreqTable
*/

#include "Codigo.hh"
using namespace std;

bool comp(const BinTree<pair<string,int> >& a, const BinTree<pair<string,int> >& b) {
    if (a.value().second == b.value().second) return a.value().first < b.value().first;
    return a.value().second < b.value().second;
}

void insercion(list<BinTree<pair<string,int> > >& lista, BinTree<pair<string,int> >& elemento) {
    bool completado = false;
    for (list<BinTree<pair<string,int> > >::iterator it = lista.begin(); !completado; ++it) {
        if (it == lista.end()) {
            lista.insert(it, elemento);
            completado = true;
        }
        else if (elemento.value().second == it->value().second) {
            if (elemento.value().first < it->value().first) lista.insert(it, elemento);
            else {
                ++it;
                lista.insert(it, elemento);
            }
            completado = true;
        }
        else if (elemento.value().second < it->value().second) {
            lista.insert(it, elemento);
            completado = true;
        }
        
    }
}

Codigo::Codigo() {}

Codigo::Codigo(const FreqTable & tabla) {
    list<BinTree<pair<string, int> > > listaTree = tabla.elementos();
    listaTree.sort(comp);
    list<string> caracteres;
    for (list<BinTree<pair<string,int> > >::const_iterator it = listaTree.begin(); it != listaTree.end(); ++it) {
        caracteres.insert(caracteres.end(), it->value().first);
    }
    while (listaTree.size() > 1) {
        list<BinTree<pair<string,int> > >::iterator it = listaTree.begin();
        string str1 = it->value().first;
        int f = it->value().second;
        BinTree<pair<string,int> > left = *it;
        it = listaTree.erase(it);
        string str2 = it->value().first;
        f += it->value().second;
        BinTree<pair<string,int> > right = *it;
        it = listaTree.erase(it);
        string str;
        if (str1 < str2) str = str1 + str2;
        else str = str2 + str1;
        BinTree<pair<string,int> > aux(make_pair(str, f), left, right);
        insercion(listaTree, aux);
    }
    treecode = listaTree.front();
    listaTree.clear();

    while (!caracteres.empty()) {
        string c = caracteres.front();
        caracteres.pop_front();
        codetable.insert(make_pair(c, codifica_caracter(c, treecode)));
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
        else cout << "El idioma no existe o el caracter no está en el idioma" << endl;
    }
}

string Codigo::codifica_caracter(string c, const BinTree< pair<string, int> >& tree) const {
    if (tree.value().first == c) return "";
    if (!tree.left().empty() and tree.left().value().first.find(c) != string::npos) return "0" + codifica_caracter(c, tree.left());
    return "1" + codifica_caracter(c, tree.right());
}

void Codigo::escribe_preorden(const BinTree<pair<string,int> >& tree) const {
    if (!tree.empty()) {
        cout << tree.value().first << " " << tree.value().second << endl;
        escribe_preorden(tree.left());
        escribe_preorden(tree.right());
    }
}

void Codigo::escribe_inorden(const BinTree<pair<string,int> >& tree) const {
    if (!tree.empty()) {
        escribe_inorden(tree.left());
        cout << tree.value().first << " " << tree.value().second << endl;
        escribe_inorden(tree.right());
    }
}

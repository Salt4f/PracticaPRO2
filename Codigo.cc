/** @file Codigo.hh
 *  @brief Implementación de la clase FreqTable
*/

#include "Codigo.hh"
using namespace std;

bool comp(const pair<string,int>& a, const pair<string,int>& b) {
    return a.second <= b.second;
}

void insercion(list<BinTree<pair<string,int> > >& lista, BinTree<pair<string,int> >& elemento) {
    bool completado = false;
    for (list<BinTree<pair<string,int> > >::iterator it = lista.begin(); !completado; ++it) {
        if (it == lista.end()) {
            lista.insert(it, elemento);
            completado = true;
        }
        else if (elemento.value().second <= it->value().second) {
            lista.insert(it, elemento);
            completado = true;
        }
        
    }
}

Codigo::Codigo() {}

Codigo::Codigo(const FreqTable & tabla) {
    list<pair<string, int> > lista = tabla.elementos();
    lista.sort(comp);
    list<BinTree<pair<string, int> > > listaTree;
    list<string> caracteres;
    while (!lista.empty()) {
        pair<string,int> par = lista.front();
        lista.pop_front();
        BinTree<pair<string,int> > aux(par);
        caracteres.insert(caracteres.end(), par.first);
        listaTree.insert(listaTree.end(), aux);
    }
    while (listaTree.size() > 1) {
        cout << "bienvenido al bucle" << endl;
        list<BinTree<pair<string,int> > >::iterator it = listaTree.begin();
        cout << "intentamos value" << endl;
        string str = it->value().first;
        int f = it->value().second;
        cout << str << " " << f << endl;
        BinTree<pair<string,int> > left = *it;
        it = listaTree.erase(it);
        str += it->value().first;
        f += it->value().second;
        cout << str << " " << f << endl;
        BinTree<pair<string,int> > right = *it;
        it = listaTree.erase(it);
        cout << "habemus arbol" << endl;
        BinTree<pair<string,int> > aux(make_pair(str, f), left, right);
        cout << "antes de inserción" << endl;
        insercion(listaTree, aux);
        treecode = aux;
        cout << "fin bucle, volvemos" << endl;
        cout << listaTree.size() << endl;
    }
    listaTree.clear();
    //Árbol hecho
    cout << "fuera bucle" << endl;
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

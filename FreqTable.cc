/** @file FreqTable.cc
 *  @brief Implementación de la clase FreqTable
*/

#include "FreqTable.hh"
using namespace std;

FreqTable::FreqTable() {}

void FreqTable::leer_tabla() {
    int n;
    cin >> n;
    string c;
    int freq;
    if (!table.empty()) {
        for (int i = 0; i < n; ++i) {
            cin >> c >> freq;
            table[c] += freq;
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            cin >> c >> freq;
            table.insert(make_pair(c, freq));
        }
    }
}

void FreqTable::escribir_tabla() const {
    for (map<string, int>::const_iterator it = table.begin(); it != table.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

Lista FreqTable::elementos() const {
    Lista lista;
    for (map<string,int>::const_iterator it = table.begin(); it != table.end(); ++it) {
        lista.insert(Arbol(*it));
    }
    return lista;
}

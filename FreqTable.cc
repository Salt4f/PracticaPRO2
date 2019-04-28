/** @file FreqTable.hh
 *  @brief Implementación de la clase FreqTable
*/

#include "FreqTable.hh"
using namespace std;

FreqTable::FreqTable() {}

void FreqTable::leer_tabla() {
    if (!table.empty()) table.clear();
    string c;
    int freq;
    while (cin >> c >> freq) {
        table.insert(make_pair(c, freq));
    }
}

bool FreqTable::esta(string c) const {
    return (table.find(c) != table.end());
}

void FreqTable::escribir_tabla() const {
    for (map<string, int>::const_iterator it = table.begin(); it != table.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

int FreqTable::frecuencia(string c) const {
    map<string,int>::const_iterator it = table.find(c);
    if (it != table.end()) return it->second;
    return -1;
}
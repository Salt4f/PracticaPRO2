/** @file freqtable.hh
 * 
*/

#ifndef FREQTABLE_HH
#define FREQTABLE_HH

#include <iostream>
#include <map>
using namespace std;

class FreqTable {
private:
    
    map<string, int> table;

public:
    FreqTable();

    void leer_tabla();

    void escribir_tabla() const;

    int frecuencia(string c) const;
};


#endif
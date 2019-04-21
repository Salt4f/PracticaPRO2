/** @file FreqTable.hh
 * 
*/

#ifndef FREQTABLE_HH
#define FREQTABLE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
using namespace std;
#endif

/** @class FreqTable
    @brief Representa una cubeta de ropa. 

    Puede contener prendas blancas y de color. Puede usarse para intentar llenar una lavadora; en ese caso, las prendas se sacan de la cubeta en orden inverso al de entrada
*/
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
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
    
    map<char, int> table;

public:
    FreqTable();

    void leer_tabla();
};


#endif
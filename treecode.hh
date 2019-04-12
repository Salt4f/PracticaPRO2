/** @file treecode.hh
 * 
*/

#ifndef TREECODE_HH
#define TREECODE_HH

#include "BinTree.hh"
#include "freqtable.hh"

#include <iostream>
using namespace std;

class Treecode {
private:
    BinTree< pair<string, int> > tree;


public:
    Treecode();
};


#endif
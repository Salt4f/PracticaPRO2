/** @file program.cc
 *  @brief Programa principal
*/

/** @mainpage Codificador/Descodificador
 * 
 * \todo Mirar <em>doxycomments</em> Diccionario.hh
 * 
*/


#include "Diccionario.hh"

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

int main() {
    int n;
    string opt;
    cin >> n;
    Diccionario diccionario;
    for (int i = 0; i < n; ++i) {
        cin >> opt;
        diccionario.modificar_idioma(opt, true);
    }
    cin >> opt;
    while (opt != "fin") {

        if (opt == "anadir/modificar") {
            cin >> opt;
            diccionario.modificar_idioma(opt, false);
        }

        else if (opt == "codifica") {
            cin >> opt;
            string texto;
            cin >> texto;
            cout << diccionario.codifica(opt, texto) << endl << endl;
        }

        else if (opt == "decodifica") {
            cin >> opt;
            string texto;
            cin >> texto;
            cout << diccionario.descodifica(opt, texto) << endl << endl;
        }

        else if (opt == "tabla_frec") {
            cin >> opt;
            diccionario.escribir_tabla_frecuencias(opt);
        }

        else if (opt == "treecode") {
            cin >> opt;
            diccionario.escribir_treecode(opt);
        }

        else if (opt == "codigos") {
            cin >> opt;
            diccionario.escribir_codigos(opt);
        }

        cin >> opt;
    }
}

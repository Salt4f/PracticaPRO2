
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
        diccionario.modificar_idioma(opt);
    }
    cin >> opt;
    while (opt != "fin") {

        if (opt == "modifica") {
            cin >> opt;
            diccionario.modificar_idioma(opt);
        }

        else if (opt == "codifica") {
            cin >> opt;
            if (diccionario.esta_idioma(opt)) {
                string texto;
                cin >> texto;
                cout << diccionario.codifica(opt, texto) << endl;
            }
            else cout << "El idioma para codificar no existe" << endl;
        }

        cin >> opt;
    }
}
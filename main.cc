
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
            else cout << "El idioma " << opt << " no existe" << endl;
        }

        else if (opt == "descodifica") {
            cin >> opt;
            if (diccionario.esta_idioma(opt)) {
                string texto;
                cin >> texto;
                cout << diccionario.descodifica(opt, texto) << endl;
            }
            else cout << "El idioma " << opt << " no existe" << endl;
        }

        else if (opt == "tabla_frec") {
            cin >> opt;
            if (diccionario.esta_idioma(opt)) diccionario.escribir_tabla_frecuencias(opt);
            else cout << "El idioma " << opt << " no existe" << endl;
        }

        else if (opt == "treecode") {
            cin >> opt;
            if (diccionario.esta_idioma(opt)) diccionario.escribir_treecode(opt);
            else cout << "El idioma " << opt << " no existe" << endl;
        }

        else if (opt == "codigos") {
            cin >> opt;
            if (diccionario.esta_idioma(opt)) diccionario.escribir_codigos(opt);
            else cout << "El idioma " << opt << " no existe" << endl;
        }

        cin >> opt;
    }
}
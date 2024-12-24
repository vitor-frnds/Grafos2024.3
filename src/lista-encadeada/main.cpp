#include <iostream>
#include "GrafoLista.h"

using namespace std;

int main() {

    GrafoLista g;
    g.carrega_grafo();

    if (g.aresta_ponderada())
        cout << "Arestas ponderadas." << endl;
    else
        cout << "Arestas nao ponderadas." << endl;

    cout << "Ordem do grafo: " << g.get_ordem() << endl;

    if (g.eh_direcionado())
        cout << "Eh direcionado." << endl;
    else
        cout << "Nao eh direcionado." << endl;

    int n = g.n_conexo();
    if (n > 0)
        cout << "Eh " << n << "-conexo." << endl;
    else
        cout << "Nao eh conexo." << endl;

    if (g.eh_arvore())
        cout << "Eh arvore." << endl;
    else
        cout << "Nao eh arvore." << endl;

    return 0;
}
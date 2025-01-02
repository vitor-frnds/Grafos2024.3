#include "Grafo.h"

Grafo::Grafo() : numVertices(0), direcionado(false) {}

Grafo::Grafo(int numVertices, bool direcionado)
    : numVertices(numVertices), direcionado(direcionado) {}

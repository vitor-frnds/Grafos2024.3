#include "GrafoLista.h"
#include <queue>
#include <stdexcept>
#include <fstream>
#include <iostream>

GrafoLista::GrafoLista(int numVertices, bool direcionado, bool arestasPonderadas)
    : Grafo(numVertices, direcionado, false, arestasPonderadas), listaAdj(numVertices) {}

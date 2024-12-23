#include "GrafoMatriz.h"
#include <queue>
#include <stdexcept>
#include <iostream>
#include <fstream>

GrafoMatriz::GrafoMatriz(int numVertices, bool direcionado)
    : Grafo(numVertices, direcionado) {
    std::fill(&matriz[0][0], &matriz[0][0] + MAX_VERTICES * MAX_VERTICES, 0);
}
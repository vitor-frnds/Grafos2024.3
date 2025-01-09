#ifndef GRAFO_H
#define GRAFO_H

#include <string>

class Grafo {
protected:
    int numVertices;
    bool direcionado;

public:
    Grafo() {}
    virtual ~Grafo() {}
    

    virtual bool eh_bipartido() = 0;
    virtual int n_conexo() = 0;
    virtual int get_grau() = 0;
    virtual int get_ordem() = 0;
    virtual bool eh_direcionado() = 0;
    virtual bool vertice_ponderado() = 0;
    virtual bool aresta_ponderada() = 0;
    virtual bool eh_completo() = 0;
    virtual bool eh_arvore() = 0;
    virtual bool possui_articulacao() = 0;
    virtual bool possui_ponte() = 0;
    virtual void carrega_grafo() = 0;
};

#endif

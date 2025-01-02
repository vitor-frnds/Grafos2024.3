#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include "Grafo.h"
#include <vector>
#include <string>

class GrafoMatriz : public Grafo {
private:
    static const int MAX_VERTICES = 100;
    int matriz[MAX_VERTICES][MAX_VERTICES];

    void BuscaProfundidade(int u, std::vector<bool>& visitado);

public:
    GrafoMatriz(int numVertices, bool direcionado = false);

    virtual bool eh_bipartido() override;
    virtual int n_conexo() override;
    virtual int get_grau(int vertice) override;
    virtual int get_ordem() override;
    virtual bool eh_direcionado() override;
    virtual bool eh_completo() override;
    virtual bool eh_arvore() override;
    virtual bool vertice_ponderado() override;
    virtual bool aresta_ponderada() override;
    virtual bool possui_articulacao() override;
    virtual bool possui_ponte() override;
    virtual void carrega_grafo(const std::string& arquivo) override;
    virtual void novo_grafo(const std::string& arquivo) override;

    void adicionaAresta(int u, int v, int peso = 1);
    int contarArestas() const;
};

#endif

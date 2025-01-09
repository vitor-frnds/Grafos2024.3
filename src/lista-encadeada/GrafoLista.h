#ifndef GRAFOLISTA_H
#define GRAFOLISTA_H

#include <Grafo.h>
#include "Vertice.h"
#include "Aresta.h"

// Os grafos não devem aceitar arestas múltiplas ou laços
// Uso de lista encadeada tanto para vertices quanto arestas usando alocação dinâmica
// Aresta armazena 1 quando não é ponderada

class Vertice;

class GrafoLista : public Grafo {
public:
    GrafoLista();
    ~GrafoLista();
    bool eh_bipartido() override;
    int n_conexo() override; /// Função que indica a quantidade de componentes conexas
    int get_grau() override;
    int get_ordem() override; /// Função que retorna a ordem do grafo
    bool eh_direcionado() override; /// Função que retorna se o grafo é direcionado ou não
    bool vertice_ponderado() override;
    bool aresta_ponderada() override; /// Função que informa se as arestas do grafo tem peso
    bool eh_completo() override;
    bool eh_arvore()override; /// Função que diz se o grafo é uma árvore
    bool possui_articulacao() override;
    bool possui_ponte() override;
    void carrega_grafo(std::string nomeArquivo) override; /// Função que lê um arquivo txt com um grafo e carrega ele
    void novo_grafo(std::string nomeArquivo) override;

    // Gabriel
    void salvaGrafoLista(std::string nomeArquivo);
    void imprimeGrafo(std::string nomeArquivo);

private:
    Vertice* raizVertice;
    Aresta* raizAresta;
    bool direcionado;

    void inserirVertice(int id, int peso);
    void inserirAresta(Vertice* inicio, Vertice* fim, int peso);
    void imprimirVertices();
    void imprimirArestas();
    bool ehConexo();
    bool ehCiclico();
    void auxEhConexo(bool *visitados, Vertice *v);
    bool auxEhCiclico(Vertice* v, bool* visitados, Vertice* pai);
    void auxNConexo(bool *visitados, Vertice *v);
};

#endif //GRAFOLISTA_H

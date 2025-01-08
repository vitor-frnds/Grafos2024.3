/*#ifndef GRAFO_H
#define GRAFO_H
#include <string>

// Classe abstrata Grafo
class Grafo {
protected:
    bool direcionado;
    bool verticesPonderados;
    bool arestasPonderadas;
    int numVertices;

public:
    //por enquanto, coloquei todas as funções como int e sem parâmetros,
    //mas depois é só trocar se precisar
    Grafo();
    Grafo(int numVertices, bool direcionado = false, bool verticesPonderados = false, bool arestasPonderadas = false);
    //função força bruta que indica se o grafo é bipartido ou não
    virtual bool eh_bipartido() = 0;
    //- função que indica a quantidade de componentes conexas
    virtual int n_conexo() = 0;
    //- função que retorna o grau do grafo
    virtual int get_grau(int vertice) = 0;
    //função que retorna a ordem do grafo
    virtual int get_ordem() = 0;
    //função que retorna se o grafo é direcionado ou não
    virtual bool eh_direcionado() = 0;
    //função que informa se os vertices do grafo tem peso
    virtual bool vertice_ponderado() = 0;
    //função que informa se as arestas do grafo tem peso
    virtual bool aresta_ponderada() = 0;
    //- função que diz se um grafo é completo ou não
    virtual bool eh_completo() = 0;
    //função que diz se o grafo é uma árvore
    virtual bool eh_arvore() = 0;
    //- função que diz se existe ao menos um vertice de articulação
    virtual bool possui_articulacao() = 0;
    //função que diz se existe ao menos uma aresta ponte
    virtual bool possui_ponte() = 0;
    //- função que lê um arquivo txt com um grafo e carrega ele
    virtual void carrega_grafo(const std::string& arquivo) = 0;
    //- função que lê um arquivo txt de configuracao e gera um grafo aleatorio
    virtual void novo_grafo(const std::string& arquivo) = 0;
    
};

#endif*/
#ifndef GRAFO_H
#define GRAFO_H

#include <string>

class Grafo {
protected:
    int numVertices;
    bool direcionado;

public:
    /*Grafo(); // Declaração do construtor padrão
    Grafo(int numVertices, bool direcionado);
    virtual ~Grafo() = default;*/
    Grafo() {} // Construtor padrão vazio
    virtual ~Grafo() {} // Destrutor virtual
    

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
    //rtual void novo_grafo(const std::string& arquivo) = 0;
};

#endif

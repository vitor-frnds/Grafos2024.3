#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include "Grafo.h"
#include <vector>

class GrafoMatriz : public Grafo{
    private:
        static int MAX_VERTICES = 100;
        int matriz[MAX_VERTICES][MAX_VERTICES];

    public:
        //por enquanto, coloquei todas as funções como int e sem parâmetros, 
        //mas depois é só trocar se precisar
        GrafoMatriz(int numVertices, bool direcionado = false);

        //função força bruta que indica se o grafo é bipartido ou não
        virtual bool eh_bipartido() override;

        //- função que indica a quantidade de componentes conexas
        virtual int n_conexo() override;

        //- função que retorna o grau do grafo
        virtual int get_grau(int vertice) override;

        //função que retorna a ordem do grafo
        virtual int get_ordem() override;

        //função que retorna se o grafo é direcionado ou não
        virtual bool eh_direcionado() override;

        //função que informa se os vertices do grafo tem peso
        virtual bool vertice_ponderado() override;

        //função que informa se as arestas do grafo tem peso
        virtual bool aresta_ponderada() override;

        //- função que diz se um grafo é completo ou não
        virtual bool eh_completo() override;

        //função que diz se o grafo é uma árvore
        virtual bool eh_arvore() override;

        //- função que diz se existe ao menos um vertice de articulação
        virtual bool possui_articulacao() override;

        //função que diz se existe ao menos uma aresta ponte
        virtual bool possui_ponte() override;

        //- função que lê um arquivo txt com um grafo e carrega ele
        virtual void carrega_grafo() override;
        
        //- função que lê um arquivo txt de configuracao e gera um grafo aleatorio
        virtual void novoGrafoO() override;

};

#endif
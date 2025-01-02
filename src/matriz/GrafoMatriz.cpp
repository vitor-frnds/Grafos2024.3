#include "GrafoMatriz.h"
#include <queue>
#include <stdexcept>
#include <iostream>
#include <fstream>



GrafoMatriz::GrafoMatriz(int numVertices, bool direcionado = false) {

    GrafoMatriz::GrafoMatriz() {
        numVertices = 0;
        direcionado = false;
        matrizAdj.clear(); // inicializa a matriz de adjacência como vazia
    }

    //talvez não precise dessa parte
    GrafoMatriz::~GrafoMatriz() {
        for (auto& linha : matrizAdj) {
            linha.clear();
        }
        matrizAdj.clear();
    }

    bool GrafoMatriz::eh_bipartido() {
        vector<int> cores(numVertices, -1); //para mostrar que não foi colorido
        queue<int> q; //fila para busca em largura

        for (int i = 0; i < numVertices; i++) {
            if (cores[i] == -1) {
                cores[i] = 0;
                q.push(i); //elemento colocado no final da fila

                //equanto houver vertices na fila remove o vertice u do 
                //início da fila para processar vizinhos
                while (!q.empty()) {
                    int u = q.front(); //retorna o elemento na frente do container
                    q.pop(); //remove o elemento da frente do container

                    //percorre os vertices para ver se há uma aresta entre o vértice u e v
                    for (int v = 0; v < numVertices; v++) {
                        //se matrizAdj[u][v] for verdadeiro, significa que há uma aresta entre os dois vértices
                        if (matrizAdj[u][v] && cores[v] == -1) {
                            //vertice v é colorido para o conjunto oposto de u
                            cores[v] = 1 - cores[u];
                            //vizinhos processador mais tarde
                            q.push(v);
                        } else if (matrizAdj[u][v] && cores[v] == cores[u]) {
                            //se há uma aresta entre u e v e possuem a mesma cor,
                            //não há como o grafo ser bipartido
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    void BuscaProfundidade(int u, vector<bool>& visitado, const vector<vector<int>>& matrizAdj) {
        visitado[u] = true;
        for (int v = 0; v < matrizAdj.size(); v++) {
            if (matrizAdj[u][v] && !visitado[v]) {
                BuscaProfundidade(v, visitado, matrizAdj);
            }
        }
    }
    int GrafoMatriz::n_conexo() {
        vector<bool> visitado(numVertices, false);
        int componentes = 0;

        for (int i = 0; i < numVertices; i++) {
            if (!visitado[i]) {
                componentes++;
                BuscaProfundidade(i, visitado, matrizAdj);
            }
        }

        return componentes;
    }

    int GrafoMatriz::get_grau(int vertice) {
        int grau = 0;
        //linha vertice da matriz representa todas as arestas conectadas ao vértice vertice
        for (int i = 0; i < numVertices; i++) {
            //ve as arestas entre o vertice e i
            grau += matrizAdj[vertice][i];
        }
        return grau;
    }

    int GrafoMatriz::get_ordem() {
        return numVertices;
    }

    bool GrafoMatriz::eh_direcionado() {
        return direcionado;
    }


    bool GrafoMatriz::eh_completo() {
        //i vertice "origem" e j vertice "destino"
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (i != j && !matrizAdj[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    //para ser uma árvore preciso ter apenas um componente conexo
    //e arestas = vertice-1
    bool GrafoMatriz::eh_arvore() {
        return (n_conexo() == 1 && contarArestas() == numVertices - 1);
    }

    void GrafoMatriz::carrega_grafo(const string& arquivo) {
        ifstream file(arquivo);
        if (!file.is_open()) {
            cerr << "Erro ao abrir o arquivo." << endl;
            return;
        }

        file >> numVertices;
        matrizAdj.resize(numVertices, vector<int>(numVertices, 0));

        int u, v, peso;
        while (file >> u >> v >> peso) {
            adicionaAresta(u, v, peso);
        }
        file.close();
    }

    void GrafoMatriz::novo_grafo(const string& arquivoConfig) {
        ifstream file(arquivoConfig);
        if (!file.is_open()) {
            cerr << "Erro ao abrir o arquivo." << endl;
            return;
        }

        int arestas;
        file >> numVertices >> arestas;
        matrizAdj.assign(numVertices, vector<int>(numVertices, 0));

        srand(time(0));
        for (int i = 0; i < arestas; i++) {
            int u = rand() % numVertices;
            int v = rand() % numVertices;
            int peso = 1 + rand() % 10;

            adicionaAresta(u, v, peso);
        }
        file.close();
    }
}
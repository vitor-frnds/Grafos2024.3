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
}
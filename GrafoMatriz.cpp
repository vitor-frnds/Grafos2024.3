/*#include "GrafoMatriz.h"
#include <queue>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
using std::vector;
using std::queue;
using std::ifstream;
using std::string;




GrafoMatriz::GrafoMatriz(int numVertices, bool direcionado) {
    this->numVertices = numVertices; // Inicializa o número de vértices
    this->direcionado = direcionado; // Inicializa se o grafo é direcionado
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            matriz[i][j] = 0;
        }
    } // Cria a matriz de adjacência
}

bool GrafoMatriz::eh_bipartido() {
    vector<int> cores(numVertices, -1); //para mostrar que não foi colorido
    std::queue<int> q; //fila para busca em largura

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
                    //se matriz[u][v] for verdadeiro, significa que há uma aresta entre os dois vértices
                    if (matriz[u][v] && cores[v] == -1) {
                        //vertice v é colorido para o conjunto oposto de u
                        cores[v] = 1 - cores[u];
                        //vizinhos processador mais tarde
                        q.push(v);
                    } else if (matriz[u][v] && cores[v] == cores[u]) {
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

void GrafoMatriz::BuscaProfundidade(int u, std::vector<bool>& visitado, const std::vector<vector<int>>& matriz) {
    visitado[u] = true;
    for (int v = 0; v < matriz.size(); v++) {
        if (matriz[u][v] && !visitado[v]) {
            BuscaProfundidade(v, visitado, matriz);
        }
    }
}
int GrafoMatriz::n_conexo() {
    vector<bool> visitado(numVertices, false);
    int componentes = 0;

    for (int i = 0; i < numVertices; i++) {
        if (!visitado[i]) {
            componentes++;
            BuscaProfundidade(i, visitado, matriz);
        }
    }

    return componentes;
}

int GrafoMatriz::get_grau(int vertice){
    int grau = 0;
    //linha vertice da matriz representa todas as arestas conectadas ao vértice vertice
    for (int i = 0; i < numVertices; i++) {
        //ve as arestas entre o vertice e i
        grau += matriz[vertice][i];
    }
    return grau;
}

int GrafoMatriz::get_ordem(){
    return numVertices;
}

bool GrafoMatriz::eh_direcionado(){
    return direcionado;
}

int GrafoMatriz::contarArestas() const{
    int arestas = 0;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matriz[i][j] != 0) {
                arestas++;
            }
        }
    }
    return direcionado ? arestas : arestas / 2;
}
bool GrafoMatriz::eh_completo(){
    //i vertice "origem" e j vertice "destino"
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i != j && !matriz[i][j]) {
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
        std::cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    file >> numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            matriz[i][j] = 0;
        }
    }

    int u, v, peso;
    while (file >> u >> v >> peso) {
        adicionaAresta(u, v, peso);
    }
    file.close();
}
void GrafoMatriz::adicionaAresta(int u, int v, int peso) {
    matriz[u][v] = peso;
    if (!direcionado) {
        matriz[v][u] = peso;
    }
}*/

#include "GrafoMatriz.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <cstdlib>

using std::vector;
using std::queue;
using std::ifstream;
using std::string;

GrafoMatriz::GrafoMatriz(int numVertices, bool direcionado) {
    this->numVertices = numVertices;
    this->direcionado = direcionado;

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            matriz[i][j] = 0;
        }
    }
}

void GrafoMatriz::adicionaAresta(int u, int v, int peso) {
    matriz[u][v] = peso;
    if (!direcionado) {
        matriz[v][u] = peso;
    }
}

void GrafoMatriz::BuscaProfundidade(int u, std::vector<bool>& visitado) {
    visitado[u] = true;
    for (int v = 0; v < numVertices; v++) {
        if (matriz[u][v] && !visitado[v]) {
            BuscaProfundidade(v, visitado);
        }
    }
}

bool GrafoMatriz::eh_bipartido() {
    vector<int> cores(numVertices, -1);
    queue<int> q;

    for (int i = 0; i < numVertices; i++) {
        if (cores[i] == -1) {
            cores[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v = 0; v < numVertices; v++) {
                    if (matriz[u][v] && cores[v] == -1) {
                        cores[v] = 1 - cores[u];
                        q.push(v);
                    } else if (matriz[u][v] && cores[v] == cores[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int GrafoMatriz::n_conexo() {
    vector<bool> visitado(numVertices, false);
    int componentes = 0;

    for (int i = 0; i < numVertices; i++) {
        if (!visitado[i]) {
            componentes++;
            BuscaProfundidade(i, visitado);
        }
    }
    return componentes;
}

int GrafoMatriz::get_grau(int vertice) {
    int grau = 0;
    for (int i = 0; i < numVertices; i++) {
        grau += matriz[vertice][i];
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
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i != j && !matriz[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int GrafoMatriz::contarArestas() const {
    int arestas = 0;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matriz[i][j] != 0) {
                arestas++;
            }
        }
    }
    return direcionado ? arestas : arestas / 2;
}

bool GrafoMatriz::eh_arvore() {
    return (n_conexo() == 1 && contarArestas() == numVertices - 1);
}

bool GrafoMatriz::vertice_ponderado() {
    return false;  // Implementação fictícia; ajuste conforme necessário
}

bool GrafoMatriz::aresta_ponderada() {
    return true;  // Implementação fictícia; ajuste conforme necessário
}

bool GrafoMatriz::possui_articulacao() {
    return false;  // Implementação fictícia; ajuste conforme necessário
}

bool GrafoMatriz::possui_ponte() {
    return false;  // Implementação fictícia; ajuste conforme necessário
}

void GrafoMatriz::carrega_grafo(const std::string& arquivo) {
    ifstream file(arquivo);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    file >> numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            matriz[i][j] = 0;
        }
    }

    int u, v, peso;
    while (file >> u >> v >> peso) {
        adicionaAresta(u, v, peso);
    }
    file.close();
}

void GrafoMatriz::novo_grafo(const std::string& arquivo) {
    srand(time(0));
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i != j) {
                matriz[i][j] = rand() % 2;  // Gera aresta aleatória
            }
        }
    }
}

#include "GrafoMatriz.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <cstdlib>
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::ios;

GrafoMatriz::GrafoMatriz(int vertices, bool dir) : numVertices(vertices), direcionado(dir) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            matriz[i][j] = 0; //inicializa a matriz de adjacência
        }
    }
}
bool GrafoMatriz::eh_bipartido() {
    int cores[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        cores[i] = -1; //inicializa as cores em -1 para dizer que ainda nao foi coloriada
    }

    int fila[MAX_VERTICES], inicio = 0, fim = 0;
    for(int i=0; i<numVertices; i++){
        if(cores[i]==-1){
            cores[i] = 0; //cor do primeiro 0
            fila[fim] = i; //add vertice inical na fila
            fim++;
            while(inicio<fim){
                int u = fila[inicio];//remove o vertice do incio da fila
                inicio++;
                for(int v=0; v<numVertices; v++){
                    if(matriz[u][v]){ //se é diferente de 0
                        if(cores[v]==-1){
                            cores[v] = 1 - cores[u]; //v é colorida com a cor oposta de u
                            fila[fim] = v;//enfileira v
                            fim++;
                        }else if(cores[v]==cores[u]){
                            return false;//se u e v sao da mesma cor é falso
                        }
                    }
                }
            }
        }
    }
    return true;
}

void GrafoMatriz::adicionaAresta(int origem, int destino, int peso) {
    matriz[origem - 1][destino - 1] = peso;
    if (!direcionado) {
        matriz[destino - 1][origem - 1] = 1;
    }
}
void GrafoMatriz::buscaProfundidade(int u, bool visitado[]) {
    visitado[u] = true;
    for (int v = 0; v < numVertices; v++) {
        if (matriz[u][v] && !visitado[v]) {
            buscaProfundidade(v, visitado);
        }
    }
}

int GrafoMatriz::n_conexo() {
    bool visitado[MAX_VERTICES] = {false};
    int componentes = 0;

    for (int i = 0; i < numVertices; i++) {
        if (!visitado[i]) {
            componentes++;
            buscaProfundidade(i, visitado);
        }
    }
    return componentes;
}

int GrafoMatriz::get_grau(){
    int maior=0;
    if(direcionado){
        for(int i=0; i<numVertices; i++){
            int grau = 0;
            for(int j=0; j<numVertices; j++){
                if(matriz[j][i]){
                    grau++;
                }
            }
            if(grau>maior){
                maior = grau;
            }
        }
        return maior;
    }else{
        for(int i=0; i<numVertices; i++){
            int grau = 0;
            for(int j=0; j<numVertices; j++){
                if(matriz[i][j]){
                    grau++;
                }
            }
            if(grau>maior){
                maior = grau;
            }
        }
    }
    return maior;
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

int GrafoMatriz::contarArestas() {
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
void GrafoMatriz::carrega_grafo() {
    ifstream arquivo;
    //cout << "Carregando grafo do arquivo " << arquivo << "..." << endl;
    arquivo.open("Grafo.txt", ios::in);

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo!" << endl;
        exit(1);
    }

    cout << "Arquivo aberto com sucesso!" << endl;

    
    int numVertices, direcionado, ponderado_nos, ponderado_arestas;
    arquivo >> numVertices >> direcionado >> ponderado_nos >> ponderado_arestas;
    /*std::cout<< "numVertices: "<<numVertices<<endl;
    std::cout<< "direcionado: "<<direcionado<<endl;
    std::cout<< "ponderado_nos: "<<ponderado_nos<<endl;
    std::cout<< "ponderado_arestas: "<<ponderado_arestas<<endl;*/

    this->numVertices = numVertices;
    this->direcionado = direcionado;

    //peso dos vertices
    int pesosVertices[numVertices];
    if (ponderado_nos == 1) {
        //cout << "Peso dos vértices:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            arquivo >> pesosVertices[i];
        }
    } else {
        //cout<< "Não há pesos nos vértices"<<endl;
        for (int i = 0; i < numVertices; ++i) {
            pesosVertices[i] = 1;
        }
    }

    //ler arestas
    int origem, destino, pesoAresta, pesoNada;
    while (arquivo >> origem >> destino) {
        
        if (ponderado_arestas == 1) {
            arquivo >> pesoAresta;
        } else {
            arquivo >> pesoNada;
            pesoAresta = 1;
        }

        if(direcionado){
            matriz[origem - 1][destino - 1] = pesoAresta;
        }
        else{
            if(origem<destino){
                matriz[origem - 1][destino - 1] = pesoAresta;
            }
            else{
                matriz[destino-1][origem-1] = pesoAresta;
            }
        }
    }

    arquivo.close();
    //cout<< "Arquivo fechado com sucesso"<<endl;
    // Exibir o grafo carregado
    //cout << "Grafo carregado com sucesso!" << endl;
    cout << "Matriz de adjacência:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << endl;
    }

    if (ponderado_nos == 1) {
        //std::cout << "Pesos dos vértices:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            //std::cout << "Vértice " << (i + 1) << ": " << pesosVertices[i] << endl;
        }
    }
}
void GrafoMatriz::imprimir_descricao() {
    cout << "Grau: " << get_grau() << endl;
    cout << "Ordem: " << get_ordem() << endl;
    cout << "Direcionado: " << (eh_direcionado() ? "Sim" : "Não") << endl;
    cout << "Componentes conexas: " << n_conexo() << endl;
    cout << "Vertices ponderados: " << (vertice_ponderado() ? "Sim" : "Não") << endl;
    cout << "Arestas ponderadas: " << (aresta_ponderada() ? "Sim" : "Não") << endl;
    cout << "Completo: " << (eh_completo() ? "Sim" : "Não") << endl;
    cout << "Bipartido: " << (eh_bipartido() ? "Sim" : "Não") << endl;
    cout << "Arvore: " << (eh_arvore() ? "Sim" : "Não") << endl;
    cout << "Aresta Ponte: " << (possui_ponte() ? "Sim" : "Não") << endl;
    cout << "Vertice de Articulação: " << (possui_articulacao() ? "Sim" : "Não") << endl;
}


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

//using std::queue;
using std::ofstream;
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
        cores[i] = -1; //inicializa as cores
    }

    int fila[MAX_VERTICES], inicio = 0, fim = 0;
    for(int i=0; i<numVertices; i++){
        if(cores[i]==-1){
            cores[i] = 0;
            fila[fim++] = i;
            while(inicio<fim){
                int u = fila[inicio++];
                for(int v=0; v<numVertices; v++){
                    if(matriz[u][v]){
                        if(cores[v]==-1){
                            cores[v] = 1 - cores[u];
                            fila[fim++] = v;
                        }else if(cores[v]==cores[u]){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

void GrafoMatriz::adicionaAresta(int origem, int destino, int peso) {
    matriz[origem - 1][destino - 1] = peso; //ajuste de índice para 1-based input
    if (!direcionado) {
        matriz[destino - 1][origem - 1] = peso; //se não for direcionado
    }
}
void GrafoMatriz::BuscaProfundidade(int u, bool visitado[]) {
    visitado[u] = true;
    for (int v = 0; v < numVertices; v++) {
        if (matriz[u][v] && !visitado[v]) {
            BuscaProfundidade(v, visitado);
        }
    }
}

int GrafoMatriz::n_conexo() {
    bool visitado[MAX_VERTICES] = {false};
    int componentes = 0;

    for (int i = 0; i < numVertices; i++) {
        if (!visitado[i]) {
            componentes++;
            BuscaProfundidade(i, visitado);
        }
    }
    return componentes;
}

/*int GrafoMatriz::get_grauVertice(int vertice) {
    int grau = 0;
    for (int i = 0; i < numVertices; i++) {
        grau += matriz[vertice][i];
    }
    return grau;
}
int GrafoMatriz::get_grau() {
        int grauTotal = 0;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                grauTotal += matriz[i][j];
            }
        }
        return direcionado ? grauTotal : grauTotal / 2;
}*/

int GrafoMatriz::get_grau(){
    int maior=0;

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
    int origem, destino, pesoAresta;
    while (arquivo >> origem >> destino) {
    
        if (ponderado_arestas == 1) {
            arquivo >> pesoAresta;
        } else {
            pesoAresta = 1;
        }

        matriz[origem - 1][destino - 1] = pesoAresta; //insere na matriz de adjacência
        if (!direcionado) {
            matriz[destino - 1][origem - 1] = pesoAresta; // Se não for direcionado, insere na outra direção
        }
    }

    arquivo.close();
    //cout<< "Arquivo fechado com sucesso"<<endl;
    // Exibir o grafo carregado
    //cout << "Grafo carregado com sucesso!" << endl;
    //cout << "Matriz de adjacência:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            //std::cout << matriz[i][j] << " ";
        }
        //std::cout << endl;
    }

    if (ponderado_nos == 1) {
        //std::cout << "Pesos dos vértices:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            //std::cout << "Vértice " << (i + 1) << ": " << pesosVertices[i] << endl;
        }
    }

    /*cout << "Grau: " << get_grau() << endl;
    cout << "Ordem: " << get_ordem() << endl;
    cout << "Direcionado: " << (eh_direcionado() ? "Sim" : "Não") << endl;
    cout << "Componentes conexas: " << n_conexo() << endl;
    cout << "Vertices ponderados: " << (vertice_ponderado() ? "Sim" : "Não") << endl;
    cout << "Arestas ponderadas: " << (aresta_ponderada() ? "Sim" : "Não") << endl;
    cout << "Completo: " << (eh_completo() ? "Sim" : "Não") << endl;
    cout << "Bipartido: " << (eh_bipartido() ? "Sim" : "Não") << endl;
    cout << "Arvore: " << (eh_arvore() ? "Sim" : "Não") << endl;*/
}
void GrafoMatriz::imprimir_descricao() {
    //cout << "Começando função de imprimir" << endl;
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

void GrafoMatriz::salvaGrafoMatriz(string entrada, string nomeArquivo) {

    ifstream entrada;
    ofstream arquivoGrafo;
    arquivoGrafo.open(entrada, ios::in);
    arquivoGrafo.open(nomeArquivo, ios::out);

    if (!arquivoGrafo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        exit(1);
    } else {
        
        arquivoGrafo << nomeArquivo << "\n\n";
        arquivoGrafo << numVertices << " " << direcionado << " "<< vertice_ponderado() << " " << aresta_ponderada() << "\n";

        if (vertice_ponderado()) {
            int pesosVertices[numVertices];
            for (int i = 0; i < numVertices; i++) {
                arquivoGrafo << pesosVertices[i] <<" ";
        }
            }
        }

        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (matriz[i][j] != 0) {
                    if (aresta_ponderada()) {
                        arquivoGrafo << i << " " << j << " " << matriz[i][j] << "\n";
                    } else {
                        arquivoGrafo << i << " " << j << "\n";
                    }
                }
            }
        }
    
    arquivoGrafo.close();
}

bool GrafoMatriz::possui_ponte() {
    int componentesIniciais = n_conexo();

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matriz[i][j] != 0) {  
                int peso = matriz[i][j];  // Armazena o peso da aresta 
                // Removendo aresta(s)

                if (!direcionado) {
                    matriz[j][i] = 0; //remove a simetrica se direcionado
                    matriz[i][j] = 0;
                }
                else{
                matriz[i][j] = 0;}
                if (n_conexo() > componentesIniciais) {
                    
                    if (!direcionado)
                    {
                        matriz[i][j] = peso;
                        matriz[j][i] = peso;
                        return true; // Há pelo menos uma ponte
                    }
                    else{
                    matriz[i][j] = peso;
                    return true; // Há pelo menos uma ponte
                }}
                matriz[i][j] = peso;

                if (!direcionado) {
                    matriz[j][i] = peso; // Restaura a aresta reversa se o grafo não for direcionado
                }
            }
        }
    }

    return false; // Não há pontes
}

bool GrafoMatriz::possui_articulacao() {
    return false;  // Implementação fictícia; ajuste conforme necessário
}



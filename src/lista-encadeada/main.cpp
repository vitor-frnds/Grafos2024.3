/*#include <iostream>
#include "GrafoLista.h"

using namespace std;

int main() {

    GrafoLista g;
    g.carregaGrafo();

    if (g.arestaPonderada())
        cout << "Arestas ponderadas." << endl;
    else
        cout << "Arestas nao ponderadas." << endl;

    cout << "Ordem do grafo: " << g.getOrdem() << endl;

    if (g.ehDirecionado())
        cout << "Eh direcionado." << endl;
    else
        cout << "Nao eh direcionado." << endl;

    if (g.ehConexo())
        cout << "Eh conexo." << endl;
    else
        cout << "Nao eh conexo." << endl;

    return 0;
}*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "GrafoMatriz.h"
#include "GrafoLista.h"

void imprimirDescricaoGrafo(Grafo* grafo) {
    std::cout << "Grau: " << grafo->get_grau(0) << "\n";
    std::cout << "Ordem: " << grafo->get_ordem() << "\n";
    std::cout << "Direcionado: " << (grafo->eh_direcionado() ? "Sim" : "Não") << "\n";
    std::cout << "Componentes conexas: " << grafo->n_conexo() << "\n";
    std::cout << "Vertices ponderados: " << (grafo->vertice_ponderado() ? "Sim" : "Não") << "\n";
    std::cout << "Arestas ponderadas: " << (grafo->aresta_ponderada() ? "Sim" : "Não") << "\n";
    std::cout << "Completo: " << (grafo->eh_completo() ? "Sim" : "Não") << "\n";
    std::cout << "Bipartido: " << (grafo->eh_bipartido() ? "Sim" : "Não") << "\n";
    std::cout << "Arvore: " << (grafo->eh_arvore() ? "Sim" : "Não") << "\n";
    std::cout << "Aresta Ponte: " << (grafo->possui_ponte() ? "Sim" : "Não") << "\n";
    std::cout << "Vertice de Articulação: " << (grafo->possui_articulacao() ? "Sim" : "Não") << "\n";
}

void criarGrafoAleatorio(bool usarMatriz, const std::string& descricao, const std::string& grafoTxt) {
    std::ifstream fileDescricao(descricao);
    if (!fileDescricao) {
        std::cerr << "Erro ao abrir o arquivo de descrição: " << descricao << "\n";
        return;
    }

    int numVertices, numArestas;
    fileDescricao >> numVertices >> numArestas;

    Grafo* grafo;
    if (usarMatriz) {
        grafo = new GrafoMatriz(numVertices, false);
    } else {
        grafo = new GrafoLista(numVertices, false);
    }

    std::srand(std::time(nullptr));
    for (int i = 0; i < numArestas; ++i) {
        int v1 = std::rand() % numVertices;
        int v2 = std::rand() % numVertices;
        int peso = std::rand() % 10 + 1;
        grafo->adicionarAresta(v1, v2, peso);
    }

    std::ofstream outFile(grafoTxt);
    if (!outFile) {
        std::cerr << "Erro ao criar o arquivo: " << grafoTxt << "\n";
        delete grafo;
        return;
    }

    grafo->salvarGrafo(outFile);
    delete grafo;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Uso inválido. Consulte a documentação.\n";
        return 1;
    }

    std::string flag1 = argv[1];
    std::string estrutura = argv[2];
    std::string arquivoEntrada = argv[3];
    std::string arquivoSaida;

    if (flag1 == "-d") {
        Grafo* grafo;
        if (estrutura == "-m") {
            grafo = new GrafoMatriz(10, true);
        } else if (estrutura == "-l") {
            grafo = new GrafoLista(10, true);
        } else {
            std::cerr << "Estrutura inválida.\n";
            return 1;
        }

        grafo->carregaGrafo(arquivoEntrada);
        imprimirDescricaoGrafo(grafo);
        delete grafo;

    } else if (flag1 == "-c") {
        if (argc < 5) {
            std::cerr << "Erro: Nome do arquivo de saída não fornecido.\n";
            return 1;
        }
        arquivoSaida = argv[4];

        if (estrutura == "-m") {
            criarGrafoAleatorio(true, arquivoEntrada, arquivoSaida);
        } else if (estrutura == "-l") {
            criarGrafoAleatorio(false, arquivoEntrada, arquivoSaida);
        } else {
            std::cerr << "Estrutura inválida.\n";
            return 1;
        }
    } else {
        std::cerr << "Comando inválido.\n";
        return 1;
    }

    return 0;
}

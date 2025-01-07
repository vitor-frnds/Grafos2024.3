#include <iostream>
#include <fstream>
#include <string>
#include "GrafoMatriz.h"
//#include "GrafoLista.h"

using namespace std;

/*void imprimir_descricao(Grafo* grafo) {
    cout << "Grau: " << grafo->get_grau(1) << endl;  // Exemplo com vértice 1
    cout << "Ordem: " << grafo->get_ordem() << endl;
    cout << "Direcionado: " << (grafo->eh_direcionado() ? "Sim" : "Não") << endl;
    cout << "Componentes conexas: " << grafo->n_conexo() << endl;
    cout << "Vertices ponderados: " << (grafo->vertice_ponderado() ? "Sim" : "Não") << endl;
    cout << "Arestas ponderadas: " << (grafo->aresta_ponderada() ? "Sim" : "Não") << endl;
    cout << "Completo: " << (grafo->eh_completo() ? "Sim" : "Não") << endl;
    cout << "Bipartido: " << (grafo->eh_bipartido() ? "Sim" : "Não") << endl;
    cout << "Arvore: " << (grafo->eh_arvore() ? "Sim" : "Não") << endl;
    //cout << "Aresta Ponte: " << (grafo->possui_ponte() ? "Sim" : "Não") << endl;
    //cout << "Vertice de Articulação: " << (grafo->possui_articulacao() ? "Sim" : "Não") << endl;
}

void carregar_descrever(string estrutura, string arquivo) {
    if (estrutura == "-m") {
        GrafoMatriz grafo(0, false);
        grafo.carrega_grafo(arquivo);
        imprimir_descricao(&grafo);
    } else if (estrutura == "-l") {
        GrafoLista grafo(0, false);
        grafo.carrega_grafo(arquivo);
        imprimir_descricao(&grafo);
    }else {
        cerr << "Estrutura inválida!" << endl;
        cout << "Estrturura inválida!" << endl;
    }
}

void criar_salvar(string estrutura, string descricao, string arquivo_saida) {
    ifstream file(descricao);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo de descrição!" << endl;
        return;
    }

    int numVertices, direcionado, ponderadoVertices, ponderadoArestas;
    file >> numVertices >> direcionado >> ponderadoVertices >> ponderadoArestas;

    if (estrutura == "-m") {
        GrafoMatriz grafo(numVertices, direcionado);
        grafo.novo_grafo(descricao);
        //grafo.salva_grafo(arquivo_saida);
    } else if (estrutura == "-l") {
        //GrafoLista grafo(numVertices, direcionado);
        //grafo.novo_grafo(descricao);
        //grafo.salva_grafo(arquivo_saida);
    } else {
        cerr << "Estrutura inválida!" << endl;
        cout << "Estrturura inválida!" << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Uso: main.out -d|-c -m|-l <arquivo> [arquivo_saida]" << endl;
        return 1;
    }

    string operacao = argv[1];
    string estrutura = argv[2];
    string arquivo = argv[3];

    if (operacao == "-d") {
        cout << "-d";
        //carregar_descrever(estrutura, arquivo);
    } else if (operacao == "-c") {
        if (argc < 5) {
            cout << "Faltando arquivo de saída para criação!" << endl;
            return 1;
        }
        string arquivo_saida = argv[4];
        criar_salvar(estrutura, arquivo, arquivo_saida);
    } else {
        cout << "Operação inválida!" << endl;
    }

    return 0;
}*/

#include <iostream>
#include "GrafoMatriz.h"
#include "GrafoMatriz.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    // Criar um grafo com 4 vértices, direcionado
    GrafoMatriz grafo(4, true);

    // Carregar o grafo a partir de um arquivo
    grafo.carrega_grafo("grafo.txt");

    // Testar função de descrição do grafo
    //cout << "O grafo é bipartido? " << (grafo.eh_bipartido() ? "Sim" : "Não") << endl;

    return 0;
}


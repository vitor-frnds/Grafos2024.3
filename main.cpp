#include <iostream>
#include <fstream>
#include <string>
#include "GrafoMatriz.h"
//#include "GrafoLista.h"

using namespace std;


/*void carregar_descrever(string estrutura, string arquivo) {
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
    // Teste 1: Criar um grafo manualmente e verificar se é bipartido
    /*GrafoMatriz grafo1(6, false); // Grafo com 4 vértices, não direcionado
    grafo1.adicionaAresta(1, 2, 1);
    grafo1.adicionaAresta(2, 3, 1);
    grafo1.adicionaAresta(3, 4, 1);
    grafo1.adicionaAresta(4, 1, 1);
    grafo1.adicionaAresta(3,1,1);
    //grafo1.adicionaAresta() // Forma um ciclo de tamanho par (bipartido)
    

    cout << "Teste 1 - Grafo manual: " << endl;
    cout << "O grafo é bipartido? " << (grafo1.eh_bipartido() ? "Sim" : "Não") << endl;
    cout << "Qual o grau do grafo?" << grafo1.get_grau() << endl;
    cout << "O grafo é completo? " << (grafo1.eh_completo() ? "Sim" : "Não") << endl;
    cout << "Número de componentes conexas: " << grafo1.n_conexo() << endl;
    cout << "Número de arestas: " << grafo1.contarArestas() << endl;

    // Teste 2: Verificar propriedades de um grafo carregado de arquivo
    GrafoMatriz grafo2(0, false);
    cout << "\nTeste 2 - Carregando grafo do arquivo:" << endl;
    grafo2.carrega_grafo();
    cout << "O grafo é bipartido? " << (grafo2.eh_bipartido() ? "Sim" : "Não") << endl;
    cout << "O grafo é uma árvore? " << (grafo2.eh_arvore() ? "Sim" : "Não") << endl;
    cout << "Número de componentes conexas: " << grafo2.n_conexo() << endl;
    cout << "Número de arestas: " << grafo2.contarArestas() << endl;*/
    GrafoMatriz grafo1(4, true);
    //grafo1.carrega_grafo();
    grafo1.adicionaAresta(1, 2, 1);
    grafo1.adicionaAresta(2,3,5);
    grafo1.adicionaAresta(2,4,6);
    grafo1.imprimir_descricao();
    //GrafoMatriz grafo1(2,true);


    return 0;
}


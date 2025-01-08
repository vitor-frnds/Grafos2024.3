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
    GrafoMatriz grafo1(6, true);
    /*grafo1.adicionaAresta(1,4,6);
    grafo1.adicionaAresta(1,5,6);
    grafo1.adicionaAresta(1,6,6);
    grafo1.adicionaAresta(2,3,6);
    grafo1.adicionaAresta(5,2,6);
    //grafo1.adicionaAresta()
    grafo1.imprimir_descricao();*/
    grafo1.carrega_grafo();
    grafo1.imprimir_descricao();


    return 0;
}


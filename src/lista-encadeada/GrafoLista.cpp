#include "GrafoLista.h"
#include <iostream>
#include <fstream>

using namespace std;

GrafoLista::GrafoLista() {
    raizVertice = nullptr;
    raizAresta = nullptr;
    direcionado = false;
}

GrafoLista::~GrafoLista() {
    while (raizVertice != nullptr) {
        Vertice* p = raizVertice->getProx();
        delete raizVertice;
        raizVertice = p;
    }

    while (raizAresta != nullptr) {
        Aresta* a = raizAresta->getProx();
        delete raizAresta;
        raizAresta = a;
    }
}

void GrafoLista::setRaizVertice(Vertice *v) {
    raizVertice = v;
}

Vertice * GrafoLista::getRaizVertice() {
    return raizVertice;
}

void GrafoLista::setRaizAresta(Aresta *a) {
    raizAresta = a;
}

Aresta * GrafoLista::getRaizAresta() {
    return raizAresta;
}

void GrafoLista::carregaGrafo() {
    ifstream arquivo;
    arquivo.open("C:/Users/henri/CLionProjects/trabalho-grafos/Grafo.txt", ios::in);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        exit(1);
    }

    int numVertices, direcionado, ponderado_nos, ponderado_arestas;
    arquivo >> numVertices >> direcionado >> ponderado_nos >> ponderado_arestas;

    this->direcionado = direcionado;

    // Criar vértices
    if (ponderado_nos == 1) {
        int peso;
        for (int i = 0; i < numVertices; ++i) {
            arquivo >> peso;
            inserirVertice(i+1, peso);
        }
    } else {
        for (int i = 0; i < numVertices; ++i) {
            inserirVertice(i+1, 1);
        }
    }

    imprimirVertices();

    // Criar arestas
    int origem, destino, peso;
    while (arquivo >> origem >> destino) {
        Vertice *v = raizVertice;
        Vertice *inicio = nullptr;
        Vertice *fim = nullptr;
        while (v != nullptr) {
            if (v->getId() == origem) {
                inicio = v;
            }
            if (v->getId() == destino) {
                fim = v;
            }
            v = v->getProx();
        }

        if (inicio != nullptr && fim != nullptr) {
            if (ponderado_arestas == 1) {
                arquivo >> peso;
                inserirAresta(inicio, fim, peso);
            } else {
                inserirAresta(inicio, fim, 1);
            }
        } else {
            cout << "Erro ao inserir arquivo" << endl;
        }
    }

    imprimirArestas();
    arquivo.close();
}

void GrafoLista::inserirVertice(int id, int peso) {
    Vertice* v = new Vertice(id);
    v->setPeso(peso);
    if (raizVertice != nullptr) {
        v->setProx(raizVertice);
    }
    raizVertice = v;
}

void GrafoLista::inserirAresta(Vertice *inicio, Vertice *fim, int peso) {
    if (inicio == fim) {
        cout << "Erro: o grafo não permite inserir laço." << endl;
    } else if (inicio->getArestas() != nullptr) {
        cout << "Erro: o grafo não permite arestas múltiplas." << endl;
    } else {
        // Criando aresta
        Aresta* a = new Aresta();
        a->setPeso(peso);
        a->setInicio(inicio);
        a->setFim(fim);

        // Adicionando ponteiro da aresta no vértice
        inicio->setArestas(a);

        // Adicionando aresta na lista
        if (raizAresta != nullptr) {
            a->setProx(raizAresta);
        }
        raizAresta = a;

        cout << "Aresta inserida: " << endl;
    }
}

void GrafoLista::imprimirVertices() {
    cout << "Lista de vertices: ";
    Vertice* v = raizVertice;
    while (v != nullptr) {
        cout << v->getId() << " ";
        v = v->getProx();
    }
    cout << endl;
}

void GrafoLista::imprimirArestas() {
    cout << "Lista de arestas: " << endl;
    Aresta* a = raizAresta;
    while (a != nullptr) {
        cout << a->getInicio()->getId() << " -> " << a->getFim()->getId() << " Peso: " << a->getPeso() << endl;
        a = a->getProx();
    }
}

bool GrafoLista::arestaPonderada() {
    Aresta *a = raizAresta;
    while (a != nullptr) {
        if (a->getPeso() != 1) {
            return true;
        }
        a = a->getProx();
    }
    return false;
}

int GrafoLista::getOrdem() {
    Vertice* v = raizVertice;
    int ordem = 0;
    while (v != nullptr) {
        ordem++;
        v = v->getProx();
    }
    return ordem;
}

bool GrafoLista::ehConexo() {
    int tam = getOrdem();
    Vertice* visitados[tam];
    visitados[0] = raizVertice;

    int i = 0;
    while (i < tam || visitados[i]->getArestas() != nullptr) {
        Vertice* v = visitados[i]->getArestas()->getFim();
        for (int j = 0; j <= i; j++) {
            if (visitados[j] == v) {
                // Como não suporta aresta múltipla então já posso dizer que não é conexo
                return false;
            }
        }
        visitados[i+1] = v;
        i++;
    }

    if (i+1 != tam) {
        return false;
    } else {
        return true;
    }
}

bool GrafoLista::ehDirecionado() {
    return direcionado;
}

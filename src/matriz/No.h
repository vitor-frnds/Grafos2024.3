#ifndef NO_H
#define NO_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>

#include "Aresta.h"
#include "Arco.h"

using namespace std;

class Aresta;
class Arco;

class No
{

private:
    int id;                      // ID contido no vértice
    float pesoNo;                  // Peso do nó
    vector<Aresta*> arestas;     // Vetor que contém as arestas ligadas ao nó atual
    vector<Arco*> arcos;         // Vetor que contém todos os arcos que saem do nó atual (Grafo Direcionado)
    vector<No*> nos_adjacentes;  // Vetor que contem os nós adjacentes ao nó atual
    vector<No*> nos_sucessores;  // Vetor que contém os nós sucessores do nó atual (Grafo Direcionado)
    int grau;                    // Grau do vértice
    int grau_entrada;            // Grau de entrada do nó (Grafo Direcionado)
    int grau_saida;              // Grau de saída do nó (Grafo Direcionado)
    

public:
    No(int _id, float _peso);
    ~No();
    int getId();
    void setId(int id);
    int getGrau();
    void setGrau(int _grau);
    void incrementaGrau();
    int getGrauEntrada();
    void setGrauEntrada(int _grau_entrada);
    void incrementaGrauEntrada();
    int getGrauSaida();
    void setGrauSaida(int _grau_saida);
    void incrementaGrauSaida();
    float getPesoNo();
    void setPesoNo(float peso);
    vector<Aresta*> getArestas();
    Aresta* getPrimeiraAresta();
    void adcAresta(No *n, int peso);
    vector<Arco*> getArcos();
    void adcArco(No *n, int peso);
    vector<No*> getNosAdj();
    vector<No*> getNosSuc();

};

#endif
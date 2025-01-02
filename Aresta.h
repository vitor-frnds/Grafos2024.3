#ifndef ARESTA_H 
#define ARESTA_H 

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include <stdio.h> 

#include "No.h" 

using namespace std; 

class No;

class Aresta 
{ 

private:
    No *no1;    // Nó ao qual a aresta está ligada 
    No *no2;    // Nó ao qual a aresta está ligada 
    float peso;   // Peso da aresta 


public: 
    Aresta(No *_no1, No *_no2, float _peso); 
    ~Aresta(); 
    No *getNo1(); 
    void setNo1(No *_no1); 
    No *getNo2(); 
    void setNo2(No *_no2); 
    float getPeso(); 
    void setPeso(float _peso); 
}; 
 
#endif 
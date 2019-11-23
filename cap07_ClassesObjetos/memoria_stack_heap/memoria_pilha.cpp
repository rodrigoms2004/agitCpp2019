/*
Memoria padrão na pilha/stack

Windows: 1MB
Linux: 8MB

Cada processo linux tem 8MB de memoria de pilha

Cada thead no linux tem 8MB de memoria de pilha


Se precisar de mais memoria, usar heap (ponteiro)

double *v = double[1100000]

tipos de memoria:

local, menor de 8 MB, dentro das funções
global, até 8MB na stack do linux
heap, toda a memória da máquina

*/

// g++ -o memoria_pilha.o memoria_pilha.cpp

#include <iostream>

using namespace std;

class Teste {
  public: 
  int x = 0;
  Teste() {
    cout << "Teste()\n";
  }

  Teste(const Teste &other) {
    cout << "Teste(const Teste &other)";
  }

  ~Teste() {
    cout << "~Teste()\n";
  }

  void imprimir() const 
  {
    cout << "Olá!\n";
  }
};


int main() {

  // int m; memoria local (pilha ou Stack)
  // int m = 10000000000;

  // double *v = new double[1100000];

  // for (int i = 0; i < 10; ++i)
  //   cout << v[i] << endl;
  // return 0;
  
  // CRIAR UM OBJETO NA HEAP EXIGE A DELEÇÃO DELE

  Teste *heap = new Teste[10];


  delete []heap;


}


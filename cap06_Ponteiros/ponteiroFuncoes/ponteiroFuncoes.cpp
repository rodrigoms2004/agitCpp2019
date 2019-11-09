#include <iostream>
#include "entrada.h"

using namespace std;

// g++ -o ponteiroFuncoes.o ponteiroFuncoes.cpp entrada.cpp entrada.h

int main() {
  int x = 5;

  cout << "-main: conteudo de 'x':" << x << '\n';
  cout << "-main: endereço de 'x':" << &x << '\n';

  // chama função 'validar_entrada', passando o endereço de 'x'
  if ( validar_entrada(&x) ) {
    cout << "\n-main: conteudo de 'x' apos 'validar_entrada' = " << x << '\n';
  }

  return 0;
}
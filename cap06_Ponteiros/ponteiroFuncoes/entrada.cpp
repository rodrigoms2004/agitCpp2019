#include <iostream>
#include <limits>
#include "entrada.h"

using namespace std;

bool validar_entrada(int * param_ptr) {
  cout << "\nvalidar_entrada\n";
  cout << "conteudo de param_ptr = " << param_ptr << "\n";
  cout << "endereço de &param_ptr = " << &param_ptr << "\n";
  cout << "conteudo inicialmente apontado por  *param_ptr = " << *param_ptr << "\n";
  cout << "\nentre com um numero inteiro:";
  cin >> *param_ptr;  // alterando a memoria apontada

  if (cin.fail()) {
    cout << "entrada invalida\n";
    cin.clear();
    cin.ignore(std::numeric_limits<int>::max(), '\n');
    return false;
  }
  return true;
}
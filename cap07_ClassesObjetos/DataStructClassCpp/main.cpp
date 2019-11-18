#include "data.h"
#include <iostream>

// g++ -o main.o  main.cpp data.h data.cpp -std=c++11

using namespace std;

int main() {

  // Data hoje(8, 2, 1800);
  // hoje.imprimir();

  // hoje.alterar(9, 6, 2020);
  // hoje.imprimir();

  // hoje.alterar(9, 7, 1996);
  // hoje.imprimir();

  // hoje.alterar(9, 8, 1996);
  // hoje.imprimir();

  // hoje.alterar(9, 9, 1996);
  // hoje.imprimir();

  Data d1;
  d1.alterar(31,1,2001); d1.imprimir(); // resultado: 31/01/2001
  d1.alterar(29,2,2001); d1.imprimir(); // resultado: ERRO | Não bissexto
  d1.alterar(29,2,1997); d1.imprimir(); // resultado: ERRO | Não bissexto
  d1.alterar(29,2,1800); d1.imprimir(); // resultado: ERRO | Não bissexto
  d1.alterar(29,2,1996); d1.imprimir(); // resultado: 29/02/1996
  d1.alterar(29,2,2000); d1.imprimir(); // resultado: 29/02/2000
  d1.alterar(31,6,2001) ; d1.imprimir(); // resultado: ERRO | Junho tem apenas 30 dias
  d1.alterar(31,7,2001) ; d1.imprimir(); // resultado: 31/07/2001
  d1.alterar(31,8,2001) ; d1.imprimir(); // resultado: 31/08/2001
  d1.alterar(31,9,2001) ; d1.imprimir(); // resultado: ERRO | Setembro tem apenas 30 dias
  d1.alterar(31,12,2001); d1.imprimir(); // resultado: 31/12/2001

  return 0;
}

#include "data.h"
#include <iostream>
#include <list>

// g++ -o main.o  main.cpp data.h data.cpp -std=c++11

using namespace std;

void testarDatas (const Data&, const Data&);

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


  Data pagamento(23, 11, 2019), vencimento1(23, 11, 2019)
                              , vencimento2(23, 11, 2018)  
                              , vencimento3(23, 11, 2020)
                              , vencimento4(23, 11, 2019)  
                              , vencimento5(23, 10, 2018)
                              , vencimento6(23, 12, 2020)
                              , vencimento7(23, 11, 2019)
                              , vencimento8(22, 11, 2018)  
                              , vencimento9(24, 11, 2020);  


  list<Data> listaDatasVencimento;

  // validando ano 
  listaDatasVencimento.push_back(vencimento1);
  listaDatasVencimento.push_back(vencimento2);
  listaDatasVencimento.push_back(vencimento3);

  // validando mes
  listaDatasVencimento.push_back(vencimento4);
  listaDatasVencimento.push_back(vencimento5);
  listaDatasVencimento.push_back(vencimento6);

  // validando dia
  listaDatasVencimento.push_back(vencimento7);
  listaDatasVencimento.push_back(vencimento8);
  listaDatasVencimento.push_back(vencimento9);

  
  for (list<Data>::iterator it = listaDatasVencimento.begin(); it != listaDatasVencimento.end(); it++) {
    int currentIndex = distance(listaDatasVencimento.begin(), it);
    // cout << currentIndex << endl;

    if (currentIndex == 0) {
      cout << "\nValidando anos" << endl;
    }

    if (currentIndex == 3) {
      cout << "\nValidando meses" << endl;
    }

    if (currentIndex == 6) {
      cout << "\nValidando dias" << endl;
    }

    testarDatas(pagamento, *it);
    // it->imprimir();
  }

  return 0;
}

void testarDatas (const Data &pagamento, const Data &vencimento) {

  // usando sobrecarga de operadores
  if(pagamento > vencimento)
  {
    cout << "Pagamento adiantado!\n";
  }
  else if(pagamento == vencimento)
  {
    cout << "No prazo!\n";
  }
  else if(pagamento < vencimento)
  {
    cout << "Atrasado!\n";
  }


  // if(pagamento.comparar(vencimento) > 0)
  // {
  //   cout << "Pagamento adiantado!\n";
  // }
  // else if(pagamento.comparar(vencimento) == 0)
  // {
  //   cout << "No prazo!\n";
  // }
  // else if(pagamento.comparar(vencimento) < 0)
  // {
  //   cout << "Atrasado!\n";
  // }
}
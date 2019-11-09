#include <iostream>

using namespace std;


// g++ -o prototipos01.o prototipos01.cpp 

int SomaNumeros(int, int);    // protótipo da função soma

// função tutorial
int fatorial(int num) {
  
  if (num == 0 || num == 1) {
    return 1;
  }

  return  num * fatorial(num - 1);
}

int main() {
  cout << "fatorial de 5 = " << fatorial(5) << "\n";

  cout << "soma dos números entre 1 e 10 = " << SomaNumeros(1, 10) << "\n";
}

int SomaNumeros(int inicial, int final) {
  return inicial + final;
}


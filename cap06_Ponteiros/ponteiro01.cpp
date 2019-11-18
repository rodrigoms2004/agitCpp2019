#include <iostream>

using namespace std;

int main() {
  int x = 5;

  // int *p;       // o ponteiro p poderá armazenar o endereço de objetos do tipo int
  int *p = &x;  // copia o endereço de x para p

  
  int y = *p;   // acessa a memória apontada por 'p' e copia seu valor para 'y'

  cout << "Valor de x = " << x << "\n";               // 5
  cout << "Valor de p = " << p << "\n";               // 0x7ffd99620b48
  cout << "Valor apontado por p = " << *p << "\n";    // 5
  cout << "Endereço de p = " << &p << "\n";           // 0x7ffd99620b50
  cout << "Endereço de &x = " << &x << "\n";          // 0x7ffd99620b48
  cout << "Valor de y = " << y << "\n";               // 5
  cout << "Endereço de &y = " << &y << "\n";          // 0x7ffd99620b4c

  int **pp = &p;
  cout << "Valor de pp = " << pp << "\n";               // 0x7ffd99620b50
  cout << "Valor apontado por pp = " << *pp << "\n";    // 0x7ffd99620b48
  cout << "Valor apontado por *pp = " << **pp << "\n";  // 5
  cout << "Endereço de pp = " << &pp << "\n";           // 0x7ffcd8bc4bc8

  return 0;
}
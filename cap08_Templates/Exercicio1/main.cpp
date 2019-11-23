#include <iostream>
 
using namespace std;


template<typename T>
T menor(T a, T b) {
  return (a < b ? a : b);
}

template<typename T>
T maior(T a, T b) {
  return (a > b ? a : b);
}

template<typename T>
T soma(T a, T b) {
  return a + b;
}


int main() {

  int a = 10, b = 7;
  double c = 40.1, d = 37.3;
  string e = "Rodrigo", f = " Silveira";
  
  cout << "Menor valor entre " << a << " e " << b << " é " << menor<int>(a, b) << endl;
  cout << "Menor valor entre " << c << " e " << d << " é " << menor<double>(c, d) << endl << endl;

  cout << "Maior valor entre " << a << " e " << b << " é " << maior<int>(a, b) << endl;
  cout << "Maior valor entre " << c << " e " << d << " é " << maior<double>(c, d) << endl << endl;

  cout << "A soma entre " << a << " e " << b << " é " << soma<int>(a, b) << endl;
  cout << "A soma entre " << c << " e " << d << " é " << soma<double>(c, d) << endl << endl;

  cout << "A soma entre " << e << " e " << f << " é " << soma<string>(e, f) << endl;

  return 0;
}




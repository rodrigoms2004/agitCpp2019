#include <iostream>

int Maximo(int x, int y)
{
  if (x > y) {
    return x;
  } else {
    return y;
  }
}

int main() {
  int a, b, c;
  a = 10;
  b = 20;

  c = Maximo(a, b);

  std::cout << "O maior valor entre " << a << " e " << b << " = " << c << "\n" ;

  return 0;
}
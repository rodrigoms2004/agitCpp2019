#include <iostream>

using namespace std;

int main() 
{
  int valor_produto, valor_imposto, valor_venda, valor_pago;

  while(1) {
    cout << "\nDigite numeros. Para interromper,"
              << "digite algo invalido (uma letra):\n\n";
    
    cout << "-(a) Informe o valor do produto:";
    cin >> valor_produto;
    if (cin.fail()) { break; }

    cout << "-(b) Informe o valor do imposto:";
    cin >> valor_imposto;
    if (cin.fail()) { break; }

    cout << "-(c) Informe o valor pago:";
    cin >> valor_pago;
    if (cin.fail()) { break; }

    cout << "\n";

    valor_venda = valor_produto + valor_imposto;

    if (valor_pago < valor_venda) {
      cout << "*** Valor pago: menor. Faltou = "
                  << valor_venda - valor_pago << "\n";
    } else {
      cout << "*** Completar venda\n";
      if (valor_pago > valor_venda) {
        cout << "*** Devolver o troco = "
                  << valor_pago - valor_venda << "\n";
      }
    }
  }

  cout << "\nfim do programa\n";
  return 0;
}
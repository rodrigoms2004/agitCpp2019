#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  cout << "===a.testando string\n";
  string nome;
  nome = "Maria";
  cout << nome << "\n";
  nome = nome + " da Silva";
  cout << nome << "\n";

  cout << "\n=== b.testando vector\n";

  const unsigned int trimestres_ano = 4;

  vector <double> vendas_trimestres;

  vendas_trimestres.resize(trimestres_ano);

  cout << "informe total de vendas de cada trimestre:\n";

  unsigned int index;
  for (index = 0; index < trimestres_ano; index++) {
    cout << "Informe o trimestre:" << index + 1 << "\n";
    cin >> vendas_trimestres[index];
  }
  
  cout << "\nimprimindo os valores informados:\n";
  double total_ano = 0;
  for ( index = 0 ; index < trimestres_ano ; index = index + 1 ) {
    cout << vendas_trimestres [ index ] << "\n" ;
    total_ano = total_ano + vendas_trimestres [ index ] ;
  }
  // imprime o total do ano:
  cout << "\ntotal vendas no ano : " << total_ano << "\n" ;

  return 0;
}
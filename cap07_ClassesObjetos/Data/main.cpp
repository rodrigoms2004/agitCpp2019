#include <iostream>

using namespace std;

struct Data {
  int m_dia;
  int m_mes;
  int m_ano;
  int m_ok;
};

void inicializar(struct Data *data) {
  // (*data).m_ok = 0;
  data->m_ok = 0;
}

void alterar(struct Data &data, int dia, int mes, int ano) {
  data.m_ano = ano;
  data.m_mes = mes;
  data.m_dia = dia;

  if (data.m_dia >= 1 && data.m_dia <= 31 &&
      data.m_mes >= 1 && data.m_mes <= 12 &&
      data.m_ano >= 1900 && data.m_ano <= 2100) {
        data.m_ok = 1;
      } else {
        data.m_ok = 0;
      }
}

void imprimir (const Data &data) {  // não permite alterar data, const = read only

  if (data.m_ok) {
    cout << data.m_dia << '/'
        << data.m_mes << '/'
        << data.m_ano << '\n';
  } else
  {
    cout << "Data invalida" << endl;
  }

}

int main() {

  struct Data hoje;
  inicializar(&hoje);
  alterar(hoje, 9, 11, 2019);
  imprimir(hoje);


  return 0;
}

#include "data.h"
#include <iostream>

using namespace std;

void Data::alterar(short dia, short mes, short ano) {
  m_ano = ano;
  m_mes = mes;
  m_dia = dia;

  validar();
}

void Data::imprimir () const  // não permite alterar, const = read only
{  
  string anoBissextoStr = anoBissexto() ? "SIM" : "NÃO";

  if (m_ok) {
    cout << m_dia << '/'
        << m_mes << '/'
        << m_ano << '\n'
        << "Ultimo dia do mês: " << ultimoDiaMes() << '\n'
        << "Ano bissexto: " << anoBissextoStr << endl << endl;
  } else
  {
    cout << "Data invalida" << endl;
  }
}

int Data::comparar(const Data &other) const 
{

  return ( m_ano < other.m_ano ? 1 : ( m_ano > other.m_ano ) ? -1 : (
    // se os anos forem iguais, compara os meses
    m_mes < other.m_mes ? 1 : ( m_mes > other.m_mes ) ? -1 : (
      // se os meses forem iguais, compara os dias
      m_dia < other.m_dia ? 1 : ( m_dia > other.m_dia ) ? -1 : 0)
    ) 
  );
}




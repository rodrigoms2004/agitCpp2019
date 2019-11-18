#include "data.h"
#include <iostream>

using namespace std;

Data::Data(short dia, short mes, short ano) {
  alterar(dia, mes, ano);
}

void Data::validar()
{
  m_ok = m_dia >= 1       && m_dia <= ultimoDiaMes() &&
         m_mes >= 1       && m_mes <= 12             &&
         m_ano >= ANO_MIN && m_ano <= ANO_MAX;
}

short Data::ultimoDiaMes() const
{
  if(m_mes == FEVEREIRO && anoBissexto()) {
    return 29;
  } else if (m_mes == FEVEREIRO && !anoBissexto()) {
    return 28;
  } else if ( (m_mes & 1) && m_mes <= 7) {  // meses impares, janeiro a julho
    return 31;
  } else if ( !(m_mes & 1) && m_mes <=7) {  // meses pares, janeiro a julho
    return 30;
  } else if ( (m_mes & 1) && m_mes > 7) {   // meses impares, agosto a dezembro
    return 30;
  } else {                                  // messes pares, agosto a dezembro
    return 31;
  }
  return (m_mes == FEVEREIRO) ? 28 + anoBissexto() : // se for bissexto soma 28 + 1 = 29, senão 28 + 0 = 28
            30 + (
              (m_mes & 1) // se m_mes, impar = 1, par = 0
              ^ (m_mes > JULHO)); // se > JULHO, resulta 0, senão resuta em 1
                                  // ^ é o operador XOR bitwise    
                                  // mês par ente jan e jul = 0^0 + 30 = 30 dias
                                  // mês impar ente jan e jul = 1^0 + 30 = 31 dias

                                  // mês par ente ago e dez = 0^1 + 30 = 31 dias
                                  // mês impar ente ago e dez = 1^1 + 30 = 30 dias

/*
  1 & 1 => 001 & 001 => 001
  2 & 1 => 010 & 001 => 000
  3 & 1 => 011 & 001 => 001
  4 & 1 => 100 & 001 => 000

  impar & 1 = 1
  par & 1 = 0
*/


  // return (m_mes == FEVEREIRO) ? 28 + anoBissexto() :
  //                                   30 + ((m_mes & 1) ^ (m_mes > JULHO));
}

bool Data::anoBissexto() const 
{
  // return ((m_ano % 4 == 0) && (m_ano % 100 != 0)) || (m_ano % 400 == 0);
  // return !(m_ano % 4) && ( (m_ano % 100) || !(m_ano % 400) );
  // return !(m_ano & 3) && ( (m_ano % 100) || !(m_ano % 400) );
  return (!(m_ano & 3) && (m_ano % 100)) || !(m_ano % 400);
}

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
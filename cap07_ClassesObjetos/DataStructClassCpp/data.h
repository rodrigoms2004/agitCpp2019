#ifndef DATA_H
#define DATA_H

// EVITAR INCLUDE NO HEADER

/*
  struct = por default todos os métodos e propriedades são public
  class = por default todos os métodos e propriedades são private
*/

// struct Data {
class Data 
{

  short m_dia = 0;
  short m_mes = 0;
  short m_ano = 0;
  bool m_ok = false;
  mutable int contador = 0;   // permite alterações mesmo em métodos const

public:
  enum {ANO_MIN = 1800, ANO_MAX = 2100};  
  enum {FEVEREIRO = 2, JULHO = 7};
 
// C++ 03
  // Data() : m_ok(false) {}

  // C++ 11
  // Data()
  // {
  //   m_ok = false;
  // }
  Data() = default;


  inline Data(short dia, short mes, short ano) {
    alterar(dia, mes, ano);
  }

  inline void validar()
  {
    m_ok = m_dia >= 1      && m_dia <= ultimoDiaMes() &&
          m_mes >= 1       && m_mes <= 12             &&
          m_ano >= ANO_MIN && m_ano <= ANO_MAX;
  }


  inline short ultimoDiaMes() const
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

  inline bool anoBissexto() const 
  {
    // return ((m_ano % 4 == 0) && (m_ano % 100 != 0)) || (m_ano % 400 == 0);
    // return !(m_ano % 4) && ( (m_ano % 100) || !(m_ano % 400) );
    // return !(m_ano & 3) && ( (m_ano % 100) || !(m_ano % 400) );
    return (!(m_ano & 3) && (m_ano % 100)) || !(m_ano % 400);
  }

  void alterar(short dia, short mes, short ano);

  void imprimir () const;

  int comparar(const Data &other) const;

  // sobrecarga de operadores
  
  inline bool operator<(const Data &other) const
  {
    return comparar(other) < 0;
  }
  
  inline bool operator>(const Data &other) const
  {
    return comparar(other) > 0;
  }
  
  inline bool operator==(const Data &other) const
  {
    return comparar(other) == 0;
  }
  
  inline bool operator!=(const Data &other) const
  {
    return comparar(other) != 0;
  }

  inline bool operator>=(const Data &other) const
  {
    return comparar(other) >= 0;
  }

  inline bool operator<=(const Data &other) const
  {
    return comparar(other) <= 0;
  }



};



#endif

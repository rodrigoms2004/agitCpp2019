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

  Data(short dia, short mes, short ano);

  void validar();

  void alterar(short dia, short mes, short ano);

  short ultimoDiaMes() const;

  void imprimir () const;

  bool anoBissexto() const;

};



#endif

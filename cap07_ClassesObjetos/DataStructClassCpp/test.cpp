#include <iostream>

using namespace std;


bool anoBissexto(short m_ano) 
{
  cout << m_ano << endl;
  return (m_ano % 400 == 0) || ((m_ano % 4) && (m_ano % 100 != 0));
}


int main() 
{
  cout << anoBissexto(1996);
  return 0;
}
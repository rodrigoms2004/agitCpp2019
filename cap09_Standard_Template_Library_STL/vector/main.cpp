#include <iostream>
#include <exception>
#include <string>

using namespace std;

template<typename TIPO>
class Vector
{
  TIPO *m_elements = nullptr;
  int m_size = 0;
public:
  Vector() = default;

  ~Vector() 
  {
    clear();
  }

  // Construtor de move O(1)
  Vector(Vector &&other)
  {
    m_size = other.m_size;
    m_elements = other.m_elements;
    other.m_size = 0;
    other.m_elements = nullptr;
  }

  // Construtor de cópia O(n)
  Vector(const Vector &other)
  {
    if(other.m_size) 
    {
      m_size = other.m_size;
      m_elements = new TIPO[m_size];
  
      for (int i = 0; i < m_size; ++i) 
      {
        m_elements[i] = other.m_elements[i];
      }      
    }  
  }

  inline int size() const
  {
    return m_size;
  }

  TIPO &operator[](int index) const
  {
    if(index > (m_size - 1) || index < 0)
    {
      throw range_error("Invalid index");
    } 
    
    return m_elements[index];
  }

  void clear()
  { 
    if(m_elements)
    {
      delete [] m_elements;
    }
    m_size = 0;
  }

  void push_back(const TIPO &value)
  {
    TIPO *temp = new TIPO[m_size + 1];
    for(int i = 0; i < m_size; ++i)
    {
      temp[i] = m_elements[i];
    }
    temp[m_size] = value;
    if(m_elements)
    {
      delete [] m_elements;
    }

    m_elements = temp;
    ++m_size;
  }

  void push_back(TIPO &&value)
  {
    TIPO *temp = new TIPO[m_size + 1];
    for(int i = 0; i < m_size; ++i)
    {
      temp[i] = move(m_elements[i]);
    }
    temp[m_size] = move(value);
    if(m_elements)
    {
      delete [] m_elements;
    }

    m_elements = temp;
    ++m_size;

  }

};

int main()
{
  string nome = {"Rodrigo"};
  Vector<string> nomes;

  cout << "nome: " << nome << endl;
  nomes.push_back(move(nome));
  // nomes.push_back(nome);
  cout << "nome: " << nome << endl;
  cout << "nomes[0]: " << nomes[0] << endl;

  Vector<int> v;

  for (int i = 0; i < 11; ++i)
  {
    v.push_back(i);
  }
  
  for (int i = 0; i < v.size(); ++i)
  {
    cout << v[i] << endl;
  }



}
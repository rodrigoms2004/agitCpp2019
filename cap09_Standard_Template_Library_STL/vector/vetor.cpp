#include <chrono>
#include <iostream>
#include <exception>

// https://www.google.com/search?q=gcc+optimization+flags&oq=gCC+op&aqs=chrome.1.69i57j0l7.4213j0j4&sourceid=chrome&ie=UTF-8
// g++ -o vetor.o -O3 vetor.cpp 

// gcc -O option flag
// option	    optimization level	                                code size
// -O0	        optimization for compilation time (default)	        +
// -O1 or -O	  optimization for code size and execution time	      -
// -O2	        optimization more for code size and execution time	
// -O3	        optimization more for code size and execution time

using namespace std;
using namespace chrono;

template <typename TIPO>
class Vetor
{
    TIPO *m_elements = nullptr;
    int m_size = 0;
public:
    Vetor() = default;

    ~Vetor()
    {
        clear();
    }

    Vetor(Vetor &&other)
    {
        cout << "Vetor(&&)\n";
        m_size = other.m_size;
        m_elements = other.m_elements;
        other.m_size = 0;
        other.m_elements = nullptr;
    }

    Vetor(const Vetor &other)
    {
        cout << "Vetor(&)\n";
        if(other.m_size)
        {
            m_size = other.m_size;
            m_elements = new TIPO[m_size];
            for(int i = 0; i < m_size; ++i)
            {
                m_elements[i] = other.m_elements[i];
            }
        }
    }

    void clear()
    {
        if(m_elements)
        {
            delete [] m_elements;
        }
        m_size = 0;
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

    void push_back(const TIPO &value)
    {
        TIPO *temp = new TIPO[m_size + 1];
        for(int i = 0; i < m_size; ++i)
        {
            temp[i] = move(m_elements[i]);
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
    const int max = 100000;
    Vetor<int> numeros;
    auto inicio = high_resolution_clock::now();

    for(int i = 0; i < max; ++i)
        numeros.push_back(i);

    auto fim = high_resolution_clock::now();

    cout << "Tempo: " << duration_cast<microseconds>(fim - inicio).count();

    return 0;
}
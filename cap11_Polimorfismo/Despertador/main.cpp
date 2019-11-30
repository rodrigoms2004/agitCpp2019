#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <mutex>

// LIBS += -pthread
// g++ -o main.o main.cpp -lpthread

using namespace std;
using namespace chrono;

mutex mu;

class Despertador 
{
  void pausar(int ms)
  {
    this_thread::sleep_for(milliseconds(ms));
  }
protected:
  virtual bool executar() = 0;  // método abstrato
public:
  Despertador() 
  {
    cout << "Despertador()\n";
  }
  virtual ~Despertador()
  {
    cout << "~Despertador()\n";
  }

  void iniciar(int ms)
  {
    while(executar())
      pausar(ms);
  }
};

class ChecarEmail: public Despertador
{
  bool executar() override
  {
    mu.lock();
    cout << "Checando e-mail...\n";
    mu.unlock();
    return true;
  }
public:
  ChecarEmail()
  {
    mu.lock();
    cout << "ChecarEmail()\n";
    mu.unlock();
  }

  ~ChecarEmail()
  {
    cout << "~ChecarEmail()\n";
  }
};

// final = não é possivel derivar da classe, é classe final
class ChecarSMS final: public Despertador
{
  bool executar() override
  {
    cout << "Checando SMS...\n";
    return true;
  }
};


int main() 
{
  // funções lambda
  thread th1([]{ ChecarEmail().iniciar(1000); });
  thread th2([]{ ChecarSMS().iniciar(1000); });

  th1.join();
  th2.join();

  return 0;
}
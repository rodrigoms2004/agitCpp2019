#include <iostream>
 
using namespace std;


class Teste
{
    int *p_i;

public:
    Teste(int x)//Aloca um inteiro no heap
    {
        p_i = new int(x);
    }

    // solução, criar um contrutor de cópia
    Teste(const Teste &t)
    {
      p_i = new int;    // aloca um novo endereço na heap
      *p_i = t.getI();  // atribui o valor nesse novo endereço
    }

    ~Teste()//Quando o destrutor é chamado ele desaloca a memória
    {
        delete p_i;
    }

    int getI() const { return *p_i; }
    int *adress() { return p_i; }

        // solução ao problema b = a, constutor de atribuição
    Teste & operator = (const Teste &t)
    {
        //p_i = new int(t.getI());  // aloca um novo endereço na heap com o valor do objeto passado ('a' no caso)
        *p_i = t.getI();
        return *this;             // retorna o valor desse endereço, para ser atribuido em 'b'
    }
};
 
int main()
{
    Teste a(20);//Cria um objeto da classe teste
    cout << "a: " << a.getI() << '\n';//Imprime o valor de p_i, nesse caso: 20
    cout << "a.adress: " << a.adress() << "\n\n";
    {
        Teste b(0);//O compilador gerou um construtor de copia

        b = a; // segundo problema

        //Agora tudo que estava em a será copiado para b
        cout << "b: " << b.getI() << '\n';//Imprime o valor de p_i, nesse caso: 20
        cout << "b.adress: " << b.adress() << "\n\n"; //Como 'b' é uma cópia de 'a' getI retornará 20
    }//Ao chegar aqui o destrutor de 'b' é chamado, desalocando o valor alocado por
    //p_i, mas como a.p_i e b.p_i apontavam para a mesma
    //região de memória agora a.p_i apontará para um valor nulo.
    cout << "a: " << a.getI() << '\n';//Podemos ter erro em tempo de execução
    cout << "a.adress: " << a.adress() << "\n\n";
    return 0;
}
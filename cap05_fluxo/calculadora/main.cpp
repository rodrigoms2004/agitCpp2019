#include <iostream>
#include "calculadora.h"

// g++ -o calculadora.o main.cpp calculadora.cpp calculadora.h

using namespace std;

int numA, numB;

void lerDados()
{
    cout << "Digite numA: ";
    cin  >> numA;
    cout << "Digite numB: ";
    cin  >> numB;
}

int main()
{
    bool continua = true;
    int opcao;

    while(continua)
    {
        cout << "1 operação & (bit a bit)\n" <<
                "2 operação | (BIT a BIT)\n" <<
                "3 Números pares com o operador %\n" <<
                "4 Números pares com o operador &\n";

        cin >> opcao;

        switch(opcao)
        {
            case 1:
                lerDados();
                cout << operadorAnd(numA, numB) << '\n';
                break;
            case 2:
                lerDados();
                cout << operadorOr(numA, numB) << '\n';
                break;
            case 3:
                lerDados();
                paresComRestoDivisao(numA, numB);
                break;
            case 4:
                lerDados();
                paresComAndBitABit(numA, numB);
                break;
        }

        cout << "Deseja prosseguir? 0 = Nao e 1 = Sim: ";
        cin >> continua;
    }
    return 0;
}

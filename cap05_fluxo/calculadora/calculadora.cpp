#include "calculadora.h"
#include <iostream>

using namespace std;

int operadorAnd(int a, int b)
{
    return a & b;
}

int operadorOr(int a, int b)
{
    return a | b;
}

void paresComRestoDivisao(int a, int b)
{
    cout << '\n';
    for(int i = a; i <= b; ++i)
    {
        if(i % 2 == 0)
        {
            cout << i << '\n';
        }
    }
    cout << '\n';
}

void paresComAndBitABit(int a, int b)
{
    cout << '\n';
    for(int i = a; i <= b; ++i)
    {
        if((i & 1) == 0)
        {
            cout << i << '\n';
        }
    }
    cout << '\n';
}
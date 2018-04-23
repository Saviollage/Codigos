#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

int main()
{
    srand(time(0));
    int tam = 5;

    int soma = 0;
    int cont = 0;

    int A[tam];
    int B[tam];

    for (int i = 0; i < tam; i++) //preenchendo A e B com valores aleatórios
    {
        A[i] = rand() % 20;
        B[i] = rand() % 20;
    }

    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
        {
           if(j>i){
            soma = A[i] + A[j];

            for (int z = 0; z < tam; z++)
                if (soma == B[z])
                    cont++;
           }
        }

    cout << "Encontramos " << cont << " combinações! \n";

    for (int i = 0; i < tam; i++)
    {
        cout << A[i] << '\t';
    }
    cout << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << B[i] << '\t';
    }

    return 0;
}
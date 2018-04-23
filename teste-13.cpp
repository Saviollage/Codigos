#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

int main()
{
    srand(time(0));
    int tam = 10;
    int a[tam];

    int max = 0;
    int aux = 0;

    for (int i = 0; i < tam; i++) //Preenchendo o vetor com numeros aleatorios
        a[i] = rand() % 25;

    for (int i = 0; i < tam - 1; i++)        //Depois do vetor pronto começa o loop
        for (int j = i; j < tam; j++)
        {                                   //aqui garantimos j >= i
            aux = a[j] - a[i];
            if (aux > max)
                max = aux;
        }

    for (int i = 0; i < tam; i++)
        cout << a[i] << '\t';
    cout << "\nValor máximo de a[j]-a[i] = " << max << '\n';
    return 0;
}
#include <iostream>

using namespace std;

struct No
{
    char info = 0;
    No *AptEsquerda = NULL;
    No *AptDireita = NULL;
};

void Mostra(No *a, int n)
{
    if (a)
    {
        int i;
        Mostra(a->AptDireita, n + 1);
        for (i = 0; i < n; i++)
            cout << "\t";
        cout << " " << a->info << endl;
        Mostra(a->AptEsquerda, n + 1);
    }
}

void Insere(No *arv)
{ //insere um novo nivel a cada chamada da funcao
    if (arv->AptEsquerda == NULL && arv->AptDireita == NULL)
    {
        arv->AptEsquerda = new No;
        arv->AptEsquerda->info = '0';
        arv->AptEsquerda->AptEsquerda = NULL;
        arv->AptEsquerda->AptDireita = NULL;

        arv->AptDireita = new No;
        arv->AptDireita->info = '1';
        arv->AptDireita->AptDireita = NULL;
        arv->AptDireita->AptEsquerda = NULL;
    }

    else if (arv)
    {
        Insere(arv->AptEsquerda);
        Insere(arv->AptDireita);
    }
}

void remove(No *a)
{
    delete a;
}



int main()
{
    No *Arv = new No;
    Arv->info = 'X';
    Arv->AptDireita = NULL;
    Arv->AptEsquerda = NULL;
    string t;
    int tam = 4;
    for (int i = 0; i < tam; i++)
        Insere(Arv);

    Mostra(Arv, 0);
   

    return 0;
}

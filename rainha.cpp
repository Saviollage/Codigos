#include <iostream>
using namespace std;

//SÁVIO HENRIQUE M. LAGE    2016003268
//BRENNER BATISTA ROCHA     2016008193

int tamanho = 15;

int tam = tamanho * tamanho;

bool verificaAtaque(int tab[], int lin, int col)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (tab[lin * tamanho + i] == 1) //verifica se a linha ta livre
            return false;
        if (tab[i * tamanho + col] == 1) //verifica se a coluna ta livre
            return false;
    }

    for (int i = lin, j = col; i < tamanho && j < tamanho; i++, j++) //verifica diagonal 
        if (tab[i * tamanho + j] == 1)
            return false;
    for (int i = lin, j = col; i >= 0 && j < tamanho; i--, j++) //verifica diagonal 
        if (tab[i * tamanho + j] == 1)
            return false;
    for (int i = lin, j = col; i < tamanho && j >= 0; i++, j--) //verifica diagonal 
        if (tab[i * tamanho + j] == 1)
            return false;
    for (int i = lin, j = col; i >= 0 && j >= 0; i--, j--) //verifica diagonal
        if (tab[i * tamanho + j] == 1)
            return false;

    return true; //retorna verdadeiro se a situação ta top
}

void insere(int tab[], int col, int &quantSolucao)
{

    if (col == tamanho) //verifica se consegui colocar todas as rainhas no tabuleiro
    {
        quantSolucao++; //aumenta a solucao

        cout << "\nSolucao " << quantSolucao << ": \n"; //mostra a solucao e como fica o tabuleiro
        
        for (int i = 0; i < tamanho; i++) //mostra o tabuleiro com  solucao em questao
        {
            cout << endl;
            for (int j = 0; j < tamanho; j++)
            {
                cout << '\t' << tab[i * tamanho + j];
            }
        }
        cout << endl;
    }
    else
    {

        for (int i = 0; i < tamanho; i++)    //anda todas as linhas da coluna
            if (verificaAtaque(tab, i, col)) //verifica se a situação ta favoravel
            {
                tab[i * tamanho + col] = 1; //se tiver coloca a rainha

                insere(tab, col + 1, quantSolucao); //add a rainha na coluna seguinte

                tab[i * tamanho + col] = 0; // se saiu foi pq ja terminou o laço e ja vimos todas as possibilidades com a rainha nessa posicao,
                                            //entao zera ela pra colocar a rainha na linha abaixo
            }
    }
}

int main()
{
    int tab[tam];
    int quantSolucao = 0;

    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
        {
            tab[i * tamanho + j] = 0;
        } //joga tudo como 0

    insere(tab, 0, quantSolucao); //inicia a brincadeira

    return 0;
}

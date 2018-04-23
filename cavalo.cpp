#include <iostream>
using namespace std;

//possiveis combinações para movimentos em L no tabuleiro
int linha[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int coluna[8] = {1, 2, 2, 1, -1, -2, -2, -1};


int tam = 6;


bool percorre(int tab[6][6],int contador, int lin, int col)
{
    int ppc;
    int ppl;
    bool verifica;

    if (contador > tam*tam) return true; //acabou a brincadeira e ta top
    
        for (int i = 0; i < 8; i++) //percorre o vetor das 8 possiveis formas do cavalo andar
        {
            ppc = col + coluna[i]; //proxima posicao coluna
            ppl = lin + linha[i]; //proxima posicao linha

            if (ppc >= 0 && ppc < tam && ppl >= 0 && ppl < tam) //verifica validade do tabuleiro
            {
                if (tab[ppl][ppc] == 0){ //verifica validade da casa
                    tab[ppl][ppc] = contador; //adiciona

                    verifica = percorre(tab,contador+1, ppl, ppc); //verifica as jogadas futuras

                    if (!verifica) //se retorna falso é pq deu ruim
                    tab[ppl][ppc] = 0; //se deu ruim, reinicia a casa
                    
                    else return true; //caso contrario é pq deu bom
                }
            }
        }
    
    return false; //se a parada foi pra fora do tabuleiro, significa que deu ruim
}

int main()
{
    int tab[6][6];
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            tab[i][j] = 0;

    tab[0][0] = 1;

    percorre(tab,2, 0, 0);

    for (int i = 0; i < tam; i++)
    {
        cout << endl;
        for (int j = 0; j < tam; j++)
            cout << '\t' << tab[i][j];
    }
    cout << endl;

    return 0;
}
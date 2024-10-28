#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

#define y 10
#define x 10

int posicao = 5;

void jogo(void);
void exibirMapa(char mapa[y][x]);

int main(void)
{
    while (1)
    {
        jogo();
    }

    return 0;
}
void jogo(void)
{
    // Define o mapa com diferentes tipos de terrenos, incluindo espaços vazios
    char mapa[y][x] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
    char tecla;
     // Exibe o mapa na tela
    mapa[8][posicao] = '1';
    exibirMapa(mapa);

    scanf("%c", &tecla);
    if (tecla == 'A' || tecla == 'a') {
        posicao--;
    }
    if (tecla == 'D' || tecla == 'd') {
        posicao++;
    }
}
void exibirMapa(char mapa[y][x])
{
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%c ", mapa[i][j]);
        }
        printf("\n");
    }
}
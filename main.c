#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define y 10
#define x 10

int posicao = 5;
void menu(void);
void jogo(void);
void comandos(int *vivo);
int sair();
int sairMenu = 1;
void exibirMapa(char mapa[y][x]);
void atualizarMapa(char mapa[y][x]);

int main(void)
{
    setlocale(LC_ALL, "UTF-8");

    do
    {
        menu();
    } while (sairMenu);

    return 0;
}

void jogo(void)
{
    int vivo = 1;

    do
    {
        system("cls");
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
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};
        mapa[8][posicao] = '1';
        
        atualizarMapa(mapa);
        comandos(&vivo);
    } while (vivo);
}

void atualizarMapa(char mapa[y][x])
{
    struct timespec data;
    timespec_get(&data, TIME_UTC);
    long long tempo = data.tv_sec;
    printf("%lld\n", tempo);

    exibirMapa(mapa);
}

void comandos(int *vivo)
{
    char tecla = getch();

    fflush(stdin);
    if (tecla == 'A' || tecla == 'a')
    {
        posicao--;
    }
    if (tecla == 'D' || tecla == 'd')
    {
        posicao++;
    }
    if (posicao == 0)
    {
        posicao++;
    }
    if (posicao == x - 1)
    {
        posicao--;
    }
    if (tecla == 27)
    {
        *vivo = 0;
    }
}

void exibirMapa(char mapa[y][x])
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%c ", mapa[i][j]);
        }
        printf("\n");
    }
}

void menu(void)
{
    system("cls");
    printf("1 - Jogo\n2 - Placar\n3 - Sair\n");
    switch (getch())
    {
    case '1':
        jogo();
        break;
    case '3':
        sair();
        break;
    }
}

int sair()
{
    sairMenu = 0;
}
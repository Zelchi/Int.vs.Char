#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"

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
    exibirMapa(mapa);
    mapa[8][posicao] = '1';
    int vivo = 1;
    int tecla = 00;
    while (vivo)
    {
        

        if (_kbhit()) comandos(&vivo, &tecla);
    }
}

void comandos(int *vivo, int *tecla)
{
    *tecla = getch();

    fflush(stdin);
    if (*tecla == 65 || *tecla == 97)
    {
        posicao--;
    }
    if (*tecla == 68 || *tecla == 100)
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
    if (*tecla == 27)
    {
        *vivo = 0;
    }

    exibirMapa(mapa);
}

void exibirMapa(char mapa[y][x])
{
    system("cls");
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

void sair(void)
{
    sairMenu = 0;
}
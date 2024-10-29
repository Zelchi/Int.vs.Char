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
    while (vivo)
    {

        if (_kbhit())
        {
            comandos();
        }
    }
}

void comandos(void)
{
    char tecla = getch();

    fflush(stdin);
    switch (tecla)
    {
    case 'a':
        teclaA();
        break;
    case 'd':
        teclaD();
        break;
    case 27:
        teclaESC();
        break;
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
            if (i == JogadorPosicaoY && j == JogadorPosicaoX)
            {
                printf("1 ");
            }
            else
            {
                printf("%c ", mapa[i][j]);
            }
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
    case 27:
        sair();
        break;
    }
}

void sair(void)
{
    sairMenu = 0;
}
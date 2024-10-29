#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

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
    vivo = 1;
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
                printf("%c ", personagem);
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
    printf("1 - Jogo\n2 - Selecionar Personagem\n3 - Placar\n4 - Sair\n");
    switch (getch())
    {
    case '1':
        jogo();
        break;
    case '2':
        selecionarPersonagem();
        break;
    case '3':
        placar();
        break;
    case '4':
        sair();
        break;
    case 27:
        sair();
        break;
    }
}

void selecionarPersonagem()
{
    system("cls");
    printf("Escolha seu número favorito de 0 a 9: ");
    personagem = getch();
    switch (personagem)
    {
    case '0':
        personagem = '0';
        break;
    case '1':
        personagem = '1';
        break;
    case '2':
        personagem = '2';
        break;
    case '3':
        personagem = '3';
        break;
    case '4':
        personagem = '4';
        break;
    case '5':
        personagem = '5';
        break;
    case '6':
        personagem = '6';
        break;
    case '7':
        personagem = '7';
        break;
    case '8':
        personagem = '8';
        break;
    case '9':
        personagem = '9';
        break;
    default:
        system("cls");
        printf("Personagem invalido!\n");
        system("pause");
        selecionarPersonagem();
        break;
    }
}

void placar(void)
{
    system("cls");
    printf("Em desenvolvimento :(\n");
    system("pause");
}

void sair(void)
{
    sairMenu = 0;
}
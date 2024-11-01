#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"
#include "tempo.h"
#include "inimigo.h"

int main(void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    do
    {
        vivo = 1;
        menu();
    } while (sairMenu);

    return 0;
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

void jogo(void)
{
    vivo = 1;
    do
    {
        if (kbhit()) // Verifica se alguma tecla foi pressionada no teclado.
        {
            comandos();
        }
        else if (tempoDecorrido() > 1)
        {
            novoTempo();

            inimigosSpawn();
        }
        if (verificarMorte())
        {
            vivo = 0;
        }

    } while (vivo);
}

int verificarMorte()
{
    for (int i = 0; i < 27; i++)
    {
        if (inimigos[i].posicaoX == JogadorPosicaoX && inimigos[i].posicaoY == JogadorPosicaoY)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void inimigosSpawn(void)
{
    srand(time(NULL));
    int numeroAleatorio = geraNumeroAleatorio(1, 8);
    int letraAleatoria = geraNumeroAleatorio(0, 26);

    inimigos[letraAleatoria].posicaoY = 0;
    inimigos[letraAleatoria].posicaoX = numeroAleatorio;

    for (int i = 0; i < 27; i++)
    {
        if (inimigos[i].posicaoY >= 0)
        {
            inimigos[i].posicaoY++;
            exibirMapa(mapa);
        }
        if (inimigos[i].posicaoY > 8)
        {
            inimigos[i].posicaoY = -1;
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
    case 'w':
        teclaW();
        break;
    case 's':
        teclaS();
        break;
    case 27:
        teclaESC();
        break;
    }
    exibirMapa(mapa);
}

void exibirMapa(char mapa[y][x]) // Renderiza o mapa
{
    system("cls");
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            int naoRenderizouPlayer = 1;
            int naoRenderizouInimigo = 1;

            for (int k = 0; k < 26; k++)
            {
                if (i == inimigos[k].posicaoY && j == inimigos[k].posicaoX)
                {
                    printf("%c ", inimigos[k].letra);
                    naoRenderizouInimigo = 0;
                }
            }
            if (i == JogadorPosicaoY && j == JogadorPosicaoX && naoRenderizouInimigo)
            {
                printf("%c ", personagem);
                naoRenderizouPlayer = 0;
            }
            if (naoRenderizouPlayer && naoRenderizouInimigo)
            {
                printf("%c ", mapa[i][j]);
            }
        }
        printf("\n");
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
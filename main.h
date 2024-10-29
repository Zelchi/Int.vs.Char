#define y 10
#define x 10

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

// Menu
int JogadorPosicaoY = 8;
int JogadorPosicaoX = 5;
int sairMenu = 1;

void menu(void);
void sair(void);

// Jogo
void jogo(void);
void comandos();
int vivo = 1;

// Mapa
void exibirMapa(char mapa[y][x]);

// Teclas

void teclaA()
{
    if (JogadorPosicaoX > 1)
    {
        JogadorPosicaoX--;
    }
}
void teclaD()
{
    if (JogadorPosicaoX < x - 2)
    {
        JogadorPosicaoX++;
    }
}
void teclaESC()
{
    vivo = 0;
}
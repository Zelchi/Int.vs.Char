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
void menu(void);
int sairMenu = 1;

void jogo(void);
void selecionarPersonagem();
char personagem = '1';
void placar(void);
void sair(void);

// Jogo
int JogadorPosicaoY = 8;
int JogadorPosicaoX = 5;
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
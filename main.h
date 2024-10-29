#define y 10
#define x 10

int posicao = 5;
void menu(void);
void jogo(void);
void comandos(int *vivo);
void sair();
int sairMenu = 1;
void exibirMapa(char mapa[y][x]);
void atualizarMapa(char mapa[y][x]);
double pegaDiferencaDeTempoEmSegundos();
double registraNovoTempo();
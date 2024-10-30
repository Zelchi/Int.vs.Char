#include <time.h>

// Ignora essas duas funções, o importante é que o intervalo na main vai fazer o que a gente quer. :)

struct timespec ultimoFrame, novoFrame;
double tempoDecorrido()
{
    clock_gettime(CLOCK_REALTIME, &novoFrame);

    double miliSegundosAtual = (novoFrame.tv_sec * 1000.0) + (novoFrame.tv_nsec / 1e6);
    double miliSegundosFrame = (ultimoFrame.tv_sec * 1000.0) + (ultimoFrame.tv_nsec / 1e6);

    return (miliSegundosAtual - miliSegundosFrame) / 1000.0;
}

void novoTempo()
{
    clock_gettime(CLOCK_REALTIME, &novoFrame);
    ultimoFrame = novoFrame;
}

// Logica de como a função tem que ser feita:
// void exemplo()
// {
//     if (tempoDecorrido() > 1) // A cada 1 segundo;
//     {
//         novoTempo();
        
//         Código...
//     }
// }
#include "../include/util.h"

void arvore_maxima(No *arvore)
{
    if (arvore == NULL)
    {
        return;
    }

    No *maior = arvore;

    if (arvore->esquerdo != NULL && arvore->esquerdo->aeronave.prioridade > maior->aeronave.prioridade)
    {
        maior = arvore->esquerdo;
    }

    if (maior->direto != NULL && arvore->direto->aeronave.prioridade > maior->aeronave.prioridade)
    {
        maior = arvore->direto;
    }

    if (maior != arvore)
    {
        Aeronave aux = arvore->aeronave;
        arvore->aeronave = maior->aeronave;
        maior->aeronave = aux;

        arvore_maxima(maior);
    }
}
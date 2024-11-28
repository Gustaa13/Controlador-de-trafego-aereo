#include "../include/util.h"
inline

void heap_maxima(Aeronave* heap, int capacidade, int indice)
{
    if (heap == NULL)
    {
        return;
    }

    int maior = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < capacidade && heap[esquerda].prioridade > heap[maior].prioridade)
    {
        maior = esquerda;
    }

    if (direita < capacidade && heap[direita].prioridade > heap[maior].prioridade)
    {
        maior = direita;
    }

    if (maior != indice)
    {
        Aeronave aux = heap[indice];
        heap[indice] = heap[maior];
        heap[maior] = aux;

        heap_maxima(heap, capacidade, maior); 
    }
}

void construir_heap_maxima(Aeronave* heap, int capacidade){
    if (heap == NULL)
    {
        return;
    }

    for (int i = capacidade/2 - 1; i >= 0; i--)
    {
        heap_maxima(heap, capacidade, i);
    }
}

void ordenar_heap(Aeronave* heap, int capacidade) {
    construir_heap_maxima(heap, capacidade);

    for (int i = capacidade - 1; i > 0; i--) {

        Aeronave aux = heap[0];
        heap[0] = heap[i];
        heap[i] = aux;

    
        heap_maxima(heap, i, 0);
    }
}

void inserir_aeronave(Frota* frota, Aeronave aeronave){
    aumentar_frota(frota);

    frota->aeronave[frota->capacidade - 1] = aeronave;

    construir_heap_maxima(frota->aeronave, frota->capacidade);
    
}



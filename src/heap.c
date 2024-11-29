#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../include/util.h"

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

void construir_heap_maxima(Frota* frota){
    if (frota->aeronave == NULL)
    {
        return;
    }

    for (int i = frota->capacidade/2 - 1; i >= 0; i--)
    {
        heap_maxima(frota->aeronave, frota->capacidade, i);
    }
}

void ordenar_heap(Frota* frota) {
    construir_heap_maxima(frota);

    for (int i = frota->capacidade - 1; i > 0; i--) {

        Aeronave aux = frota->aeronave[0];
        frota->aeronave[0] = frota->aeronave[i];
        frota->aeronave[i] = aux;

    
        heap_maxima(frota->aeronave, i, 0);
    }
}

void inserir_na_heap(Frota* frota, Aeronave aeronave){
    
    aumentar_frota(frota);

    frota->aeronave[frota->capacidade - 1] = aeronave;

    construir_heap_maxima(frota);
}

void remover_maior_prioridade(Frota** frota){
    diminuir_frota(*frota);

    construir_heap_maxima(*frota);
}

void atualizarPrioridade(Frota* frota){
    frota->aeronave->prioridade = calculador_de_prioridade(*frota->aeronave);
    construir_heap_maxima(frota);
}

Aeronave consultar_maior_prioridade(Frota frota){
    return frota.aeronave[frota.capacidade - 1];
}





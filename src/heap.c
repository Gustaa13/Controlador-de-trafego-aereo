#include "../include/util.h"
#include <string.h>

#define MAX_LINHAS 100  
#define TAM_LINHA 1024

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

void carregarAeronave(char* nome_arquivo, Frota* heap){
    
    FILE *file = fopen(nome_arquivo, "r");

    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char line[TAM_LINHA];

    while (fgets(line, sizeof(line), file)){
        Aeronave* aeronave = malloc(sizeof(Aeronave));

        if (!aeronave){
            perror("Erro ao alocar memoria para Livro");
            fclose(file);
            return;
        }

        line[strcspn(line, "\n")] = 0;

        char *token = strtok(line, ",");
        int coluna = 0;

        while (token != NULL){
            coluna++;
            switch (coluna){
                case 1: 
                    strncpy(aeronave->indetificador, token, sizeof(aeronave->indetificador) - 1); 
                    aeronave->indetificador[sizeof(aeronave->indetificador) - 1] = '\0';
                    break;
                case 2: aeronave->combustivel = atoi(token); break;
                case 3: aeronave->horario_em_minutos = atoi(token); break;
                case 4: aeronave->tipo = atoi(token); break;
                case 5: aeronave->emergencia = atoi(token); break;
            }

             token = strtok(NULL, ",");
        }

        aeronave->prioridade = calculador_de_prioridade(*aeronave);
        inserir_aeronave(heap, *aeronave);
        free(aeronave);
    }

    fclose(file);
}



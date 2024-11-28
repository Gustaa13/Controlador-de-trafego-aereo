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

void carregar_aeronave(char* nome_arquivo, Frota* frota){
    
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
                    strncpy(aeronave->indentificador, token, sizeof(aeronave->indentificador) - 1); 
                    aeronave->indentificador[sizeof(aeronave->indentificador) - 1] = '\0';
                    break;
                case 2: aeronave->combustivel = atoi(token); break;
                case 3: aeronave->horario_em_minutos = atoi(token); break;
                case 4: aeronave->tipo = atoi(token); break;
                case 5: aeronave->emergencia = atoi(token); break;
            }

             token = strtok(NULL, ",");
        }

        aeronave->prioridade = calculador_de_prioridade(*aeronave);
        inserir_aeronave(frota, *aeronave);
        free(aeronave);
    }

    fclose(file);
}

void remover_maior_prioridade(Frota** frota){
    for (int i = 0; i < (*frota)->capacidade - 1; i++) {
        (*frota)->aeronave[i] = (*frota)->aeronave[i + 1];
    }

    diminuir_frora(*frota);

    construir_heap_maxima((*frota)->aeronave, (*frota)->capacidade);
}

void atualizarPrioridade(Frota* frota){
    frota->aeronave->prioridade = calculador_de_prioridade(*frota->aeronave);
    construir_heap_maxima(frota->aeronave, frota->capacidade);
}

void consultar_maior_prioridade(Aeronave* heap){
    printf("Aeronave com maior prioridade:\n");
    printf("Identificador: %s\n", heap[0].indentificador);
    printf("Combustivel: %d\n", heap[0].combustivel);
    printf("Horario: %d\n", heap[0].horario_em_minutos);
    printf("Tipo: %d\n", heap[0].tipo);
    printf("Emergencia: %d\n", heap[0].emergencia);
    printf("Prioridade: %d\n", heap[0].prioridade);
}

void exibirArvore(Frota* frota){
    for (int i = 0; i < frota->capacidade; i++)
    {
        printf("Aeronave %d:\n", i+1);
        printf("Aeronave com maior prioridade:\n");
        printf("Identificador: %s\n", frota->aeronave[i].indentificador);
        printf("Combustivel: %d\n", frota->aeronave[i].combustivel);
        printf("Horario: %d\n", frota->aeronave[i].horario_em_minutos);
        printf("Tipo: %d\n", frota->aeronave[i].tipo);
        printf("Emergencia: %d\n", frota->aeronave[i].emergencia);
        printf("Prioridade: %d\n", frota->aeronave[i].prioridade);
    }
}





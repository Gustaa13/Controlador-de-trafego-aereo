#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/util.h"

#define MAX_LINHAS 100  
#define TAM_LINHA 1024

Frota* iniciar_frota(){
    Frota* frota = (Frota*)malloc(sizeof(Frota));

    if (frota == NULL)
    {
        printf("Erro ao iniciar biblioteca!\n");
        return NULL;
    }

    frota->aeronave = (Aeronave*)malloc(sizeof(Aeronave));
    frota->capacidade = 1;
    return frota;
}

void aumentar_frota(Frota *frota)
{
    Aeronave *temporario = realloc(frota->aeronave, (frota->capacidade + 1) * sizeof(Aeronave));

    if (temporario == NULL)
    {
        printf("Erro ao realocar memoria!\n");
        return;
    }

    frota->aeronave = temporario;
    frota->capacidade++;
}

void diminuir_frota(Frota* frota){
    Aeronave *temporario = realloc(frota->aeronave, (frota->capacidade - 1) * sizeof(Aeronave));

    if (temporario == NULL)
    {
        printf("Erro ao realocar memoria!\n");
        return;
    }

    frota->aeronave = temporario;
    frota->capacidade--;
}

void exibir_frota(Frota* frota){
    for (int i = frota->capacidade - 1; i >= 0; i--)
    {
        printf("\n");
        exibir_aeronave(frota->aeronave[i]);
    }
}

void carregar_frota(char* nome_arquivo, Frota* frota){
    
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
            perror("Erro ao alocar memoria para aeronave");
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
        frota->aeronave[frota->capacidade - 1] = *aeronave;
        aumentar_frota(frota);
        free(aeronave);
    }

    diminuir_frota(frota);
    fclose(file);
}

void liberar_frota(Frota* frota){
    free(frota->aeronave);
    free(frota);
}


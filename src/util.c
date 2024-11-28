#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/util.h"

void menu(){
    printf("\n======== MENU PRINCIPAL ========\n\n");

    printf("Selecione uma das operacoes abaixo:\n");

    printf("1 - Cadastrar uma nova aeronave\n");
    printf("2 - Consultar maior prioridade\n");
    printf("3 - Remover maior prioridade\n");
    printf("4 - Exibir todas as aeronaves\n");
    printf("5 - Finalizar o programa\n");

    printf("\nDigite o numero da operacao desejada: ");
}

void menuOperacoes(int entrada, char* nome_arquivo){
    Aeronave aeronave;

    switch (entrada)
    {
    case 1:
        aeronave = cadastrar_aeronave();
        salvar_aeronave(nome_arquivo, aeronave);
        exibir_aeronave(aeronave);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        break;
    }
}

void limpador_de_buffer(){
    while (getchar() != '\n');
}

int leitor_de_numeros(){
    int numero;
    int resultado;

    resultado = scanf("%d", &numero);

    if(resultado != 1 || numero <= 0 || numero >= 500000){
        printf("Numero invalido!\nDigite o numero novamente: ");
        limpador_de_buffer();
        return leitor_de_numeros();
    }

    limpador_de_buffer();
    return numero;
}

int leitor_de_tipo(){
    int numero;
    int resultado;

    resultado = scanf("%d", &numero);

    if(resultado != 1 || (numero != 0 && numero != 1)){
        printf("Numero invalido!\nDigite o numero novamente: ");
        limpador_de_buffer();
        return leitor_de_numeros();
    }

    limpador_de_buffer();
    return numero;
}

char* leitor_de_palavras(){
    char* palavra = (char*)malloc(50 * sizeof(char));

    if (palavra == NULL){
        printf("Erro: Memoria insuficiente.\n");
        return NULL;
    }

    if(fgets(palavra, 50, stdin) != NULL){
        palavra[strcspn(palavra, "\n")] = '\0';
        
        if(strlen(palavra) == 49) {
            limpador_de_buffer();
        }

        return palavra;
    }else{
        printf("Erro ao ler o nome!\nDigite novamente: ");
        free(palavra);
        return leitor_de_palavras();
    }
}

int calculador_de_prioridade(Aeronave aeronave){
    int prioridade;

    prioridade = (1000 - aeronave.combustivel) + (1440 - aeronave.horario_em_minutos) + 500 * (aeronave.tipo) + 5000 * (aeronave.emergencia);

    return prioridade;
}


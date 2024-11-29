#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/util.h"

void menu(){
    printf("\n======== MENU PRINCIPAL ========\n\n");

    printf("Selecione uma das operacoes abaixo:\n");

    printf("1 - Cadastrar uma nova aeronave\n");
    printf("2 - Consultar maior prioridade\n");
    printf("3 - Remover maior prioridade\n");
    printf("4 - Exibir todas as aeronaves\n");
    printf("5 - Consultar aeronave\n");
    printf("6 - Finalizar o programa\n");

    printf("\nDigite o numero da operacao desejada: ");
}

void menu_alterar(){
    printf("\n======== MENU ALTERADOR DE AERONAVES ========\n\n");

    printf("Selecione uma das operacoes abaixo:\n");

    printf("1 - Alterar combustivel\n");
    printf("2 - Alterar horario_em_minutos\n");
    printf("3 - Alterar tipo (decolagem ou pouso)\n");
    printf("4 - Alterar situacao de emergencia (em emergencia ou sem emergencia)\n");
    printf("5 - Voltar para o Menu Principal\n");

    printf("\nDigite o numero da operacao desejada: ");
}

void menuOperacoes(int entrada, char* nome_arquivo, Frota* frota){
    Aeronave aeronave;
    Aeronave* aeronave_da_busca;

    switch (entrada)
    {
    case 1:
        aeronave = cadastrar_aeronave();
        salvar_aeronave(nome_arquivo, aeronave);
        inserir_na_heap(frota, aeronave);
        printf("\n");
        exibir_aeronave(aeronave);
        break;
    case 2:
        aeronave = consultar_maior_prioridade(*frota);
        printf("\n");
        exibir_aeronave(aeronave);
        break;
    case 3:
        remover_maior_prioridade(&frota);
        printf("Remoção bem sucedida!");
        break;
    case 4:
        ordenar_heap(frota);
        exibir_frota(frota);
        break;
    case 5:
        printf("Digite a aeronave que deseja procurar: ");
        char* identificador = leitor_de_palavras();

        aeronave_da_busca = buscar_aeronave(frota, identificador);
        if(aeronave_da_busca == NULL){
            return;
        }
        printf("\n");
        exibir_aeronave(*aeronave_da_busca);

        int nova_entrada;
        do{
            menu_alterar();
            nova_entrada = leitor_de_numeros();

            menuOperacoes_de_alterar(nova_entrada, aeronave_da_busca);
        } while (nova_entrada != 5);

        ordenar_heap(frota);
        break;
    case 6:
        printf("\nObrigado por usar os nossos servicos!\n\n");
        break;
    default:
        printf("\nOpcao invalida!\n");
        break;
    }
}

void menuOperacoes_de_alterar(int entrada, Aeronave* aeronave){
    
    switch (entrada)
    {
    case 1:
        alterador_de_combustivel(aeronave);
        break;
    case 2:
        alterador_de_horario(aeronave);
        break;
    case 3:
        alterador_de_tipo(aeronave);
        break;
    case 4:
        alterador_de_emergencia(aeronave);
        break;
    case 5:
        return;
        break;
    default:
        printf("\nOpcao invalida\n");
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

void para_maisculo(char* palavra){
    if (palavra == NULL) return;

    for(int i = 0; palavra[i] != '\0'; i++){
        palavra[i] = toupper_personalizado(&palavra[i]);
    }
}

int comparador_de_palavras(char* palavra1, char* palavra2){
    char temp1[strlen(palavra1) + 1]; 
    char temp2[strlen(palavra2) + 1]; 

    strcpy(temp1, palavra1);
    strcpy(temp2, palavra2);

    para_maisculo(temp1);
    para_maisculo(temp2);

    return strcmp(temp1, temp2);
}

char toupper_personalizado(char* letra){
    if (strcmp(letra, "á") == 0) {
        strcpy(letra, "Á");
    } else if (strcmp(letra, "é") == 0) {
        strcpy(letra, "É");
    } else if (strcmp(letra, "í") == 0) {
        strcpy(letra, "Í");
    } else if (strcmp(letra, "ó") == 0) {
        strcpy(letra, "Ó");
    } else if (strcmp(letra, "ú") == 0) {
        strcpy(letra, "Ú");
    } else if (strcmp(letra, "ç") == 0) {
        strcpy(letra, "Ç");
    } else if (strcmp(letra, "ã") == 0) {
        strcpy(letra, "Ã");
    } else if (strcmp(letra, "õ") == 0) {
        strcpy(letra, "Õ");
    } else {
        letra[0] = toupper(letra[0]);
        letra[1] = '\0';
    }
    
    return *letra;
}

void reiniciar_arquivo(char* nome_arquivo){
    FILE* arquivo = fopen(nome_arquivo, "w");
    fclose(arquivo);
}

void exibir_alteracao_sucedida(){
    printf("Alteracao bem sucedida!");
}


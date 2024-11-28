#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/util.h"
#include "../include/aerovane.h"

Aeronave cadastrar_aeronave(){
    Aeronave aeronave;
    char* entrada;

    printf("Digite o indentificador da aeronave: ");
    entrada = leitor_de_palavras();
    strcpy(aeronave.indentificador, entrada);
    free(entrada);

    printf("Digite o combustivel da aeronave: ");
    aeronave.combustivel = leitor_de_numeros();

    printf("Digite a hora de partida ou chegada em minutos da aeronave: ");
    aeronave.horario_em_minutos = leitor_de_numeros();

    printf("Digite o tipo de operacao da aeronave (0: decolagem, 1: pouso): ");
    aeronave.tipo = leitor_de_tipo();

    printf("Digite a situacao de emergencia (0: nao, 1: sim): ");
    aeronave.emergencia = leitor_de_tipo();

    aeronave.prioridade = calculador_de_prioridade(aeronave);  
    
    return aeronave;
}

void salvar_aeronave(char* nome_arquivo, Aeronave aeronave){
    FILE *arquivo = fopen(nome_arquivo, "a");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    fprintf(arquivo, "%s,%i,%i,%i,%i,%i\n",
        aeronave.indentificador,
        aeronave.combustivel,
        aeronave.horario_em_minutos,
        aeronave.tipo,
        aeronave.emergencia,
        aeronave.prioridade
    );

    fclose(arquivo);
}

void exibir_aeronave(Aeronave aeronave){
    printf("Aeronave \"%s\":\n", aeronave.indentificador);
    printf("  Combustivel: %i\n", aeronave.combustivel);
    printf("  Horario em minutos da decolagem ou pouso: %i\n", aeronave.horario_em_minutos);
    printf("  Tipo de operacao (0: decolagem, 1: pouso): %i\n", aeronave.tipo);
    printf("  Situacao de emergencia (0: nao, 1: sim): %i\n", aeronave.emergencia);
    printf("  Prioridade da aeronave: %i\n", aeronave.prioridade);
}
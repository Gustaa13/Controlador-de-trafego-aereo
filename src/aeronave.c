#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/util.h"

Aeronave cadastrar_aeronave(){
    Aeronave aeronave;
    char* entrada;

    printf("Digite o indentificador da aeronave: ");
    entrada = leitor_de_palavras();
    strcpy(aeronave.identificador, entrada);
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

    fprintf(arquivo, "%s,%i,%i,%i,%i\n",
        aeronave.identificador,
        aeronave.combustivel,
        aeronave.horario_em_minutos,
        aeronave.tipo,
        aeronave.emergencia
    );

    fclose(arquivo);
}

void exibir_aeronave(Aeronave aeronave){
    printf("Aeronave \"%s\":\n", aeronave.identificador);
    printf("  Combustivel: %i\n", aeronave.combustivel);
    printf("  Horario em minutos da decolagem ou pouso: %i\n", aeronave.horario_em_minutos);
    printf("  Tipo de operacao (0: decolagem, 1: pouso): %i\n", aeronave.tipo);
    printf("  Situacao de emergencia (0: nao, 1: sim): %i\n", aeronave.emergencia);
    printf("  Prioridade da aeronave: %i\n", aeronave.prioridade);
}

void alterador_de_combustivel(Aeronave* aeronave){
    int combustivel;

    printf("O valor do combustivel atual e: %d\n", aeronave->combustivel);
    printf("Digite o novo valor do combustivel: ");
    combustivel = leitor_de_numeros();

    if((aeronave->combustivel < combustivel) && aeronave->tipo == 1){
        printf("\nO aviao ja esta em voo, o combustivel nao pode ser aumentado!\n");

        return;
    }else if(aeronave->combustivel == combustivel){
        printf("\nEsse ja e o valor do combustivel!\n");

        return;
    }

    aeronave->combustivel = combustivel;
    aeronave->prioridade = calculador_de_prioridade(*aeronave);

    exibir_alteracao_sucedida();
}

void alterador_de_horario(Aeronave* aeronave){
    int horario_em_minutos;

    printf("O valor do horario em minutos atual e: %d\n", aeronave->horario_em_minutos);
    printf("Digite o novo valor do horario em minutos: ");
    horario_em_minutos = leitor_de_numeros();
    
    if(aeronave->horario_em_minutos == horario_em_minutos){
        printf("\nEsse ja e o valor do horario em minutos!\n");

        return;
    }
    
    aeronave->horario_em_minutos = horario_em_minutos;
    aeronave->prioridade = calculador_de_prioridade(*aeronave);

    exibir_alteracao_sucedida();
}

void alterador_de_tipo(Aeronave* aeronave){
     int tipo;

    printf("O tipo de operacao e: %d\n", aeronave->tipo);
    printf("Digite o novo tipo de operacao(0: decolagem, 1: pouso): ");
    tipo = leitor_de_tipo();

    if(aeronave->tipo == tipo){
        printf("\nEsse ja e o tipo atual de operacao!\n");

        return;
    }
    
    aeronave->tipo = tipo;
    aeronave->prioridade = calculador_de_prioridade(*aeronave);
    
    exibir_alteracao_sucedida();
}

void alterador_de_emergencia(Aeronave* aeronave){
    int emergencia;

    printf("A situacao de emergencia e: %d\n", aeronave->emergencia);
    printf("Digite a nova situacao de emergencia(0: sem emergencia, 1: com emergencia): ");
    emergencia = leitor_de_tipo();

    if(aeronave->emergencia == emergencia){
        printf("\nEssa ja e a situacao atual de emergencia!\n");

        return;
    }
    
    aeronave->emergencia = emergencia;
    aeronave->prioridade = calculador_de_prioridade(*aeronave);

    exibir_alteracao_sucedida();
}
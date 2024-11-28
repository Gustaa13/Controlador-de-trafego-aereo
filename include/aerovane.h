#ifndef AERONAVE_H
#define AERONAVE_H

typedef struct Aeronave 
{
    char indetificador[50];
    int combustivel;
    int horario_em_minutos;
    int tipo;
    int emergencia;
    int prioridade;
} Aeronave;

Aeronave cadastrar_aeronave();
void salvar_aeronave(char* nome_arquivo, Aeronave aeronave);
void exibir_aeronave(Aeronave aeronave);

#endif
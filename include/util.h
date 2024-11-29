#include "heap.h"

void menu();
void menu_alterar();
void menuOperacoes(int entrada, char* nome_arquivo, Frota* frota);
void menuOperacoes_de_alterar(int entrada, Aeronave* aeronave);
void limpador_de_buffer();
int leitor_de_numeros();
int leitor_de_tipo();
char* leitor_de_palavras();
int calculador_de_prioridade(Aeronave aeronave);
void para_maisculo(char* palavra);
int comparador_de_palavras(char* palavra1, char* palavra2);
char toupper_personalizado(char* letra);
void reiniciar_arquivo(char* nome_arquivo);
void exibir_alteracao_sucedida();
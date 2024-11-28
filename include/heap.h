#include "aerovane.h"
#include "frota.h"
#include <stdio.h>
#include <stdlib.h>  // Inclua este cabeçalho para evitar os avisos de 'malloc' e 'free'
#include <stdlib.h>  // Inclua este cabeçalho para evitar os avisos de 'malloc' e 'free'



void heap_maxima(Aeronave* heap, int capacidade, int indice);
void construir_heap_maxima(Aeronave* heap, int capacidade);
void ordenar_heap(Aeronave* heap, int capacidade);
void carregar_aeronave(char* nome_arquivo, Frota* frota);
void inserir_aeronave(Frota* frota, Aeronave aeronave);
void consultar_maior_prioridade(Aeronave* heap);
void remover_maior_prioridade(Frota** frota);
void atualizarPrioridade(Frota* frota);
void exibir_heap(Frota* frota);

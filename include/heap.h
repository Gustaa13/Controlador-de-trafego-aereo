#include "frota.h"

void heap_maxima(Aeronave* heap, int capacidade, int indice);
void construir_heap_maxima(Frota* frota);
void ordenar_heap(Frota* frota);
void inserir_na_heap(Frota* frota, Aeronave aeronave);
Aeronave consultar_maior_prioridade(Frota frota);
void remover_maior_prioridade(Frota** frota);
void atualizarPrioridade(Frota* frota);

#include "aerovane.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Frota
{
    Aeronave* aeronave;
    int capacidade;
} Frota;

// Frota* iniciar_frota();
// void liberar_frota(Frota* frota);
// void exibir_frota(Frota* frota);
void aumentar_frota(Frota* frota);
void diminuir_frora(Frota* frota);

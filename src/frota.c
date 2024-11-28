#include "../include/frota.h"

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


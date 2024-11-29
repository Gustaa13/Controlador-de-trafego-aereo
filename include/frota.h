#include "aerovane.h"

typedef struct Frota
{
    Aeronave* aeronave;
    int capacidade;
}Frota;

Frota* iniciar_frota();
void liberar_frota(Frota* frota);
void exibir_frota(Frota* frota);
void aumentar_frota(Frota* frota);
void diminuir_frota(Frota* frota);
void carregar_frota(char* nome_arquivo, Frota* frota);
void salvar_frota(char* nome_arquivo, Frota frota);
Aeronave* buscar_aeronave(Frota* frota, char* identificador);
#include "aerovane.h"
#include <stdio.h>

typedef struct No 
{
    Aeronave aeronave;
    struct No *esquerdo;
    struct No *direto;
}No;

void arvore_maxima(No* arvore);
void construir_arvore_maxima(No* arvore, int n);
void organizar_arvore(No* arvore, int n);
void carregarAeronave(char* nome_arquivo, No* raiz);
void inserirAeronave(No* arvore, Aeronave aeronave);
void consultarMaiorPrioridade(No* arvore);
void removerMaiorPrioridade(No* arvore);
void atualizarPrioridade(No* arvore, Aeronave aeronave);
void exibirArvore(No* arvore);

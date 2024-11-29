#include <stdio.h>
#include <locale.h>
#include "../include/util.h"

int main(){
    char* nome_arquivo = "data/voos.csv";
    Frota* frota = iniciar_frota();
    carregar_frota(nome_arquivo, frota);
    ordenar_heap(frota);
    
    int entrada;

    do{
        menu();
        entrada = leitor_de_numeros();

        menuOperacoes(entrada, nome_arquivo, frota);
    } while (entrada != 6);

    reiniciar_arquivo(nome_arquivo);
    salvar_frota(nome_arquivo, *frota);
    liberar_frota(frota);
    return 0;
}

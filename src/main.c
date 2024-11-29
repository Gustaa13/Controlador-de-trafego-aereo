#include <stdio.h>
#include <locale.h>
#include "../include/util.h"

int main(){
    char* nome_arquivo = "data/voos.csv";
    Frota* frota = iniciar_frota();
    carregar_frota(nome_arquivo, frota);
    
    int entrada;

    do{
        menu();
        entrada = leitor_de_numeros();

        menuOperacoes(entrada, nome_arquivo, frota);
    } while (entrada != 5);

    liberar_frota(frota);
    return 0;
}

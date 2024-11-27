#include <stdio.h>
#include <locale.h>
#include "../include/util.h"

int main(){
    char* nome_arquivo = "data/aeronaves.csv";
    
    int entrada;

    do{
        menu();
        entrada = leitor_de_numeros();

        menuOperacoes(entrada);
    } while (entrada != 5);

    return 0;
}

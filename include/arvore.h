#include "aerovane.h"

typedef struct No 
{
    Aeronave aeronave;
    struct No *esquerdo;
    struct No *direto;
}No;
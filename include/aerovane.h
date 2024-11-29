typedef struct Aeronave 
{
    char identificador[50];
    int combustivel;
    int horario_em_minutos;
    int tipo;
    int emergencia;
    int prioridade;
}Aeronave;

Aeronave cadastrar_aeronave();
void salvar_aeronave(char* nome_arquivo, Aeronave aeronave);
void exibir_aeronave(Aeronave aeronave);
void alterador_de_combustivel(Aeronave* aeronave);
void alterador_de_horario(Aeronave* aeronave);
void alterador_de_tipo(Aeronave* aeronave);
void alterador_de_emergencia(Aeronave* aeronave);
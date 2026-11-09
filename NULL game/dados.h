/* Tipos e funcoes que fornecem os objetos investigaveis de cada comodo. */
#ifndef DADOS_H
#define DADOS_H

#include <stdbool.h>

/* Um objeto pode ou nao estar associado a uma pista coletavel. */
typedef struct {
    const char *nome;
    const char *descricao;
    int idPista;                 /* Zero indica que o objeto nao revela evidencia. */
    const char *pista;
    bool investigado;
} Objeto;

/* Retorna os objetos da sala e informa quantos existem no vetor. */
Objeto *obter_objetos(int sala, int *quantidade);

/* Retorna o nome da sala correspondente ao numero informado. */
const char *nome_sala(int sala);

#endif

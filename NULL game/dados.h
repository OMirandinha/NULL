#ifndef DADOS_H
#define DADOS_H

#include <stdbool.h>

typedef struct {
    const char *nome;
    const char *descricao;
    int idPista;                 /* Zero indica que o objeto nao revela evidencia. */
    const char *pista;
    bool investigado;
} Objeto;

Objeto *obter_objetos(int sala, int *quantidade);
const char *nome_sala(int sala);

#endif

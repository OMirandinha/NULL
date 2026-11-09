/* Definicao da lista simplesmente encadeada usada como inventario de pistas. */
#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

/* Cada no guarda uma pista e o endereco do proximo no da lista. */
typedef struct No {
    int id;
    char *descricao; /* Texto alocado dinamicamente e liberado ao destruir a lista. */
    struct No *proximo;
} No;

/* Mantem o inicio da lista e a quantidade de pistas armazenadas. */
typedef struct {
    No *inicio;
    int quantidade;
} Inventario;

/* Operacoes basicas da lista: inicializar, buscar, inserir, exibir e liberar. */
void inicializar_inventario(Inventario *inv);
int buscar_pista(const Inventario *inv, int id);
int inserir_pista(Inventario *inv, int id, const char *descricao);
void exibir_pistas(const Inventario *inv);
void liberar_inventario(Inventario *inv);

#endif

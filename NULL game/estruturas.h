#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct No {
    int id;
    char *descricao;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int quantidade;
} Inventario;

void inicializar_inventario(Inventario *inv);
int buscar_pista(const Inventario *inv, int id);
int inserir_pista(Inventario *inv, int id, const char *descricao);
void exibir_pistas(const Inventario *inv);
void liberar_inventario(Inventario *inv);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

/* Prepara a lista encadeada para receber evidencias. */
void inicializar_inventario(Inventario *inv) {
    if (inv == NULL) return;
    inv->inicio = NULL;
    inv->quantidade = 0;
}

/* Percorre a lista procurando uma evidencia pelo identificador. */
int buscar_pista(const Inventario *inv, int id) {
    const No *atual;
    if (inv == NULL) return 0;
    atual = inv->inicio;
    while (atual != NULL) {
        if (atual->id == id) return 1;
        atual = atual->proximo;
    }
    return 0;
}

/* Aloca um novo no e o insere no final, sem permitir IDs repetidos. */
int inserir_pista(Inventario *inv, int id, const char *descricao) {
    No *novo, *atual;
    size_t tamanho;

    if (inv == NULL || descricao == NULL) return -1;
    if (buscar_pista(inv, id)) return 0;

    /* Reserva memoria para o no; em caso de falha, informa erro ao chamador. */
    novo = malloc(sizeof(No));
    if (novo == NULL) return -1;

    /* A descricao tambem precisa de memoria propria para permanecer na lista. */
    tamanho = strlen(descricao) + 1;
    novo->descricao = malloc(tamanho);
    if (novo->descricao == NULL) {
        free(novo);
        return -1;
    }

    strcpy(novo->descricao, descricao);
    novo->id = id;
    novo->proximo = NULL;

    /* Se a lista estiver vazia, o novo no passa a ser o primeiro elemento. */
    if (inv->inicio == NULL) {
        inv->inicio = novo;
    } else {
        atual = inv->inicio;
        while (atual->proximo != NULL) atual = atual->proximo;
        atual->proximo = novo;
    }

    /* Atualiza o contador somente depois de inserir o no com sucesso. */
    inv->quantidade++;
    return 1;
}

/* Mostra todas as evidencias percorrendo a lista do inicio ao fim. */
void exibir_pistas(const Inventario *inv) {
    const No *atual;
    int numero = 1;

    printf("\n========== EVIDENCIAS COLETADAS ==========\n");
    if (inv == NULL || inv->inicio == NULL) {
        printf("Nenhuma evidencia foi encontrada ainda.\n");
        return;
    }

    atual = inv->inicio;
    while (atual != NULL) {
        printf("%d. %s\n", numero++, atual->descricao);
        atual = atual->proximo;
    }
    printf("Total: %d evidencia(s).\n", inv->quantidade);
}

/* Libera primeiro a descricao e depois cada no da lista. */
void liberar_inventario(Inventario *inv) {
    No *atual, *proximo;
    if (inv == NULL) return;

    atual = inv->inicio;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual->descricao);
        free(atual);
        atual = proximo;
    }
    inv->inicio = NULL;
    inv->quantidade = 0;
}

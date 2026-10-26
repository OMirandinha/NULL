#include <stdio.h>
#include "jogo.h"

void executar_jogo(void) {
    int opcao = -1;

    while (opcao != 0) {
        printf("\n==============================\n");
        printf("       NULL - INVESTIGACAO\n");
        printf("==============================\n");
        printf("1. Iniciar investigacao\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            int caractere;

            while ((caractere = getchar()) != '\n' &&
                   caractere != EOF) {
                /* Limpa a entrada inválida. */
            }

            printf("Entrada invalida. Digite um numero.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\nO Sr. Almeida foi encontrado morto...\n");
                printf("A investigacao comecara em breve.\n");
                break;

            case 0:
                printf("\nEncerrando o jogo...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
}
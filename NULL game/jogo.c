#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include "jogo.h"
#include "estruturas.h"
#include "dados.h"

/* Quantidade de evidencias cadastradas no modulo dados.c. */
#define TOTAL_PISTAS 11

/* Le uma linha inteira e valida se ela contem somente um numero inteiro.
   Retorna 1 em caso de sucesso, 0 para entrada invalida e -1 no fim da entrada. */
static int ler_opcao(int *opcao) {
    char linha[100];
    char *fim;
    long valor;

    if (opcao == NULL) return 0;
    if (fgets(linha, sizeof(linha), stdin) == NULL) return -1;

    /* Descarta o restante da linha caso ela seja maior que o buffer. */
    if (strchr(linha, '\n') == NULL) {
        int caractere;
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
            /* Descarta caracteres excedentes. */
        }
    }

    errno = 0;
    valor = strtol(linha, &fim, 10);
    if (fim == linha || errno == ERANGE || valor < INT_MIN || valor > INT_MAX) {
        return 0;
    }

    while (isspace((unsigned char)*fim)) fim++;
    if (*fim != '\0') return 0;

    *opcao = (int)valor;
    return 1;
}

/* Apresenta o contexto narrativo antes de iniciar a investigacao. */
static void apresentar_introducao(void) {
    printf("\n========================================\n");
    printf("                  NULL\n");
    printf("             O ULTIMO SUSPIRO\n");
    printf("========================================\n\n");
    printf("Era uma noite de chuvas fortes na mansao do Sr. Almeida.\n");
    printf("Perto da lareira, ele ouvia musica classica e lia um livro,\n");
    printf("acompanhado de uma taca de vinho, completamente absorto.\n");
    printf("A chuva abafava quase todos os sons, deixando apenas os\n");
    printf("trovoes e as gotas contra as paredes da mansao.\n\n");
    printf("Bruno estava em uma videoconferencia com seus agentes financeiros.\n");
    printf("Daniel preparava o cha do Sr. Almeida na cozinha.\n");
    printf("Carla repousava na cama, em mais um sono leve.\n");
    printf("Elisa caminhava como uma sombra pelo jardim coberto.\n\n");
    printf("De repente, a energia caiu. Dez minutos depois, quando\n");
    printf("a luz voltou, o Sr. Almeida estava morto em sua poltrona,\n");
    printf("atingido por um disparo no coracao.\n\n");
    printf("Quatro suspeitos. Uma mansao. Uma verdade escondida.\n");
    printf("Explore os comodos, examine os objetos e reuna as evidencias.\n");
    printf("A investigacao tem uma solucao: descubra o que Elisa tentou ocultar.\n");
    printf("Dica: examine os objetos com atencao; algumas evidencias se conectam.\n");
    printf("\nPressione ENTER para iniciar...");
    getchar();
}

/* Exibe um objeto e registra sua pista no inventario, quando houver. */
static void examinar_objeto(Objeto *obj, Inventario *inv) {
    int resultado;

    printf("\n--- %s ---\n", obj->nome);
    printf("%s\n", obj->descricao);

    if (obj->investigado) {
        printf("Voce ja examinou este objeto.\n");
        return;
    }

    if (obj->idPista == 0 || obj->pista == NULL) {
        obj->investigado = true;
        printf("Voce nao encontrou nenhuma evidencia relevante aqui.\n");
        return;
    }

    resultado = inserir_pista(inv, obj->idPista, obj->pista);
    if (resultado == 1) {
        obj->investigado = true;
        printf("\n[NOVA EVIDENCIA] %s\n", obj->pista);
        printf("Evidencias coletadas: %d de %d\n", inv->quantidade, TOTAL_PISTAS);
    } else if (resultado == 0) {
        obj->investigado = true;
        printf("Essa evidencia ja esta registrada no inventario.\n");
    } else {
        printf("Nao foi possivel armazenar a evidencia. Tente novamente.\n");
    }
}

/* Permite examinar os objetos de uma sala sem sair do menu principal. */
static void explorar_sala(int sala, Inventario *inv) {
    int quantidade = 0;
    int opcao, i;
    Objeto *objetos = obter_objetos(sala, &quantidade);

    if (objetos == NULL || quantidade == 0) return;

    do {
        printf("\n========================================\n");
        printf("  %s\n", nome_sala(sala));
        printf("========================================\n");
        for (i = 0; i < quantidade; i++) {
            printf("  [%d] %s%s\n", i + 1, objetos[i].nome,
                   objetos[i].investigado ? " (examinado)" : "");
        }
        printf("  [0] Voltar ao mapa da mansao\n");
        printf("----------------------------------------\n");
        printf("Evidencias coletadas: %d de %d\n", inv->quantidade, TOTAL_PISTAS);
        printf("Escolha um objeto: ");

        {
            int leitura = ler_opcao(&opcao);
            if (leitura == -1) {
                printf("\nEntrada encerrada. Voltando ao menu principal.\n");
                break;
            }
            if (leitura == 0) {
                printf("Opcao invalida. Digite um numero.\n");
                continue;
            }
        }
        if (opcao >= 1 && opcao <= quantidade) {
            examinar_objeto(&objetos[opcao - 1], inv);
        } else if (opcao != 0) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

/* Mostra a solucao da historia depois de uma acusacao correta. */
static void revelar_desfecho(const Inventario *inv) {
    printf("\n========================================\n");
    printf("          CONCLUSAO DA INVESTIGACAO\n");
    printf("========================================\n\n");
    printf("Ao reunir as evidencias, voce percebe que a queda de energia\n");
    printf("foi provocada manualmente. As pegadas ligam o jardim ao porao,\n");
    printf("e o brinco e o bilhete encontrados no jardim apontam para Elisa.\n\n");
    printf("O motivo estava relacionado aos negocios do Sr. Almeida.\n");
    printf("Elisa temia que ele revelasse um acordo que colocaria seus\n");
    printf("planos em risco. Aproveitando os dez minutos de escuridao,\n");
    printf("ela entrou na biblioteca e atirou contra o Sr. Almeida.\n\n");
    printf("As evidencias tambem ligam Elisa ao trajeto ate o porao e\n");
    printf("ao bilhete que revela seu interesse nos negocios da vitima.\n");
    printf("Alem disso, o fragmento metalico da biblioteca e compativel\n");
    printf("com o disparo que matou Almeida.\n\n");
    printf("A CULPADA E ELISA.\n");
    printf("Carla, Bruno e Daniel eram suspeitos, mas as evidencias\n");
    printf("nao os colocam como autores do assassinato.\n\n");
    printf("Voce encontrou %d de %d evidencias.\n", inv->quantidade, TOTAL_PISTAS);
    printf("                 FIM\n");
}

/* Permite acusar qualquer suspeito mesmo sem reunir todas as evidencias.
   Retorna 1 quando a acusacao encerra o jogo, 0 quando o jogador cancela. */
static int acusar_suspeito(const Inventario *inv) {
    int escolha;
    int leitura;

    printf("\n========================================\n");
    printf("             FAZER ACUSACAO\n");
    printf("========================================\n");
    printf("Escolha quem voce acredita ser o culpado:\n");
    printf("  [1] Carla\n");
    printf("  [2] Bruno\n");
    printf("  [3] Daniel\n");
    printf("  [4] Elisa\n");
    printf("  [0] Voltar sem acusar\n");
    printf("Sua acusacao: ");

    leitura = ler_opcao(&escolha);
    if (leitura == -1) {
        printf("\nEntrada encerrada. O culpado escapou.\n");
        return 1;
    }
    if (leitura == 0 || escolha < 0 || escolha > 4) {
        printf("Acusacao invalida. Retornando ao menu principal.\n");
        return 0;
    }
    if (escolha == 0) {
        printf("Voce decidiu continuar investigando.\n");
        return 0;
    }

    if (escolha == 4) {
        printf("\nSua acusacao esta correta!\n");
        revelar_desfecho(inv);
    } else {
        const char *nome = escolha == 1 ? "Carla" : (escolha == 2 ? "Bruno" : "Daniel");
        printf("\nVoce acusou %s, mas nao conseguiu provar a acusacao.\n", nome);
        printf("Enquanto a investigacao seguia pelo caminho errado, Elisa percebeu\n");
        printf("que seria descoberta e fugiu da mansao.\n\n");
        printf("========================================\n");
        printf("              FIM DE JOGO\n");
        printf("========================================\n");
        printf("O verdadeiro culpado, Elisa, escapou.\n");
        printf("Voce reuniu %d de %d evidencias.\n", inv->quantidade, TOTAL_PISTAS);
    }
    return 1;
}

/* Mantem em um unico local as opcoes principais da interface textual. */
static void exibir_menu(void) {
    printf("\n========================================\n");
    printf("          MANSÃO DO SR. ALMEIDA\n");
    printf("========================================\n");
    printf("  [1] Hall de Entrada\n");
    printf("  [2] Biblioteca\n");
    printf("  [3] Quarto de Carla\n");
    printf("  [4] Cozinha\n");
    printf("  [5] Escritorio\n");
    printf("  [6] Porao\n");
    printf("  [7] Jardim Coberto\n");
    printf("  [8] Consultar evidencias\n");
    printf("  [9] Acusar um suspeito\n");
    printf("  [0] Encerrar investigacao\n");
    printf("----------------------------------------\n");
    printf("Escolha uma opcao: ");
}

/* Controla o ciclo principal e garante a liberacao do inventario ao terminar. */
void executar_jogo(void) {
    Inventario inv;
    int opcao;
    int leitura;
    int jogo_encerrado = 0;

    /* A lista comeca vazia e sera preenchida conforme o jogador encontra pistas. */
    inicializar_inventario(&inv);
    apresentar_introducao();

    do {
        exibir_menu();
        leitura = ler_opcao(&opcao);
        if (leitura == -1) {
            printf("\nEntrada encerrada. Finalizando o jogo com seguranca.\n");
            opcao = 0;
        } else if (leitura == 0) {
            printf("Opcao invalida. Digite um numero de 0 a 9.\n");
            continue;
        }

        if (opcao >= 1 && opcao <= 7) {
            explorar_sala(opcao, &inv);
        } else if (opcao == 8) {
            exibir_pistas(&inv);
        } else if (opcao == 9) {
            jogo_encerrado = acusar_suspeito(&inv);
            if (jogo_encerrado) opcao = 0;
        } else if (opcao == 0) {
            printf("\nEncerrando a investigacao...\n");
        } else {
            printf("Opcao invalida. Digite um numero de 0 a 9.\n");
        }

        /* Reunir todas as pistas nao encerra automaticamente: o jogador decide quando acusar. */
    } while (opcao != 0);

    if (!jogo_encerrado) {
        printf("\nVoce encerrou a investigacao sem identificar o culpado.\n");
        printf("Enquanto voce deixava a mansao, Elisa fugiu sem ser descoberta.\n");
        printf("O culpado escapou.\n");
        printf("Evidencias coletadas: %d de %d.\n", inv.quantidade, TOTAL_PISTAS);
    }

    /* Todos os nos e textos alocados sao liberados antes de sair da funcao. */
    liberar_inventario(&inv);
    printf("Memoria do inventario liberada. Obrigado por jogar NULL!\n");
}

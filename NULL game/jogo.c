#include <stdio.h>
#include "jogo.h"
#include "estruturas.h"
#include "dados.h"

#define TOTAL_PISTAS 11

static void limpar_entrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* Descarta caracteres excedentes. */
    }
}

static int ler_opcao(void) {
    int opcao;
    if (scanf("%d", &opcao) != 1) {
        limpar_entrada();
        return -1;
    }
    limpar_entrada();
    return opcao;
}

static void apresentar_introducao(void) {
    printf("\n========================================\n");
    printf("                  NULL\n");
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
    printf("\nPressione ENTER para iniciar...");
    getchar();
}

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

        opcao = ler_opcao();
        if (opcao >= 1 && opcao <= quantidade) {
            examinar_objeto(&objetos[opcao - 1], inv);
        } else if (opcao != 0) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

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
    printf("A CULPADA E ELISA.\n");
    printf("Carla, Bruno e Daniel eram suspeitos, mas as evidencias\n");
    printf("nao os colocam como autores do assassinato.\n\n");
    printf("Voce encontrou %d de %d evidencias.\n", inv->quantidade, TOTAL_PISTAS);
    printf("                 FIM\n");
}

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
    printf("  [0] Encerrar investigacao\n");
    printf("----------------------------------------\n");
    printf("Escolha uma opcao: ");
}

void executar_jogo(void) {
    Inventario inv;
    int opcao;
    int desfecho_exibido = 0;

    inicializar_inventario(&inv);
    apresentar_introducao();

    do {
        exibir_menu();
        opcao = ler_opcao();

        if (opcao >= 1 && opcao <= 7) {
            explorar_sala(opcao, &inv);
        } else if (opcao == 8) {
            exibir_pistas(&inv);
        } else if (opcao == 0) {
            printf("\nEncerrando a investigacao...\n");
        } else {
            printf("Opcao invalida. Digite um numero de 0 a 8.\n");
        }

        /* O final e unico e acontece automaticamente quando todas as evidencias sao coletadas. */
        if (inv.quantidade == TOTAL_PISTAS && !desfecho_exibido) {
            revelar_desfecho(&inv);
            desfecho_exibido = 1;
            opcao = 0;
        }
    } while (opcao != 0);

    if (!desfecho_exibido) {
        printf("\nInvestigacao encerrada antes de todas as evidencias serem encontradas.\n");
        printf("Evidencias coletadas: %d de %d.\n", inv.quantidade, TOTAL_PISTAS);
    }

    liberar_inventario(&inv);
    printf("Memoria do inventario liberada. Obrigado por jogar NULL!\n");
}

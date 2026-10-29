
#include <stdio.h>
#include "jogo.h"

/* Representa um objeto ou local que pode ser examinado. */
typedef struct {
    const char *nome;
    const char *descricao;
} Objeto;

/* Limpa os caracteres restantes da entrada. */
void limpar_entrada(void) {
    int caractere;

    while ((caractere = getchar()) != '\n' &&
           caractere != EOF) {
        /* Descarta caracteres excedentes. */
    }
}

/* Le uma opcao numerica e trata entradas invalidas. */
int ler_opcao(void) {
    int opcao;

    if (scanf("%d", &opcao) != 1) {
        limpar_entrada();
        return -1;
    }

    limpar_entrada();
    return opcao;
}

/* Introducao narrativa do jogo. */
void apresentar_introducao(void) {
    printf("\n========================================\n");
    printf("                 NULL\n");
    printf("========================================\n");

    printf("\nEra uma noite de chuvas fortes na mansao do Sr. Almeida.\n");
    printf("Perto da lareira, ele ouvia musica classica e lia um livro,\n");
    printf("acompanhado de uma taca de vinho, completamente absorto.\n");
    printf("A chuva abafava quase todos os sons, deixando apenas\n");
    printf("os trovoes e as gotas contra as paredes da mansao.\n");

    printf("\nBruno estava em uma videoconferencia com seus agentes financeiros.\n");
    printf("Daniel preparava o cha do Sr. Almeida na cozinha.\n");
    printf("Carla repousava na cama, em mais um sono leve.\n");
    printf("Elisa caminhava pela cupula fechada do jardim, envolta em sombras.\n");

    printf("\nDe repente, a energia caiu.\n");
    printf("Durante dez minutos, a mansao permaneceu na escuridao.\n");
    printf("Quando a energia voltou, o Sr. Almeida estava morto,\n");
    printf("sentado em sua cadeira, com uma bala no coracao.\n");

    printf("\nQuatro suspeitos. Uma vitima. Dez minutos sem luz.\n");
    printf("Sua missao e explorar a mansao e investigar o ocorrido.\n");

    printf("\nPressione ENTER para continuar...");
    getchar();
}

/* Objetos que podem ser examinados no hall. */
static const Objeto hall[] = {
    {"Porta principal", "A porta e robusta e esta fechada."},
    {"Tapete", "O tapete ocupa boa parte da entrada da mansao."},
    {"Relogio de parede", "O relogio antigo marca as horas em silencio."},
    {"Escadaria", "Uma escadaria leva ao andar superior."}
};

/* Objetos da biblioteca. */
static const Objeto biblioteca[] = {
    {"Estantes", "As estantes estao repletas de livros antigos."},
    {"Poltrona", "Uma poltrona esta posicionada perto da lareira."},
    {"Lareira", "As brasas ainda iluminam discretamente o ambiente."},
    {"Janela", "A chuva escorre pelo vidro da janela."}
};

/* Objetos do quarto do casal. */
static const Objeto quarto[] = {
    {"Cama", "A cama esta parcialmente desarrumada."},
    {"Criado-mudo", "Ha alguns objetos pessoais sobre o movel."},
    {"Guarda-roupa", "O guarda-roupa esta fechado."},
    {"Penteadeira", "Perfumes e pequenos acessorios estao organizados aqui."}
};

/* Objetos da cozinha. */
static const Objeto cozinha[] = {
    {"Bancada", "A bancada esta limpa, com alguns utensilios sobre ela."},
    {"Chaleira", "A chaleira repousa perto do fogao."},
    {"Armarios", "Os armarios guardam loucas e mantimentos."},
    {"Pia", "Algumas gotas de agua escorrem pela pia."}
};

/* Objetos do escritorio do Sr. Almeida. */
static const Objeto escritorio[] = {
    {"Mesa", "A mesa esta coberta de documentos e materiais de trabalho."},
    {"Computador", "O computador esta desligado."},
    {"Estante", "Pastas e livros ocupam as prateleiras."},
    {"Cofre", "Um cofre esta embutido na parede."}
};

/* Objetos do porao. */
static const Objeto porao[] = {
    {"Quadro eletrico", "O quadro eletrico controla parte da energia da mansao."},
    {"Caixa de ferramentas", "Uma caixa com ferramentas esta encostada na parede."},
    {"Armario antigo", "Um armario empoeirado ocupa o canto do porao."},
    {"Escada", "A escada leva de volta ao interior da mansao."}
};

/* Retorna os objetos disponiveis em cada sala. */
const Objeto *obter_objetos(int sala, int *quantidade) {
    switch (sala) {
        case 1:
            *quantidade = (int)(sizeof(hall) / sizeof(hall[0]));
            return hall;

        case 2:
            *quantidade = (int)(sizeof(biblioteca) / sizeof(biblioteca[0]));
            return biblioteca;

        case 3:
            *quantidade = (int)(sizeof(quarto) / sizeof(quarto[0]));
            return quarto;

        case 4:
            *quantidade = (int)(sizeof(cozinha) / sizeof(cozinha[0]));
            return cozinha;

        case 5:
            *quantidade = (int)(sizeof(escritorio) / sizeof(escritorio[0]));
            return escritorio;

        case 6:
            *quantidade = (int)(sizeof(porao) / sizeof(porao[0]));
            return porao;

        default:
            *quantidade = 0;
            return NULL;
    }
}

/* Mostra uma interacao basica com o objeto escolhido. */
void examinar_objeto(const Objeto *objeto) {
    printf("\n--- %s ---\n", objeto->nome);
    printf("%s\n", objeto->descricao);
}

/* Permite ao jogador examinar objetos dentro de uma sala. */
void interagir_sala(int sala) {
    int quantidade = 0;
    int opcao;
    int i;

    const Objeto *objetos = obter_objetos(sala, &quantidade);

    if (objetos == NULL || quantidade == 0) {
        printf("Sala invalida.\n");
        return;
    }

    do {
        printf("\n======= EXPLORAR SALA =======\n");

        for (i = 0; i < quantidade; i++) {
            printf("%d. Examinar %s\n", i + 1, objetos[i].nome);
        }

        printf("0. Voltar para as salas\n");
        printf("Escolha uma interacao: ");

        opcao = ler_opcao();

        if (opcao >= 1 && opcao <= quantidade) {
            examinar_objeto(&objetos[opcao - 1]);
        } else if (opcao == 0) {
            printf("\nVoce saiu da sala.\n");
        } else {
            printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);
}

/* Menu de navegacao da mansao. */
void iniciar_investigacao(void) {
    int sala = -1;

    apresentar_introducao();

    while (sala != 0) {
        printf("\n========== MANSÃO ==========\n");
        printf("1. Hall de entrada\n");
        printf("2. Biblioteca\n");
        printf("3. Quarto do casal\n");
        printf("4. Cozinha\n");
        printf("5. Escritorio do Sr. Almeida\n");
        printf("6. Porao\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma sala: ");

        sala = ler_opcao();

        if (sala >= 1 && sala <= 6) {
            interagir_sala(sala);
        } else if (sala == 0) {
            printf("\nVoce voltou ao menu principal.\n");
        } else {
            printf("\nOpcao invalida. Escolha um numero de 0 a 6.\n");
        }
    }
}

/* Menu principal do jogo. */
void executar_jogo(void) {
    int opcao = -1;

    while (opcao != 0) {
        printf("\n========================================\n");
        printf("          NULL - INVESTIGACAO\n");
        printf("========================================\n");
        printf("1. Iniciar investigacao\n");
        printf("0. Sair do jogo\n");
        printf("Escolha uma opcao: ");

        opcao = ler_opcao();

        switch (opcao) {
            case 1:
                iniciar_investigacao();
                break;

            case 0:
                printf("\nObrigado por jogar NULL!\n");
                printf("Encerrando o jogo...\n");
                break;

            case -1:
                printf("\nEntrada invalida. Digite um numero.\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    }
}

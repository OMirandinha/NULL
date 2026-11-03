#include <stddef.h>
#include "dados.h"

/* Sala 1: Hall de entrada. */
static Objeto hall[] = {
    {"Porta principal", "A porta esta fechada. Nao ha sinais claros de arrombamento.", 0, NULL, false},
    {"Tapete", "O tapete esta umido por causa da chuva trazida pelos visitantes.", 0, NULL, false},
    {"Relogio de parede", "O relogio antigo continua funcionando normalmente.", 0, NULL, false},
    {"Escadaria", "A escadaria leva aos quartos e ao corredor superior.", 0, NULL, false}
};

/* Sala 2: Biblioteca. */
static Objeto biblioteca[] = {
    {"Estantes", "As estantes estao repletas de livros antigos.", 0, NULL, false},
    {"Poltrona do Sr. Almeida", "A poltrona esta diante da lareira, onde a vitima foi encontrada.",
     1, "A posicao da poltrona e a marca no tapete indicam que o Sr. Almeida estava sentado quando foi atingido.", false},
    {"Lareira", "As brasas ainda estao mornas. Entre as cinzas ha um pequeno fragmento metalico.",
     2, "O fragmento parece ser parte de um estojo de bala. O disparo aconteceu dentro da biblioteca.", false},
    {"Vitrola", "A vitrola ainda conserva o disco de musica classica usado naquela noite.",
     3, "O disco estava tocando durante a queda de energia. A musica e a tempestade poderiam abafar o som de um disparo.", false}
};

/* Sala 3: Quarto de Carla. */
static Objeto quarto[] = {
    {"Cama", "A cama esta desarrumada, como se alguem tivesse se levantado rapidamente.", 0, NULL, false},
    {"Criado-mudo", "Ha um copo de agua e um livro sobre o criado-mudo.", 0, NULL, false},
    {"Guarda-roupa", "Os casacos estao pendurados e organizados.",
     4, "Um casaco de Carla esta seco e sem marcas de barro, o que nao confirma sua presenca no jardim durante a tempestade.", false},
    {"Penteadeira", "Entre os objetos pessoais ha uma fotografia antiga do casal.", 0, NULL, false}
};

/* Sala 4: Cozinha. */
static Objeto cozinha[] = {
    {"Bancada", "A bancada foi limpa recentemente.", 0, NULL, false},
    {"Chaleira", "A chaleira esta fria e vazia.",
     5, "O cha preparado por Daniel permaneceu praticamente intacto. Isso indica que o Sr. Almeida nao chegou a toma-lo.", false},
    {"Armario de loucas", "As xicaras estao guardadas, exceto uma que foi deixada sobre a pia.",
     6, "A xicara separada tem marcas de dedos, mas nao ha evidencia de que tenha sido usada pela vitima.", false},
    {"Pia", "A pia esta molhada e contem alguns utensilios lavados.", 0, NULL, false}
};

/* Sala 5: Escritorio. */
static Objeto escritorio[] = {
    {"Mesa do Sr. Almeida", "A mesa esta coberta de documentos e relatorios financeiros.",
     7, "Um documento mostra que Bruno participava de uma reuniao por video no horario aproximado do crime. A reuniao, porem, nao prova que ele permaneceu diante da camera o tempo todo.", false},
    {"Computador", "O computador esta ligado ao historico de reunioes recentes.", 0, NULL, false},
    {"Estante", "Pastas e livros ocupam as prateleiras.", 0, NULL, false},
    {"Cofre", "O cofre esta fechado e nao apresenta sinais de violacao.", 0, NULL, false}
};

/* Sala 6: Porao. */
static Objeto porao[] = {
    {"Quadro eletrico", "O quadro eletrico controla a energia de parte da mansao.",
     8, "O disjuntor foi desligado manualmente. A queda de energia nao parece ter sido causada pela tempestade.", false},
    {"Caixa de ferramentas", "Uma caixa de ferramentas esta encostada na parede.", 0, NULL, false},
    {"Armario antigo", "O armario esta empoeirado e parece nao ser aberto ha muito tempo.", 0, NULL, false},
    {"Escada de servico", "A escada conecta o porao ao corredor lateral da mansao.", 0, NULL, false}
};

/* Sala 7: Jardim coberto, local onde Elisa foi vista. */
static Objeto jardim[] = {
    {"Porta de vidro", "A porta de vidro que liga o jardim ao corredor esta entreaberta.", 0, NULL, false},
    {"Vasos de plantas", "Alguns vasos foram deslocados e ha terra espalhada no piso.",
     9, "As marcas na terra formam pegadas que saem do jardim e seguem em direcao ao corredor do porao. O tamanho e o desenho coincidem com as marcas de um sapato encontrado no quarto de hospedes usado por Elisa.", false},
    {"Banco de pedra", "O banco esta molhado, apesar de ficar sob a cobertura.",
     10, "Debaixo do banco ha um brinco. Carla confirma que nao e dela; Daniel diz ter visto Elisa usando um par igual naquela noite.", false},
    {"Mesa de jardinagem", "Sobre a mesa ha luvas e pequenos utensilios de jardinagem.",
     11, "Sob a mesa ha um bilhete amassado, escrito por Elisa: 'Depois que Almeida assinar, ninguem podera nos impedir'. A frase sugere um motivo ligado aos negocios da vitima.", false}
};

Objeto *obter_objetos(int sala, int *quantidade) {
    if (quantidade == NULL) return NULL;

    switch (sala) {
        case 1: *quantidade = (int)(sizeof(hall) / sizeof(hall[0])); return hall;
        case 2: *quantidade = (int)(sizeof(biblioteca) / sizeof(biblioteca[0])); return biblioteca;
        case 3: *quantidade = (int)(sizeof(quarto) / sizeof(quarto[0])); return quarto;
        case 4: *quantidade = (int)(sizeof(cozinha) / sizeof(cozinha[0])); return cozinha;
        case 5: *quantidade = (int)(sizeof(escritorio) / sizeof(escritorio[0])); return escritorio;
        case 6: *quantidade = (int)(sizeof(porao) / sizeof(porao[0])); return porao;
        case 7: *quantidade = (int)(sizeof(jardim) / sizeof(jardim[0])); return jardim;
        default: *quantidade = 0; return NULL;
    }
}

const char *nome_sala(int sala) {
    switch (sala) {
        case 1: return "Hall de Entrada";
        case 2: return "Biblioteca";
        case 3: return "Quarto de Carla";
        case 4: return "Cozinha";
        case 5: return "Escritorio do Sr. Almeida";
        case 6: return "Porao";
        case 7: return "Jardim Coberto";
        default: return "Local desconhecido";
    }
}

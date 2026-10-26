# NULL — Jogo de Investigação Criminal
Toda pista é uma conexão. Todo suspeito esconde uma possibilidade.

NULL é um jogo textual de investigação criminal desenvolvido em linguagem C. O jogador assume o papel de um investigador que explora uma mansão, encontra pistas e reúne evidências para descobrir quem matou o Sr. Almeida.

O jogo possui uma narrativa fixa: o culpado não muda entre partidas, mas o jogador pode escolher a ordem em que explora os cômodos.

📌 Índice
Objetivo do projeto

Como funciona o jogo

Estrutura de arquivos

Estrutura de dados principal

Requisitos acadêmicos

Compilação

Execução

Etapas de desenvolvimento

Escopo do projeto

🎯 Objetivo do projeto
Desenvolver um jogo simples que aplique conceitos de programação em C e Estruturas de Dados, com foco em uma lista simplesmente encadeada para armazenar as pistas encontradas durante a investigação.

🕹️ Como funciona o jogo
Explorar seis cômodos da mansão.

Investigar pistas predefinidas em cada cômodo.

Consultar as pistas encontradas durante a investigação.

Conhecer os depoimentos de quatro suspeitos.

Reunir as evidências necessárias para solucionar o caso.

Descobrir o culpado e visualizar o desfecho da história.

Cômodos
#	Cômodo
1	Hall de entrada
2	Biblioteca
3	Quarto do casal
4	Cozinha
5	Escritório do Sr. Almeida
6	Porão
Suspeitos
Suspeito	Relação com a vítima
Carla	Esposa da vítima
Bruno	Sócio da vítima
Daniel	Mordomo da mansão
Elisa	Conhecida da vítima
Os detalhes da história, as pistas e a solução do crime serão definidos durante a implementação.

📁 Estrutura de arquivos
text
NULL/
├── main.c
├── jogo.c
├── jogo.h
├── estruturas.c
├── estruturas.h
├── dados.c
├── dados.h
├── arquivo.c
├── arquivo.h
├── saves/
│   └── progresso.txt
├── README.md
└── .gitignore
Responsabilidade dos arquivos
Arquivo	Responsabilidade
main.c	Iniciar o programa e chamar a função principal do jogo.
jogo.c / jogo.h	Controlar os menus, a exploração dos cômodos, a coleta de pistas e o encerramento da investigação.
estruturas.c / estruturas.h	Implementar e declarar as operações da lista encadeada e os tipos de dados necessários.
dados.c / dados.h	Definir os cômodos, os suspeitos e as pistas predefinidas.
arquivo.c / arquivo.h	Implementar o salvamento e o carregamento do progresso, caso essa funcionalidade seja incluída.
saves/progresso.txt	Armazenar o progresso do jogador, se o salvamento for implementado.
.gitignore	Ignorar o executável e arquivos temporários do ambiente de desenvolvimento.
Observação: o salvamento em arquivo é opcional no escopo inicial. O diretório saves/ e o arquivo progresso.txt podem ser adicionados posteriormente.

🧩 Estrutura de dados principal
Lista simplesmente encadeada
A lista encadeada armazenará dinamicamente as pistas encontradas pelo jogador. Cada nó conterá os dados de uma pista e um ponteiro para o próximo nó.

As operações previstas são:

Inserção — adicionar uma pista encontrada à lista.

Busca — localizar uma pista pelo identificador.

Exibição — mostrar todas as pistas coletadas.

Remoção — remover uma pista, se necessário.

Liberação — liberar todos os nós alocados dinamicamente ao encerrar o jogo.

A implementação utilizará ponteiros e alocação dinâmica de memória com malloc, além de liberar a memória corretamente com free.

Uma pilha para desfazer a última ação poderá ser adicionada como funcionalidade complementar, caso haja tempo. Ela não faz parte do escopo inicial.

📚 Requisitos acadêmicos
☑ Código desenvolvido em linguagem C.
☑ Organização do código em funções.
☑ Utilização adequada de ponteiros.
☑ Tratamento de entradas inválidas.
☑ Comentários nas partes mais importantes do programa.
☑ Implementação correta das operações da estrutura de dados escolhida.
☑ Liberação adequada da memória dinâmica utilizada.
☑ Interface textual organizada e compreensível.
☑ Participação de todos os integrantes da equipe.
⚙️ Compilação
Com o GCC instalado, na raiz do projeto, compile os arquivos .c:

bash
gcc -Wall -Wextra -std=c11 main.c jogo.c estruturas.c dados.c arquivo.c -o null
Esse comando pressupõe que todos os arquivos listados já existam e estejam implementados. Se o módulo arquivo.c ainda não estiver pronto, ele pode ser omitido temporariamente do comando.

▶️ Execução
Linux ou macOS:

bash
./null
Windows (dependendo do compilador):

text
null.exe
🛠️ Etapas de desenvolvimento
Criar o menu principal e o fluxo básico da investigação.

Implementar a exploração dos seis cômodos.

Implementar a lista encadeada e a coleta de pistas.

Adicionar as funções de consulta e remoção de pistas.

Validar as entradas do jogador.

Definir as condições necessárias para revelar o culpado.

Testar a liberação de memória e corrigir erros.

Implementar o salvamento em arquivo, se houver tempo.

Finalizar a documentação e preparar a apresentação.

📦 Escopo do projeto
✅ Um único culpado e um desfecho predefinido.

✅ Seis cômodos exploráveis.

✅ Quatro suspeitos.

✅ Pistas predefinidas, sem geração aleatória.

✅ Liberdade para escolher a ordem de exploração.

✅ Lista encadeada como estrutura de dados principal.

✅ Interface textual executada no terminal.

O foco do projeto é demonstrar a aplicação correta de uma estrutura de dados em um programa funcional, priorizando organização, gerenciamento de memória e clareza do código, em vez de uma grande quantidade de funcionalidades.

<p align="center"> <strong>NULL — encontre a conexão que revela a verdade.</strong> </p>

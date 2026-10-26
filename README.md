# NULL — Jogo de Investigação Criminal

> **Toda pista é uma conexão. Todo suspeito esconde uma possibilidade.**

**NULL** é um jogo textual de investigação criminal desenvolvido em linguagem **C**. O jogador assume o papel de um investigador que explora uma mansão, encontra pistas e reúne evidências para descobrir quem matou o Sr. Almeida.

O jogo possui uma narrativa fixa: o culpado não muda entre partidas, mas o jogador pode escolher a ordem em que explora os cômodos.

---

## 📌 Índice

- [Objetivo do projeto](#-objetivo-do-projeto)
- [Como funciona o jogo](#️-como-funciona-o-jogo)
- [Estrutura de arquivos](#-estrutura-de-arquivos)
- [Estrutura de dados principal](#-estrutura-de-dados-principal)
- [Requisitos acadêmicos](#-requisitos-acadêmicos)
- [Compilação](#️-compilação)
- [Execução](#️-execução)
- [Etapas de desenvolvimento](#️-etapas-de-desenvolvimento)
- [Escopo do projeto](#-escopo-do-projeto)

---

## 🎯 Objetivo do projeto

Desenvolver um jogo simples que aplique conceitos de programação em C e Estruturas de Dados, com foco em uma **lista simplesmente encadeada** para armazenar as pistas encontradas durante a investigação.

---

## 🕹️ Como funciona o jogo

- Explorar **seis cômodos** da mansão.
- Investigar pistas predefinidas em cada cômodo.
- Consultar as pistas encontradas durante a investigação.
- Conhecer os depoimentos de **quatro suspeitos**.
- Reunir as evidências necessárias para solucionar o caso.
- Descobrir o culpado e visualizar o desfecho da história.

### Cômodos

| # | Cômodo |
|---|--------|
| 1 | Hall de entrada |
| 2 | Biblioteca |
| 3 | Quarto do casal |
| 4 | Cozinha |
| 5 | Escritório do Sr. Almeida |
| 6 | Porão |

### Suspeitos

| Suspeito | Relação com a vítima |
|----------|----------------------|
| **Carla** | Esposa da vítima |
| **Bruno** | Sócio da vítima |
| **Daniel** | Mordomo da mansão |
| **Elisa** | Conhecida da vítima |

> Os detalhes da história, as pistas e a solução do crime serão definidos durante a implementação.

---

## 📁 Estrutura de arquivos

```text
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

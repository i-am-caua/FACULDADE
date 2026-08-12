# Questão 02 — Árvore AVL

Espaço reservado para a solução da segunda questão da lista de Árvores (BST e
AVL), disponibilizada no Moodle (AVA) da disciplina **Algoritmos e Estruturas de
Dados IV**.

Quando a implementação for iniciada, usar o nome `questao-02-avl.c` e adicionar
aqui os comandos exatos de compilação, execução e teste.
# Questao 02 - Arvore AVL

Solucao da segunda questao da lista de Arvores (BST e AVL), disponibilizada no
Moodle (AVA) da disciplina **Algoritmos e Estruturas de Dados IV**.

## Arquivos

- `questao-02-avl.c`: implementacao da arvore AVL com chave e nome em cada no.

## Funcionalidades

- Insercao com rotacoes simples e duplas.
- Busca por chave, retornando o nome armazenado.
- Consulta da menor e da maior chave.
- Remocao com rebalanceamento da arvore.
- Consulta da quantidade de filhos de um no.
- Exibicao em pre-ordem, incluindo altura e fator de balanceamento.

## Como compilar

No GCC:

```bash
gcc -Wall -Wextra -pedantic -std=c11 questao-02-avl.c -o questao-02-avl
```

## Como executar

Linux ou laboratorio:

```bash
./questao-02-avl
```

Windows:

```powershell
.\questao-02-avl.exe
```

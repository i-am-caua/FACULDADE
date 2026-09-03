# Exercício — Árvore Trie (Árvore de Prefixos)

Implementação de árvore de prefixos (Trie) para inserção, busca, remoção e
impressão de palavras, desenvolvida para a disciplina **Algoritmos e Estruturas
de Dados IV** (Professor Thamer Horbylon Nascimento).

## Arquivos

- `main.c`: implementação da estrutura de dados Trie em C com menu interativo.
- `apoio/visualizacao-inserir-trie.html`: visualizador interativo passo a passo
  da função recursiva `inserir`, sincronizado com código C, pilha de execução,
  fita de caracteres e inspeção de memória.

## Como compilar

No GCC (Linux, WSL ou laboratório):

```bash
gcc -Wall -Wextra -std=c99 main.c -o main
```

No Windows (PowerShell / CMD com GCC/MinGW):

```powershell
gcc -Wall -Wextra -std=c99 main.c -o main.exe
```

## Como executar

Linux ou laboratório:

```bash
./main
```

Windows:

```powershell
.\main.exe
```

## Material de apoio

Abra `apoio/visualizacao-inserir-trie.html` em qualquer navegador (Google Chrome,
Firefox, Microsoft Edge, etc.).

### Recursos do visualizador:

- **Passo a passo didático**: avanço e retorno com as setas do teclado (`←` e `→`)
  ou botões de controle.
- **Sincronização com o código C**: destaca linha a linha a execução da função
  `inserir` de `main.c` (linhas 19 a 29).
- **Pilha de chamadas (Call Stack)**: exibe o empilhamento e desempilhamento dos
  níveis de recursão.
- **Fita de caracteres da palavra**: visualização de `palavra[0]`, lookahead
  `palavra[1] == '\0'`, cálculo de índice ASCII (`index = palavra[0] - 'a'`).
- **Inspeção de nós e ponteiros**: tabela de variáveis em tempo real e visualização
  completa do vetor `letras[26]` de cada nó da árvore.
- **Cenários pré-configurados e personalizados**: botões para cenários rápidos
  (ex.: `"sol"`, `"sola"`, `"som"`, `"so"`) ou inserção de qualquer palavra digitada.

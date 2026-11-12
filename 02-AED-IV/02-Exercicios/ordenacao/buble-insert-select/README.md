# Ordenacao: bubble, selection, insertion, shell e merge sort

Programa em C para gerar um vetor aleatorio e ordena-lo usando um dos cinco
algoritmos pelo menu. O insertion sort e o shell sort imprimem o vetor a cada
deslocamento e insercao de chave, e o merge sort imprime as intercalacoes.

## Compilar

```bash
gcc -std=c11 -Wall -Wextra -g exc.c -o exc
```

## Executar

```bash
./exc
```

Escolha `1` para bubble sort, `2` para selection sort, `3` para insertion
sort, `4` para shell sort, `5` para merge sort ou `0` para sair. Cada escolha
gera um novo vetor aleatorio.

## Visualizacao do insertion sort

Abra [apoio/visualizacao-insertion-sort.html](apoio/visualizacao-insertion-sort.html)
no navegador. Funciona sem internet e sem instalar dependencias.

- Use **Avancar**, **Voltar** ou a barra de progresso para acompanhar cada
  instrucao da sua funcao `insertionSort`, com a linha correspondente em `exc.c`.
- Observe `i`, `j`, `chave`, os indices e valores do vetor. A borda tracejada
  indica onde a chave entrara; o valor permanece no vetor ate ser sobrescrito.
- Compare as etapas com a saida de `printVtr`; clique em uma impressao para
  voltar ao passo correspondente.
- Use **Reproduzir** para animar ou informe outro vetor de ate 20 inteiros.
  O modo aleatorio usa os mesmos limites do C: 10 a 20 valores entre 1 e 100.

O exemplo inicial `[8, 3, 5, 2, 7]` termina em `[2, 3, 5, 7, 8]`.
No primeiro deslocamento, o vetor fica `[8, 8, 5, 2, 7]`, mas `chave = 3`
continua salva. A linha `vtr[j + 1] = chave` depois produz `[3, 8, 5, 2, 7]`.
O teste usa `>`: valores iguais nao sao deslocados entre si. Quando `j = -1`,
o `&&` evita acessar `vtr[-1]`.

Este HTML e material de apoio, separado do codigo de entrega. Contexto da
disciplina: Moodle (AVA), AED IV (`Disciplina.0088`), professor Thamer Horbylon
Nascimento. Nenhum enunciado oficial foi fornecido nesta pasta.

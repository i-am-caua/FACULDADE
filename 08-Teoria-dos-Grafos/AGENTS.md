# Teoria dos Grafos

> Leia o `AGENTS.md` global (pasta raiz) antes de trabalhar nesta disciplina.

## Identificação

| Campo | Valor |
|---|---|
| Nome da disciplina | Teoria dos Grafos |
| Código (Moodle) | Disciplina.0093 |
| Professor | Newarney Torrezao da Costa |
| Ambiente | Moodle (AVA) |
| Semestre | Atual (2026/2) |

## Estrutura de pastas

```
08-Teoria-dos-Grafos/
├── AGENTS.md
├── 00-Plano-de-Ensino/    ← ementa oficial, cronograma (atualizar quando chegar)
├── 01-Anotacoes/          ← 2026-08-06-assunto.md
├── 02-Exercicios/         ← listas resolvidas (teoria e demonstrações)
├── 03-Projetos/           ← trabalhos práticos (algoritmos em código)
├── 04-Avaliacoes/         ← provas por data
└── 05-Materiais/          ← slides, PDFs, links
```

## Tópicos prováveis (ESTIMATIVA — atualizar com o plano de ensino)

1. Conceitos básicos: grafos, digrafos, graus, caminhos, ciclos
2. Representações: matriz de adjacência, lista de adjacência
3. Buscas: BFS e DFS, ordenação topológica
4. Árvores geradoras: Prim e Kruskal
5. Caminhos mínimos: Dijkstra, Bellman-Ford, Floyd-Warshall
6. Conectividade, pontes e articulações (confirmar)
7. Coloração e aplicações (confirmar)
8. Aplicações: redes, escalonamento, matching

## Linguagens e ferramentas

- Linguagem principal: **C** (padrão nos laboratórios) — confirmar.
- Compilador: GCC (`gcc -Wall -Wextra -o prog prog.c`).
- Implementações compartilham técnicas com AED IV (listas de adjacência).

## Regras específicas

1. Teoria: resolver listas com **demonstrações/explicações em pt-BR**, não só
   respostas.
2. Implementações de algoritmos: subpasta kebab-case em `03-Projetos/` ou
   `02-Exercicios/<assunto>/` + `README.md` com comando de compilação e exemplo
   de entrada/saída.
3. Grafos em testes: representar como arestas listadas no enunciado do
   exercício (salvar exemplos junto da solução).
4. Provas: `05-Avaliacoes/YYYY-MM-DD-<tipo>.md`.

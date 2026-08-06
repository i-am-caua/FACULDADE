# AED IV — Algoritmos e Estruturas de Dados IV

> Leia o `AGENTS.md` global (pasta raiz) antes de trabalhar nesta disciplina.

## Identificação

| Campo | Valor |
|---|---|
| Nome da disciplina | Algoritmos e Estruturas de Dados IV |
| Código (Moodle) | Disciplina.0088 |
| Professor | Thamer Horbylon Nascimento |
| Ambiente | Moodle (AVA) |
| Semestre | Atual (2026/2) |

## Estrutura de pastas (expandida)

```
02-AED-IV/
├── AGENTS.md
├── 00-Plano-de-Ensino/    ← ementa oficial, cronograma (PRIORIDADE nº 1 quando chegar)
├── 01-Anotacoes/          ← resumo por aula: 2026-08-06-assunto.md
├── 02-Exercicios/         ← listas resolvidas, organizadas por tópico:
│   ├── arvores/
│   ├── heap/
│   ├── hash/
│   └── grafos/
├── 03-Implementacoes/     ← código-fonte organizado por estrutura:
│   ├── arvore-avl/
│   ├── arvore-rubro-negra/
│   ├── b-tree/
│   ├── heap/
│   ├── tabela-hash/
│   └── grafos/
├── 04-Projetos/           ← trabalhos práticos valendo nota
├── 05-Avaliacoes/         ← provas e trabalhos, organizados por data
└── 06-Materiais/          ← slides e PDFs por tópico (aulas numeradas):
    ├── 01-arvores-balanceadas/
    ├── 02-arvores-b/
    ├── 03-heaps-e-filas-de-prioridade/
    ├── 04-tabelas-hash/
    ├── 05-grafos-representacoes/
    ├── 06-ordenacao-e-complexidade/
    ├── 07-busca-em-grafos/
    └── 08-complexidade-amortizada/
```

> Slides: nomear como `aula-NN-MM-assunto.pdf` dentro da pasta do tópico
> (ex.: `aula-01-02-arvores-balanceadas-avl.pdf`).

## Tópicos prováveis (ESTIMATIVA — atualizar com o plano de ensino)

> Estes tópicos são a sequência clássica de uma AED IV e **devem ser marcados
> como confirmados ou descartados assim que o plano de ensino chegar**.

1. Árvores balanceadas: AVL e Rubro-Negra
2. Árvores B e variantes (uso em banco de dados e arquivos)
3. Heaps e heap sort; filas de prioridade
4. Tabelas hash: funções de espalhamento e tratamento de colisões
5. Estruturas para grafos: listas/matriz de adjacência
6. Algoritmos de ordenação avançados e análise de complexidade (Big-O)
7. Algoritmos de busca em grafos: BFS/DFS, caminhos mínimos
8. Análise de complexidade de tempo e espaço (revisão/amortizada)

## Linguagens e ferramentas

- Linguagem principal: **C** (padrão nos laboratórios). Confirmar com o
  professor; alguns semestres usam Java.
- Compilador: GCC (`gcc -Wall -Wextra -o prog prog.c`).
- Recomendação: cada implementação em `03-Implementacoes/` com seu próprio
  `README.md` contendo o comando exato de compilação e como rodar.

## Regras específicas

1. Priorizar **código comentado em pt-BR** com nomes de variáveis claros.
2. Para cada implementação nova: criar a subpasta kebab-case em
   `03-Implementacoes/` + `README.md` (como compilar/rodar/testar).
3. Exercícios de lista: criar arquivo em `02-Exercicios/<topico>/` seguindo o
   nome da questão (ex.: `questao-01.c` + `README.md` com enunciado resumido).
4. Provas: salvar em `05-Avaliacoes/YYYY-MM-DD-<tipo>.md` (ex.: `2026-10-15-prova-2.md`).
5. Se o professor usar plataforma específica de juiz/entrega (ex.: Moodle,
   RunCodes, URI/Beecrowd), anotar aqui qual é — marca a fonte oficial de
   exercícios.

# FACULDADE — Contexto Global do Repositório

> Guia mestre para o agente de IA. Este arquivo é lido antes de qualquer tarefa.
> Sempre consulte também o `AGENTS.md` da disciplina específica antes de trabalhar nela.

## Propósito deste repositório

Organizar os materiais, anotações, exercícios, projetos e avaliações de todas as
disciplinas da faculdade em um único lugar, sincronizado entre o laboratório da
faculdade e a casa do estudante.

## Disciplinas do semestre atual

| Pasta | Disciplina | Professor |
|---|---|---|
| `01-Atividade-de-Extensao-I` | Atividade de Extensão I | Cleon Xavier Pereira Junior |
| `02-AED-IV` | Algoritmos e Estruturas de Dados IV | Thamer Horbylon Nascimento |
| `03-Banco-de-Dados-II` | Banco de Dados II | Wesley Flavio de Miranda |
| `04-Computacao-Movel` | Computação Móvel | Thamer Horbylon Nascimento |
| `05-Pesquisa-Operacional` | Pesquisa Operacional | Lais Candido Rodrigues da Silva Lopes |
| `06-Redes-de-Computadores` | Redes de Computadores | Wesley Flavio de Miranda |
| `07-Teoria-dos-Grafos` | Teoria dos Grafos | Newarney Torrezao da Costa |

## Estrutura padrão de uma disciplina

Cada disciplina segue a mesma estrutura numérica (exceto as Atividades):

```
NN-Disciplina/
├── AGENTS.md              ← contexto específico da disciplina
├── 00-Plano-de-Ensino/    ← ementa, plano, cronograma (sempre manter atualizado)
├── 01-Anotacoes/          ← notas de aula, resumos (nomear: YYYY-MM-DD-assunto.md)
├── 02-Exercicios/         ← listas e exercícios resolvidos
├── 03-Projetos/           ← projetos/trabalhos práticos (um subpasta por projeto)
├── 04-Avaliacoes/         ← provas, trabalhos valendo nota (organizar por data)
└── 05-Materiais/          ← slides, PDFs, livros, links úteis
```

Disciplinas de Atividade (Extensão) usam `02-Entregas` e `03-Comprovantes`.
A disciplina AED IV possui estrutura expandida — ver `02-AED-IV/AGENTS.md`.

## Organização de atividades, listas e enunciados

Para atividades com várias questões ou vários arquivos, usar uma pasta própria
dentro do tópico correspondente:

```
02-Exercicios/<topico>/NN-lista-<assunto>/
├── README.md                  ← índice e estado das soluções
├── 00-enunciado/             ← fonte oficial da atividade
│   ├── nome-da-atividade.pdf ← arquivo original, quando disponível
│   └── nome-da-atividade.md  ← transcrição fiel para leitura por IA
├── 01-<questao-ou-tema>/
│   ├── README.md             ← como compilar, executar e testar
│   ├── questao-01.c
│   └── apoio/                ← visualizações e materiais que não são entrega
└── 02-<questao-ou-tema>/
    ├── README.md
    └── questao-02.c
```

Regras para essa estrutura:

1. Quando o professor disponibilizar uma atividade ou lista em PDF, **manter o
   PDF original** e criar, sempre que viável, uma versão `.md` fiel para
   facilitar busca, leitura e uso por agentes de IA.
2. O PDF e sua transcrição Markdown ficam juntos em `00-enunciado/`. A versão
   Markdown deve identificar a origem: Moodle (AVA), disciplina e professor.
3. Nunca substituir o enunciado oficial por um `README.md`. O `README.md` é
   apenas um índice da pasta e um guia para compilar, executar e testar.
4. Separar soluções em subpastas numeradas por questão ou tema quando a
   atividade possuir vários entregáveis.
5. Colocar visualizações HTML, diagramas, rascunhos e outros materiais
   didáticos em `apoio/`; eles não fazem parte da entrega, salvo instrução do
   professor.
6. Anotações de aula continuam em `01-Anotacoes/`, e slides ou materiais gerais
   continuam em `05-Materiais/` (ou na pasta equivalente da disciplina).
7. Para exercícios pequenos de arquivo único, a estrutura pode ser simplificada,
   mas a separação entre **enunciado oficial**, **solução** e **apoio** deve ser
   preservada.

## Convenções obrigatórias (pt-BR)

1. **Idioma:** todo conteúdo (anotações, nomes de arquivo, READMEs, código,
   mensagens de commit) é escrito em **português (pt-BR)**.
2. **Nomes de arquivos/pastas:** sem acentos, sem espaços, separados por hífen
   (`kebab-case`). Ex.: `arvore-avl.c`, `aula-01-filas.md`.
3. **Datas:** usar formato `YYYY-MM-DD` em prefixo de anotações e provas
   (ex.: `2026-08-06-grafos-bfs.md`).
4. **Código:** sempre acompanhado de `README.md` com como compilar e rodar
   (incluir comando exato do GCC/compilador usado nos labs).
5. **Nunca** apagar pastas vazias estruturais — elas são a espinha dorsal da
   organização (pastas vazias são mantidas via `.gitkeep` se houver git).
6. **Nunca** remover ou renomear as pastas numeradas sem avisar o usuário.
7. **Link para Moodle:** sempre que mencionar uma atividade, citar o ambiente
   (Moodle) e a disciplina de origem para conferência.
8. **Sempre** atualizar `00-Plano-de-Ensino/` quando o plano de ensino for
   disponibilizado pelo professor — ele é a fonte primária de contexto.

## Fluxo de trabalho (labs ↔ casa)

- O usuário troca de laboratório constantemente; o repositório deve funcionar
  em qualquer máquina sem configuração manual (código com `Makefile` ou
  `README` com instruções de compilação).
- Se o projeto estiver em **git**: usar `git pull` ao iniciar e `git commit`
  + `git push` ao finalizar sessões de trabalho. Mensagens de commit curtas em
  pt-BR seguindo o padrão `assunto: resumo` (ex.: `aed4: implementa arvore AVL`).
- Alternativas aceitas para sincronização: OneDrive/Google Drive/Dropbox
  (sincronização automática da pasta FACULDADE).

## Regras para o agente de IA

1. **Sempre** ler `AGENTS.md` da disciplina antes de criar/editar arquivos nela.
2. Ao criar anotações: verificar se já existe arquivo do mesmo assunto (evitar
   duplicidade); se existir, **editar/expandir** em vez de criar novo.
3. Ao criar projeto: criar subpasta com nome kebab-case em `03-Projetos/` e
   incluir `README.md` com instruções de execução.
4. Ao ajudar com exercícios: resolver na pasta `02-Exercicios/` seguindo o
   assunto e a estrutura de atividades definida acima, com arquivo de solução e
   explicação breve em pt-BR.
5. Tópicos de disciplina são **estimativas** até o plano de ensino chegar —
   marcar no AGENTS.md da disciplina o que já foi confirmado vs. estimado.
6. Se o usuário citar o Moodle/professor, preferir o conteúdo do plano de
   ensino local (se existir) sobre suposições genéricas.

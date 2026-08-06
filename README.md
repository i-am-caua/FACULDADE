# FACULDADE

Repositório central de organização das disciplinas da faculdade — anotações,
exercícios, projetos e avaliações, tudo em um só lugar.

> **Objetivo:** funcionar igual em qualquer máquina. O estudante alterna entre
> o laboratório da faculdade e a casa o tempo todo; basta `git pull` ao chegar
> e `git commit` + `git push` ao sair, e tudo continua sincronizado.

---

## Disciplinas do semestre atual

| Pasta | Disciplina | Professor |
|---|---|---|
| `01-Atividade-de-Extensao-I` | Atividade de Extensão I | Cleon Xavier Pereira Junior |
| `02-Atividade-Complementar` | Atividade Complementar (.0003) | — |
| `03-AED-IV` | Algoritmos e Estruturas de Dados IV | Thamer Horbylon Nascimento |
| `04-Banco-de-Dados-II` | Banco de Dados II | Wesley Flavio de Miranda |
| `05-Computacao-Movel` | Computação Móvel | Thamer Horbylon Nascimento |
| `06-Pesquisa-Operacional` | Pesquisa Operacional | Lais Candido Rodrigues da Silva Lopes |
| `07-Redes-de-Computadores` | Redes de Computadores | Wesley Flavio de Miranda |
| `08-Teoria-dos-Grafos` | Teoria dos Grafos | Newarney Torrezao da Costa |

---

## Estrutura geral

```
FACULDADE/
├── AGENTS.md                          ← guia para o agente de IA (contexto global)
├── README.md                          ← este arquivo
├── 01-Atividade-de-Extensao-I/        ← pastas numeradas = disciplinas
├── 02-Atividade-Complementar/
├── 03-AED-IV/                         ← estrutura expandida (ver abaixo)
├── 04-Banco-de-Dados-II/
├── 05-Computacao-Movel/
├── 06-Pesquisa-Operacional/
├── 07-Redes-de-Computadores/
└── 08-Teoria-dos-Grafos/
```

### Estrutura padrão de cada disciplina

```
NN-Disciplina/
├── AGENTS.md              ← contexto específico da disciplina (professor, tópicos, regras)
├── 00-Plano-de-Ensino/    ← ementa, plano e cronograma oficiais
├── 01-Anotacoes/          ← notas de aula e resumos
├── 02-Exercicios/         ← listas e exercícios resolvidos
├── 03-Projetos/           ← projetos e trabalhos práticos
├── 04-Avaliacoes/         ← provas e trabalhos valendo nota
└── 05-Materiais/          ← slides, PDFs, livros e links úteis
```

### Disciplinas de atividade

Extensão e Complementar seguem estrutura própria:

```
NN-Atividade/
├── AGENTS.md
├── 00-Plano-de-Ensino/    ← regulamento e orientações oficiais
├── 01-Anotacoes/          ← planejamento e controle de horas
├── 02-Entregas/           ← relatórios e formulários
└── 03-Comprovantes/       ← certificados, declarações e comprovantes
```

### AED IV (estrutura expandida)

```
03-AED-IV/
├── AGENTS.md
├── 00-Plano-de-Ensino/
├── 01-Anotacoes/                  ← resumo por aula
├── 02-Exercicios/                 ← listas por tópico:
│   ├── arvores/
│   ├── heap/
│   ├── hash/
│   └── grafos/
├── 03-Implementacoes/             ← código-fonte por estrutura:
│   ├── arvore-avl/
│   ├── arvore-rubro-negra/
│   ├── b-tree/
│   ├── heap/
│   ├── tabela-hash/
│   └── grafos/
├── 04-Projetos/
├── 05-Avaliacoes/
└── 06-Materiais/
```

---

## Convenções do repositório

1. **Idioma:** todo conteúdo em português (pt-BR) — anotações, código,
   READMEs e mensagens de commit.
2. **Nomes de arquivos/pastas:** `kebab-case`, sem acentos e sem espaços
   (ex.: `arvore-avl.c`, `2026-08-06-grafos-bfs.md`).
3. **Datas:** prefixo `YYYY-MM-DD` em anotações e provas.
4. **Código:** sempre com `README.md` explicando como compilar e rodar
   (comando exato do GCC/compilador usado no laboratório).
5. **Pastas vazias estruturais são mantidas** (via `.gitkeep`) — são a espinha
   dorsal da organização.
6. **Não renomear/remover** as pastas numeradas.

---

## Fluxo de trabalho (laboratório ↔ casa)

### Ao chegar em qualquer máquina

```bash
git pull
```

### Ao finalizar uma sessão de trabalho

```bash
git add .
git commit -m "assunto: resumo da mudanca"   # ex.: aed4: implementa arvore AVL
git push
```

### Mensagens de commit

Formato curto em pt-BR: `assunto: resumo` — ex.:

- `aed4: implementa arvore AVL`
- `bd2: resolve lista de normalizacao`
- `grafos: anota aula de caminhos minimos`

> Alternativa de sincronização: OneDrive/Google Drive/Dropbox com a pasta
> FACULDADE sincronizada automaticamente (não usar junto com git no mesmo
> diretório para evitar conflitos).

---

## O papel do AGENTS.md

Os arquivos `AGENTS.md` (um global na raiz + um por disciplina) são o manual
de instruções para agentes de IA que trabalharem neste repositório. Eles contêm:

- contexto global (disciplinas, convenções, fluxo de trabalho);
- contexto por disciplina (professor, código do Moodle, tópicos da ementa,
  linguagens e ferramentas, regras específicas).

Os tópicos de cada disciplina são **estimativas** da ementa clássica e devem
ser atualizados assim que o **plano de ensino oficial** for disponibilizado
pelo professor (arquivado em `00-Plano-de-Ensino/`).

---

## Próximos passos sugeridos

- [ ] Baixar e arquivar o plano de ensino de cada disciplina em `00-Plano-de-Ensino/`
- [ ] Confirmar linguagem/ferramentas de cada disciplina (C, SQL, Flutter, etc.)
- [ ] Preencher o controle de horas da Atividade Complementar
- [ ] Adicionar `.gitignore` específicos por projeto (builds, SDKs, etc.)

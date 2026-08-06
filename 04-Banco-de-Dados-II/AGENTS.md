# Banco de Dados II

> Leia o `AGENTS.md` global (pasta raiz) antes de trabalhar nesta disciplina.

## Identificação

| Campo | Valor |
|---|---|
| Nome da disciplina | Banco de Dados II |
| Código (Moodle) | Disciplina.0089 |
| Professor | Wesley Flavio de Miranda |
| Ambiente | Moodle (AVA) |
| Semestre | Atual (2026/2) |

## Estrutura de pastas

```
04-Banco-de-Dados-II/
├── AGENTS.md
├── 00-Plano-de-Ensino/    ← ementa oficial, cronograma (atualizar quando chegar)
├── 01-Anotacoes/          ← 2026-08-06-assunto.md
├── 02-Exercicios/         ← listas e scripts SQL resolvidos
├── 03-Projetos/           ← trabalhos práticos (um subpasta por projeto)
├── 04-Avaliacoes/         ← provas por data
└── 05-Materiais/          ← slides, PDFs, modelos, links
```

## Tópicos prováveis (ESTIMATIVA — atualizar com o plano de ensino)

1. Revisão de modelo relacional e SQL (DQL/DML/DDL)
2. Projeto de banco de dados: modelagem conceitual → lógica → física
3. Normalização: formas normais, dependências funcionais
4. Índices, views, procedures, functions, triggers
5. Transações, controle de concorrência, isolamento
6. Backup e recuperação
7. Bancos NoSQL (conceitos e comparação) — confirmar
8. Administração de banco de dados (usuários, permissões)

## Ferramentas prováveis

- SGBD: PostgreSQL e/ou MySQL/MariaDB (confirmar com o professor).
- SQL puro em `.sql` ou scripts `.md` com explicação em pt-BR.

## Regras específicas

1. Scripts SQL: nomear `YYYY-MM-DD-assunto.sql` e incluir comentário com o
   objetivo em pt-BR.
2. Exercícios de modelagem: salvar DER/diagramas em `02-Exercicios/` ou
   `05-Materiais/` (formatos `.png`, `.drawio`).
3. Projetos: subpasta kebab-case em `03-Projetos/` + `README.md` com instruções
   de configuração (criar banco, rodar scripts, credenciais de exemplo).
4. Anotar aqui o SGBD real usado quando o professor confirmar.

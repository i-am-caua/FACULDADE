# Computação Móvel

> Leia o `AGENTS.md` global (pasta raiz) antes de trabalhar nesta disciplina.

## Identificação

| Campo | Valor |
|---|---|
| Nome da disciplina | Computação Móvel |
| Código (Moodle) | Disciplina.0090 |
| Professor | Thamer Horbylon Nascimento |
| Ambiente | Moodle (AVA) |
| Semestre | Atual (2026/2) |

## Estrutura de pastas

```
05-Computacao-Movel/
├── AGENTS.md
├── 00-Plano-de-Ensino/    ← ementa oficial, cronograma (atualizar quando chegar)
├── 01-Anotacoes/          ← 2026-08-06-assunto.md
├── 02-Exercicios/         ← exercícios de código e pequenos testes
├── 03-Projetos/           ← apps (um subpasta por projeto)
├── 04-Avaliacoes/         ← provas por data
└── 05-Materiais/          ← slides, PDFs, SDKs, links
```

## Tópicos prováveis (ESTIMATIVA — atualizar com o plano de ensino)

1. Introdução ao desenvolvimento móvel (Android/iOS/Flutter — confirmar)
2. Interface e componentes visuais, ciclos de vida
3. Persistência local (SQLite/SharedPreferences)
4. Consumo de APIs REST (JSON)
5. Sensores, permissões e recursos do dispositivo
6. Publicação de aplicativos (assinatura, lojas)
7. Boas práticas: testes, acessibilidade, desempenho

## Ferramentas prováveis

- Linguagem/framework: **Flutter (Dart)** ou **Kotlin/Android Studio**
  (confirmar com o professor — comum nas IES brasileiras).
- Emuladores: Android Studio AVD ou dispositivo físico via USB.

## Regras específicas

1. Cada app em `03-Projetos/<nome-do-app>/` com `README.md` explicando como
   abrir no IDE e rodar (SDK mínimo, emulador, dependências).
2. Código e nomes de arquivos em pt-BR quando possível (IDs de layout,
   variáveis), respeitando convenções da linguagem.
3. Dependências grandes (SDKs, node_modules, build) **não** devem ser
   sincronizadas — usar `.gitignore` se houver git.
4. Anotar aqui o framework oficial quando o professor confirmar.

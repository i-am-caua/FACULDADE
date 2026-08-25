# Atividade: Problema de Localização — Hospital Regional do Oeste Goiano

Atividade prática da disciplina **Teoria dos Grafos** (`Disciplina.0093`), ministrada pelo **Prof. Newarney Torrezão da Costa** no IF Goiano — Campus Iporá (3º Período — 2026/2).

---

## 🎯 Objetivo

Determinar a melhor cidade para a construção do **Hospital Regional do Oeste Goiano** a partir de uma rede de 7 cidades conectadas por rodovias, aplicando o **Algoritmo de Floyd-Warshall** para caminhos mínimos em C e analisando a decisão sob dois critérios clássicos de localização em grafos:

1. **Centro (Critério Minimax / Menor Excentricidade):** Minimiza a distância máxima até a cidade mais distante ($\min_u \max_v d(u, v)$). Ideal para garantir equidade e atendimento rápido em situações de urgência crítica.
2. **Mediana (Critério Minisum / Menor Soma das Distâncias):** Minimiza a soma total das distâncias ($\min_u \sum_v d(u, v)$). Ideal para reduzir o custo acumulado de transporte e o deslocamento médio da população.

---

## 📁 Estrutura da Pasta

```
01-problema-de-localizacao-hospital/
├── README.md                      ← Este índice e visão geral
├── 00-enunciado/                  ← Enunciado oficial e transcrição
│   └── problema-de-localizacao-hospital.md
├── 01-implementacao-c/            ← Código e compilação em C (GCC)
│   ├── README.md                  ← Instruções de compilação e execução
│   └── problema-localizacao.c     ← Arquivo para implementação
└── apoio/                         ← Materiais de suporte e apoio visual
    ├── visualizador-grafo.html    ← Visualizador interativo do mapa e estradas
    └── diario-de-bordo-ia.md      ← Registro de uso do tutor socrático
```

---

## 🗺️ Rede de Cidades e Conexões

- **Cidades (7):** Iporá, Israelândia, Amorinópolis, Jaupaci, Fazenda Nova, Córrego do Ouro, São Luís de Montes Belos.
- **Conexões diretas (km):**
  - Iporá ↔ Israelândia: **26 km**
  - Iporá ↔ Amorinópolis: **24 km**
  - Iporá ↔ Jaupaci: **30 km**
  - Israelândia ↔ Fazenda Nova: **30 km**
  - Amorinópolis ↔ Córrego do Ouro: **35 km**
  - Jaupaci ↔ Fazenda Nova: **35 km**
  - Córrego do Ouro ↔ São Luís de Montes Belos: **50 km**
  - Fazenda Nova ↔ São Luís de Montes Belos: **60 km**

---

## ⚡ Como Compilar e Rodar em C

```bash
cd 01-implementacao-c
gcc -Wall -Wextra -std=c99 -o problema-localizacao problema-localizacao.c
./problema-localizacao
```

### Visualizador Interativo:
Abra `apoio/visualizador-grafo.html` em qualquer navegador web para ver o mapa interativo das cidades, conexões diretas, graus e a matriz inicial.

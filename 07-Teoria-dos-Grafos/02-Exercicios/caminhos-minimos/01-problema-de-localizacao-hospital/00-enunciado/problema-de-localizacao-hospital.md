# Atividade: Problema de Localização
## Onde construir o hospital regional do Oeste Goiano?

> **Origem:** Moodle (AVA) — Instituto Federal Goiano (Campus Iporá)  
> **Curso:** Bacharelado em Ciência da Computação (3º Período — 2026/2)  
> **Disciplina:** Teoria dos Grafos (`Disciplina.0093`)  
> **Professor:** Newarney Torrezão da Costa  

---

## 1. O Problema

A Região de Planejamento Oeste Goiano vai receber um hospital regional. Em qual cidade construí-lo para atender melhor toda a região? Vocês vão usar o **algoritmo de Floyd** sobre a rede de estradas entre 7 cidades da região e decidir por dois critérios: **centro** (menor afastamento) e **mediana** (menor soma).

---

## 2. Como vocês vão trabalhar

- **Formato:** Em duplas, em sala / laboratório.
- **Implementação:** Em **C** (`gcc`) ou **Python** (Colab), à escolha da dupla.
- **Uso de IA:** Vocês podem usar um chatbot de IA como **tutor socrático** (ele ajuda a pensar e orienta o raciocínio, não entrega a resposta pronta) e registram o uso no diário de bordo.

---

## 3. A Rede de Cidades

As 7 cidades pertencem ao Oeste Goiano (conforme mapa anexo à tarefa). As distâncias são aproximadas, em quilômetros (km), e consideramos uma única estrada bidirecional entre duas cidades conectadas.

### Cidades (7 vértices)
1. Iporá
2. Israelândia
3. Amorinópolis
4. Jaupaci
5. Fazenda Nova
6. Córrego do Ouro
7. São Luís de Montes Belos

### Estradas Diretas (8 arestas com pesos em km)

| Origem | Destino | Distância (km) |
|---|---|:---:|
| Iporá | Israelândia | 26 |
| Iporá | Amorinópolis | 24 |
| Iporá | Jaupaci | 30 |
| Israelândia | Fazenda Nova | 30 |
| Amorinópolis | Córrego do Ouro | 35 |
| Jaupaci | Fazenda Nova | 35 |
| Córrego do Ouro | São Luís de Montes Belos | 50 |
| Fazenda Nova | São Luís de Montes Belos | 60 |

> *Nota:* Onde não há estrada direta, a distância mínima é obtida passando por cidades intermediárias — exatamente o que o algoritmo de Floyd-Warshall calcula.

---

## 4. Critérios de Decisão para a Localização

Seja $D[u][v]$ a matriz de distâncias mínimas calculada pelo algoritmo de Floyd entre todos os pares de cidades $u, v \in V$:

### Critério 1: Centro da Rede (Menor Afastamento / Excentricidade)
- **Definição:** O afastamento (ou excentricidade) de uma cidade $u$ é a distância máxima dela até qualquer outra cidade da rede:
  $$e(u) = \max_{v \in V} D[u][v]$$
- **Objetivo:** Minimizar o tempo/distância no **pior caso** (garantir que nenhum cidadão fique excessivamente longe do hospital).
  $$\text{Centro} = \arg\min_{u \in V} e(u)$$

### Critério 2: Mediana da Rede (Menor Soma das Distâncias)
- **Definição:** A soma das distâncias de uma cidade $u$ até todas as demais cidades:
  $$s(u) = \sum_{v \in V} D[u][v]$$
- **Objetivo:** Minimizar o deslocamento médio ou total de todos os habitantes da região até o hospital.
  $$\text{Mediana} = \arg\min_{u \in V} s(u)$$

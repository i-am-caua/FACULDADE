# Implementação em C — Problema de Localização do Hospital

Implementação em C do **Algoritmo de Floyd-Warshall** para resolução do problema de localização do Hospital Regional do Oeste Goiano.

---

## 🛠️ Requisitos e Compilação

- **Compilador:** GCC com suporte a C99 (`gcc`).
- **Arquivos:**
  - `problema-localizacao.c`: Código-fonte completo com estrutura de matrizes, Floyd-Warshall e análise de critérios.

### Comando de Compilação:
```bash
gcc -Wall -Wextra -std=c99 -o problema-localizacao problema-localizacao.c
```

### Comando de Execução:
- **No Linux / macOS:**
  ```bash
  ./problema-localizacao
  ```
- **No Windows (PowerShell / CMD):**
  ```powershell
  .\problema-localizacao.exe
  ```

---

## 📊 Estruturas de Dados e Algoritmo

1. **Matriz de Adjacência e Distâncias (`dist[7][7]`):**
   - Inicializada com zeros na diagonal principal, `INF` (999999) onde não há aresta direta e os pesos das 8 estradas.
2. **Matriz de Reconstrução de Rota (`prox[7][7]`):**
   - Armazena o próximo nó no caminho ótimo entre $i$ e $j$.
3. **Floyd-Warshall:**
   - Três laços aninhados ($k, i, j \in \{0, \dots, 6\}$) verificando a desigualdade triangular:
     $$\text{se } dist[i][k] + dist[k][j] < dist[i][j] \implies dist[i][j] = dist[i][k] + dist[k][j]$$
4. **Análise dos Critérios:**
   - **Centro (Minimax):** $e(u) = \max_v dist[u][v]$
   - **Mediana (Minisum):** $s(u) = \sum_v dist[u][v]$

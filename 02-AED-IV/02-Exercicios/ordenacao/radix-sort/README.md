# Ordenação: Radix Sort (LSD) em C e Go

Implementação simples e didática do algoritmo **Radix Sort (LSD - Least Significant Digit)** em C e em Go.

O algoritmo ordena os números dígito a dígito, começando pelas unidades ($\text{exp}=1$), depois dezenas ($\text{exp}=10$), centenas ($\text{exp}=100$), etc., usando uma sub-rotina de **Counting Sort** estável a cada passo.

---

## Como Rodar em C

### Compilar

```bash
gcc -std=c11 -Wall -Wextra -g radix.c -o radix
```

### Executar

```bash
./radix
```

Escolha `1` para ver a ordenação com o vetor clássico `[170, 45, 75, 90, 802, 24, 2, 66]`, `2` para gerar um vetor aleatório, ou `0` para sair.

---

## Como Rodar em Go

### Executar diretamente

```bash
go run radix.go
```

Ou se preferir compilar o executável:

```bash
go build radix.go
./radix
```

O menu possui as mesmas opções da versão em C.

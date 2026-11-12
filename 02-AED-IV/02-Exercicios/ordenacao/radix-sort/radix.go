package main

import (
	"fmt"
	"math/rand"
	"time"
)

func printVtr(vtr []int) {
	for _, v := range vtr {
		fmt.Printf("%d ", v)
	}
	fmt.Println()
}

func vetorAleatorio(tam int) []int {
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	vtr := make([]int, tam)
	for i := 0; i < tam; i++ {
		vtr[i] = r.Intn(900) + 10 // valores de 10 a 999
	}
	return vtr
}

func obterMaior(vtr []int) int {
	maior := vtr[0]
	for _, v := range vtr[1:] {
		if v > maior {
			maior = v
		}
	}
	return maior
}

// Counting sort que ordena pelo digito da posicao exp (1 = unidades, 10 = dezenas, 100 = centenas...)
func countingSort(vtr []int, exp int) {
	tam := len(vtr)
	saida := make([]int, tam)
	contagem := make([]int, 10)

	// 1. Frequencia dos digitos
	for i := 0; i < tam; i++ {
		digito := (vtr[i] / exp) % 10
		contagem[digito]++
	}

	// 2. Acumula para achar as posicoes
	for i := 1; i < 10; i++ {
		contagem[i] += contagem[i-1]
	}

	// 3. Monta o vetor de tras para frente para manter estabilidade
	for i := tam - 1; i >= 0; i-- {
		digito := (vtr[i] / exp) % 10
		saida[contagem[digito]-1] = vtr[i]
		contagem[digito]--
	}

	// 4. Copia de volta para o vetor original
	for i := 0; i < tam; i++ {
		vtr[i] = saida[i]
	}
}

func radixSort(vtr []int) {
	if len(vtr) <= 1 {
		return
	}

	maior := obterMaior(vtr)

	fmt.Println("\nVetor inicial:")
	printVtr(vtr)

	passo := 1
	// exp multiplica por 10 a cada rodada: unidades, dezenas, centenas...
	for exp := 1; maior/exp > 0; exp *= 10 {
		countingSort(vtr, exp)
		fmt.Printf("Passo %d (ordenado por exp = %d):\n", passo, exp)
		printVtr(vtr)
		passo++
	}
}

func main() {
	var opcao int

	for {
		fmt.Println("\nEscolha uma opcao:")
		fmt.Println("1 - Radix sort com vetor de exemplo")
		fmt.Println("2 - Radix sort com vetor aleatorio")
		fmt.Println("0 - Sair")
		fmt.Print("Opcao: ");

		_, err := fmt.Scan(&opcao)
		if err != nil {
			fmt.Println("Entrada invalida. Encerrando.")
			break
		}

		if opcao == 0 {
			fmt.Println("Encerrando.")
			break
		}

		switch opcao {
		case 1:
			exemplo := []int{170, 45, 75, 90, 802, 24, 2, 66}
			radixSort(exemplo)
		case 2:
			vetor := vetorAleatorio(10)
			radixSort(vetor)
		default:
			fmt.Println("Opcao invalida. Escolha 0, 1 ou 2.")
		}
	}
}

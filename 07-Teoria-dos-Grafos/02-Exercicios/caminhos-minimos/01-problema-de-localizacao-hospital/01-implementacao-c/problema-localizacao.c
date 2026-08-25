#include <stdio.h>
#include <time.h>
#define INF 999999
#define V 7

int main() {
    const char *cidades[V] = {
        "Ipora", "Israelandia", "Amorinopolis", "Corrego do Ouro",
        "Jaupaci", "Fazenda Nova", "Sao Luis de Montes Belos"
    };
           /*
         * Mapeamento dos Índices (Linhas e Colunas):
         *   [0] Iporá
         *   [1] Israelândia
         *   [2] Amorinópolis
         *   [3] Córrego do Ouro
         *   [4] Jaupaci
         *   [5] Fazenda Nova
         *   [6] São Luís de Montes Belos
         *
         * Matriz Inicial de Adjacência (distâncias em km / INF = sem estrada direta):
         *
         *                          [0]   [1]   [2]   [3]   [4]   [5]   [6]
         *                          IPO   ISR   AMO   COU   JAU   FNO  SLMB
         */
        int dist[V][V] = {
            /* [0] Iporá          */ {  0,   26,   24,  INF,   30,  INF,  INF},
            /* [1] Israelândia    */ { 26,    0,  INF,  INF,  INF,   30,  INF},
            /* [2] Amorinópolis   */ { 24,  INF,    0,   35,  INF,  INF,  INF},
            /* [3] Córrego do Ouro*/ {INF,  INF,   35,    0,  INF,  INF,   50},
            /* [4] Jaupaci        */ { 30,  INF,  INF,  INF,    0,   35,  INF},
            /* [5] Fazenda Nova   */ {INF,   30,  INF,  INF,   35,    0,   60},
            /* [6] São Luís M. B. */ {INF,  INF,  INF,   50,  INF,   60,    0}
        };
        int Soma [V];
        int afastamento [V];
   

    

    /* 1) Floyd: menor distancia entre TODOS os pares. */
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) {
                /* TODO: se passar por k encurta, atualize dist[i][j] */
                if (dist [i][k]+ dist [k][j] < dist[i][j])
                dist[i][j] = dist [i][k]+ dist [k][j];
            }

    /* 2) Afastamento (maior distancia) e soma, por cidade. */
    for (int i = 0; i < V; i++) {
        int afast = 0;   /* TODO: maior valor da linha i */
        int soma  = 0;   /* TODO: soma dos valores da linha i */
        for (int j = 0; j < V; j++){
            if (afast < dist[i][j]) afast = dist[i][j];
            soma += dist[i][j];
            afastamento[i] = afast;
            Soma[i] =soma;
        }
        printf("%-26s afastamento=%4d  soma=%d\n", cidades[i], afast, soma);
    }

    /* 3) TODO: indique a cidade com MENOR afastamento (centro)
              e a com MENOR soma (mediana). */
    int menorSoma = INF;
    int menorAfast = INF;
    int indexS = 0;
    int indexA = 0;
    for (int i = 0; i < V;i++) {
      
            if (menorSoma > Soma[i]) {
                menorSoma = Soma[i];
                indexS = i;
            }
            if (menorAfast > afastamento[i]) {
                menorAfast = afastamento[i];
                indexA = i;
            }
        
    }
    printf ("\n");
    for (int i = 0; i < V;i++) {
        for (int j = 0; j < V;j++) {
            printf ("%d\t", dist[i][j]);
        }
        printf("\n");
    }
     /* 1. Obtém o tempo atual em segundos desde o Epoch (01/01/1970) */
        time_t tempoAtual = time(NULL);

        /* 2. Converte para o fuso horário local */
        struct tm *infoTempo = localtime(&tempoAtual);

        /* --- Forma 1: Usando os campos da struct tm --- */
        printf("\n\nHora atual: %02d:%02d:%02d\n\n",
               infoTempo->tm_hour,
               infoTempo->tm_min,
               infoTempo->tm_sec);

   
    printf ("\n\nWesio && Caua\n\n");
    printf ("Menor afastamento: %s, %d\n", cidades[indexA], menorAfast);
    printf ("Menor Soma: %s, %d ", cidades[indexS], menorSoma);
    printf("\nPressione ENTER para sair...");
        getchar();
     
    return 0;
}
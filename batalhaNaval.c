#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Inicializa o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Cria matriz de habilidade em formato de Cone
void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Lógica para formar um cone apontando para baixo
            if (j >= i && j < TAM_HABILIDADE - i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Cria matriz de habilidade em formato de Cruz
void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Cria matriz de habilidade em formato de Octaedro (losango)
void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int dist = abs(i - centro) + abs(j - centro);
            if (dist <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Aplica uma habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                      int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                      int linha, int coluna) {
    int offset = TAM_HABILIDADE / 2;
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int tab_i = linha - offset + i;
            int tab_j = coluna - offset + j;
            
            // Verifica se está dentro dos limites do tabuleiro
            if (tab_i >= 0 && tab_i < TAM_TABULEIRO && 
                tab_j >= 0 && tab_j < TAM_TABULEIRO && 
                habilidade[i][j] == 1) {
                
                // Marca a área afetada (não sobrescreve navios)
                if (tabuleiro[tab_i][tab_j] != NAVIO) {
                    tabuleiro[tab_i][tab_j] = HABILIDADE;
                }
            }
        }
    }
}

// Exibe o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval com Habilidades:\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios (como no exemplo anterior)
    // Navio horizontal
    for (int j = 2; j < 2 + TAM_NAVIO; j++) {
        tabuleiro[2][j] = NAVIO;
    }
    
    // Navio vertical
    for (int i = 5; i < 5 + TAM_NAVIO; i++) {
        tabuleiro[i][5] = NAVIO;
    }
    
    // Navio diagonal 1
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[i][i] = NAVIO;
    }
    
    // Navio diagonal 2
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[1 + i][7 - i] = NAVIO;
    }

    // Cria e aplica habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
    
    // Aplica habilidades em posições específicas
    aplicarHabilidade(tabuleiro, cone, 4, 4);      // Cone centrado em (4,4)
    aplicarHabilidade(tabuleiro, cruz, 7, 2);      // Cruz centrada em (7,2)
    aplicarHabilidade(tabuleiro, octaedro, 3, 7);  // Octaedro centrado em (3,7)

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);
    
    // Exibe exemplos das matrizes de habilidade
    printf("\nExemplo de matriz Cone:\n");
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }
    
    printf("\nExemplo de matriz Cruz:\n");
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }
    
    printf("\nExemplo de matriz Octaedro:\n");
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
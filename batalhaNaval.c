#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

bool posicaoValida(int linha, int coluna, int tamanho, bool vertical, bool diagonal) {
    if (diagonal) {
        return (linha >= 0) && (linha + tamanho - 1 < TAMANHO_TABULEIRO) &&
               (coluna >= 0) && (coluna + tamanho - 1 < TAMANHO_TABULEIRO);
    } else if (vertical) {
        return (linha >= 0) && (linha + tamanho - 1 < TAMANHO_TABULEIRO) && 
               (coluna >= 0) && (coluna < TAMANHO_TABULEIRO);
    } else {
        return (linha >= 0) && (linha < TAMANHO_TABULEIRO) && 
               (coluna >= 0) && (coluna + tamanho - 1 < TAMANHO_TABULEIRO);
    }
}

bool semSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                    int linha, int coluna, int tamanho, bool vertical, bool diagonal) {
    if (diagonal) {
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna + i] == NAVIO) {
                return false;
            }
        }
    } else if (vertical) {
        for (int i = linha; i < linha + tamanho; i++) {
            if (tabuleiro[i][coluna] == NAVIO) {
                return false;
            }
        }
    } else {
        for (int j = coluna; j < coluna + tamanho; j++) {
            if (tabuleiro[linha][j] == NAVIO) {
                return false;
            }
        }
    }
    return true;
}

void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                    int linha, int coluna, int tamanho, bool vertical, bool diagonal) {
    if (diagonal) {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    } else if (vertical) {
        for (int i = linha; i < linha + tamanho; i++) {
            tabuleiro[i][coluna] = NAVIO;
        }
    } else {
        for (int j = coluna; j < coluna + tamanho; j++) {
            tabuleiro[linha][j] = NAVIO;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval:\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posições ajustadas para evitar sobreposição
    // Navio 1 - Horizontal
    posicionarNavio(tabuleiro, 2, 2, TAMANHO_NAVIO, false, false);
    
    // Navio 2 - Vertical
    posicionarNavio(tabuleiro, 5, 5, TAMANHO_NAVIO, true, false);
    
    // Navio 3 - Diagonal (principal)
    posicionarNavio(tabuleiro, 0, 0, TAMANHO_NAVIO, false, true);
    
    // Navio 4 - Diagonal (secundária)
    posicionarNavio(tabuleiro, 1, 7, TAMANHO_NAVIO, false, true);

    exibirTabuleiro(tabuleiro);
    
    return 0;
}
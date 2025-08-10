#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se a posição do navio é válida
bool posicaoValida(int linha, int coluna, int tamanho, bool vertical) {
    if (vertical) {
        return (linha >= 0) && (linha + tamanho - 1 < TAMANHO_TABULEIRO) && (coluna >= 0) && (coluna < TAMANHO_TABULEIRO);
    } else {
        return (linha >= 0) && (linha < TAMANHO_TABULEIRO) && (coluna >= 0) && (coluna + tamanho - 1 < TAMANHO_TABULEIRO);
    }
}

// Função para verificar sobreposição
bool semSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, bool vertical) {
    if (vertical) {
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

// Função para posicionar navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, bool vertical) {
    if (vertical) {
        for (int i = linha; i < linha + tamanho; i++) {
            tabuleiro[i][coluna] = NAVIO;
        }
    } else {
        for (int j = coluna; j < coluna + tamanho; j++) {
            tabuleiro[linha][j] = NAVIO;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval:\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);
    
    // Define as coordenadas dos navios (fixas no código)
    int linha_navio1 = 2, coluna_navio1 = 2;  // Navio horizontal
    bool vertical_navio1 = false;
    
    int linha_navio2 = 5, coluna_navio2 = 5;  // Navio vertical
    bool vertical_navio2 = true;
    
    // Valida e posiciona o primeiro navio (horizontal)
    if (posicaoValida(linha_navio1, coluna_navio1, TAMANHO_NAVIO, vertical_navio1) &&
        semSobreposicao(tabuleiro, linha_navio1, coluna_navio1, TAMANHO_NAVIO, vertical_navio1)) {
        posicionarNavio(tabuleiro, linha_navio1, coluna_navio1, TAMANHO_NAVIO, vertical_navio1);
    } else {
        printf("Posição inválida ou sobreposição para o navio horizontal!\n");
        return 1;
    }
    
    // Valida e posiciona o segundo navio (vertical)
    if (posicaoValida(linha_navio2, coluna_navio2, TAMANHO_NAVIO, vertical_navio2) &&
        semSobreposicao(tabuleiro, linha_navio2, coluna_navio2, TAMANHO_NAVIO, vertical_navio2)) {
        posicionarNavio(tabuleiro, linha_navio2, coluna_navio2, TAMANHO_NAVIO, vertical_navio2);
    } else {
        printf("Posição inválida ou sobreposição para o navio vertical!\n");
        return 1;
    }
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
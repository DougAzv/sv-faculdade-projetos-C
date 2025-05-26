#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para verificar se uma posição está ocupada
bool posicaoOcupada(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == NAVIO;
}

// Função para verificar se um navio pode ser posicionado
bool podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int delta_linha, int delta_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int nova_linha = linha + i * delta_linha;
        int nova_coluna = coluna + i * delta_coluna;
        
        // Verifica se está dentro do tabuleiro
        if (nova_linha < 0 || nova_linha >= TAMANHO_TABULEIRO || 
            nova_coluna < 0 || nova_coluna >= TAMANHO_TABULEIRO) {
            return false;
        }
        
        // Verifica se a posição já está ocupada
        if (posicaoOcupada(tabuleiro, nova_linha, nova_coluna)) {
            return false;
        }
    }
    return true;
}

// Função para posicionar um navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int delta_linha, int delta_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int nova_linha = linha + i * delta_linha;
        int nova_coluna = coluna + i * delta_coluna;
        tabuleiro[nova_linha][nova_coluna] = NAVIO;
    }
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    
    // Navio 1 - Horizontal
    if (podePosicionar(tabuleiro, 2, 3, 0, 1)) {
        posicionarNavio(tabuleiro, 2, 3, 0, 1);
    }
    
    // Navio 2 - Vertical
    if (podePosicionar(tabuleiro, 5, 7, 1, 0)) {
        posicionarNavio(tabuleiro, 5, 7, 1, 0);
    }
    
    // Navio 3 - Diagonal principal (linha e coluna aumentam)
    if (podePosicionar(tabuleiro, 1, 1, 1, 1)) {
        posicionarNavio(tabuleiro, 1, 1, 1, 1);
    }
    
    // Navio 4 - Diagonal secundária (linha aumenta, coluna diminui)
    if (podePosicionar(tabuleiro, 3, 8, 1, -1)) {
        posicionarNavio(tabuleiro, 3, 8, 1, -1);
    }
    
    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval com Navios Diagonais:\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n"); // Cabeçalho das colunas
    
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%d ", linha); // Número da linha
        
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
    
    return 0;
}
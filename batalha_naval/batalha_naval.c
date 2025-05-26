#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    
    // Coordenadas do navio horizontal (linha, coluna inicial)
    int navio_horizontal_linha = 2;
    int navio_horizontal_coluna = 4;
    
    // Coordenadas do navio vertical (linha inicial, coluna)
    int navio_vertical_linha = 5;
    int navio_vertical_coluna = 7;
    
    // Posiciona o navio horizontal (3 posições consecutivas na mesma linha)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        // Verifica se a posição está dentro do tabuleiro
        if (navio_horizontal_coluna + i < TAMANHO_TABULEIRO) {
            tabuleiro[navio_horizontal_linha][navio_horizontal_coluna + i] = NAVIO;
        }
    }
    
    // Posiciona o navio vertical (3 posições consecutivas na mesma coluna)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        // Verifica se a posição está dentro do tabuleiro
        if (navio_vertical_linha + i < TAMANHO_TABULEIRO) {
            tabuleiro[navio_vertical_linha + i][navio_vertical_coluna] = NAVIO;
        }
    }
    
    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
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
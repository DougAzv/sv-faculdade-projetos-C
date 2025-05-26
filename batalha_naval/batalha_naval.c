#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n  ");
    for (int col = 0; col < TAM_TABULEIRO; col++) {
        printf("%2d", col);
    }
    printf("\n");
    
    for (int lin = 0; lin < TAM_TABULEIRO; lin++) {
        printf("%2d", lin);
        for (int col = 0; col < TAM_TABULEIRO; col++) {
            printf("%2d", tabuleiro[lin][col]);
        }
        printf("\n");
    }
}

// Função para criar matriz de habilidade em Cone
void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        int largura = i + 1;
        int inicio = (TAM_HABILIDADE - largura) / 2;
        
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = (j >= inicio && j < inicio + largura) ? 1 : 0;
        }
    }
}

// Função para criar matriz de habilidade em Cruz
void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = (i == centro || j == centro) ? 1 : 0;
        }
    }
}

// Função para criar matriz de habilidade em Octaedro
void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        int distancia = centro - abs(i - centro);
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = (abs(j - centro) <= distancia) ? 1 : 0;
        }
    }
}

// Função para aplicar habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                      int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                      int centro_lin, int centro_col) {
    int offset = TAM_HABILIDADE / 2;
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int lin = centro_lin - offset + i;
            int col = centro_col - offset + j;
            
            if (lin >= 0 && lin < TAM_TABULEIRO && col >= 0 && col < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[lin][col] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    // Inicializa o tabuleiro com água
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    
    // Posiciona alguns navios para demonstração
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    
    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][7] = NAVIO;
    tabuleiro[7][7] = NAVIO;
    
    // Cria as matrizes de habilidade
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
    
    // Aplica as habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);       // Cone centrado em (4,4)
    aplicarHabilidade(tabuleiro, cruz, 2, 7);       // Cruz centrada em (2,7)
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);   // Octaedro centrado em (7,2)
    
    // Exibe o tabuleiro com as habilidades aplicadas
    printf("Tabuleiro com Habilidades Especiais:\n");
    printf("0: Agua | 3: Navio | 5: Area de Habilidade\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
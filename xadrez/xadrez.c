#include <stdio.h>

// Função recursiva para o movimento da Torre
void moverTorre(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Função recursiva para o movimento do Bispo
void moverBispo(int casas) {
    if (casas <= 0) return;
    printf("Cima, Direita\n");
    moverBispo(casas - 1);
}

// Função recursiva para o movimento da Rainha
void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Função para movimento complexo do Cavalo
void moverCavalo() {
    // Loop externo controla as partes do movimento em L
    for (int parte = 0; parte < 2; parte++) {
        int repeticoes = (parte == 0) ? 2 : 1; // 2 para cima, 1 para direita
        
        // Loop interno controla as repetições de cada parte
        int contador = 0;
        while (contador < repeticoes) {
            if (parte == 0) {
                printf("Cima\n");
            } else {
                printf("Direita\n");
            }
            contador++;
            
            // Condição de parada adicional para segurança
            if (contador > 10) break; // Prevenção contra loops infinitos
        }
    }
}

// Versão do Bispo com loops aninhados
void moverBispoAninhado(int casas) {
    for (int vertical = 0; vertical < casas; vertical++) {
        for (int horizontal = 0; horizontal < 1; horizontal++) {
            printf("Cima, Direita\n");
        }
    }
}

int main() {
    // Movimento da Torre (recursivo)
    printf("Movimento da Torre (5 casas para a direita - recursivo):\n");
    moverTorre(5);
    
    // Movimento do Bispo (versão recursiva)
    printf("\nMovimento do Bispo (5 casas na diagonal - recursivo):\n");
    moverBispo(5);
    
    // Movimento do Bispo (versão com loops aninhados)
    printf("\nMovimento do Bispo (5 casas na diagonal - loops aninhados):\n");
    moverBispoAninhado(5);
    
    // Movimento da Rainha (recursivo)
    printf("\nMovimento da Rainha (8 casas para a esquerda - recursivo):\n");
    moverRainha(8);
    
    // Movimento do Cavalo (loops complexos)
    printf("\nMovimento do Cavalo (2 casas para cima e 1 para direita):\n");
    moverCavalo();
    
    return 0;
}

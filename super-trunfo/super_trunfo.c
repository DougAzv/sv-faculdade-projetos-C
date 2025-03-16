#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");
    
    //declara��o de vari�veis
    char estado1, estado2, cod1[4], cod2[4], nomeCidade1[50], nomeCidade2[50];
    int populacao1, populacao2, nPontosT1, nPontosT2;
    float pib1, pib2, area1, area2;

    // Entrada de dados para a Carta 1
    printf("Insira os dados da primeira carta: \n");
    
    printf("\nEstado: ");
    scanf("%c", &estado1);

    printf("C�digo: ");
    scanf("%s", cod1);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade1);

    printf("Popula��o: ");
    scanf("%d", &populacao1);

    printf("�rea (em km�): ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("N�mero de Pontos Tur�sticos: ");
    scanf("%d", &nPontosT1);

    // Exibi��o dos dados da Carta 1
    printf("\nCarta 1\n");
    printf("Estado: %c\n", estado1);
    printf("C�digo: %s\n", cod1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Popula��o: %d\n", populacao1);
    printf("�rea %.2f km� \n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("N�mero de Pontos Tur�sticos: %d\n\n", nPontosT1);

    // Entrada de dados para a Carta 2
    printf("Insira os dados da segunda carta: \n");
    
    printf("\nEstado: ");
    scanf(" %c", &estado2);  // Espa�o antes do %c para ignorar o \n residual

    printf("C�digo: ");
    scanf("%s", cod2);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade2);

    printf("Popula��o: ");
    scanf("%d", &populacao2);

    printf("�rea (em km�): ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("N�mero de Pontos Tur�sticos: ");
    scanf("%d", &nPontosT2);

    // Exibi��o dos dados da Carta 2
    printf("\nCarta 2\n");
    printf("Estado: %c\n", estado2);
    printf("C�digo: %s\n", cod2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Popula��o: %d\n", populacao2);
    printf("�rea %.2f km� \n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("N�mero de Pontos Tur�sticos: %d\n", nPontosT2);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(void) {

    /*
    O código foi salvo com a codificação ISO-8859-1 para garantir que caracteres acentuados (como ç, ã, é) sejam exibidos corretamente ao executar o programa.
    
    Ao executar o programa, utilize "," (vírgula) ao invés de "." (ponto) para casas decimais, pois o locale "Portuguese_Brazil" foi configurado. 

    O uso de "." pode causar erros na leitura dos números.
    */

    setlocale(LC_ALL, "Portuguese_Brazil");
    
    // Declaração de variáveis
    char estado1[4], estado2[4], cod1[4], cod2[4], nomeCidade1[50], nomeCidade2[50], atributo[100];
    int nPontosT1, nPontosT2;
    int populacao1, populacao2;
    float pib1, pib2, area1, area2, calcDensidadePop1, calcDensidadePop2, calcPib1, calcPib2, vAtributo1, vAtributo2;

    // Entrada de dados para a Carta 1
    printf("Insira os dados da primeira carta: \n");
    
    printf("\nEstado: ");
    scanf("%s", estado1);

    printf("Código: ");
    scanf("%s", cod1);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade1);

    printf("População: ");
    scanf("%d", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &nPontosT1);

    // Cálculo Densidade Populacional e PIB per Capita referente a Carta 1
    calcDensidadePop1 = (float) populacao1 / area1;
    calcPib1 = (float) pib1 / populacao1;

    // Exibição dos dados da Carta 1
    printf("\nCarta 1\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", cod1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área %.2f km² \n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1 / 1e9); //divisão por 1bi, para que quando exibido, apareça no formato correto
    printf("Número de Pontos Turísticos: %d\n", nPontosT1);
    printf("Densidade Populacional %.2f hab/km²\n", calcDensidadePop1);
    printf("PIB per Capita: %.2f reais\n\n", calcPib1);

    // Entrada de dados para a Carta 2
    printf("Insira os dados da segunda carta: \n");
    
    printf("\nEstado: ");
    scanf(" %s", estado2);  // Espaço antes do %c para ignorar o \n residual

    printf("Código: ");
    scanf("%s", cod2);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade2);

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &nPontosT2);

    // Cálculo Densidade Populacional e PIB per Capita referente a Carta 2
    calcDensidadePop2 = (float) populacao2 / area2;
    calcPib2 = (float) pib2 / populacao2;

    // Exibição dos dados da Carta 2
    printf("\nCarta 2\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", cod2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área %.2f km² \n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2 / 1e9); //divisão por 1bi, para que quando exibido, apareça no formato correto
    printf("Número de Pontos Turísticos: %d\n", nPontosT2);
    printf("Densidade Populacional %.2f hab/km²\n", calcDensidadePop2);
    printf("PIB per Capita: %.2f reais\n\n", calcPib2);

    // Declaração do atributo e atribuição de valores
    atributo[99] = "Densidade populacional";
    vAtributo1 = calcDensidadePop1;
    vAtributo2 = calcDensidadePop2;

    // Exibição das cartas/atributos da comparação
    printf("Comparação de cartas (Atributo: %s)\n\n", atributo);
    printf("Carta 1 - %s (%s): %.2f hab/km²\n", nomeCidade1, cod1, vAtributo1);
    printf("Carta 2 - %s (%s): %.2f hab/km²\n", nomeCidade2, cod2, vAtributo2);

    // Estrutura de decisão para a comparação de apenas um atributo
    if (vAtributo1 < vAtributo2) {
        printf("Resultado: Carta 1 (%s) venceu!", nomeCidade1);
    }
    else {
        printf("Resultado: Carta 2 (%s) venceu!", nomeCidade2);
    }

    return 0;
}
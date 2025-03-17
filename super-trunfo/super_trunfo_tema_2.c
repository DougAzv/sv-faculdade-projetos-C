#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

int main(void) {

    /*
    O código foi salvo com a codificação ISO-8859-1 para garantir que caracteres acentuados (como ç, ã, é) sejam exibidos corretamente ao executar o programa.
    
    Ao executar o programa, utilize "," (vírgula) ao invés de "." (ponto) para casas decimais, pois o locale "Portuguese_Brazil" foi configurado. 

    O uso de "." pode causar erros na leitura dos números.
    */

    setlocale(LC_ALL, "Portuguese_Brazil");
    
    // Declaração de variáveis
    char estado1[4], estado2[4], cod1[4], cod2[4], nomeCidade1[50], nomeCidade2[50], atributo[99];
    int nPontosT1, nPontosT2, populacao1, populacao2, cAtributo;
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

    // Exibição da escolha/opção de atributo
    printf("Escolha um atributo para ser comparado: \n");

    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. PIB per Capita\n");
    scanf("%d", &cAtributo);

    // Definição da estrutura de decisão Switch-case
    // A variável vAtributo1 e vAtributo2, recebem os respectivos valores a depender da escolha do usuário
    switch (cAtributo)
    {
    case 1:
        strcpy(atributo, "População");
        vAtributo1 = populacao1;
        vAtributo2 = populacao2;
        break;
    case 2:
        strcpy(atributo, "Área");
        vAtributo1 = area1;
        vAtributo2 = area2;
        break;
    case 3:
        strcpy(atributo, "PIB");
        vAtributo1 = pib1;
        vAtributo2 = pib2;
        break;
    case 4:
        strcpy(atributo, "Número de Pontos Turísticos");
        vAtributo1 = nPontosT1;
        vAtributo2 = nPontosT2;
        break;
    case 5:
        strcpy(atributo, "Densidade Populacional");
        vAtributo1 = calcDensidadePop2; //densidade inversamente colocada para que a comparação seja feita corretamente na estrutura de decisão
        vAtributo2 = calcDensidadePop1; //densidade inversamente colocada para que a comparação seja feita corretamente na estrutura de decisão
        break;
    case 6:
        strcpy(atributo, "PIB per Capita");
        vAtributo1 = calcPib1;
        vAtributo2 = calcPib2;
        break;
    default:
        printf("Opção inválida!");
        break;
    }

    // Exibição das cartas/atributos da comparação
    printf("\nComparação de cartas (Atributo: %s)\n\n", atributo);
    if (cAtributo == 1 || cAtributo == 4) { // Atributos inteiros
        printf("Carta 1 - %s (%s): %d\n", nomeCidade1, estado1, (int)vAtributo1);
        printf("Carta 2 - %s (%s): %d\n", nomeCidade2, estado2, (int)vAtributo2);
    } else { // Atributos float
        printf("Carta 1 - %s (%s): %.2f\n", nomeCidade1, estado1, vAtributo1);
        printf("Carta 2 - %s (%s): %.2f\n", nomeCidade2, estado2, vAtributo2);
    }

    // Estrutura de decisão para a comparação
    if (vAtributo1 > vAtributo2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (vAtributo1 < vAtributo2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}




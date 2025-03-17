#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(void) {

    /*
    O c�digo foi salvo com a codifica��o ISO-8859-1 para garantir que caracteres acentuados (como �, �, �) sejam exibidos corretamente ao executar o programa.
    
    Ao executar o programa, utilize "," (v�rgula) ao inv�s de "." (ponto) para casas decimais, pois o locale "Portuguese_Brazil" foi configurado. 

    O uso de "." pode causar erros na leitura dos n�meros.
    */

    setlocale(LC_ALL, "Portuguese_Brazil");
    
    // Declara��o de vari�veis
    char estado1[4], estado2[4], cod1[4], cod2[4], nomeCidade1[50], nomeCidade2[50], atributo[100];
    int nPontosT1, nPontosT2;
    int populacao1, populacao2;
    float pib1, pib2, area1, area2, calcDensidadePop1, calcDensidadePop2, calcPib1, calcPib2, vAtributo1, vAtributo2;

    // Entrada de dados para a Carta 1
    printf("Insira os dados da primeira carta: \n");
    
    printf("\nEstado: ");
    scanf("%s", estado1);

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

    // C�lculo Densidade Populacional e PIB per Capita referente a Carta 1
    calcDensidadePop1 = (float) populacao1 / area1;
    calcPib1 = (float) pib1 / populacao1;

    // Exibi��o dos dados da Carta 1
    printf("\nCarta 1\n");
    printf("Estado: %s\n", estado1);
    printf("C�digo: %s\n", cod1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Popula��o: %d\n", populacao1);
    printf("�rea %.2f km� \n", area1);
    printf("PIB: %.2f bilh�es de reais\n", pib1 / 1e9); //divis�o por 1bi, para que quando exibido, apare�a no formato correto
    printf("N�mero de Pontos Tur�sticos: %d\n", nPontosT1);
    printf("Densidade Populacional %.2f hab/km�\n", calcDensidadePop1);
    printf("PIB per Capita: %.2f reais\n\n", calcPib1);

    // Entrada de dados para a Carta 2
    printf("Insira os dados da segunda carta: \n");
    
    printf("\nEstado: ");
    scanf(" %s", estado2);  // Espa�o antes do %c para ignorar o \n residual

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

    // C�lculo Densidade Populacional e PIB per Capita referente a Carta 2
    calcDensidadePop2 = (float) populacao2 / area2;
    calcPib2 = (float) pib2 / populacao2;

    // Exibi��o dos dados da Carta 2
    printf("\nCarta 2\n");
    printf("Estado: %s\n", estado2);
    printf("C�digo: %s\n", cod2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Popula��o: %d\n", populacao2);
    printf("�rea %.2f km� \n", area2);
    printf("PIB: %.2f bilh�es de reais\n", pib2 / 1e9); //divis�o por 1bi, para que quando exibido, apare�a no formato correto
    printf("N�mero de Pontos Tur�sticos: %d\n", nPontosT2);
    printf("Densidade Populacional %.2f hab/km�\n", calcDensidadePop2);
    printf("PIB per Capita: %.2f reais\n\n", calcPib2);

    // Declara��o do atributo e atribui��o de valores
    atributo[99] = "Densidade populacional";
    vAtributo1 = calcDensidadePop1;
    vAtributo2 = calcDensidadePop2;

    // Exibi��o das cartas/atributos da compara��o
    printf("Compara��o de cartas (Atributo: %s)\n\n", atributo);
    printf("Carta 1 - %s (%s): %.2f hab/km�\n", nomeCidade1, cod1, vAtributo1);
    printf("Carta 2 - %s (%s): %.2f hab/km�\n", nomeCidade2, cod2, vAtributo2);

    // Estrutura de decis�o para a compara��o de apenas um atributo
    if (vAtributo1 < vAtributo2) {
        printf("Resultado: Carta 1 (%s) venceu!", nomeCidade1);
    }
    else {
        printf("Resultado: Carta 2 (%s) venceu!", nomeCidade2);
    }

    return 0;
}
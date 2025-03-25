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
    char estado1, estado2, cod1[4], cod2[4], nomeCidade1[50], nomeCidade2[50];
    int nPontosT1, nPontosT2, vencedorPopulacao, vencedorArea, vencedorDensidade, vencedorPib, vencedorSuperPoder, vencedorPontoT, vencedorPibPc;
    unsigned long int populacao1, populacao2;
    float pib1, pib2, area1, area2, calcDensidadePop1, calcDensidadePop2, calcPib1, calcPib2, inversoDensidade1, inversoDensidade2, superPoder1, superPoder2;

    // Entrada de dados para a Carta 1
    printf("Insira os dados da primeira carta: \n");
    
    printf("\nEstado: ");
    scanf("%c", &estado1);

    printf("Código: ");
    scanf("%s", cod1);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade1); // %s não utilizado, pois não lê espaços em branco (como espaços, tabs ou quebras de linha)

    printf("População: ");
    scanf("%lu", &populacao1);

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
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", cod1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área %.2f km² \n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1 / 1e9); // divisão por 1bi, para que quando exibido, apareça no formato correto
    printf("Número de Pontos Turísticos: %d\n", nPontosT1);
    printf("Densidade Populacional %.2f hab/km²\n", calcDensidadePop1);
    printf("PIB per Capita: %.2f reais\n\n", calcPib1);

    // Entrada de dados para a Carta 2
    printf("Insira os dados da segunda carta: \n");
    
    printf("\nEstado: ");
    scanf(" %c", &estado2);  // Espaço antes do %c para ignorar o \n residual

    printf("Código: ");
    scanf("%s", cod2);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade2); // %s não utilizado, pois não lê espaços em branco (como espaços, tabs ou quebras de linha)

    printf("População: ");
    scanf("%lu", &populacao2);

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
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", cod2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área %.2f km² \n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2 / 1e9); // divisão por 1bi, para que quando exibido, apareça no formato correto
    printf("Número de Pontos Turísticos: %d\n", nPontosT2);
    printf("Densidade Populacional %.2f hab/km²\n", calcDensidadePop2);
    printf("PIB per Capita: %.2f reais\n\n", calcPib2);


    // Cálculo Inverso da Densidade Populacional
    inversoDensidade1 = area1 / populacao1;
    inversoDensidade2 = area2 / populacao2;

    // Cálculo Super Poder
    superPoder1 = (float)area1 + (float)populacao1 + inversoDensidade1 + calcPib1 + (float)nPontosT1 + pib1;
    superPoder2 = (float)area2 + (float)populacao2 + inversoDensidade2 + calcPib2 + (float)nPontosT2 + pib2;

    // Comparação dos atributos - resultado exibido como 1 (true) ou 0 (false)
    vencedorPopulacao = (populacao1 > populacao2);
    vencedorArea = (area1 > area2);
    vencedorPib = (pib1 > pib2);
    vencedorPontoT = (nPontosT1 > nPontosT2);
    vencedorDensidade = (calcDensidadePop1 < calcDensidadePop2); // Menor densidade vence
    vencedorPibPc = (calcPib1 > calcPib2);
    vencedorSuperPoder = (superPoder1 > superPoder2);

    // lógica utilizada para a exibição dos resultados: 
    // A comparação anterior gera o valor 1 (true) ou 0 (false), então na exibição do resultado é feita a subtração "2 - vencedorAlgumaCoisa" (dois menos vencedorAlgumaCoisa)
    // Então se a comparação anterior gerou um resultado true, a subtração seria 2 - 1 = 1
    // Porém se a comparação anterior gerar um resultado false, a subtração seria 2 - 0 = 2
    // Então se o resultado for true, a carta 1 vence (2 - 1 = 1), se for false a carta 2 vence (2 - 0 = 2)

    // Exibição dos resultados das comparações:
    printf("\nResultados das Comparações:\n");
    printf("População: Carta %d venceu(%d)\n", 2 - vencedorPopulacao, vencedorPopulacao);
    printf("Área: Carta %d venceu (%d)\n", 2 - vencedorArea, vencedorArea);
    printf("PIB: Carta %d venceu (%d)\n", 2 - vencedorPib, vencedorPib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", 2 - vencedorPontoT, vencedorPontoT);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 2 - vencedorDensidade, vencedorDensidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", 2 - vencedorPibPc, vencedorPibPc);
    printf("Super Poder: Carta %d venceu (%d)\n", 2 - vencedorSuperPoder, vencedorSuperPoder);

    return 0;
}



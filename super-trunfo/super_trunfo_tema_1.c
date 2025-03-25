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
    char estado1, estado2, cod1[4], cod2[4], nomeCidade1[50], nomeCidade2[50];
    int nPontosT1, nPontosT2, vencedorPopulacao, vencedorArea, vencedorDensidade, vencedorPib, vencedorSuperPoder, vencedorPontoT, vencedorPibPc;
    unsigned long int populacao1, populacao2;
    float pib1, pib2, area1, area2, calcDensidadePop1, calcDensidadePop2, calcPib1, calcPib2, inversoDensidade1, inversoDensidade2, superPoder1, superPoder2;

    // Entrada de dados para a Carta 1
    printf("Insira os dados da primeira carta: \n");
    
    printf("\nEstado: ");
    scanf("%c", &estado1);

    printf("C�digo: ");
    scanf("%s", cod1);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade1); // %s n�o utilizado, pois n�o l� espa�os em branco (como espa�os, tabs ou quebras de linha)

    printf("Popula��o: ");
    scanf("%lu", &populacao1);

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
    printf("Estado: %c\n", estado1);
    printf("C�digo: %s\n", cod1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Popula��o: %lu\n", populacao1);
    printf("�rea %.2f km� \n", area1);
    printf("PIB: %.2f bilh�es de reais\n", pib1 / 1e9); // divis�o por 1bi, para que quando exibido, apare�a no formato correto
    printf("N�mero de Pontos Tur�sticos: %d\n", nPontosT1);
    printf("Densidade Populacional %.2f hab/km�\n", calcDensidadePop1);
    printf("PIB per Capita: %.2f reais\n\n", calcPib1);

    // Entrada de dados para a Carta 2
    printf("Insira os dados da segunda carta: \n");
    
    printf("\nEstado: ");
    scanf(" %c", &estado2);  // Espa�o antes do %c para ignorar o \n residual

    printf("C�digo: ");
    scanf("%s", cod2);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade2); // %s n�o utilizado, pois n�o l� espa�os em branco (como espa�os, tabs ou quebras de linha)

    printf("Popula��o: ");
    scanf("%lu", &populacao2);

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
    printf("Estado: %c\n", estado2);
    printf("C�digo: %s\n", cod2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Popula��o: %lu\n", populacao2);
    printf("�rea %.2f km� \n", area2);
    printf("PIB: %.2f bilh�es de reais\n", pib2 / 1e9); // divis�o por 1bi, para que quando exibido, apare�a no formato correto
    printf("N�mero de Pontos Tur�sticos: %d\n", nPontosT2);
    printf("Densidade Populacional %.2f hab/km�\n", calcDensidadePop2);
    printf("PIB per Capita: %.2f reais\n\n", calcPib2);


    // C�lculo Inverso da Densidade Populacional
    inversoDensidade1 = area1 / populacao1;
    inversoDensidade2 = area2 / populacao2;

    // C�lculo Super Poder
    superPoder1 = (float)area1 + (float)populacao1 + inversoDensidade1 + calcPib1 + (float)nPontosT1 + pib1;
    superPoder2 = (float)area2 + (float)populacao2 + inversoDensidade2 + calcPib2 + (float)nPontosT2 + pib2;

    // Compara��o dos atributos - resultado exibido como 1 (true) ou 0 (false)
    vencedorPopulacao = (populacao1 > populacao2);
    vencedorArea = (area1 > area2);
    vencedorPib = (pib1 > pib2);
    vencedorPontoT = (nPontosT1 > nPontosT2);
    vencedorDensidade = (calcDensidadePop1 < calcDensidadePop2); // Menor densidade vence
    vencedorPibPc = (calcPib1 > calcPib2);
    vencedorSuperPoder = (superPoder1 > superPoder2);

    // l�gica utilizada para a exibi��o dos resultados: 
    // A compara��o anterior gera o valor 1 (true) ou 0 (false), ent�o na exibi��o do resultado � feita a subtra��o "2 - vencedorAlgumaCoisa" (dois menos vencedorAlgumaCoisa)
    // Ent�o se a compara��o anterior gerou um resultado true, a subtra��o seria 2 - 1 = 1
    // Por�m se a compara��o anterior gerar um resultado false, a subtra��o seria 2 - 0 = 2
    // Ent�o se o resultado for true, a carta 1 vence (2 - 1 = 1), se for false a carta 2 vence (2 - 0 = 2)

    // Exibi��o dos resultados das compara��es:
    printf("\nResultados das Compara��es:\n");
    printf("Popula��o: Carta %d venceu(%d)\n", 2 - vencedorPopulacao, vencedorPopulacao);
    printf("�rea: Carta %d venceu (%d)\n", 2 - vencedorArea, vencedorArea);
    printf("PIB: Carta %d venceu (%d)\n", 2 - vencedorPib, vencedorPib);
    printf("Pontos Tur�sticos: Carta %d venceu (%d)\n", 2 - vencedorPontoT, vencedorPontoT);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 2 - vencedorDensidade, vencedorDensidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", 2 - vencedorPibPc, vencedorPibPc);
    printf("Super Poder: Carta %d venceu (%d)\n", 2 - vencedorSuperPoder, vencedorSuperPoder);

    return 0;
}



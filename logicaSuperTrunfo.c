#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

// ...existing code...
#include <string.h> // Necessário para comparar strings
// ...existing code...

// --- DOCUMENTAÇÃO ---
// Desafio: Comparando Cartas do Super Trunfo (Nível Novato)
// Linguagem: C
// Objetivo: Implementar a lógica de comparação entre duas cartas de Super Trunfo
// com base em um atributo numérico pré-definido no código, utilizando if-else.

// --- ESTRUTURA DA CARTA ---
// Define a estrutura para armazenar todos os dados de uma carta do Super Trunfo.
// Isso organiza as informações e facilita o acesso a cada atributo.
struct Carta {
    char estado[3];             // Ex: "SP" (2 caracteres + 1 para o terminador nulo '\0')
    char codigo[5];             // Ex: "C01"
    char cidade[50];
    int populacao;
    float area;                 // Em km²
    float pib;                  // Em bilhões de R$
    int pontos_turisticos;
    
    // Atributos calculados
    float densidade_populacional; // hab/km²
    float pib_per_capita;         // R$ por pessoa
};

// --- FUNÇÃO PRINCIPAL DO PROGRAMA ---
int main() {
    
    // --- REQUISITO: ESCOLHER O ATRIBUTO PARA COMPARAÇÃO DIRETAMENTE NO CÓDIGO ---
    // Para mudar o atributo, basta alterar a string abaixo.
    // Opções válidas: "POPULACAO", "AREA", "PIB", "DENSIDADE", "PIB_PER_CAPITA"
    // NOTA: O número de pontos turísticos não foi listado como opção de comparação no desafio.
    #define ATRIBUTO_A_COMPARAR "DENSIDADE"

    // --- REQUISITO: RECEBER OS DADOS DE DUAS CARTAS ---
    // Como simplificação para o nível básico, as cartas são pré-definidas no código.
    
    // Carta 1: São Paulo
    struct Carta carta1;
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo, "C01");
    strcpy(carta1.cidade, "Sao Paulo");
    carta1.populacao = 12396372;
    carta1.area = 1521.11;
    carta1.pib = 747.9; // 747.9 bilhões
    carta1.pontos_turisticos = 15;

    // Carta 2: Curitiba
    struct Carta carta2;
    strcpy(carta2.estado, "PR");
    strcpy(carta2.codigo, "C02");
    strcpy(carta2.cidade, "Curitiba");
    carta2.populacao = 1963726;
    carta2.area = 435.036;
    carta2.pib = 98.0; // 98.0 bilhões
    carta2.pontos_turisticos = 12;

    // --- REQUISITO: CALCULAR DENSIDADE POPULACIONAL E PIB PER CAPITA ---
    
    // Cálculo para a Carta 1
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    // O PIB está em bilhões, então multiplicamos por 1.000.000.000 para o cálculo per capita.
    carta1.pib_per_capita = (carta1.pib * 1000000000) / carta1.populacao;
    
    // Cálculo para a Carta 2
    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 1000000000) / carta2.populacao;

    printf("--- Super Trunfo: Comparador de Cartas ---\n\n");

    // --- REQUISITO: DETERMINAR A CARTA VENCEDORA E EXIBIR O RESULTADO ---
    // A lógica de comparação é feita usando uma série de if-else if para
    // verificar qual atributo foi escolhido na diretiva #define.

    // Comparação por POPULAÇÃO
    if (strcmp(ATRIBUTO_A_COMPARAR, "POPULACAO") == 0) {
        printf("Comparacao de cartas (Atributo: Populacao):\n\n");
        printf("Carta 1 - %s (%s): %d habitantes\n", carta1.cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d habitantes\n", carta2.cidade, carta2.estado, carta2.populacao);

        if (carta1.populacao > carta2.populacao) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
    // Comparação por ÁREA
    else if (strcmp(ATRIBUTO_A_COMPARAR, "AREA") == 0) {
        printf("Comparacao de cartas (Atributo: Area):\n\n");
        printf("Carta 1 - %s (%s): %.2f km^2\n", carta1.cidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f km^2\n", carta2.cidade, carta2.estado, carta2.area);

        if (carta1.area > carta2.area) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta2.area > carta2.area) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
    // Comparação por PIB
    else if (strcmp(ATRIBUTO_A_COMPARAR, "PIB") == 0) {
        printf("Comparacao de cartas (Atributo: PIB):\n\n");
        printf("Carta 1 - %s (%s): R$ %.2f bilhoes\n", carta1.cidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): R$ %.2f bilhoes\n", carta2.cidade, carta2.estado, carta2.pib);

        if (carta1.pib > carta2.pib) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta2.pib > carta1.pib) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
    // Comparação por DENSIDADE POPULACIONAL (REGRA ESPECIAL)
    else if (strcmp(ATRIBUTO_A_COMPARAR, "DENSIDADE") == 0) {
        printf("Comparacao de cartas (Atributo: Densidade Populacional):\n\n");
        printf("Lembre-se: para Densidade, o MENOR valor vence!\n\n");
        printf("Carta 1 - %s (%s): %.2f hab/km^2\n", carta1.cidade, carta1.estado, carta1.densidade_populacional);
        printf("Carta 2 - %s (%s): %.2f hab/km^2\n", carta2.cidade, carta2.estado, carta2.densidade_populacional);

        // A lógica é invertida: menor valor ganha.
        if (carta1.densidade_populacional < carta2.densidade_populacional) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
    // Comparação por PIB PER CAPITA
    else if (strcmp(ATRIBUTO_A_COMPARAR, "PIB_PER_CAPITA") == 0) {
        printf("Comparacao de cartas (Atributo: PIB per capita):\n\n");
        printf("Carta 1 - %s (%s): R$ %.2f por habitante\n", carta1.cidade, carta1.estado, carta1.pib_per_capita);
        printf("Carta 2 - %s (%s): R$ %.2f por habitante\n", carta2.cidade, carta2.estado, carta2.pib_per_capita);

        if (carta1.pib_per_capita > carta2.pib_per_capita) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
    // Caso o #define seja preenchido com uma opção inválida
    else {
        printf("Erro: O atributo definido para comparacao ('%s') e invalido.\n", ATRIBUTO_A_COMPARAR);
    }
    
    return 0; // Finaliza o programa com sucesso
}
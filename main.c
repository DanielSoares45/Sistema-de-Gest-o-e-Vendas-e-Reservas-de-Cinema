/**
 * ============================================================================
 * SISTEMA DE GESTAO DE VENDAS E RESERVAS DE CINEMA
 * ============================================================================
 * Estrutura Principal: Matriz 6x8 para mapeamento de lugares.
 * Estados dos lugares: 0 = Livre | 1 = Inteira | 2 = Meia-Entrada
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Definicao das dimensoes da sala (Constantes)
#define FILEIRAS 6
#define ASSENTOS 8

// --- ESTRUTURAS DE DADOS GLOBAIS / TABELAS DE AUXILIO ---
char rotuloFileiras[FILEIRAS] = {'A', 'B', 'C', 'D', 'E', 'F'}; // Mapeamento visual
float tabelaPrecos[2] = {30.00, 15.00};                         // [0] Inteira, [1] Meia

// --- PROTOTIPOS DAS FUNCOES ---
void inicializarSala(int sala[FILEIRAS][ASSENTOS]);
void exibirMapa(int sala[FILEIRAS][ASSENTOS]);
void realizarVenda(int sala[FILEIRAS][ASSENTOS]);
void gerarRelatorio(int sala[FILEIRAS][ASSENTOS]);
void identificarFileiraMaisProcurada(int sala[FILEIRAS][ASSENTOS]); // Desafio Bonus

// ============================================================================
// FUNCAO PRINCIPAL (MAIN)
// ============================================================================
int main() {
    // Declaracao da matriz principal
    int sala[FILEIRAS][ASSENTOS];
    int opcao;

    // Preenche a matriz com zeros antes de iniciar o loop do menu
    inicializarSala(sala);

    do {
        printf("\n=============================================\n");
        printf("       CINE-SYSTEM :: MENU PRINCIPAL         \n");
        printf("=============================================\n");
        printf("1. Visualizar Mapa da Sala\n");
        printf("2. Comprar / Reservar Ingresso\n");
        printf("3. Relatorio Financeiro e de Bilheteria\n");
        printf("4. Destaque: Fileira mais Procurada (Bonus)\n");
        printf("0. Sair do Sistema\n");
        printf("---------------------------------------------\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            // Limpa buffer de entrada em caso de digitacao de caracteres invalidos
            while (getchar() != '\n');
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                exibirMapa(sala);
                break;
            case 2:
                realizarVenda(sala);
                break;
            case 3:
                gerarRelatorio(sala);
                break;
            case 4:
                identificarFileiraMaisProcurada(sala);
                break;
            case 0:
                printf("\nEncerrando o sistema de cinema... Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Digite um numero de 0 a 4.\n");
        }

    } while (opcao != 0);

    return 0;
}

// ============================================================================
// INICIALIZACAO DA MATRIZ
// ============================================================================
void inicializarSala(int sala[FILEIRAS][ASSENTOS]) {
    // Laco duplo para percorrer todas as linhas e colunas zerando a matriz
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < ASSENTOS; j++) {
            sala[i][j] = 0; // 0 representa lugar LIVRE
        }
    }
}

// ============================================================================
// RENDERIZACAO DO MAPA DA SALA NO CONSOLE
// ============================================================================
void exibirMapa(int sala[FILEIRAS][ASSENTOS]) {
    printf("\n================== TELA DO CINEMA ==================\n\n");
    
    // Imprime cabecalho das colunas (Lugares 01 a 08)
    printf("       ");
    for (int j = 0; j < ASSENTOS; j++) {
        printf("%02d  ", j + 1);
    }
    printf("\n");

    // Percorre as linhas (Fileiras A a F)
    for (int i = 0; i < FILEIRAS; i++) {
        // Acessa o vetor rotuloFileiras para converter o indice 'i' na letra
        printf("   %c  ", rotuloFileiras[i]);

        // Percorre cada lugar da fileira atual
        for (int j = 0; j < ASSENTOS; j++) {
            if (sala[i][j] == 0) {
                printf("[ L ]"); // Livre
            } else {
                printf("[ X ]"); // Ocupado
            }
        }
        printf("\n"); // Quebra de linha ao finalizar uma fileira
    }
    
    printf("\nLegenda: [ L ] = Livre | [ X ] = Ocupado / Vendido\n");
    printf("====================================================\n");
}

// ============================================================================
// REGISTRO E VALIDACAO DE VENDAS
// ============================================================================
void realizarVenda(int sala[FILEIRAS][ASSENTOS]) {
    char letraFileira;
    int linha, coluna, tipoIngresso;

    printf("\n--- Venda de Ingressos ---\n");

    // Loop de validacao de coordenadas
    while (1) {
        printf("Informe a Fileira (A-F): ");
        scanf(" %c", &letraFileira);
        
        // Normaliza para maiusculo e converte Char para Indice Numerico (0-5)
        linha = toupper(letraFileira) - 'A';

        printf("Informe o numero da cadeira (1-8): ");
        scanf("%d", &coluna);
        coluna--; // Ajusta de escala do usuario (1-8) para indice de vetor em C (0-7)

        // 1. Validacao de limites da matriz
        if (linha < 0 || linha >= FILEIRAS || coluna < 0 || coluna >= ASSENTOS) {
            printf("[ERRO] Lugar inexistente na sala! Tente novamente.\n\n");
            continue;
        }

        // 2. Validacao de ocupacao previa
        if (sala[linha][coluna] != 0) {
            printf("[ALERTA] Lugar %c%d ja esta ocupado! Escolha outra cadeira.\n\n", 
                   rotuloFileiras[linha], coluna + 1);
            continue;
        }

        // Se passar por ambas as validacoes, a posicao e valida e esta livre
        break;
    }

    // Leitura do tipo de ingresso
    do {
        printf("Tipo de Ingresso (1 - Inteira R$%.2f | 2 - Meia R$%.2f): ", 
               tabelaPrecos[0], tabelaPrecos[1]);
        scanf("%d", &tipoIngresso);

        if (tipoIngresso != 1 && tipoIngresso != 2) {
            printf("[ERRO] Opcao invalida! Digite 1 para Inteira ou 2 para Meia.\n");
        }
    } while (tipoIngresso != 1 && tipoIngresso != 2);

    // Gravacao final na matriz
    sala[linha][coluna] = tipoIngresso;

    printf("\n[SUCESSO] Lugar %c%d reservado com sucesso (%s)!\n", 
           rotuloFileiras[linha], coluna + 1, (tipoIngresso == 1) ? "Inteira" : "Meia");
}

// ============================================================================
// PROCESSAMENTO E RELATORIO DE BILHETERIA
// ============================================================================
void gerarRelatorio(int sala[FILEIRAS][ASSENTOS]) {
    int totalInteiras = 0;
    int totalMeias = 0;
    int capacidadeTotal = FILEIRAS * ASSENTOS;

    // Varre toda a matriz acumulando a contagem de tipos de ingressos
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < ASSENTOS; j++) {
            if (sala[i][j] == 1) {
                totalInteiras++;
            } else if (sala[i][j] == 2) {
                totalMeias++;
            }
        }
    }

    int totalVendidos = totalInteiras + totalMeias;
    float taxaOcupacao = ((float)totalVendidos / capacidadeTotal) * 100.0f;
    
    // Calculo financeiro indexado ao vetor tabelaPrecos
    float faturamentoInteiras = totalInteiras * tabelaPrecos[0];
    float faturamentoMeias = totalMeias * tabelaPrecos[1];
    float faturamentoTotal = faturamentoInteiras + faturamentoMeias;

    printf("\n=============================================\n");
    printf("        RELATORIO GERAL DE BILHETERIA        \n");
    printf("=============================================\n");
    printf("Capacidade da Sala:    %d lugares\n", capacidadeTotal);
    printf("Lugares Ocupados:      %d\n", totalVendidos);
    printf("Lugares Livres:        %d\n", capacidadeTotal - totalVendidos);
    printf("Taxa de Ocupacao:      %.2f%%\n", taxaOcupacao);
    printf("---------------------------------------------\n");
    printf("Ingressos Inteira:     %d | Total: R$ %.2f\n", totalInteiras, faturamentoInteiras);
    printf("Ingressos Meia:        %d | Total: R$ %.2f\n", totalMeias, faturamentoMeias);
    printf("---------------------------------------------\n");
    printf("FATURAMENTO TOTAL:     R$ %.2f\n", faturamentoTotal);
    printf("=============================================\n");
}

// ============================================================================
// DESAFIO BONUS: IDENTIFICAR A FILEIRA MAIS PROCURADA
// ============================================================================
void identificarFileiraMaisProcurada(int sala[FILEIRAS][ASSENTOS]) {
    // Vetor local para acumular as vendas de cada uma das 6 fileiras
    int vendasPorFileira[FILEIRAS] = {0};
    int maiorVenda = 0;

    // 1. Soma os ingressos vendidos por fileira (percorre linha por linha)
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < ASSENTOS; j++) {
            if (sala[i][j] > 0) { // Qualquer valor acima de 0 e lugar vendido
                vendasPorFileira[i]++;
            }
        }
        // Identifica o maior volume de vendas encontrado
        if (vendasPorFileira[i] > maiorVenda) {
            maiorVenda = vendasPorFileira[i];
        }
    }

    printf("\n=============================================\n");
    printf("      DESTAQUE: FILEIRA MAIS PROCURADA       \n");
    printf("=============================================\n");

    if (maiorVenda == 0) {
        printf("Nenhum ingresso foi vendido ate o momento.\n");
    } else {
        printf("Maior volume de ocupacao: %d lugares vendidos.\n", maiorVenda);
        printf("Fileira(s) campea(s) de vendas: ");

        // 2. Percorre o vetor para imprimir a(s) fileira(s) que atingiram o valor maximo
        for (int i = 0; i < FILEIRAS; i++) {
            if (vendasPorFileira[i] == maiorVenda) {
                printf("[%c] ", rotuloFileiras[i]);
            }
        }
        printf("\n");
    }
    printf("=============================================\n");
}
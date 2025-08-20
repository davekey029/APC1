#include <stdio.h>
#include <string.h> // Para usar strcpy

// Definição da estrutura para armazenar os dados de cada operação
typedef struct {
    float num1;
    float num2;
    char operacao[20]; // Ex: "Soma", "Subtracao"
    float resultado;
} Operacao;

#define MAX_OPERACOES 100 // Tamanho máximo do histórico

int main() {
    int opcao;
    float num1, num2, resultado;
    char entrada[50];
    Operacao historico[MAX_OPERACOES]; // Array para armazenar o histórico
    int contador = 0; // Contador para rastrear o número de operações realizadas

    do {
        printf("\n=== Calculadora ===\n");
        printf("1. Soma\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("5. Exibir Historico\n");
        printf("6. Sair\n");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL || entrada[0] == '\n') {
            printf("Entrada invalida! Por favor, insira uma opcao valida.\n");
            continue;
        }
        if (sscanf(entrada, "%d", &opcao) != 1) {
            printf("Entrada invalida! Por favor, insira uma opcao valida.\n");
            continue;
        }

        if (opcao >= 1 && opcao <= 4) {
            // Validação da entrada para o primeiro número
            do {
                printf("Digite o primeiro numero: ");
                if (fgets(entrada, sizeof(entrada), stdin) == NULL || entrada[0] == '\n') {
                    printf("Entrada invalida! Por favor, insira um numero valido.\n");
                    continue;
                }
                if (sscanf(entrada, "%f", &num1) != 1) {
                    printf("Entrada invalida! Por favor, insira um numero valido.\n");
                    continue;
                }
                break;
            } while (1);

            // Validação da entrada para o segundo número
            do {
                printf("Digite o segundo numero: ");
                if (fgets(entrada, sizeof(entrada), stdin) == NULL || entrada[0] == '\n') {
                    printf("Entrada invalida! Por favor, insira um numero valido.\n");
                    continue;
                }
                if (sscanf(entrada, "%f", &num2) != 1) {
                    printf("Entrada invalida! Por favor, insira um numero valido.\n");
                    continue;
                }
                break;
            } while (1);

            // Realiza a operação e armazena no histórico
            switch (opcao) {
                case 1:
                    resultado = num1 + num2;
                    printf("A soma de %.2f + %.2f = %.2f\n", num1, num2, resultado);
                    strcpy(historico[contador].operacao, "+");
                    break;
                case 2:
                    resultado = num1 - num2;
                    printf("A subtracao de %.2f - %.2f = %.2f\n", num1, num2, resultado);
                    strcpy(historico[contador].operacao, "-");
                    break;
                case 3:
                    resultado = num1 * num2;
                    printf("A multiplicacao de %.2f * %.2f = %.2f\n", num1, num2, resultado);
                    strcpy(historico[contador].operacao, "*");
                    break;
                case 4:
                    if (num2 != 0) {
                        resultado = num1 / num2;
                        printf("A divisao de %.2f / %.2f = %.2f\n", num1, num2, resultado);
                        strcpy(historico[contador].operacao, "/");
                    } else {
                        printf("Erro: Divisao por zero nao permitida.\n");
                        continue; // Não armazena no históricos
                    }
                    break;
            }

            // Armazena os dados no histórico
            historico[contador].num1 = num1;
            historico[contador].num2 = num2;
            historico[contador].resultado = resultado;
            contador++;

            // Verifica se o histórico está cheio
            if (contador >= MAX_OPERACOES) {
                printf("Historico cheio! Novas operacoes nao serao armazenadas.\n");
                contador = MAX_OPERACOES; // Garante que não ultrapasse o limite
            }
        } else if (opcao == 5) {
            // Exibe o histórico de operações
            printf("\n=== Historico de Operacoes ===\n");
            for (int i = 0; i < contador; i++) {
                printf("%d: %.2f %s %.2f = %.2f\n", i + 1, historico[i].num1, historico[i].operacao, historico[i].num2, historico[i].resultado);
            }
            if (contador == 0) {
                printf("Nenhuma operacao realizada ainda.\n");
            }
        } else if (opcao == 6) {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
#include <stdio.h>
#include <string.h> // Para usar strcpy
#include <locale.h> // Para configurar o locale para português

// Definição da estrutura para armazenar os dados de cada operação
typedef struct {
    float num1;
    float num2;
    char operacao[20]; // Operação como string (pode ser "+", "-", "*", "/")
    float resultado;
} Operacao;

#define MAX_OPERACOES 100 // Definindo o tamanho máximo do histórico de operações

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura o locale para português

    int opcao;
    float num1, num2, resultado;
    char entrada[50];
    Operacao historico[MAX_OPERACOES]; // Array para armazenar o histórico de operações
    int contador = 0; // Contador para o número de operações realizadas

    do {
        printf("\n=== Calculadora ===\n");
        printf("1. Soma\n");
        printf("2. Subtracão\n");
        printf("3. Multiplicacão\n");
        printf("4. Divisão\n");
        printf("5. Exibir Histórico\n");
        printf("6. Sair\n");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL || entrada[0] == '\n') {
            printf("Entrada inválida! Por favor, insira uma opcao válida.\n");
            continue;
        }
        if (sscanf(entrada, "%d", &opcao) != 1) {
            printf("Entrada inválida! Por favor, insira uma opcao válida.\n");
            continue;
        }

        if (opcao >= 1 && opcao <= 4) {
            // Validação da entrada para o primeiro número
            do {
                printf("Digite o primeiro número: ");
                if (fgets(entrada, sizeof(entrada), stdin) == NULL || entrada[0] == '\n') {
                    printf("Entrada inválida! Por favor, insira um número válido.\n");
                    continue;
                }
                if (sscanf(entrada, "%f", &num1) != 1) {
                    printf("Entrada inválida! Por favor, insira um número válido.\n");
                    continue;
                }
                break;
            } while (1);

            // Validação da entrada para o segundo número
            do {
                printf("Digite o segundo número: ");
                if (fgets(entrada, sizeof(entrada), stdin) == NULL || entrada[0] == '\n') {
                    printf("Entrada inválida! Por favor, insira um número válido.\n");
                    continue;
                }
                if (sscanf(entrada, "%f", &num2) != 1) {
                    printf("Entrada inválida! Por favor, insira um número válido.\n");
                    continue;
                }
                break;
            } while (1);

            // Realiza a operação selecionada
            switch (opcao) {
                case 1:
                    resultado = num1 + num2;
                    printf("A soma de %.2f + %.2f = %.2f\n", num1, num2, resultado);
                    strcpy(historico[contador].operacao, "+");
                    break;
                case 2:
                    resultado = num1 - num2;
                    printf("A subtração de %.2f - %.2f = %.2f\n", num1, num2, resultado);
                    strcpy(historico[contador].operacao, "-");
                    break;
                case 3:
                    resultado = num1 * num2;
                    printf("A multiplicação de %.2f * %.2f = %.2f\n", num1, num2, resultado);
                    strcpy(historico[contador].operacao, "*");
                    break;
                case 4:
                    if (num2 != 0) {
                        resultado = num1 / num2;
                        printf("A divisão de %.2f / %.2f = %.2f\n", num1, num2, resultado);
                        strcpy(historico[contador].operacao, "/");
                    } else {
                        printf("Erro: Divisão por zero não é permitida!\n");
                        continue; // Pula para a próxima iteração do loop se a divisão por zero for tentada
                    }
                    break;
            }

            // Armazena a operação no histórico
            historico[contador].num1 = num1;
            historico[contador].num2 = num2;
            historico[contador].resultado = resultado;
            contador++;

            // Verifica se o contador ultrapassou o limite do histórico
            if (contador >= MAX_OPERACOES) {
                printf("Historico cheio! Novas operacoes nao serao armazenadas.\n");
                contador = MAX_OPERACOES; // Garante que nÃ£o ultrapasse o limite
            }
        } else if (opcao == 5) {
            // Exibe o histórico de operações
            printf("\n=== Historico de Operações ===\n");
            for (int i = 0; i < contador; i++) {
                printf("%d: %.2f %s %.2f = %.2f\n", i + 1, historico[i].num1, historico[i].operacao, historico[i].num2, historico[i].resultado);
            }
            if (contador == 0) {
                printf("Nenhuma operação realizada ainda.\n");
            }
        } else if (opcao == 6) {
            printf("Saindo...\n");
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
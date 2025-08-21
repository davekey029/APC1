#include <stdio.h>
#include <string.h> // Para usar strcpy
#include <locale.h> // Para configurar o locale para portugu�s

// Defini��o da estrutura para armazenar os dados de cada opera��o
typedef struct {
    float num1;
    float num2;
    char operacao[20]; // Opera��o como string (pode ser "+", "-", "*", "/")
    float resultado;
} Operacao;

#define MAX_OPERACOES 100 // Definindo o tamanho m�ximo do hist�rico de opera��es

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura o locale para portugu�s

    int opcao;
    float num1, num2, resultado;
    char entrada[50];
    Operacao historico[MAX_OPERACOES]; // Array para armazenar o hist�rico de opera��es
    int contador = 0; // Contador para o n�mero de opera��es realizadas

    do {
        printf("\n=== Calculadora ===\n");
        printf("1. Soma\n");
        printf("2. Subtrac�o\n");
        printf("3. Multiplicac�o\n");
        printf("4. Divis�o\n");
        printf("5. Exibir Hist�rico\n");
        printf("6. Sair\n");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL || entrada[0] == '\n') {
            printf("Entrada inv�lida! Por favor, insira uma opcao v�lida.\n");
            continue;
        }
        if (sscanf(entrada, "%d", &opcao) != 1) {
            printf("Entrada inv�lida! Por favor, insira uma opcao v�lida.\n");
            continue;
        }

        if (opcao >= 1 && opcao <= 4) {
            // Valida��o da entrada para o primeiro n�mero
            do {
                printf("Digite o primeiro n�mero: ");
                if (fgets(entrada, sizeof(entrada), stdin) == NULL || entrada[0] == '\n') {
                    printf("Entrada inv�lida! Por favor, insira um n�mero v�lido.\n");
                    continue;
                }
                if (sscanf(entrada, "%f", &num1) != 1) {
                    printf("Entrada inv�lida! Por favor, insira um n�mero v�lido.\n");
                    continue;
                }
                break;
            } while (1);

            // Valida��o da entrada para o segundo n�mero
            do {
                printf("Digite o segundo n�mero: ");
                if (fgets(entrada, sizeof(entrada), stdin) == NULL || entrada[0] == '\n') {
                    printf("Entrada inv�lida! Por favor, insira um n�mero v�lido.\n");
                    continue;
                }
                if (sscanf(entrada, "%f", &num2) != 1) {
                    printf("Entrada inv�lida! Por favor, insira um n�mero v�lido.\n");
                    continue;
                }
                break;
            } while (1);

            // Realiza a opera��o selecionada
            switch (opcao) {
                case 1:
                    resultado = num1 + num2;
                    printf("A soma de %.2f + %.2f = %.2f\n", num1, num2, resultado);
                    strcpy(historico[contador].operacao, "+");
                    break;
                case 2:
                    resultado = num1 - num2;
                    printf("A subtra��o de %.2f - %.2f = %.2f\n", num1, num2, resultado);
                    strcpy(historico[contador].operacao, "-");
                    break;
                case 3:
                    resultado = num1 * num2;
                    printf("A multiplica��o de %.2f * %.2f = %.2f\n", num1, num2, resultado);
                    strcpy(historico[contador].operacao, "*");
                    break;
                case 4:
                    if (num2 != 0) {
                        resultado = num1 / num2;
                        printf("A divis�o de %.2f / %.2f = %.2f\n", num1, num2, resultado);
                        strcpy(historico[contador].operacao, "/");
                    } else {
                        printf("Erro: Divis�o por zero n�o � permitida!\n");
                        continue; // Pula para a pr�xima itera��o do loop se a divis�o por zero for tentada
                    }
                    break;
            }

            // Armazena a opera��o no hist�rico
            historico[contador].num1 = num1;
            historico[contador].num2 = num2;
            historico[contador].resultado = resultado;
            contador++;

            // Verifica se o contador ultrapassou o limite do hist�rico
            if (contador >= MAX_OPERACOES) {
                printf("Historico cheio! Novas operacoes nao serao armazenadas.\n");
                contador = MAX_OPERACOES; // Garante que não ultrapasse o limite
            }
        } else if (opcao == 5) {
            // Exibe o hist�rico de opera��es
            printf("\n=== Historico de Opera��es ===\n");
            for (int i = 0; i < contador; i++) {
                printf("%d: %.2f %s %.2f = %.2f\n", i + 1, historico[i].num1, historico[i].operacao, historico[i].num2, historico[i].resultado);
            }
            if (contador == 0) {
                printf("Nenhuma opera��o realizada ainda.\n");
            }
        } else if (opcao == 6) {
            printf("Saindo...\n");
        } else {
            printf("Op��o inv�lida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
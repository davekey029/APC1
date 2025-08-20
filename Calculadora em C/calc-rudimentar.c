#include <stdio.h>  // Inclui a biblioteca padrão E/S

int main() {     
  
  int opcao;
  float num1, num2, resultado; 
  char entrada[50];
   // Função principal obrigatória
  do
  {

  printf("\n=== Calculadora ===\n");
    printf("1. Soma\n");
    printf("2. Subtracao\n");
    printf("3. Multiplicacao\n");
    printf("4. Divisao\n");
    printf("5. Sair\n");

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
    }
    
    switch (opcao) {
            case 1:
                resultado = num1 + num2;
                printf("A soma de %.2f + %.2f = %.2f\n", num1, num2, resultado);
                break;
            case 2:
                resultado = num1 - num2;
                printf("A subtracao de %.2f - %.2f = %.2f\n", num1, num2, resultado);
                break;
            case 3:
                resultado = num1 * num2;
                printf("A multiplicacao de %.2f * %.2f é igual a %.2f\n", num1, num2, resultado);
                break;
            case 4:
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("A divisao de %.2f por %.2f é igual a %.2f\n", num1, num2, resultado);
                } else {
                    printf("Erro: Divisao por zero nao permitida.\n");
                }
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opçao invalida. Tente novamente.\n");
    }

  } while (opcao != 5);



  return 0;            // Indica término com sucesso
}
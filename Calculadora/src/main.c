#include <stdio.h>
#include "calc.h"
int main()
{
	int valor, num1, num2;
	do
	{
		printf("\nQual a operacao que voce deseja realizar?\n\nMenu de escolha\n");
		printf("1: Soma\n");
		printf("2: Subtracao\n");
		printf("3: Multiplicacao\n");
		printf("4: Divisao\n");
		printf("\nOperacao desejada: ");
		scanf("%d", &valor);
		if(valor>=1 && valor<=4)
		{
			printf("\nInforme os dois numeros: ");
			scanf("%d %d", &num1, &num2);
		}
		if(valor==1)
			printf("\nSoma de %d + %d = %d\n", num1, num2, soma(num1, num2));
		else if(valor==2)
			printf("\nSubtracao de %d - %d = %d\n", num1, num2, subtracao(num1, num2));
		else if(valor==3)
			printf("\nMultiplicacao de %d * %d = %d\n", num1, num2, mult(num1, num2));
		else if(valor==4)
			printf("\nDivisao de %d / %d = %.2f\n", num1, num2, divisao(num1, num2));
		else
			printf("\nInforme uma operacao valida\n");
		printf("\nDeseja continuar?\n 0: Nao\n 1: Sim\n ");
		scanf("%d", &valor);
	}while(valor);
	printf("\nPrograma Encerrado\n");
	return 0;
}

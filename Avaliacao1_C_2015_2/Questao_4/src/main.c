//ALUNO: PAULO FELIPE FEITOSA DA SILVA
//DUVIDA NESSA QUESTÃO...
//SÃO OS NÚMEROS DA SEQUÊNCIA QUE ESTÃO ENTRE 0 E 10000?
//OU OS 10000 NÚMEROS DA SEQUÊNCIA?

#include <stdio.h>
#define MAX 10000
int main()
{
	int F1=1, F2=1, F3=0;
	printf("%d, %d", F1, F2);
	do
	{
		F3 = F1 + F2;
		F1 = F2;
		F2 = F3;
		if(F3<=MAX)
			printf(", %d", F3);
	}while(F3<=MAX);
	printf("\n");
	return 0;
}

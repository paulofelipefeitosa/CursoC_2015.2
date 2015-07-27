//ALUNO: PAULO FELIPE FEITOSA DA SILVA
#include <stdio.h>
#include "insertsort.h"

int main()
{
	int qntde, i;
	printf("Informe a quantidade de Alunos: ");
	scanf("%d", &qntde);
	getchar();
	aloc(&qntde);
	for(i=0;i<qntde;i++)
		leia(&i);

	insert(&qntde);
	printf("\nMedia da Turma: %.2f\n", media(&qntde));
	imprima(&qntde);
	desaloc();
	return 0;
}

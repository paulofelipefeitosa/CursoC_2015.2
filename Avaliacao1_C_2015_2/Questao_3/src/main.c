//ALUNO: PAULO FELIPE FEITOSA DA SILVA
#include <stdio.h>
int main()
{
	int i, soma=0;
	for(i=0;i<=1000;i++)
	{
		if( ((i%3)==0) && ((i%7)==0) )
			soma+=i;
	}
	printf("Soma dos Multiplos de 3 e de 7 entre 0 a 1000 = %d\n", soma);
	return 0;
}
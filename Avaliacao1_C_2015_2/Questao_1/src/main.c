//ALUNO: PAULO FELIPE FEITOSA DA SILVA
#include <stdio.h>
#include <string.h>
#include "changechar.h"
#define MAX 1000
int main()
{
	char str[MAX]={0};
	printf("Informe a frase: ");
	scanf("%[^\n]s", str);
	int i, topo=0;
	for(i=0;i<strlen(str);i++)
		str[i] = change_char(&str[i]);
	printf("\nFrase corrigida: ");
	for(i=0;i<strlen(str);i++)
		printf("%c", str[i]);
	printf("\n");

	return 0;
}
//ALUNO: PAULO FELIPE FEITOSA DA SILVA
#include <stdio.h>
#include <string.h>
#include "changechar.h"
#define MAX 1000
int main()
{
	char str[MAX]={0}, str1[MAX]={0};
	printf("Informe a frase: ");
	scanf("%[^\n]s", str);
	int i, topo=0;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]==-61)
			continue;
		else
		{
			str1[topo] = change_char(&str[i]);
			topo++;
		}
	}
	str1[topo] = '\0';
	topo++;
	printf("\nFrase corrigida: ");
	for(i=0;i<topo;i++)
		printf("%c", str1[i]);
	printf("\n");

	return 0;
}
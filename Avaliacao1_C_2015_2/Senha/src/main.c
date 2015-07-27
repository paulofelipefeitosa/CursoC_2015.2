//ALUNO: PAULO FELIPE FEITOSA DA SILVA
#include <stdio.h>
#include <string.h>
int main()
{
	char key[] = {"MaStErSuPeRhYpErKeY"};
	char hash[64] = {0};
	char password[32] = {0};

	printf("Informe a hash: ");
	scanf("%[^\n]s", hash);
	int idx, ckey;
	for(idx = (strlen(hash)/2)-1 ; idx>=0 ; idx--)
	{
		ckey = strlen(key) - (idx % strlen(key)) - 1;
		password[idx] = ((hash[(idx*2)+1] - 33)^(key[ckey]+10))-10;
	}
	password[strlen(hash)/2] = '\0';
	printf("\nDecrypt: %s\n", password);
	return 0;
}
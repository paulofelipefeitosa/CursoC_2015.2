//ALUNO: PAULO FELIPE FEITOSA DA SILVA
#include <stdio.h>

#define QNTDE_LAMPS 8
#define MENU1 printf("\nMENU PRINCIPAL:\n\n1 - LIGAR OU DESLIGAR UMA LAMPADA\n2 - CONSULTAR O ESTADO DE UMA LAMPADA\n3 - ENCERRAR O PROGRAMA\n\nOPCAO: ");
#define MENU2 printf("\nCONJUNTO DAS LAMPADAS = {A, B, C, D, E, F, G, H}\n\nPARA LIGAR ~ LAMPADA A - DIGITE A\n\nPARA DESLIGAR ~ LAMPADA a - DIGITE a\n\nLAMPADA DESEJADA: ");
#define MENU3 printf("\nCONJUNTO DAS LAMPADAS = {A, B, C, D, E, F, G, H}\n\nPARA CONSULTAR ~ LAMPADA A - DIGITE A\n\nLAMPADA DESEJADA: ");
#define BACK printf("\n~~~~ VOLTANDO PARA O MENU PRINCIPAL... ~~~~\n");
#define OPINV printf("\n~~~~ OPCAO INVALIDA! TENTE NOVAMENTE! ~~~~\n");
#define END printf("\n~~~~ PROGRAMA ENCERRADO! ~~~~\n");
#define MAISC(A) (A>=65 && A<=72)
#define MINUS(A) (A>=97 && A<=104)
#define ESTADO(A, B) ( (A=='1') ? (printf("\n~~~~ LAMPADA %c - LIGADA ~~~~\n", B) ) : (printf("\n~~~~ LAMPADA %c - DESLIGADA ~~~~\n", B) ) )

int main()
{
	char STATUS_LAMPS[QNTDE_LAMPS]={0}, op;
	do
	{
		MENU1;
		scanf("%c", &op);
		getchar();
		if(op=='1')
		{
			do
			{
				MENU2;
				scanf("%c", &op);
				getchar();
				if(MAISC(op)) 
					STATUS_LAMPS[op-65] = '1';
				if(MINUS(op)) 
					STATUS_LAMPS[op-97] = '0';
				if(!(MAISC(op) || MINUS(op)))
					OPINV;
			}while(!(MAISC(op) || MINUS(op)));
			BACK;
			op='1';
		}
		else if(op=='2')
		{
			do
			{
				MENU3;
				scanf("%c", &op);
				getchar();
				if(MAISC(op)) 
					ESTADO(STATUS_LAMPS[op-65], op);
				else
					OPINV;
			}while(!MAISC(op));
			BACK;
			op='2';
		}
		else if(op>'3' || op<'1')
			OPINV;
	}while(op!='3');
	END;
	return 0;
}

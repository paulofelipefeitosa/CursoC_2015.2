#ifndef insertsort_h
#define insertsort_h

typedef struct
{
	char nome[100];
	float nota;
}ALUNO;

ALUNO *ALUNOS;

void insert(int* QNTDE);
void aloc(int* qntde);
void leia(int* i);
void imprima(int* qntde);
void desaloc();
float media(int* qntde);

#endif

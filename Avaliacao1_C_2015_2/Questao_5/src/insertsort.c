#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "insertsort.h"

void Troca(ALUNO *PTR1, ALUNO *PTR2);

void insert(int* QNTDE)
{
    int i=0, j=1, ult=0, troca=0;
    while(i!=*(QNTDE))
    {
        if((troca==0) && (i<(*(QNTDE)-1)) && (ALUNOS[i].nota < ALUNOS[j].nota))
        {
            Troca(&ALUNOS[i], &ALUNOS[j]);
            ult = i;
            j = i - 1;
            troca++;
        }
        else if((troca>0) && (j>=0) && (ALUNOS[i].nota > ALUNOS[j].nota))
        {
            Troca(&ALUNOS[i], &ALUNOS[j]);
            i--; j--;
            troca++;
        }
        else
        {
            troca = 0;
            i = ult + 1;
            j = i + 1;
            ult = i;
        }
    }
}

void Troca(ALUNO *PTR1, ALUNO *PTR2)
{
    int VALOR = PTR1->nota;
    char name[100] = {0};
    strcpy(name, PTR1->nome);

    PTR1->nota = PTR2->nota;
    strcpy(PTR1->nome, PTR2->nome);
    
    PTR2->nota = VALOR;
    strcpy(PTR2->nome, name);
}

void aloc(int* qntde)
{
    ALUNOS = (ALUNO*) malloc(*(qntde) * sizeof(ALUNO));
}

void desaloc()
{
    free((void*)ALUNOS);
}

void leia(int* i)
{
    printf("Informe o Nome do Aluno %d: ", *i+1);
    scanf("%[^\n]s", ALUNOS[*i].nome);
    printf("Informe a Nota do Aluno %d: ", *i+1);
    scanf("%f", &ALUNOS[*i].nota);
    getchar();
}

void imprima(int* qntde)
{
    int i;
    for(i=0;i<*(qntde);i++)
        printf("\n%s ---> Nota: %.2f\n", ALUNOS[i].nome, ALUNOS[i].nota);
}

float media(int* qntde)
{
    int i;
    float media = 0;
    for(i=0;i<*qntde;i++)
        media+=ALUNOS[i].nota;
    return media / *(qntde);
}

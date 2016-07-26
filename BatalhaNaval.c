#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define N 6

void Imprimir(char [][N]);
void ZeraT(char [][N], char [][N]);
void HH(char [][N]);
void CH(char [][N]);
void HC(char [][N], char [][N]);
void Leia(char [][N]);
void Jogada(char [][N], char [][N], int);
void Aloca(char [][N], int, int, int);
void ImprimirAux(int);
void GerarEspiral(int [][N]);
int AcertouNavio(char [][N], char [][N], int, int, int);
int cont(char [][N]);
int AlocaC(char [][N], int, int, int, int, int);
int Menu();

int tipo, pos, aloc, contjog1 = 0, contjog2 = 0, cont1 = 0, cont2 = 0, contpos = 0;

int main()
{
    printf("\a\t\tIFPB - Campus Joao Pessoa\n");
    printf("\t\tCurso Superior de Engenharia Eletrica\n");
    printf("\t\tDisciplina de Algoritmos e Logica de Programacao\n");
    printf("\t\tProfessor: Erick\n");
    printf("\t\tProva 2: Parte 2, Jogo de Batalha Naval\n");
    printf("\t\tGrupo: Paulo Felipe, Josivaldo Gomes e Marcello Aires\n\n");
    printf("\n--------------------------------------------------------------------------------\n");
    char M[N][N], MB[N][N];
    int i, j, opcao, ME[N][N]={};
    GerarEspiral(ME);
    ZeraT(M, MB);//JOGADOR 1
    opcao = Menu();
    if(opcao==1)
    {
        HH(MB);
        contpos = cont(MB);
        printf("\nSecao de Jogadas do Jogador 1\n\n");
        for(i=0;i<N*N;i++)
        {
            Imprimir(M);
            Jogada(M, MB, 0);
            printf("\nQuantidade de Jogadas: %d\nQuantidade de Acertos: %d\nQuantidade Total de Posicoes de Barco: %d\n\n", contjog1, cont1, contpos);
            if(contpos == cont1)
                break;
        }
        Imprimir(M);
        printf("\n\nSECAO DE JOGADAS DO JOGADOR 1 TERMINADA\n\n");
    }
    else if(opcao==2)
    {
        CH(MB);
        contpos = cont(MB);
        printf("\nSecao de Jogadas do Jogador 1\n\n");
        for(i=0;i<N*N;i++)
        {
            Imprimir(M);
            Jogada(M, MB, 0);
            printf("\nQuantidade de Jogadas: %d\nQuantidade de Acertos: %d\nQuantidade Total de Posicoes de Barco: %d\n\n", contjog1, cont1, contpos);
            if(contpos == cont1)
                break;
        }
        Imprimir(M);
        printf("\n\nSECAO DE JOGADAS DO JOGADOR 1 TERMINADA\n\n");
    }
    else if(opcao==3)
    {
        int X, Y, i, estado = 0, ult=0;
        HC(MB, M);
        contpos = cont(MB);
        for(i=0;i<N*N;i++)
        {
            do
            {
                estado = 0;
                X = (rand()%N);//VAI DE 0 A N-1
                Y = (rand()%N);//VAI DE 0 A N-1
                if(MB[X][Y]=='~' && M[X][Y]=='~')
                {
                    M[X][Y] = '*';
                    contjog1++;
                    estado = 1;
                }
                else if(MB[X][Y]=='B' && M[X][Y]=='~')
                {
                    M[X][Y] = 'X';
                    contjog1++;
                    cont1++;
                    i += AcertouNavio(M, MB, X, Y, 0);
                    estado = 1;
                }
            }while(estado!=1);
            ImprimirAux(0);
            Imprimir(M);
            if(cont1==contpos)
            {
                printf("\n\nSECAO DE JOGADAS DO JOGADOR 1 TERMINADA\n\n");
                break;
            }
        }
    }

    ZeraT(M, MB);//JOGADOR 2
    opcao = Menu();
    if(opcao==1)
    {
        HH(MB);
        contpos = cont(MB);
        printf("\nSecao de Jogadas do Jogador 2\n\n");
        for(i=0;i<N*N;i++)
        {
            Imprimir(M);
            Jogada(M, MB, 1);
            printf("\nQuantidade de Jogadas: %d\nQuantidade de Acertos: %d\nQuantidade Total de Posicoes de Barco: %d\n\n", contjog2, cont2, contpos);
            if(contpos == cont2)
                break;
        }
        Imprimir(M);
        printf("\n\nSECAO DE JOGADAS DO JOGADOR 2 TERMINADA\n\n");
    }
    else if(opcao==2)
    {
        CH(MB);
        contpos = cont(MB);
        printf("\nSecao de Jogadas do Jogador 2\n\n");
        for(i=0;i<N*N;i++)
        {
            Imprimir(M);
            Jogada(M, MB, 1);
            printf("\nQuantidade de Jogadas: %d\nQuantidade de Acertos: %d\nQuantidade Total de Posicoes de Barco: %d\n\n", contjog2, cont2, contpos);
            if(contpos == cont2)
                break;
        }
        Imprimir(M);
        printf("\n\nSECAO DE JOGADAS DO JOGADOR 2 TERMINADA\n\n");
    }
    else if(opcao==3)
    {
        int X, Y, i, estado = 0, ult=0;
        HC(MB, M);
        contpos = cont(MB);
        for(i=0;i<N*N;i++)
        {
            do
            {
                estado = 0;
                X = (rand()%N);//VAI DE 0 A N-1
                Y = (rand()%N);//VAI DE 0 A N-1
                if(MB[X][Y]=='~' && M[X][Y]=='~')
                {
                    M[X][Y] = '*';
                    contjog2++;
                    estado = 1;
                }
                else if(MB[X][Y]=='B' && M[X][Y]=='~')
                {
                    M[X][Y] = 'X';
                    contjog2++;
                    cont2++;
                    i+=AcertouNavio(M, MB, X, Y, 1);
                    estado = 1;
                }
            }while(estado!=1);
            ImprimirAux(1);
            Imprimir(M);
            if(cont2==contpos)
            {
                printf("\n\nSECAO DE JOGADAS DO JOGADOR 2 TERMINADA\n\n");
                break;
            }
        }
    }
    if(contjog1<contjog2)
        printf("\nJOGADOR 1 VENCEU!!!   %d x %d\n\n", contjog1, contjog2);
    else if(contjog1>contjog2)
        printf("\nJOGADOR 2 VENCEU!!!   %d x %d\n\n", contjog2, contjog1);
    else
        printf("\nJOGO EMPATADO!!!      %d x %d\n\n", contjog1, contjog2);
    return 0;
}


void GerarEspiral(int ME[][N])
{
    int i, j, ult=0, num=1, k;
    for(k=0;k<(N/2);k++)
    {
        for(j=ult, i=ult;j<(N-ult);j++, num++)
            ME[i][j] = num;
        for(j=(N-1-ult), i=(ult+1);i<(N-1-ult);i++, num++)
            ME[i][j] = num;
        for(j=(N-1-ult), i=(N-1-ult);j>=ult;j--, num++)
            ME[i][j] = num;
        for(j=ult, i=(N-2-ult);i>=(ult+1);i--, num++)
            ME[i][j] = num;
        ult++;
    }
    if(N%2)
        ME[N/2][N/2] = N*N;
}


void ImprimirAux(int jog)
{
    usleep(999999);
    usleep(999999);
    usleep(999999);
    if(jog==0)
        printf("\nQuantidade de Jogadas: %d\nQuantidade de Acertos: %d\nQuantidade Total de Posicoes de Barco: %d\n\n", contjog1, cont1, contpos);
    else if(jog==1)
        printf("\nQuantidade de Jogadas: %d\nQuantidade de Acertos: %d\nQuantidade Total de Posicoes de Barco: %d\n\n", contjog2, cont2, contpos);
}


int AcertouNavio(char M[][N], char MB[][N], int x, int y, int jog)
{
    int posicao, V[4], topo=0, i, joj = 0, aux=x, auy=y;
    srand(time(NULL));
    if((x-1)>=0 && M[x-1][y]=='~')//POSIÇÕES QUE EU POSSO SORTEAR
    {
        V[topo] = 1;
        topo++;
    }
    if((y-1)>=0 && M[x][y-1]=='~')
    {
        V[topo] = 2;
        topo++;
    }
    if((x+1)<N && M[x+1][y]=='~')
    {
        V[topo] = 3;
        topo++;
    }
    if((y+1)<N && M[x][y+1]=='~')
    {
        V[topo] = 4;
        topo++;
    }
    if(topo!=0)
    {
        posicao = rand()%topo;//DE 0 A TOPO
        if(V[posicao]==1)
        {
            while(1)//VAI IMPLEMENTANDO
            {
                aux--;
                if(aux>=0 && M[aux][auy]=='~')//É UMA JOGADA VÁLIDA?
                {
                    if(jog==0)
                        contjog1++;
                    else if(jog==1)
                        contjog2++;
                    joj++;
                    if(MB[aux][auy]=='B')//CONTINUA, ACERTOU
                    {
                        M[aux][auy] = 'X';
                        if(jog==0)
                            cont1++;
                        else if(jog==1)
                            cont2++;
                        ImprimirAux(jog);
                        Imprimir(M);
                    }
                    else if(MB[aux][auy]=='~')
                    {
                        M[aux][auy] = '*';
                        ImprimirAux(jog);
                        Imprimir(M);
                        joj += AcertouNavio(M, MB, x, y, jog);
                        break;
                    }
                }
                else//NÃO É UMA JOGADA VÁLIDA!
                {
                    joj += AcertouNavio(M, MB, x, y, jog);
                    break;
                }
            }
        }
        else if(V[posicao]==2)
        {
            while(1)//VAI IMPLEMENTANDO
            {
                auy--;
                if(auy>=0 && M[aux][auy]=='~')//É UMA JOGADA VÁLIDA?
                {
                    if(jog==0)
                        contjog1++;
                    else if(jog==1)
                        contjog2++;
                    joj++;
                    if(MB[aux][auy]=='B')//CONTINUA
                    {
                        M[aux][auy] = 'X';
                        if(jog==0)
                            cont1++;
                        else if(jog==1)
                            cont2++;
                        ImprimirAux(jog);
                        Imprimir(M);
                    }
                    else if(MB[aux][auy]=='~')
                    {
                        M[aux][auy] = '*';
                        ImprimirAux(jog);
                        Imprimir(M);
                        joj += AcertouNavio(M, MB, x, y, jog);
                        break;
                    }
                }
                else//NÃO É UMA JOGADA VÁLIDA!
                {
                    joj += AcertouNavio(M, MB, x, y, jog);
                    break;
                }
            }
        }
        else if(V[posicao]==3)
        {
            while(1)//VAI IMPLEMENTANDO
            {
                aux++;
                if(aux<N && M[aux][auy]=='~')//É UMA JOGADA VÁLIDA?
                {
                    if(jog==0)
                        contjog1++;
                    else if(jog==1)
                        contjog2++;
                    joj++;
                    if(MB[aux][auy]=='B')//CONTINUA
                    {
                        M[aux][auy] = 'X';
                        if(jog==0)
                            cont1++;
                        else if(jog==1)
                            cont2++;
                        ImprimirAux(jog);
                        Imprimir(M);
                    }
                    else if(MB[aux][auy]=='~')
                    {
                        M[aux][auy] = '*';
                        ImprimirAux(jog);
                        Imprimir(M);
                        joj += AcertouNavio(M, MB, x, y, jog);
                        break;
                    }
                }
                else//NÃO É UMA JOGADA VÁLIDA!
                {
                    joj += AcertouNavio(M, MB, x, y, jog);
                    break;
                }
            }
        }
        else if(V[posicao]==4)
        {
            while(1)//VAI IMPLEMENTANDO
            {
                auy++;
                if(auy<N && M[aux][auy]=='~')//É UMA JOGADA VÁLIDA?
                {
                    if(jog==0)
                        contjog1++;
                    else if(jog==1)
                        contjog2++;
                    joj++;
                    if(MB[aux][auy]=='B')//CONTINUA
                    {
                        M[aux][auy] = 'X';
                        if(jog==0)
                            cont1++;
                        else if(jog==1)
                            cont2++;
                        ImprimirAux(jog);
                        Imprimir(M);
                    }
                    else if(MB[aux][auy]=='~')
                    {
                        M[aux][auy] = '*';
                        ImprimirAux(jog);
                        Imprimir(M);
                        joj += AcertouNavio(M, MB, x, y, jog);
                        break;
                    }
                }
                else//NÃO É UMA JOGADA VÁLIDA!
                {
                    joj += AcertouNavio(M, MB, x, y, jog);
                    break;
                }
            }
        }
    }
    return joj;
}


int cont(char MB[][N])
{
    int i, j, conta=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(MB[i][j]=='B')
                conta++;
        }
    }
    return conta;
}


void Jogada(char M[][N], char MB[][N], int status)
{
    int X, Y, i, j, estado = 0;
    do
    {
        printf("\nInforme as Coordenadas de Linha e Coluna da Jogada (L, C): ");
        scanf("%d %d", &X, &Y);
        i = X-1;
        j = Y-1;
        if(i<0 || i>=N || j<0 || j>=N)
        {
            printf("\n\nJogada Invalida! Tente Novamente!\n");
            estado = 0;
        }
        else if(M[i][j]=='~')
        {
            if(status == 0)
                contjog1++;
            else if(status == 1)
                contjog2++;
            estado = 1;
            if(MB[i][j]=='B')
            {
                if(status == 0)
                    cont1++;
                else if(status == 1)
                    cont2++;
                M[i][j]='X';
            }
            else if(MB[i][j]=='~')
                M[i][j]='*';
        }
        else
        {
            printf("\nJogada Invalida! Tente Novamente!\n");
            estado = 0;
        }
        printf("\n");
    }while(estado==0);
}


void Leia(char MB[][N])
{
    int i, cont=0;
    printf("\nAlocacao dos Navios nas Posicoes:\n");
    printf("\nMenu de Escolha das Embarcacoes:\n\n1 - Para o Navio do Tipo Porta Avioes (5 Posicoes)\n2 - Para o Navio do Tipo Encouracado (3 Posicoes)\n3 - Para o Navio do Tipo Embarcacao Comum (1 Posicao)\n");

    do
    {
        if(cont==0)
            printf("\nEscolha o Tipo da Embarcacao: ");
        else
            printf("\nNumero Invalido, Tente Novamente: ");
        scanf("%d", &tipo);
        cont++;
    }while(tipo<1 || tipo>3);

    if(tipo!=3)
    {
        printf("\nComo Navio ficara Posicionado:\n\n1 - Verticalmente\n2 - Horizontalmente\n\n");
        cont = 0;
        do
        {
            if(cont==0)
                printf("Informe: ");
            else
                printf("\nNumero Invalido, Tente Novamente: ");
            scanf("%d", &pos);
            cont++;
        }while(pos<1 || pos>2);

        printf("\nComo Navio ira ser Alocado:\n\n");
        if(pos==1)
            printf("Vertical:\n1 - de Baixo para Cima\n2 - de Cima para Baixo\n\n");
        else if(pos==2)
            printf("Horizontal:\n3 - da Esquerda para Direita\n4 - da Direita para a Esquerda\n\n");

        cont = 0;
        do
        {
            if(cont==0)
                printf("Informe: ");
            else
                printf("\nNumero Invalido, Tente Novamente: ");
            scanf("%d", &aloc);
            cont++;
        }while(aloc<1 || aloc>4);

        if(tipo==1)//Navio do Tipo Porta Avioes
        {
            printf("\nNavio do Tipo Porta Avioes:");
            Aloca(MB, 5, pos, aloc);
        }
        else if(tipo==2)//Navio do Tipo Encouracado
        {
            printf("\nNavio do Tipo Encouracado:");
            Aloca(MB, 3, pos, aloc);
        }
    }
    else
    {
        printf("\nNavio do Tipo Embarcacao Comum:");
        Aloca(MB, 1, 1, 1);
    }
}


void Aloca(char MB[][N], int numpos, int pos, int aloc)
{
    int X, Y, k, i, j;
    printf("\n\nInforme as Posicoes da Linha e Coluna onde o Navio Iniciara (L, C): ");
    scanf("%d %d", &X, &Y);
    i = X-1;
    j = Y-1;
    if(numpos==1)
    {
        if(MB[i][j]=='~' && i>=0 && i<N && j>=0 && j<N)
            MB[i][j]='B';
        else
        {
            printf("\n\n\nPosicao invalida! Tente Novamente!\n\n");
            Leia(MB);
        }
    }
    else if(pos==1)//ALOCAÇÃO VERTICAL
    {
        if(aloc==1)//De Baixo para Cima, SENÃO PEDE PRA LER OUTRA VEZ
        {
            if(numpos==3)
            {
                if(MB[i][j]=='~' && MB[i-1][j]=='~' && MB[i-2][j]=='~' && (i-2)>=0 && i<N && j>=0 && j<N)
                {
                    MB[i][j]='B'; MB[i-1][j]='B'; MB[i-2][j]='B';
                }
                else
                {
                    printf("\n\n\nPosicao invalida! Tente Novamente!\n\n");
                    Leia(MB);
                }
            }
            else if(numpos==5)
            {
                if(MB[i][j]=='~' && MB[i-1][j]=='~' && MB[i-2][j]=='~' && MB[i-3][j]=='~' && MB[i-4][j]=='~' && (i-4)>=0 && i<N && j>=0 && j<N)
                {
                    MB[i][j]='B'; MB[i-1][j]='B'; MB[i-2][j]='B'; MB[i-3][j]='B'; MB[i-4][j]='B';
                }
                else
                {
                    printf("\n\n\nPosicao invalida! Tente Novamente!\n\n");
                    Leia(MB);
                }
            }
        }
        else if(aloc==2)//De Cima para Baixo
        {
            if(numpos==3)
            {
                if(MB[i][j]=='~' && MB[i+1][j]=='~' && MB[i+2][j]=='~' && i>=0 && (i+2)<N && j>=0 && j<N)
                {
                    MB[i][j]='B'; MB[i+1][j]='B'; MB[i+2][j]='B';
                }
                else
                {
                    printf("\n\n\nPosicao invalida! Tente Novamente!\n\n");
                    Leia(MB);
                }
            }
            else if(numpos==5)
            {
                if(MB[i][j]=='~' && MB[i+1][j]=='~' && MB[i+2][j]=='~' && MB[i+3][j]=='~' && MB[i+4][j]=='~' && i>=0 && (i+4)<N && j>=0 && j<N)
                {
                    MB[i][j]='B'; MB[i+1][j]='B'; MB[i+2][j]='B'; MB[i+3][j]='B'; MB[i+4][j]='B';
                }
                else
                {
                    printf("\n\n\nPosicao invalida! Tente Novamente!\n\n");
                    Leia(MB);
                }
            }
        }
    }
    else if(pos==2)//ALOCAÇÃO HORIZONTAL
    {
        if(aloc==3)//Da Esquerda para Direita
        {
            if(numpos==3)
            {
                if(MB[i][j]=='~' && MB[i][j+1]=='~' && MB[i][j+2]=='~' && j>=0 && (j+2)<N && i>=0 && i<N)
                {
                    MB[i][j]='B'; MB[i][j+1]='B'; MB[i][j+2]='B';
                }
                else
                {
                    printf("\n\n\nPosicao invalida! Tente Novamente!\n\n");
                    Leia(MB);
                }
            }
            else if(numpos==5)
            {
                if(MB[i][j]=='~' && MB[i][j+1]=='~' && MB[i][j+2]=='~' && MB[i][j+3]=='~' && MB[i][j+4]=='~' && j>=0 && (j+4)<N && i>=0 && i<N)
                {
                    MB[i][j]='B'; MB[i][j+1]='B'; MB[i][j+2]='B'; MB[i][j+3]='B'; MB[i][j+4]='B';
                }
                else
                {
                    printf("\n\n\nPosicao invalida! Tente Novamente!\n\n");
                    Leia(MB);
                }
            }
        }
        else if(aloc==4)//da Direita para Esquerda
        {
            if(numpos==3)
            {
                if(MB[i][j]=='~' && MB[i][j-1]=='~' && MB[i][j-2]=='~' && (j-2)>=0 && j<N && i>=0 && i<N)
                {
                    MB[i][j]='B'; MB[i][j-1]='B'; MB[i][j-2]='B';
                }
                else
                {
                    printf("\n\n\nPosicao invalida! Tente Novamente!\n\n");
                    Leia(MB);
                }
            }
            else if(numpos==5)
            {
                if(MB[i][Y]=='~' && MB[i][j-1]=='~' && MB[i][j-2]=='~' && MB[i][j-3]=='~' && MB[i][j-4]=='~' && (j-4)>=0 && j<N && i>=0 && i<N)
                {
                    MB[i][j]='B'; MB[i][j-1]='B'; MB[i][j-2]='B'; MB[i][j-3]='B'; MB[i][j-4]='B';
                }
                else
                {
                    printf("\n\n\nPosicao invalida! Tente Novamente!\n\n");
                    Leia(MB);
                }
            }
        }
    }
    printf("\n");
    Imprimir(MB);
}


int AlocaC(char MB[][N], int numpos, int pos, int aloc, int X, int Y)
{
    int k, i, j;
    i=X-1;
    j=Y-1;

    if(numpos==1)//TIPO EMBARCAÇÃO COMUM De Baixo para Cima
    {
        if(MB[i][j]=='~')
        {
            MB[i][j]='B';
            return 1;//Alocação deu Certo
        }
        else
            return 0;//Alocação não deu Certo
    }
    else if(pos==1)//ALOCAÇÃO VERTICAL
    {
        if(aloc==1)//De Baixo para Cima, SENÃO PEDE PRA LER OUTRA VEZ
        {
            if(numpos==3)//TIPO ENCOURACADO De Baixo para Cima
            {
                if(MB[i][j]=='~' && MB[i-1][j]=='~' && MB[i-2][j]=='~' && (i-2)>=0)
                {
                    MB[i][j]='B'; MB[i-1][j]='B'; MB[i-2][j]='B';
                    return 1;//Alocação deu Certo
                }
                else
                    return 0;//Alocação não deu Certo
            }
            else if(numpos==5)//TIPO PORTA AVIÃO De Baixo para Cima
            {
                if(MB[i][j]=='~' && MB[i-1][j]=='~' && MB[i-2][j]=='~' && MB[i-3][j]=='~' && MB[i-4][j]=='~' && (i-4)>=0)
                {
                    MB[i][j]='B'; MB[i-1][j]='B'; MB[i-2][j]='B'; MB[i-3][j]='B'; MB[i-4][j]='B';
                    return 1;//Alocação deu Certo
                }
                else
                    return 0;//Alocação não deu Certo
            }
        }
        else if(aloc==2)//De Cima para Baixo
        {
            if(numpos==3)//TIPO ENCOURAÇADO De Cima para Baixo
            {
                if(MB[i][j]=='~' && MB[i+1][j]=='~' && MB[i+2][j]=='~' && (i+2)<N)
                {
                    MB[i][j]='B'; MB[i+1][j]='B'; MB[i+2][j]='B';
                    return 1;//Alocação deu Certo
                }
                else
                    return 0;//Alocação não deu Certo
            }
            else if(numpos==5)//TIPO PORTA AVIÃO De Cima para Baixo
            {
                if(MB[i][j]=='~' && MB[i+1][j]=='~' && MB[i+2][j]=='~' && MB[i+3][j]=='~' && MB[i+4][j]=='~' && (i+4)<N)
                {
                    MB[i][j]='B'; MB[i+1][j]='B'; MB[i+2][j]='B'; MB[i+3][j]='B'; MB[i+4][j]='B';
                    return 1;//Alocação deu Certo
                }
                else
                    return 0;//Alocação não deu Certo
            }
        }
    }
    else if(pos==2)//ALOCAÇÃO HORIZONTAL
    {
        if(aloc==3)//Da Esquerda para Direita
        {
            if(numpos==3)//TIPO ENCOURAÇADO Da Esquerda para Direita
            {
                if(MB[i][j]=='~' && MB[i][j+1]=='~' && MB[i][j+2]=='~' && (j+2)<N)
                {
                    MB[i][j]='B'; MB[i][j+1]='B'; MB[i][j+2]='B';
                    return 1;//Alocação deu Certo
                }
                else
                    return 0;//Alocação não deu Certo
            }
            else if(numpos==5)//TIPO PORTA AVIÃO Da Esquerda para Direita
            {
                if(MB[i][j]=='~' && MB[i][j+1]=='~' && MB[i][j+2]=='~' && MB[i][j+3]=='~' && MB[i][j+4]=='~' && (j+4)<N)
                {
                    MB[i][j]='B'; MB[i][j+1]='B'; MB[i][j+2]='B'; MB[i][j+3]='B'; MB[i][j+4]='B';
                    return 1;//Alocação deu Certo
                }
                else
                    return 0;//Alocação não deu Certo
            }
        }
        else if(aloc==4)//da Direita para Esquerda
        {
            if(numpos==3)//TIPO ENCOURAÇADO da Direita para Esquerda
            {
                if(MB[i][j]=='~' && MB[i][j-1]=='~' && MB[i][j-2]=='~' && (j-2)>=0)
                {
                    MB[i][j]='B'; MB[i][j-1]='B'; MB[i][j-2]='B';
                    return 1;//Alocação deu Certo
                }
                else
                    return 0;//Alocação não deu Certo
            }
            else if(numpos==5)//TIPO PORTA AVIÃO da Direita para Esquerda
            {
                if(MB[i][Y]=='~' && MB[i][j-1]=='~' && MB[i][j-2]=='~' && MB[i][j-3]=='~' && MB[i][j-4]=='~' && (j-4)>=0)
                {
                    MB[i][j]='B'; MB[i][j-1]='B'; MB[i][j-2]='B'; MB[i][j-3]='B'; MB[i][j-4]='B';
                    return 1;//Alocação deu Certo
                }
                else
                    return 0;//Alocação não deu Certo
            }
        }
    }
}


void HH(char MB[][N])//Função Para Posicionar os Barcos, HUMANO PREENCHE
{
    int X, Y, i;
    printf("\nPara cada Tabuleiro Existem 5 Navios\n");
    Imprimir(MB);
    for(i=0;i<5;i++)
        Leia(MB);
    printf("\n");
}


void CH(char MB[][N])//Função Para Posicionar os Barcos, COMPUTADOR PREENCHE
{
    srand(time(NULL));
    int num, num1, i, num2, X, Y, estado=0;
    for(i=0;i<5;i++)
    {
        do
        {
            num = (rand()%3)+1;//TIPO DE EMBARCAÇÃO
            if(num==1)//TIPO PORTA AVIÃO
            {
                num1 = (rand()%2)+1;//POSICIONAMENTO
                if(num1==1)//ALOCADO VERTICALMENTE
                {
                    num2 = (rand()%2)+1;//ALOCAÇÃO
                    X = (rand()%N)+1;
                    Y = (rand()%N)+1;
                    estado = AlocaC(MB, 5, num1, num2, X, Y);
                }
                else if(num1==2)//ALOCADO HORIZONTALMENTE
                {
                    num2 = (rand()%2)+3;//ALOCAÇÃO
                    X = (rand()%N)+1;
                    Y = (rand()%N)+1;
                    estado = AlocaC(MB, 5, num1, num2, X, Y);
                }
            }
            else if(num==2)//TIPO ENCOURACADO
            {
                num1 = (rand()%2)+1;//POSICIONAMENTO
                if(num1==1)//ALOCADO VERTICALMENTE
                {
                    num2 = (rand()%2)+1;//ALOCAÇÃO
                    X = (rand()%N)+1;
                    Y = (rand()%N)+1;
                    estado = AlocaC(MB, 3, num1, num2, X, Y);
                }
                else if(num1==2)//ALOCADO HORIZONTALMENTE
                {
                    num2 = (rand()%2)+3;//ALOCAÇÃO
                    X = (rand()%N)+1;
                    Y = (rand()%N)+1;
                    estado = AlocaC(MB, 3, num1, num2, X, Y);
                }
            }
            else if(num==3)//TIPO EMBARCAÇÃO COMUM
            {
                X = (rand()%N)+1;
                Y = (rand()%N)+1;
                estado = AlocaC(MB, 1, num1, num2, X, Y);
            }
        }while(estado==0);
    }
}


void HC(char MB[][N], char M[][N])//Função Para Posicionar os Barcos, HUMANO PREENCHE
{
    int X, Y, i;
    srand(time(NULL));
    printf("\nPara cada Tabuleiro Existem 5 Navios\n");
    for(i=0;i<5;i++)
        Leia(MB);
    printf("\n");
}


int Menu()
{
    int opcao, cont = 0;
    do
    {
        if(cont==0)
        {
            printf("\nMenu de Escolha do Tipo de Jogo: \n\n");
            printf("1 - Para Humano cria para Humano\n");//CADA HUMANO CRIA UM TABULEIRO PARA UM HUMANO JOGAR
            printf("2 - Para Computador cria para Humano\n");//O COMPUTADOR CRIA UM TABULEIRO PARA UM HUMANO JOGAR
            printf("3 - Para Humano cria para Computador\n\n");//O HUMANO CRIA UM TABULEIRO PARA O COMPUTADOR JOGAR
            printf("Escolha: ");
        }
        else
            printf("Numero Invalido, Tente Novamente: ");
        scanf("%d", &opcao);
        cont++;
    }while(opcao<1 || opcao>3);
    return opcao;
}


void ZeraT(char M[][N], char MB[][N])
{
    int i, j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            M[i][j] = '~';
            MB[i][j] = '~';
        }
    }
}


void Imprimir(char M[][N])
{
    int i, j;
    printf("   ");
    for(i=0;i<N;i++)
        printf("%d  ", i+1);
    printf("\n");
    for(i=0;i<N;i++)
    {
        printf("%d  ", i+1);
        for(j=0;j<N;j++)
        {
            printf("%c  ", M[i][j]);
        }
        printf("\n");
    }
}

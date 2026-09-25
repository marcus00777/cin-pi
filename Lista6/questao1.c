#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ataqueSequencial(char** tabuleiro, int n, int tentativa, int* linha, int* coluna);
void ataqueReverso(char** tabuleiro, int n, int tentativa, int* linha, int* coluna);

int main(){

    int tentativas = 0;  //contagem das tentativas
    int tamtabuleiro; //definir o tamanho do tabuleiro
    int qtdNavios; //quantiddes de navios

    int colunaNavio;
    int linhaNavio;

    int estrategia;

    scanf("%d", &tamtabuleiro);
    scanf("%d", &qtdNavios);

    char **matriz = (char **) calloc(tamtabuleiro, sizeof(char *));

    if(matriz == NULL){
        return 1;
    }

    //alocação das linhas da matriz
    for (int i = 0; i < tamtabuleiro; i++)
    {
        matriz[i] = (char *) calloc(tamtabuleiro, sizeof(char));

        if(matriz[i] == NULL){

            for (int j = 0; j < i; j++)
            {
                free(matriz[j]);
            }

            free(matriz);
            return 1;
        }
    }
    
    //preencher a matriz com ~
    for (int k = 0; k < tamtabuleiro; k++)
    {
        for (int i = 0; i < tamtabuleiro; i++)
        {
            matriz[k][i] = '~';
        }
        
    }
    
    //adicionando Navios
    for (int w = 0; w < qtdNavios; w++)
    {
        scanf("%d %d", &colunaNavio, &linhaNavio);
        matriz[linhaNavio][colunaNavio] = 'N';
    }

    scanf("%d", &estrategia);
    
    void (*escolha[2])(char**, int, int, int*, int*) = {ataqueSequencial, ataqueReverso};

    int naviosAtc = 0;
    int linhaAtc, colunaAtc;

    do {
        tentativas++;
        escolha[estrategia - 1](matriz, tamtabuleiro, tentativas, &linhaAtc, &colunaAtc);

        if (matriz[linhaAtc][colunaAtc] == 'X')
        {
            naviosAtc++;
        }
        
    }while (naviosAtc < qtdNavios);
    
    printf("Tentativas ate vencer: %d\n", tentativas);

    //exibição da matriz
    printf("Tabuleiro final:\n");
    for (int j = 0; j < tamtabuleiro; j++)
    {
        for (int i = 0; i < tamtabuleiro; i++)
        {
            printf("%c ", matriz[j][i]);
        }
        printf("\n");
    }
    

    //Liberando memoria
    for (int i = 0; i < tamtabuleiro; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;
}

void ataqueSequencial(char** tabuleiro, int n, int tentativa, int* linha, int* coluna){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O'){

                if(tabuleiro[i][j] == 'N'){
                    tabuleiro[i][j] = 'X';
                }
                else{
                    tabuleiro[i][j] = 'O';
                }

                *linha = i;
                *coluna = j;
                return;
            }   
        }
        
    }
    
}


void ataqueReverso(char** tabuleiro, int n, int tentativa, int* linha, int* coluna){

     for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n- 1; j >= 0; j--)
        {
            if(tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O'){

                if(tabuleiro[i][j] == 'N'){
                    tabuleiro[i][j] = 'X';
                }
                else{
                    tabuleiro[i][j] = 'O';
                }

                *linha = i;
                *coluna = j;
                return;
            }   
        }
        
    }
    
}
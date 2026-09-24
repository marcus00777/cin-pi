#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int tentativas = 0;  //contagem das tentativas
    int tamtabuleiro; //definir o tamanho do tabuleiro
    int qtdNavios; //quantiddes de navios

    int colunaNavio;
    int linhaNavio;

    int estrategia;

    scanf("%d", &tamtabuleiro);
    scanf("%d", &qtdNavios);
    scanf("%d %d", &colunaNavio, &linhaNavio);
    scanf("%d", &estrategia);

    char **matriz = (char **) calloc(tamtabuleiro, sizeof(char *));

    if(matriz == NULL){
        return 1;
    }

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
    
    for (int k = 0; k < tamtabuleiro; k++)
    {
        for (int i = 0; i < tamtabuleiro; i++)
        {
            matriz[k][i] = '~';
        }
        
    }
    
    for (int i = 0; i < qtdNavios; i++)
    {
        for (int j = 0; j < qtdNavios; j++)
        {
            matriz[linhaNavio][colunaNavio] = 'N';
        }
        
    }
    

    //exibição da matriz
    for (int j = 0; j < tamtabuleiro; j++)
    {
        for (int i = 0; i < tamtabuleiro; i++)
        {
            printf("%c", matriz[j][i]);
        }
        printf("\n");
    }
    

    //Liberando memoria
    for (int i = 0; i < tamtabuleiro; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}
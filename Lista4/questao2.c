#include <stdio.h>

int main(){

    int linha, coluna;
    scanf("%d %d", &linha, &coluna);

    char matriz[linha][coluna];

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            scanf(" %c", &matriz[i][j]);
        }
        
    }

    int num;
    scanf("%d", &num);
    char procurar[200];

    for (int i = 0; i < num; i++)
    {
        scanf(" %s", procurar[i]);
    }
    

    int dl[] = {-1, 1,  0, 0, -1, -1,  1, 1};
    int dc[] = { 0, 0, -1, 1, -1,  1, -1, 1};

    
    
}
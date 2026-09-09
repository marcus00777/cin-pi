#include <stdio.h>
#include <string.h>

 void laserMatriz(int l, int c, char matriz[l][c], int posx, int posy, int x, int y);

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
    
    //posição inicial do laser
    int posx, posy;
    scanf("%d %d", &posx, &posy);
    char direcao[10];
    scanf(" %s", direcao);

    int x = 0; //cima baixo
    int y = 0; //direita esquerda

    if(strcmp(direcao, "DIREITA") == 0){
        x = 0; //não altera
        y = 1; //anda de um em um

    }else if(strcmp(direcao, "CIMA") == 0){
        x = -1; 
        y = 0;
        
    }else if(strcmp(direcao, "ESQUERDA") == 0){
        x = 0;
        y = -1;

    }else if(strcmp(direcao, "BAIXO") == 0){
        x = 1; 
        y = 0;

    }
 
    laserMatriz(linha, coluna, matriz, posx, posy, x, y);

}

 void laserMatriz(int l, int c, char matriz[l][c], int posx, int posy,int x, int y){

    while (posx >= 0 && posx < l && posy >= 0 && posy < c)
    {   
        if(matriz[posx][posy] == '.'){
            matriz[posx][posy] = '*';
        }
        else if(matriz[posx][posy] == '/'){
            int aux = x;
            x = -y;
            y = -aux;
        }  
        else if(matriz[posx][posy] == '\\'){
            int aux = x;
            x = y;
            y = aux;
        }  
        else if(matriz[posx][posy] == '#'){
            break; //encerra;
        }

        posx += x;
        posy += y;
    }

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%c", matriz[i][j]);
        }
       printf("\n"); 
    }
    
 }
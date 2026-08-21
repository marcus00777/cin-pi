#include <stdio.h>

int main(){

    int tamanho_grid = 0;

    scanf("%d", &tamanho_grid);

    //Montando o grid
    for (int i = 0; i < tamanho_grid; i++)
    {
        for (int j = 0; j < tamanho_grid; j++)
        {
            //Se for impar
            if (tamanho_grid % 2 != 0){
                
                //Preenchendo grid com #
                if (j != (tamanho_grid/2)){

                    printf("#");
                }

                if (j == (tamanho_grid /2)){

                    printf(".");
                }
                
            }

            //Se for par
            if (tamanho_grid % 2 == 0){
                
                //Preenchendo grid com #
                 if (j != (tamanho_grid/2) - 1){

                    printf("#");
                }
                
                if (j == (tamanho_grid /2) - 1){
                    
                    printf(".");
                }
            }     
        }
        printf("\n");
    }
    
}
#include <stdio.h>

int main(){

    int tamanho_grid = 0;

    scanf("%d", &tamanho_grid);

    int grid_c = tamanho_grid / 2;

    //Montando o grid
    for (int i = 0; i < tamanho_grid; i++)
    {
        for (int j = 0; j < tamanho_grid; j++)
        {
            //Se for impar
            if(tamanho_grid % 2 != 0){

                if (j >= grid_c - i && j <= grid_c + i && i <= grid_c){

                    printf(".");

                }else{

                    if (j == grid_c){
                        printf(".");
                    }else{
                        printf("#");
                    }
                }
            }

            //Se for par
             else{

                if (j >= (grid_c - 1) - i && j <= (grid_c - 1) + i && i < grid_c){

                    printf(".");

                }else{

                    if (j == grid_c - 1){
                        printf(".");
                    }else{
                        printf("#");
                    }
                }
            }

        }
        printf("\n");
    }
    
}
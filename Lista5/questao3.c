#include <stdio.h>
#include <stdlib.h>

void operacao(int *valor1, int *valor2, char *comando, int *Resultados, int *pos){

    if(*comando == '+'){
        *(Resultados + *pos) = *valor1 + *valor2;
        printf("Resultado Operação %d %c %d: %d\n", *valor1, *comando, *valor2, *(Resultados + *pos));
        (*pos)++;

    }else if(*comando == '-'){
        *(Resultados + *pos) = *valor1 - *valor2;
        printf("Resultado Operação %d %c %d: %d\n", *valor1, *comando, *valor2, *(Resultados + *pos));
        (*pos)++;

    }else if(*comando == '*'){
        *(Resultados + *pos) = *valor1 * *valor2;
        printf("Resultado Operação %d %c %d: %d\n", *valor1, *comando, *valor2, *(Resultados + *pos));
        (*pos)++;

    }else if(*comando == '/'){

        if(*valor2 != 0){
            *(Resultados + *pos) = *valor1 / *valor2;
            printf("Resultado Operação %d %c %d: %d\n", *valor1, *comando, *valor2, *(Resultados + *pos));
            (*pos)++;
        }else{
            printf("Operação Inválida! Próxima!\n");
        }
    }else{
        printf("Operação Inválida! Próxima!\n");
    }

}

int main(){
    
    printf("=Iniciando Cálculos=\n");

    int tam = 0;
    int capacidade = 1;

    int * Resultados = (int*) calloc(1, sizeof(int));

    //se der erro retorna 1
    if(Resultados == NULL){
        return 1;
    }

    int num1;
    int num2;
    char caractere;

    while (scanf("%d %c %d", &num1, &caractere, &num2) != EOF)
    {
        
        if(tam == capacidade){
            capacidade *= 2;

            int *temp = (int *) realloc(Resultados, capacidade * sizeof(int));

            if(temp == NULL){
                free(Resultados);
                return 1;
            }

            Resultados = temp;
        }

        operacao(&num1, &num2, &caractere, Resultados, &tam);

    }
    
    printf("\nOperações concluídas:\n");
    for (int i = 0; i < tam; i++)
    {
        printf("Resultado Operação %d: %d\n", i+1, *(Resultados + i));
    }
    

    free(Resultados);
    Resultados = NULL;
}
#include <stdio.h>
#include <stdlib.h>

int *insere(int *vetor, int *qtd, int *capacidade, int num){

    if(*qtd == *capacidade){

        *capacidade *= 2;

        int *temp = (int *) realloc(vetor, *capacidade * sizeof(int));

        if(temp == NULL){
            return vetor;
        }

        vetor = temp;
    }

    *(vetor + *qtd) = num;
    (*qtd)++;

    return vetor;
}

void exibirVet(int *vet, int tam){

    int alteracao = 1;

    while (alteracao)
    {
        alteracao = 0;

        //compara cada num com  o proximo
        for (int i = 0; i < tam - 1; i++)
        {
            if(*(vet + i) == *(vet + 1 + i)){
                *(vet + i) = *(vet + i) + 1;
               
                for (int j = i + 1; j < tam - 1; j++)
                {
                    *(vet + j) = *(vet + j + 1);
                }

                tam--;
                alteracao = 1;
                break;
            }      
        }
        
    }
    
    printf("Slimes restantes: ");
    for (int k = 0; k < tam; k++)
    {
        printf("%d ", *(vet + k));
    }
    
}

int main(){

    int tam = 0;
    int capacidade = 1;

    int *vet = (int *) malloc(capacidade * sizeof(int));

    if(vet == NULL){
        return 1;
    }

    int num = 0;
    int flag = 0;

    while (flag != 1 && num != -1)
    {
        scanf("%d", &num);

        if(num == -1){
            flag = 1;
        }

        if(num != -1){

            vet = insere(vet, &tam, &capacidade, num);
        }
    }
    

    exibirVet(vet, tam);
    

    free(vet);
    vet = NULL;
    return 0;
}
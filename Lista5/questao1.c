#include <stdio.h>
#include <stdlib.h>

int *insere(int *vetor, int *quantidade, int *capacidade, int valor){

    //verifica se o tamanho do vetor é igual a capacidade max, se for expandi a memoria  
    if(*quantidade == *capacidade){

        *capacidade *= 2;

        int *temp = (int *) realloc(vetor, *capacidade * sizeof(int));

        if(temp == NULL){
            return vetor;  //Se não for possivel a apenas retorna o vetor
        }

        vetor = temp;
    }

    *(vetor + *quantidade) = valor;  //adiciona o valor no final
    (*quantidade)++; 

    return vetor;
}

void imprime_invertido(int *vetor, int quantidade){

    for (int i = 0; i < quantidade/2; i++)
    {
        int aux = *(vetor + i);
        *(vetor + i) = *(vetor + quantidade - 1 - i);
        *(vetor + quantidade - 1 - i) = aux;
    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("%d ", *(vetor + i));
    }
    
    
}

int main(){

    int quantidade = 0;
    int capacidade = 1;

    int *vet = (int *) malloc(capacidade * sizeof(int));

    if(vet == NULL){
        return 1;
    }

    int num = 0;
    int flag = 0;
    int verifica = 0; 

    while (num != -1 && flag != 1)
    {
        scanf("%d", &num);
        verifica++;

        if(num == -1){   
            flag = 1;
        }

        if(num != -1){
            vet = insere(vet, &quantidade, &capacidade, num);
        }
    }

    if(flag == 1 && verifica == 1){
        printf("\n");
    }

    imprime_invertido(vet, quantidade);
    
    free(vet);
    vet = NULL;

    return 0;
}
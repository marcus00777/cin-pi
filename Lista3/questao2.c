#include <stdio.h>

void recebeVet(int vetor[], int tam);

int main(){

    int qtdElementos;
    scanf("%d", &qtdElementos);

    int vet[qtdElementos];
    recebeVet(vet, qtdElementos);

    for (int i = 0; i < qtdElementos; i++)
    {
        printf("%d ", vet[i]);
    }
    
    
}
//função para receber o vetor
void recebeVet(int vetor[], int tam){

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
}
#include <stdio.h>

void codificaFun(int vet[], int tam){

    
}

int main(){

    int n;
    char escolha;

    scanf("%d", &n);

    int vetor[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    scanf(" %c", &escolha);

    if(escolha == 'C'){

        codificaFun(vetor, n);
    }
    
}
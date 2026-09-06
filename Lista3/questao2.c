#include <stdio.h>

void recebeVet(int vetor[], int tam);
void inverteVet(int vetor[], int tam);
void imprimirVet(int vet[], int tam);

int main(){

    int qtdElementos;
    scanf("%d", &qtdElementos);

    int vet[qtdElementos];
    recebeVet(vet, qtdElementos);
    
    inverteVet(vet, qtdElementos);

    imprimirVet(vet, qtdElementos);
    
    
}
//função para receber o vetor
void recebeVet(int vetor[], int tam){

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
}

void inverteVet(int vetor[], int tam){

    int i = 0;
    int zero = 1; //posição do zero no vetor
    int somaVet = 0; //para verificar se tem zero no vetor

    while (i < tam && zero != 0)
    {
        if(vetor[i] == 0){

            zero = i;
            i++;
        }

        i++;
        somaVet++;
    }
    
    for (int i = 0; i < zero / 2; i++)
    {
        int aux = vetor[i];
        vetor[i] = vetor[zero - 1 - i];
        vetor[zero - 1 - i] = aux ;
    }

    int primeiroElem = zero + 1; //posição do primeiro elemento depois do zero
    int ultimoElemt = tam - 1;

    for (int i = 0; i < (ultimoElemt  - primeiroElem + 1) / 2; i++)
    {
        int aux = vetor[primeiroElem + i];
        vetor[primeiroElem + i] = vetor[ultimoElemt - i];
        vetor[ultimoElemt - i] = aux ;
    }

    if(somaVet > 0){

        for (int i = 0; i < zero / 2; i++)
    {
        int aux = vetor[i];
        vetor[i] = vetor[zero - 1 - i];
        vetor[zero - 1 - i] = aux ;
    }
    }
}

void imprimirVet(int vet[], int tam){

    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
}
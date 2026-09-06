#include <stdio.h>

void recebeVet(int vetor[], int tam);
void inverteVet(int vetor[], int ini, int fim);
void imprimirVet(int vet[], int tam);

int main(){

    int qtdElementos;
    scanf("%d", &qtdElementos);

    int vet[qtdElementos];
    recebeVet(vet, qtdElementos);
    
    int inicioV = 0;

    for (int i = 0; i < qtdElementos; i++)
    {
        //encontra a posição do zero para inverter até aquela parte do vetor, ou todo se não tiver 0
        if(vet[i] == 0 || i == qtdElementos - 1){

            int fimV;
            if(vet[i] == 0){

                fimV = i-1;   //recebe o índice antes do zero que será invertido

            }else{
                fimV = i; 
            }

            inverteVet(vet, inicioV, fimV);
            inicioV = i + 1; //vai para o próximo bloco
        }
    }
    

    imprimirVet(vet, qtdElementos);
    
    
}
//função para receber o vetor
void recebeVet(int vetor[], int tam){

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
}

void inverteVet(int vetor[], int ini, int fim){

    for (int i = 0; i < (fim - ini + 1) / 2; i++)
    {
        int aux = vetor[ini + i];
        vetor[ini + i] = vetor[fim - i];
        vetor[fim - i] = aux;
    }
    
    
}

void imprimirVet(int vet[], int tam){

    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
}
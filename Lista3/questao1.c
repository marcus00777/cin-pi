#include <stdio.h>

void codificaFun(int vet[], int tam, int deslocamento);
void decodificaFun(int vet[], int tam, int deslocamento);
int verificaFun(int vet[], int tam);

int main(){

    int n;
    char escolha;
    
    //tam vetor
    scanf("%d", &n);

    int vetor[n];

    //preenche vetor de tam n
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int deslocamento;
    scanf("%d", &deslocamento);

    scanf(" %c", &escolha);

    if(escolha == 'C'){

        codificaFun(vetor, n, deslocamento);
        int verificacao = verificaFun(vetor, n);

        printf("Código codificado: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", vetor[i]);
        }

        printf("\nVerificador: %d\n", verificacao);
        
        if(verificacao >= 0 && verificacao <= 2){

            printf("Nível de segurança: BAIXO");
        }else if(verificacao >= 3 && verificacao <= 6){

            printf("Nível de segurança: MÉDIO");
        }else if(verificacao >= 7 && verificacao <= 9){

            printf("Nível de segurança: ALTO");
        }
        

    }else if(escolha == 'D'){

        decodificaFun(vetor, n, deslocamento);
        int verificacao = verificaFun(vetor, n);

        printf("Código decodificado: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", vetor[i]);
        }

        printf("\nVerificador: %d\n", verificacao);
        
        if(verificacao >= 0 && verificacao <= 2){

            printf("Nível de segurança: BAIXO");
        }else if(verificacao >= 3 && verificacao <= 6){

            printf("Nível de segurança: MÉDIO");
        }else if(verificacao >= 7 && verificacao <= 9){

            printf("Nível de segurança: ALTO");
        }
    }
    
}

void codificaFun(int vet[], int tam, int deslocamento){

    for (int i = 0; i < tam; i++)
    {
        int soma = vet[i] + deslocamento;
        if(soma <= 9){
            vet[i] = soma;

        }else{
            soma = soma % 10;
            vet[i] = soma;
        }
    }
    
}

void decodificaFun(int vet[], int tam, int deslocamento){

    for (int i = 0; i < tam; i++)
    {
        int subtrai = vet[i] - deslocamento;

        if(subtrai >= 0){

            vet[i] = subtrai;

        }else{

            vet[i] = subtrai + 10;
        }
    }
    
}

int verificaFun(int vet[], int tam){

    int soma = 0;
    for (int i = 0; i < tam; i++)
    {
        soma += vet[i];
    }

    return soma % 10;
    
}

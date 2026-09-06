#include <stdio.h>
#include <string.h>
#define tamV 1000

int main(void){
    
    char frase[tamV];
    float nota = 10;
    int erros = 0;

    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0'; //final da str

    int tam = strlen(frase);

    //verifica se a primeira letra da frase é maiuscula
    if(frase[0] >= 'a' && frase[0] <= 'z'){          
        nota -= 0.5;
        erros++;
        frase[0] = frase[0] - 32;  //corrige a letra correspondente na tabela ASCII
    }

     if(frase[tam - 1] != '.'){
        nota -= 0.5;
        erros++;
        frase[tam] = '.'; //ponto final no final da frase 
        frase[tam + 1] = '\0'; //final da str que foi substituido por .
    }

    int maiuscula = 0;
    for (int i = 0; i < tam - 1; i++)
    {   
        //Se caso tenha palavra apos o ponto deverá ser maiuscula
        if(frase[i] == '.'){
            maiuscula++;
        
        //Se a palavra for diferente do espaço e depois de um ponto deverá ser maiuscula, se não deverá ser minuscula
        }else if(frase[i] != ' '){

            if(maiuscula > 0){
                if(frase[i] >= 'a' && frase[i] <= 'z'){
                nota -= 0.5;
                erros++;
                frase[i] = frase[i] - 32;
                }
                maiuscula = 0;

            }else{
                if(frase[i] >= 'A' && frase[i] <= 'Z'){
                nota -= 0.5;
                erros++;
                frase[i] = frase[i] + 32;
                }
            }
        }
    }

    if(strlen(frase) > 0){
        printf("Texto corrigido: %s\n", frase);
        printf("Total de palavras: %d\n", strlen(frase) - 1);
        printf("Total de erros: %d\n", erros);
        printf("Nota: %.1f\n", nota);

    }else{
        nota = 0;
        printf("Texto vazio! Nota: %.1f", nota);
    }

}
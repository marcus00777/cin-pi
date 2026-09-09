#include <stdio.h>
#include <string.h>
#define tamV 1000

int main(void){
    
    char frase[tamV];
    float nota = 10;
    int erros = 0;
    int letra_minus = 0;

    fgets(frase, tamV, stdin);
    frase[strcspn(frase, "\n")] = '\0'; //final da str

    int tam = strlen(frase);

    //verifica se a primeira letra da frase é maiuscula
    if(frase[0] >= 'a' && frase[0] <= 'z'){          
        nota -= 0.5;
        erros++;
        letra_minus++;
        frase[0] = frase[0] - 32;  //corrige a letra correspondente na tabela ASCII
    }
    if(tam > 0){
        if(frase[tam - 1] != '.'){

            if(frase[tam - 1] <= 32 && frase[tam - 1] >= 64){
                nota -= 0.5;
                erros++;
                frase[tam] = '.'; //ponto final no final da frase 
                frase[tam + 1] = '\0'; //final da str que foi substituido por .
            }    
        }
    }


    int maiuscula = 0;
    for (int i = 1; i < tam - 1; i++)
    {   
        //Se caso tenha palavra apos o ponto deverá ser maiuscula
        if(frase[i] == '.' || frase[i] == '?' || frase[i] == '!'){
            maiuscula++;
        
        //Se a palavra for diferente do espaço e depois de um ponto deverá ser maiuscula, se não deverá ser minuscula
        }else if(frase[i] != ' '){

            if(maiuscula > 0){
                if(frase[i] >= 'a' && frase[i] <= 'z'){
                nota -= 0.5;
                erros++;
                letra_minus++;
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

    int palavra = 0;
    int fim = 0; 
    for (int i = 0; i < strlen(frase); i++)
    {
        //analisa cada caractere, se for um caractere da palavra a variavel recebe um e para a até fim atualizar no final do caractere
        if(frase[i] != '\n' && frase[i] != ' '){

            if(fim == 0){
                palavra++;
                fim = 1;
            }
        }else{
            fim = 0;
        }

    }

    if(strlen(frase) > 0 && erros < 20){
        printf("Texto corrigido:\n");
        printf("%s\n", frase);
        printf("Frases que iniciavam com letra minúscula: %d\n", letra_minus);
        printf("Total de palavras: %d\n", palavra);
        printf("Total de erros: %d\n", erros);
        printf("Nota: %.1f\n", nota);

    }else if(strlen(frase) > 0 && erros >= 20){

        nota = 0;
        printf("Texto corrigido:\n");
        printf("%s\n", frase);
        printf("Frases que iniciavam com letra minúscula: %d\n", letra_minus);
        printf("Total de palavras: %d\n", palavra);
        printf("Total de erros: %d\n", erros);
        printf("Nota: %.1f\n", nota);

    }else{
        nota = 0;
        printf("Texto vazio! Nota: %.1f", nota);
    }

}
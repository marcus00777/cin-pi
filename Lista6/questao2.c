#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tam 100

int main(){

    int linhas = 1; int quantidadePalavra = 0;

    char **inventario = (char **) malloc(linhas * sizeof(char *));

    if(inventario == NULL){
        return 1;
    }

    char temporario[tam];
    int pos = 0;

    char palavra;
    while (scanf("%c", &palavra) != EOF)
    {
        if(palavra != '\n' && palavra != '\t'){
            temporario[pos] = palavra;
            pos++;

        }else if(pos > 0){
            temporario[pos] = '\0';

             //verificação do espaço reservado para as palavras
            if(quantidadePalavra == linhas){

                linhas *= 2;

                char **temp = (char **) realloc(inventario, linhas * sizeof(char *));

                if(temp == NULL){

                    for (int i = 0; i < quantidadePalavra; i++)
                    {
                        free(inventario[i]);
                    }
                    free(inventario);
                    return 1;
                    
                }
                inventario = temp;
            }

            inventario[quantidadePalavra] = (char *) malloc((pos + 1) * sizeof(char));

            if(inventario[quantidadePalavra] == NULL){
                return 1;
            }

            strcpy(inventario[quantidadePalavra], temporario);
            printf("Sucesso! Mais um item pra colecao: %s\n", inventario[quantidadePalavra]);

            quantidadePalavra++;
            pos = 0;
        }

    }

    //para a última palavra
    if (pos > 0) {
        temporario[pos] = '\0';

        if(quantidadePalavra == linhas){
            linhas++;
            char **temp = (char **) realloc(inventario, linhas * sizeof(char *));
            if(temp != NULL){

                inventario = temp;}
        }

        inventario[quantidadePalavra] = (char *) malloc((pos + 1) * sizeof(char));

        if(inventario[quantidadePalavra] != NULL){
            strcpy(inventario[quantidadePalavra], temporario);
            printf("Sucesso! Mais um item pra colecao: %s\n", inventario[quantidadePalavra]);

            quantidadePalavra++;
        }
    }
    
    for (int i = 0; i < quantidadePalavra; i++)
    {
        printf("%d. %s\n", i+1, inventario[i]);
    }

    printf("O que vou fazer com tudo isso?\n");
    
    for (int i = 0; i < quantidadePalavra; i++)
    {
        free(inventario[i]);
    }
    free(inventario);
    inventario = NULL;

    return 0;
    
}
#include <stdio.h>

int main(){

    char escolha;
    int N;
    int energia = 10;

    //Enquanto a energia for maior que 0 verifica a escolha  
    while (energia > 0)
    {
        //Brincar ou alimentar o pou
        scanf("%c", &escolha);

        //Número N de energia que será consumida ou restaurada 
        scanf("%d", &N);

        if (N >= 1 && N <= 4){

            //Se a escolha for alimentar
            if (escolha == 'a'){

                //Verifica se a energia é menor que 10 para que possa alimentar
                if (energia < 10){
                    for (int i = 0; i < N; i++)
                    {
                        printf("Alimento %d foi consumido.\n", i+1);
                    }

                    energia += N;
                    printf("%d de energia recuperado! Meu total agora é %d.\n", N, energia);

                }else{
                    printf("O Pou está muito gordinho... ele precisa brincar!\n");
                }
            
            //Se a escolha for brincar
            }else if (escolha == 'b'){

                if (N == 1){
                    printf("Queimei meus neurônios em Memory!\n");
                    energia -= N;
                }else if (N == 2){
                    printf("Novo recorde em Free Fall!\n");
                    energia -= N;
                }else if (N == 3){
                    printf("Cliff Jump é demais!\n");
                    energia -= N;
                }else if (N == 4){
                    printf("Sky Jump é o clássico!\n");
                    energia -= N;
                }
            }
        }   
    }
    
    printf("CONGRATURATION. THIS STORY IS HAPPY END. THANK YOU.\n");
}
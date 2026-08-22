#include <stdio.h>

int main(){

    int quantidade_cupom, numero_cupom;
    int comum = 0;
    int premiado = 0;

    scanf("%d", &quantidade_cupom);

    if (quantidade_cupom >= 1 || quantidade_cupom <= 100){

        //repete até a quantidade de cupons acabar
        for (int i = 0; i < quantidade_cupom; i++)
        {
            //Número do cupom
            scanf("%d", &numero_cupom);

            int impares = 0;
            int pares = 0;
            int total = 0;
            int P = 0;
            int C = 0;

            //verifica se o número do cupom está no intervalo válid o
            if (numero_cupom >= 10 || numero_cupom <= 99999999){

                //Enquanto o número do cupom for maior que zero ele executa a verificação dos algarismos 
                while (numero_cupom > 0)
                {
                    //pega o último elemento e verifica
                    int ultimo = numero_cupom % 10;

                    //se for par o dobro
                    if (ultimo % 2 == 0){
                        
                        pares += 1;
                        total += ultimo * 2;

                    }else{
                        //Se impar o triplo
                        impares += 1;
                        total += ultimo * 3;
                    }

                    //pega o restante dos algarismos sem o último para analisar novamente
                    numero_cupom = numero_cupom / 10;
                    
                }
                
                //Mais algarismos par, acrescenta 5 ao total
                if (pares > impares){

                    total += 5;

                }else if (impares > pares){
                    //Mais algarismos impares, acresecnta 3 ao total
                    total += 3;

                }else{
                    //iguais acresecnta 1 ao total
                    total += 1;
                }

                //classificando os cupons
                if(total % 10 == 0){
                    P += 1;
                    premiado += 1;
                }else{
                    C += 1;
                    comum += 1;
                }

            }

            if(P > C){

                printf("%d PREMIADO\n", total);

            }else if (C > P){

                printf("%d COMUM\n", total);

            }else{

                printf("%d EMPATE\n", total);
            }

        }
    
    }

    if(premiado > comum){

        printf("Premiados: %d\n", premiado);
        printf("Comuns: %d\n", comum);
        printf("Resultado: PROMOCAO\n");

    }else if (comum > premiado){

        printf("Premiados: %d\n", premiado);
        printf("Comuns: %d\n", comum);
        printf("Resultado: NORMAL\n");

    }else{

        printf("Premiados: %d\n", premiado);
        printf("Comuns: %d\n", comum);
        printf("Resultado: EMPATE\n");
    }

    
}
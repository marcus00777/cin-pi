#include <stdio.h>

int main(){

    int dinheiro_rebeca = 3;
    int dinheiro, x, y, z, arrecadado_rebeca;
    float a, b, c;

    scanf("%d" "%d" "%d" "%d", &dinheiro, &x, &y, &z);

    if (x <= 100 && y <= 100 && z <= 100){

        a = dinheiro * x/100.0;
        b = dinheiro * y/100.0;
        c = dinheiro * z/100.0;

        //Se a divisão for inteira 
        if (a == (int)a && b == (int)b && c == (int)c && a + b + c <= dinheiro){

            printf("Cada homem ficou com %.0f, %.0f e %.0f reais, respectivamente.\n", a, b, c);

            arrecadado_rebeca = dinheiro - (a + b + c);
            if (arrecadado_rebeca + dinheiro_rebeca >= 7){
                printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir na noite passada!\n");
            }else{
                printf("E parece que Rebeka vai ter que voltar andando...\n");
            }
        }//Se a divisão não for inteira
        else if (a != (int)a && b != (int)b && c != (int)c){
            
            //Adicionando 1 ao dinheiro do prêmio
            dinheiro += 1;
            dinheiro_rebeca -= 1;
            
            a = dinheiro * x/100.0;
            b = dinheiro * y/100.0;
            c = dinheiro * z/100.0;

            arrecadado_rebeca = dinheiro - (a + b + c);

            if (a == (int)a && b == (int)b && c == (int)c && a + b + c <= dinheiro && arrecadado_rebeca >= 2){
                
                printf("Cada homem ficou com %.0f, %.0f e %.0f reais, respectivamente.\n", a, b, c);

                if (arrecadado_rebeca + dinheiro_rebeca >= 7){
                printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir na noite passada!\n");
                }else{
                    printf("E parece que Rebeka vai ter que voltar andando...\n");
                }
            }else if (a != (int)a && b != (int)b && c != (int)c){
            
                //Adicionando 2 ao dinheiro do prêmio
                dinheiro -= 1;
                dinheiro += 2;
                dinheiro_rebeca += 1;
                dinheiro_rebeca -= 2;
                
                a = dinheiro * x/100.0;
                b = dinheiro * y/100.0;
                c = dinheiro * z/100.0;

                arrecadado_rebeca = dinheiro - (a + b + c);

                
                //Caso a divisão seja inteira
                if (a == (int)a && b == (int)b && c == (int)c && a + b + c <= dinheiro && arrecadado_rebeca >= 3){
                    
                    char letra1, letra2, letra3;
                    int soma;
                    scanf(" %c", &letra1);
                    scanf(" %c", &letra2);
                    scanf(" %c", &letra3);
                    
                    //Convertendo os caracteres
                    int conversao1 = letra1 - 'a' + 1;
                    int conversao2 = letra2 - 'a' + 1;
                    int conversao3 = letra3 - 'a' + 1;

                    soma = conversao1 + conversao2 + conversao3;

                    printf("Cada homem ficou com %.0f, %.0f e %.0f reais, respectivamente.\n", a, b, c);
                    printf("%d\n", soma);
                    
                    if (arrecadado_rebeca + dinheiro_rebeca >= 7){
                    printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir na noite passada!\n");
                    }else{
                        printf("E parece que Rebeka vai ter que voltar andando...\n");
                    }

                //Caso a divisão não seja inteira
                }else if (a != (int)a && b != (int)b && c != (int)c){
                    
                    //Adicionando 3 ao dinheiro do prêmio
                    dinheiro -= 2;
                    dinheiro += 3;
                    dinheiro_rebeca += 2;
                    dinheiro_rebeca -= 3;
                    
                    a = dinheiro * x/100.0;
                    b = dinheiro * y/100.0;
                    c = dinheiro * z/100.0;

                    arrecadado_rebeca = dinheiro - (a + b + c);

                    //Se a divisão for inteira 
                    if (a == (int)a && b == (int)b && c == (int)c && a + b + c <= dinheiro && arrecadado_rebeca >= 4){
                    
                        int idade1, idade2, idade3;
                        int soma_parcelas = 0;
                        scanf("%d" "%d" "%d", &idade1, &idade2, &idade3);
                        
                        //Soma das parcelas
                        if (idade1 % 3 == 0 && idade2 % 3 == 0 && idade3 % 3 == 0){
                            soma_parcelas += (idade1 / 3) + (idade2 / 3) + (idade3 / 3); 
                        }else if (idade1 % 3 == 0 && idade2 % 3 == 0 && idade3 % 3 != 0){
                            soma_parcelas += (idade1 / 3) + (idade2 / 3);
                        }else if (idade1 % 3 == 0 && idade2 % 3 != 0 && idade3 % 3 == 0){
                            soma_parcelas += (idade1 / 3) + (idade3 / 3);
                        }else if (idade1 % 3 != 0 && idade2 % 3 == 0 && idade3 % 3 == 0){
                            soma_parcelas += (idade3 / 3) + (idade2 / 3);
                        }else if (idade1 % 3 == 0 && idade2 % 3 != 0 && idade3 % 3 != 0){
                            soma_parcelas += (idade1 / 3);
                        }else if (idade1 % 3 != 0 && idade2 % 3 == 0 && idade3 % 3 != 0){
                            soma_parcelas += (idade2 / 3);
                        }else if (idade1 % 3 != 0 && idade2 % 3 != 0 && idade3 % 3 == 0){
                            soma_parcelas += (idade3 / 3);
                        }

                        if (soma_parcelas > 0){

                            printf("Cada homem ficou com %.0f, %.0f e %.0f reais, respectivamente.\n", a, b, c);
                            printf("%d\n", soma_parcelas);

                            if (arrecadado_rebeca + dinheiro_rebeca >= 7){
                            printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir na noite passada!\n");
                            }else{
                                printf("E parece que Rebeka vai ter que voltar andando...\n");
                            }

                        }else{
                            printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
                            printf("E parece que Rebeka vai ter que voltar andando...\n");
                        }

                    //Caso a divisão não seja inteira e Rebeca não consiga ajudar
                    }else{
                        printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
                        printf("E parece que Rebeka vai ter que voltar andando...\n");
                    }
    
    //Se a porcetagem for maior que 100
    }else{
        printf("Nao foi dessa vez que Rebeka pode ajudar...\n");    
    }
}
        }
    }
}
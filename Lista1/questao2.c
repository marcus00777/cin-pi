#include <stdio.h>

int main(){

    int dia, mes, ano, ultimo_digito, digito1, digito2;

    scanf("%d" "%d" "%d", &dia, &mes, &ano);

    if (dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && ano >= 1900 && ano <= 2100){

        //ano bissexto divisiveis por 100 e 400
        if (ano % 100 == 0 && ano % 400 == 0){

            if (mes != 2 && mes != 4 && mes != 6 && mes != 9 && mes != 11){
                printf("Data valida");
            }else if (mes == 2 && dia <= 29){
                printf("Data valida");
            }else if (mes == 4 && mes == 6 && mes == 9 && mes == 11 && dia <= 30){
                printf("Data valida");
            }
            else{
                printf("Data invalida");
            }
        }

        //ano bissexto divisiveis por 4
        else if (ano % 4 == 0 && ano % 100 != 0){

            if (mes != 2 && mes != 4 && mes != 6 && mes != 9 && mes != 11){
                printf("Data valida");
            }else if (mes == 2 && dia <= 29){
                printf("Data valida");
            }else if (mes == 4 && mes == 6 && mes == 9 && mes == 11 && dia <= 30){
                printf("Data valida");
            }
            else{
                printf("Data invalida");
            }
        }

        //anos não bissexto
        else{
            if (mes != 2 && mes != 4 && mes != 6 && mes != 9 && mes != 11){
                printf("Data valida");
            }else if (mes == 2 && dia <= 28){
                printf("Data valida");
            }else if (mes == 4 && mes == 6 && mes == 9 && mes == 11 && dia <= 30){
                printf("Data valida");
            }
            else{
                printf("Data invalida");
            }
        }

    }else{
        printf("Data invalida");
    }
}
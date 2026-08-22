#include <stdio.h>

#define infracao1 100
#define infracao2 200
#define infracao3 300
#define infracao4 1000
#define vel_max 100


int main(){

    int carros, pontos_estrada;
    int arrecadados_multas = 0;
    int pontos_carteira = 0;

    scanf("%d" "%d", &carros, &pontos_estrada);

    //Vai percorrer a quantidade de carros que são analisados no dia
    for (int i = 0; i < carros; i++)
    {
        float hora_anterior = 0;
        int min_anterior = 0;
        float km_anterior = 0;

        int multas = 0;

        float hora;
        int min;
        float km;
      
        //Vai percorrer os pontos da estrada em que o carro passou
        for (int j = 0; j < pontos_estrada; j++)
        {
            scanf("%f", &hora);
            scanf("%d", &min);
            scanf("%f", &km);

            hora += min/60.0;

            float vel_media = 0.0;
            
            if (km >= km_anterior){
                vel_media = (km - km_anterior) / (hora - hora_anterior);
            }else if (km_anterior > km){
                vel_media = (km_anterior - km) / (hora - hora_anterior);
            }

            if (vel_media > vel_max){

                multas += 1;
            }

            hora_anterior = hora;
            min_anterior = min;
            km_anterior = km;
        }

        if (multas == 1){
            arrecadados_multas += infracao1;
        }else if (multas == 2){
            arrecadados_multas += infracao1 + infracao2;
        }else if (multas == 3){
            arrecadados_multas += infracao1 + infracao2 + infracao3;
        }else if (multas >= 4){
            arrecadados_multas += infracao1 + infracao2 + infracao3 + infracao4;
            pontos_carteira += 1;
        }
        
    }
    
printf("Arrecadacao Multas: %d\n", arrecadados_multas);
printf("Carros com ponto na carteira: %d\n", pontos_carteira);

}
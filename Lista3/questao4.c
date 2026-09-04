#include <stdio.h>
#define caract 4

void ler_dataset(float caule[], float folha[], float raiz[], float broto[], int rotulos[], int n);
void calcular_centroides(float caule[], float folha[], float raiz[], float broto[], int rotulos[], int n, float centroide_caule[], float centroide_folha[], float centroide_raiz[], float centroide_broto[]);

int main(){

    int qtdTreino;
    scanf("%d", &qtdTreino);

    //vetores das plantas treino    
   float caule[qtdTreino], folha[qtdTreino], raiz[qtdTreino], broto[qtdTreino]; 
   int rotulos[qtdTreino];

   //Centroides das plantas treino
   float centroide_caule[3], centroide_folha[3], centroide_raiz[3], centroide_broto[3];

   //recebe as informações das plantas treino
   ler_dataset(caule, folha, raiz, broto, rotulos, qtdTreino);
   calcular_centroides(caule, folha, raiz, broto, rotulos, qtdTreino, centroide_caule, centroide_folha, centroide_raiz, centroide_broto);



   //------------------Parte teste dos vetores-----------------------
   printf("\n");
   for (int i = 0; i < qtdTreino; i++)
   {
        printf("%.1f %.1f %.1f %.1f %d\n", caule[i], folha[i], raiz[i], broto[i], rotulos[i]);
        printf("%.1f %.1f %.1f\n", centroide_caule[i]);
        printf("%.1f %.1f %.1f\n", centroide_folha[i]);
        printf("%.1f %.1f %.1f\n", centroide_raiz[i]);
        printf("%.1f %.1f %.1f\n", centroide_broto[i]);
   }
   //-----------------Parte teste dos vetores----------------------------
   
}

void ler_dataset(float caule[], float folha[], float raiz[], float broto[], int rotulos[], int n){

    for (int i = 0; i < n; i++)
    {   
        //recebe os dados e salva nos respectivos vetores
        scanf("%f %f %f %f", &caule[i], &folha[i], &raiz[i], &broto[i]);
        scanf("%d", &rotulos[i]);
    }
    
}

void calcular_centroides(float caule[], float folha[], float raiz[], float broto[], int rotulos[], int n, float centroide_caule[], float centroide_folha[], float centroide_raiz[], float centroide_broto[]){

    int rAnter = rotulos[0];
    int r = rotulos[0];

    int anteri = rotulos[0];
    int atual;

    int plantas = 0;
    int indice = 0;
    
    //descobrir a qtd de Palntas da mesma especie
    while (r == rAnter)
    {
        r = rotulos[indice];
        plantas++;

        rAnter = r;
        indice++;
    }
    
    for (int i = 0; i < n; i++)
    {
        float mediaC, mediaF, mediaR, mediaB, somaC, somaF, somaR, somaB;

        atual = rotulos[i];

        if(atual == anteri){

            somaC += caule[i];
            somaF += folha[i];
            somaR += raiz[i];
            somaB += broto[i];

            mediaC = somaC / plantas;
            mediaF = somaF / plantas;
            mediaR = somaR / plantas;
            mediaB = somaB / plantas;

            centroide_caule[i] = mediaC;
            centroide_folha[i] = mediaF;
            centroide_raiz[i] = mediaR;
            centroide_broto[i] = mediaB;

        }else{

            anteri = atual;
        }
    }
    
}
 
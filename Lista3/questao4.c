#include <stdio.h>
#define caract 4

void ler_dataset(float caule[], float folha[], float raiz[], float broto[], int rotulos[], int n);

int main(){

    int qtdTreino;
    scanf("%d", &qtdTreino);

    //vetores das plantas treino
   float caule[qtdTreino], folha[qtdTreino], raiz[qtdTreino], broto[qtdTreino]; 
   int rotulos[qtdTreino];
   float centroide_caule[caract], centroide_folha[caract], centroide_raiz[caract], centroide_broto[caract];

   //recebe as informações das plantas treino
   ler_dataset(caule, folha, raiz, broto, rotulos, qtdTreino);



   //------------------Parte teste dos vetores-----------------------
   printf("\n");
   for (int i = 0; i < qtdTreino; i++)
   {
        printf("%.1f %.1f %.1f %.1f %d\n", caule[i], folha[i], raiz[i], broto[i], rotulos[i]);
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
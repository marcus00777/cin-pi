#include <stdio.h>
#define caract 4

void ler_dataset(float caule[], float folha[], float raiz[], float broto[], int rotulos[], int n);
void calcular_centroides(float caule[], float folha[], float raiz[], float broto[], int rotulos[], int n, float centroide_caule[], float centroide_folha[], float centroide_raiz[], float centroide_broto[]);
float distancia_quadrados(float caule, float folha, float raiz, float broto, float centroide_caule, float centroide_folha, float centroide_raiz, float centroide_broto);
int classificar(float caule, float folha, float raiz, float broto, float centroide_caule[], float centroide_folha[], float centroide_raiz[], float centroide_broto[]);
void classificar_conjunto(float caule[], float folha[], float raiz[], float broto[], int n, float centroide_caule[], float centroide_folha[], float centroide_raiz[], float centroide_broto[], int previstos[]);
void imprimir_especie(int classe);
void imprimir_previsoes(int previstos[], int n);
float calcular_acuracia(int previstos[], int reais[], int n);

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

    int qtdTeste;
    scanf("%d", &qtdTeste);

    //vetores das plantas testes
    float cauleTeste[qtdTeste], folhaTeste[qtdTeste], raizTeste[qtdTeste], brotoTeste[qtdTeste]; 
    int rotulosTeste[qtdTeste]; //me fornece as classificações corretas das plantas

    //recebe as informações das plantas testes
    ler_dataset(cauleTeste, folhaTeste, raizTeste, brotoTeste, rotulosTeste, qtdTeste);
    int previstos[qtdTeste];

    classificar_conjunto(cauleTeste, folhaTeste, raizTeste, brotoTeste, qtdTeste, centroide_caule, centroide_folha, centroide_raiz, centroide_broto, previstos);
    imprimir_previsoes(previstos, qtdTeste);
    
    float acuracia = calcular_acuracia(previstos, rotulosTeste, qtdTeste);
    printf("Acuracia: %.2f%%\n", acuracia);
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

    int anteri = rotulos[0];
    int atual;

    float mediaC, mediaF, mediaR, mediaB; 
    float somaC = 0, somaF = 0, somaR = 0, somaB = 0;

    int plantas = 0;
    int posCentreoide = 0;
    int indice = 0;
    
    for (int i = 0; i < n; i++)
    {
        //Ao mudar a planta calcula a media e atualiza as variáveis
        if(rotulos[i] != rAnter){

            mediaC = somaC / plantas;
            mediaF = somaF / plantas;
            mediaR = somaR / plantas;
            mediaB = somaB / plantas;

            centroide_caule[posCentreoide] = mediaC;
            centroide_folha[posCentreoide] = mediaF;
            centroide_raiz[posCentreoide] = mediaR;
            centroide_broto[posCentreoide] = mediaB;

            posCentreoide++;
            somaB = 0, somaC = 0, somaF = 0, somaR = 0;
            plantas = 0;
            rAnter = rotulos[i];           
        }

        //soma as caracteristicas das plantas
        somaC += caule[i];
        somaF += folha[i];
        somaR += raiz[i];
        somaB += broto[i];
        plantas++;
    
    }

    //calcular a última os dados da última planta
    if(plantas > 0){

        mediaC = somaC / plantas;
        mediaF = somaF / plantas;
        mediaR = somaR / plantas;
        mediaB = somaB / plantas;

        centroide_caule[posCentreoide] = mediaC;
        centroide_folha[posCentreoide] = mediaF;
        centroide_raiz[posCentreoide] = mediaR;
        centroide_broto[posCentreoide] = mediaB;
    }
}

//Função para calcular a distância ao quadrado
float distancia_quadrados(float caule, float folha, float raiz, float broto, float centroide_caule, float centroide_folha, float centroide_raiz, float centroide_broto){

    float distancia = 0;

    distancia = (caule - centroide_caule) * (caule - centroide_caule) + (folha - centroide_folha) * (folha - centroide_folha) + (raiz - centroide_raiz) * (raiz - centroide_raiz) + (broto - centroide_broto) * (broto - centroide_broto);
     
    return distancia;
    
}

int classificar(float caule, float folha, float raiz, float broto, float centroide_caule[], float centroide_folha[], float centroide_raiz[], float centroide_broto[]){

    float menorDistan = -1;
    int classificacao = -1;

    for (int j = 0; j < 3; j++)
    {
        float d = distancia_quadrados(caule, folha, raiz, broto, centroide_caule[j], centroide_folha[j], centroide_raiz[j], centroide_broto[j]);
        
        if(j == 0 || d < menorDistan){
            menorDistan = d;
            classificacao = j;
        }
    }
    return classificacao;
}

void classificar_conjunto(float caule[], float folha[], float raiz[], float broto[], int n, float centroide_caule[], float centroide_folha[], float centroide_raiz[], float centroide_broto[], int previstos[]){

    int classificacao;
    for (int i = 0; i < n; i++)
    {
        classificacao = classificar(caule[i], folha[i], raiz[i], broto[i], centroide_caule, centroide_folha, centroide_raiz, centroide_broto);

        previstos[i] = classificacao;
    }
    
}

void imprimir_especie(int classe){

    if(classe == 0){
        printf("Lunaria");
    }else if(classe == 1){
        printf("Ignea");
    }else if(classe == 2){
        printf("Bruma");
    }
}

void imprimir_previsoes(int previstos[], int n){

    for (int i = 0; i < n; i++)
    {
        printf("Amostra %d: ", i+1);
        imprimir_especie(previstos[i]);
        printf("\n");
    }
    
}

float calcular_acuracia(int previstos[], int reais[], int n){

    float somaAcuracia = 0;
    float acuracia;

    for (int i = 0; i < n; i++)
    {
        if(previstos[i] == reais[i]){
            somaAcuracia++;
        }
    }
    return somaAcuracia/n * 100;
    
}
#include <stdio.h>

void caminhoColeta(int tam, int matriz[tam][tam], int posx, int posy, int qtdFrutas);

int main() {
    printf("Inicializando analise do movimento.\n");

    int tamTabuleiro;
    scanf("%d", &tamTabuleiro);

    int posx = tamTabuleiro / 2;
    int posy = tamTabuleiro / 2;

    int qtdFrutas;
    scanf("%d", &qtdFrutas);

    int tempX[qtdFrutas], tempY[qtdFrutas];
    int frutaDI = tamTabuleiro; 

    //descobrir a maior dimensão
    for (int i = 0; i < qtdFrutas; i++) {
        scanf(" (%d,%d)", &tempX[i], &tempY[i]);
        if (tempX[i] >= frutaDI) frutaDI = tempX[i] + 1;
        if (tempY[i] >= frutaDI) frutaDI = tempY[i] + 1;
    }

    //tamanho da matriz de acordo com as frutas digitadas
    int tabuleiro[frutaDI][frutaDI];
    for (int i = 0; i < frutaDI; i++) {
        for (int j = 0; j < frutaDI; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //matriz das frutas
    for (int i = 0; i < qtdFrutas; i++) {
        tabuleiro[tempX[i]][tempY[i]] = 2;
    }

    caminhoColeta(frutaDI, tabuleiro, posx, posy, qtdFrutas);

    return 0;
}

void caminhoColeta(int tam, int matriz[tam][tam], int posx, int posy, int qtdFrutas){
    int caminhos = 0;
    int tamanhoCobra = 1;

    for(int k = 0; k < qtdFrutas; k++) {
        int menorDist = 999999;
        int maisproxX = -1, maisproxY = -1;

        //busca a fruta mais próxima no tabuleiro
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {

                if (matriz[i][j] == 2) {

                    int dx, dy;

                    if (posx > i) {
                        dx = posx - i;
                    } else {
                        dx = i - posx;
                    }

                    if (posy > j) {
                        dy = posy - j;
                    } else {
                        dy = j - posy;
                    }

                    int dist = dx + dy;

                    if (dist < menorDist) {
                        menorDist = dist;
                        maisproxX = i;
                        maisproxY = j;
                    }
                }
            }
        }

        if (maisproxX != -1) {
            posx = maisproxX;
            posy = maisproxY;
            caminhos += menorDist;
            tamanhoCobra++;
            matriz[maisproxX][maisproxY] = 0; // Remove a fruta do mapa

            printf("Fruta coletada, tamanho atual: %d e %d movimentos ate o momento.\n", tamanhoCobra, caminhos);
        }
    }

    printf("Interessante o comportamento, foram %d movimentos para coletar tudo. Eu não podia ser mais craque, agora e bom eu voltar para os tickets.\n", caminhos);
}
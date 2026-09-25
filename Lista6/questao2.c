#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*Acao_t)(int estado_atual, int *energia, void *payload, void *matriz, int *linhas, int *colunas);

int ignorar(int estado_atual, int *energia, void *payload, void *matriz, int *linhas, int *colunas);
int deslocar(int estado_atual, int *energia, void *payload, void *matriz, int *linhas, int *colunas);
int minerar(int estado_atual, int *energia, void *payload, void *matriz, int *linhas, int *colunas);
int transmitir(int estado_atual, int *energia, void *payload, void *matriz, int *linhas, int *colunas);
int clonar(int estado_atual, int *energia, void *payload, void *matriz, int *linhas, int *colunas);

//função para mapear o caractere ao ponteiro da ação
Acao_t obterAcao(char codigo) {
    switch (codigo) {
        case 'D': return deslocar;
        case 'M': return minerar;
        case 'T': return transmitir;
        case 'C': return clonar;
        case 'I':
        default:  return ignorar;
    }
}

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2){
        return 1;
    }

    int Q;
    if (scanf("%d", &Q) != 1){
        return 1;
    }

    int linhas = N;
    int colunas = M;

    //alocando matriz
    Acao_t **matriz = (Acao_t **) malloc(linhas * sizeof(Acao_t *));
    if (matriz == NULL){ 
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (Acao_t *) malloc(colunas * sizeof(Acao_t));
        
        if (matriz[i] == NULL){

            for (int j = 0; j < i; j++)
            {
                free(matriz[j]);
            }
            free(matriz);
            return 1;
        }
        
    }

     // Inicialização de toda a matriz com a ação 'Ignorar'
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = ignorar;
        }
    }
    

    //leitura e gravação das regras
    for (int k = 0; k < Q; k++) {
        int e, ev;
        char cod;
        scanf("%d %d %c", &e, &ev, &cod);
        if (e >= 0 && e < linhas && ev >= 0 && ev < colunas) {
            matriz[e][ev] = obterAcao(cod);
        }
    }

    int estado_atual, energia;
    scanf("%d %d", &estado_atual, &energia);

    int evento;
    char tipo_dado;

    while (scanf("%d %c", &evento, &tipo_dado) == 2) {

        int val_int = 0;
        char val_str[256];
        void *payload = NULL;

        //leitura do payload
        if (tipo_dado == 'I') {
            scanf("%d", &val_int);
            payload = &val_int;
        } else if (tipo_dado == 'S') {
            scanf("%255s", val_str);
            payload = val_str;
        }

        if (evento >= 0 && evento < colunas) {
            estado_atual = matriz[estado_atual][evento](estado_atual, &energia, payload, matriz, &linhas, &colunas);
        }

        printf("[CLONE] Evento: %d | Energia: %d | Novo Estado: %d\n", evento, energia, estado_atual);
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;

    return 0;
}

int ignorar(int estado_atual, int *energia, void *payload, void *matriz, int *linhas, int *colunas) {
    (void)energia;
    (void)payload;
    (void)matriz;
    (void)linhas;
    (void)colunas;
    return estado_atual;
}

int deslocar(int estado_atual, int *energia, void *payload, void *matriz, int *linhas, int *colunas) {
    (void)matriz;
    (void)linhas;
    (void)colunas;
    int consumo = *((int *)payload);
    *energia -= consumo;
    if (*energia < 0) {
        *energia = 0;
        return 2; // Estado de Emergência
    }
    return estado_atual;
}

int minerar(int estado_atual, int *energia, void *payload, void *matriz, int *linhas, int *colunas) {
    (void)estado_atual;
    (void)matriz;
    (void)linhas;
    (void)colunas;
    int ganho = *((int *)payload);
    *energia += ganho;
    return 1; // Estado Em Operação
}


int transmitir(int estado_atual, int *energia, void *payload, void *matriz, int *linhas, int *colunas) {
    (void)matriz;
    (void)linhas;
    (void)colunas;
    char *mensagem = (char *)payload;
    printf("[TRANSMISSAO] %s\n", mensagem);
    *energia -= 5;
    if (*energia < 0) {
        *energia = 0;
    }
    return estado_atual;
}

int clonar(int estado_atual, int *energia, void *payload, void *matriz, int *linhas, int *colunas) {
    if (*energia < 70) {
        printf("[SISTEMA] Falha na clonagem: energia insuficiente\n");
        return estado_atual;
    }

    *energia -= 70;
    int expansao = *((int *)payload);
    Acao_t **grid = (Acao_t **)matriz;
    int novas_colunas = *colunas + expansao;

    // Redimensiona as colunas de cada linha da matriz
    for (int i = 0; i < *linhas; i++) {
        Acao_t *nova_linha = (Acao_t *) realloc(grid[i], novas_colunas * sizeof(Acao_t));
        if (nova_linha != NULL) {
            grid[i] = nova_linha;

            for (int j = *colunas; j < novas_colunas; j++) {
                grid[i][j] = ignorar;
            }
        }
    }

    *colunas = novas_colunas;
    printf("[SISTEMA] Sonda clonada e matriz expandida para %d eventos\n", *colunas);
    return 0;
}
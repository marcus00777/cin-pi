#include <stdio.h>

int main(){

    int v1, v2, v3, d, d1, d2, soma_direto, soma_P2;

    scanf("%d %d %d %d", &v1, &v2, &v3, &d);

    //O resto da divisão por 10 é o último dígito do número
    //E o resultado da divisão por 10 é o primeiro dígito do número
    d1 = d / 10;
    d2 = d % 10;

    //Energia
    soma_direto = v1 + v3;
    soma_P2 = v1 + v2 + v3;

    //Atributos do código vital
    if (d1 > d2){
        
        soma_direto += d1 - d2;
    }else if (d1 < d2){
        
        soma_P2 += d2 - d1;
    }else{
        soma_direto += d1 + d2;
        soma_P2 += d1 + d2;
    }

    //Prints do caminho direto
    if (soma_direto > soma_P2 && soma_direto > 30){
        printf("Caminho: direto. Xupenio aprova! Nível: ELITE.");
    }else if (soma_direto > soma_P2 && soma_direto >= 10 && soma_direto <= 30){
        printf("Caminho: direto. Boa caminhada! Nível: SÓLIDO.");
    }else if (soma_direto > soma_P2 && soma_direto >= 0 && soma_direto <= 9){
        printf("Caminho: direto. Passou por pouco. Nível: BÁSICO.");
    }else if (soma_direto > soma_P2 && soma_direto < 0){
        printf("Caminho: direto. Xupenio reprova. Nível: CRÍTICO.");
    }

    //Prints do caminho passando pelo P2
    if ((soma_P2 > soma_direto || soma_P2 == soma_direto) && soma_P2 > 30){
        printf("Caminho: P2. Xupenio aprova! Nível: ELITE.");
    }else if ((soma_P2 > soma_direto || soma_P2 == soma_direto) && soma_P2 >= 10 && soma_P2 <= 30){
        printf("Caminho: P2. Boa caminhada! Nível: SÓLIDO.");
    }else if ((soma_P2 > soma_direto || soma_P2 == soma_direto) && soma_P2 >= 0 && soma_P2 <= 9){
        printf("Caminho: P2. Passou por pouco. Nível: BÁSICO.");
    }else if ((soma_P2 > soma_direto || soma_P2 == soma_direto) && soma_P2 < 0){
        printf("Caminho: P2. Xupenio reprova. Nível: CRÍTICO.");
    }

    return 0;
}


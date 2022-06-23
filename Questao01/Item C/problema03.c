/*
* PROBLEMA 03: Faça um programa que cadastre 10 números, ordene-os e em
* seguida encontre e mostre (Dica: Use C, Python ou Ruby):
*
*   I  - O menor número e quantas vezes ele aparece no vetor;
*   II - O maior número e quantas vezes ele aparece no vetor;
*
* Método do Insertion Sort foi utilizado para resolver esse problema.
*/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int v[]) {
    int i, j, x;

    for (i = 1; i < 10; i++) {
        x = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > x) {
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = x;
    }
}

int main() {
    int vetor[10];

    for (int i = 0; i < 10; i++) {
        printf("Informe o %dª numero: ", i+1);
        scanf("%d", &vetor[i]);
    }
    printf("\n");

    insertionSort(vetor);

    int menor = vetor[0];
    int maior = vetor[9];

    int qtdeMenor = 0, qtdeMaior = 1;

    for (int j = 0; j < 10; j++) {
        printf("%d\t", vetor[j]);
        if (menor == vetor[j]) 
            qtdeMenor++;
        if (maior == vetor[j])
            qtdeMaior++;
    }
    printf("\n");

    printf("O menor numero: %d\n", menor);
    printf("Quantidade de vezes que ele aparece: %d\n", qtdeMenor);
    printf("O maior numero: %d\n", maior);
    printf("Quantidade de vezes que ele aparece: %d\n", qtdeMenor);

    return 1;    
}
/*
* Instituo Federal do Ceará - IFCE
* Campus: Tianguá
* Curso: Bacharelado em Ciência da Computação
* Disciplina: Construção e Análise de Algoritmos
* Professor: Adonias Caetano de Oliveira
* Assunto: Métodos de Ordenação
*
* Equipe:
*       -> Francinilson Rodrigues Lima
*       -> Ricardo Martins Cordeiro
*        
* PROBLEMA 03: Faça um programa que cadastre 10 números, ordene-os e em
* seguida encontre e mostre (Dica: Use C, Python ou Ruby):
*
*   I  - O menor número e quantas vezes ele aparece no vetor;
*   II - O maior número e quantas vezes ele aparece no vetor;
*
* Método do Counting Sort foi utilizado para resolver esse problema.
*/

#include <stdio.h>
#include <string.h>

int maiorElemento(int vetor[]) {
    int maior = 0;

    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            maior = vetor[i];
        } else {
            if (vetor[i] > maior) {
                maior = vetor[i];
            }
        }
    }
    
    return maior;
}

int quantidadeMaiorElemento(int vetor[]) {
    int qtde = 0;
    int maior = maiorElemento(vetor);

    for (int i = 0; i < 10; i++) {
        if (vetor[i] == maior)
            qtde++;
    }
    
    return qtde;
}

int menorElemento(int vetor[]) {
    int menor = 0;

    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            menor = vetor[i];
        } else {
            if (vetor[i] < menor) {
                menor = vetor[i];
            }
        }
    }
    
    return menor;
}

int quantidadeMenorElemento(int vetor[]) {
    int qtde = 0;
    int menor = menorElemento(vetor);

    for (int i = 0; i < 10; i++) {
        if (vetor[i] == menor)
            qtde++;
    }
    
    return qtde;
}

void countingSort(int vetorA[], int n) {

    int k = maiorElemento(vetorA);
    int vetorB[n];
    int vetorC[k+1];
    int i = 0;

    for (i = 0; i < n; i++) {
        vetorB[i] = 0;
    }

    for (i = 0; i < k; i++) {
        vetorC[i] = 0;
    }

    for (i = 0; i < n; i++) {
        vetorC[vetorA[i]-1]++;
    }

    for (i = 1; i < k; i++) {
        vetorC[i] += vetorC[i-1];
    }

    for (i = n-1; i >= 0; i--) {
        vetorB[vetorC[vetorA[i]-1]-1] = vetorA[i];
        vetorC[vetorA[i]-1]--;
    }

    for (i = 0; i < n; i++) {
        vetorA[i] = vetorB[i];
    }
}

void imprimirLinha() {
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void imprimirVetor(int vetor[]) {
    for (int i = 0; i < 10; i++) {
        printf("%d\t", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[10];

    for (int i = 0; i < 10; i++) {
        printf("Informe o %dª numero: ", i+1);
        scanf("%d", &vetor[i]);
    }

    imprimirLinha();

    countingSort(vetor, 10);

    imprimirVetor(vetor);

    imprimirLinha();

    printf("O menor numero: %d\n", menorElemento(vetor));
    printf("Quantidade de vezes que ele aparece: %d\n", quantidadeMenorElemento(vetor));
    printf("O maior numero: %d\n", maiorElemento(vetor));
    printf("Quantidade de vezes que ele aparece: %d\n", quantidadeMaiorElemento(vetor));

    return 1;    
}
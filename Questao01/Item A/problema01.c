/*
* PROBLEMA 01: Considere a seguinte estrutura na linguagem C:
*
* struct pessoa {
*    int Matricula;
*    char Nome[30]
*    float Nota;   
* }
*
* Implemente uma função em C que dado um array de tamanho N dessa estrutura,
* ordene o array pelo campo escolhido pelo usuário.
*
* Método do Selection sort foi utilizado para resolver esse problema.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int Matricula;
    char Nome[30];
    float Nota;
} Pessoa;

void selectionSort(Pessoa v[], int n, int ordenacao) {
    int i, j, menor;
    Pessoa troca;

    if (ordenacao == 1) {
        for (i = 0; i < n-1; i++) {
            menor = i;
            for (j = i + 1; j < n; j++) {
                if (v[j].Matricula < v[menor].Matricula) {
                    menor = j;
                } 
            }
            if (i != menor) {
                troca = v[i];
                v[i] = v[menor];
                v[menor] = troca;
            }
        }
    } else if (ordenacao == 2) {
        for (i = 0; i < n-1; i++) {
            menor = i;
            for (j = i + 1; j < n; j++) {
                if (v[j].Nome[0] < v[menor].Nome[0]) {
                    menor = j;
                } 
            }
            if (i != menor) {
                troca = v[i];
                v[i] = v[menor];
                v[menor] = troca;
            }
        }
    } else if (ordenacao == 3) {
        for (i = 0; i < n-1; i++) {
            menor = i;
            for (j = i + 1; j < n; j++) {
                if (v[j].Nota < v[menor].Nota) {
                    menor = j;
                } 
            }
            if (i != menor) {
                troca = v[i];
                v[i] = v[menor];
                v[menor] = troca;
            }
        }
    }
}

int main() {
    int N = 0, ordenar = 0;

    printf("Informe a quantidade de alunos: ");
    scanf("%d", &N);

    Pessoa vetor[N];

    for (int i = 0; i < N; i++) {
        printf("Informe a matricula do aluno: ");
        scanf("%d", &vetor[i].Matricula);
        printf("Informe o nome do aluno: ");
        scanf("%s", vetor[i].Nome);
        printf("Informe a nota do aluno: ");
        scanf("%f", &vetor[i].Nota);
        printf("---------------------------------------------\n");
    }

    printf("Voce quer ordenar por qual camopo:\n[1] Matricula\n[2] Nome\n[3] Nota\nOpcao: ");
    scanf("%d", &ordenar);

    printf("---------------------------------------------\n");

    selectionSort(vetor, N, ordenar);
    
    for (int j = 0; j < N; j++) {
        printf("Matricula: %d\nNome: %s\nNota: %.2f\n", vetor[j].Matricula, vetor[j].Nome, vetor[j].Nota);
        printf("---------------------------------------------\n");
    }

    return 1;    
}
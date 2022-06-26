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
* Método do Bucket Sort com o auxílio do Selection Sort foi utilizado para resolver 
* esse problema.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 3 

typedef struct pessoa{
    int Matricula;
    char Nome[30];
    float Nota;
} Pessoa;

struct balde {
  int qtde;
  Pessoa pessoas[TAM];
};

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

void bucketSort(Pessoa vetor[], int tamanho, int ordenacao) {
    int i, j, numeroBaldes, pos;
    struct balde *bd;

    Pessoa maior = vetor[0];
    Pessoa menor = vetor[0];

    if (ordenacao == 1) {
        for (i = 1; i < tamanho; i++) {
            if (vetor[i].Matricula > maior.Matricula) maior = vetor[i];
            if (vetor[i].Matricula < menor.Matricula) menor = vetor[i];
        }
        
        numeroBaldes = (maior.Matricula - menor.Matricula) / TAM + 1;
        bd = (struct balde *) malloc (numeroBaldes * sizeof(struct balde));

        for (i = 0; i < numeroBaldes; i++) {
            bd[i].qtde = 0;
        }

        for (i = 0; i < tamanho; i++) {
            pos = (vetor[i].Matricula - menor.Matricula) / TAM;
            bd[pos].pessoas[bd[pos].qtde] = vetor[i];
            bd[pos].qtde++;
        }

        pos = 0;
        for (i = 0; i < numeroBaldes; i++) {
            selectionSort(bd[i].pessoas, bd[i].qtde, ordenacao);
            for (j = 0; j < bd[i].qtde; j++) {
                vetor[pos] = bd[i].pessoas[j];
                pos++;
            }
        }
    } else if (ordenacao == 2) {
        for (i = 1; i < tamanho; i++) {
            if (vetor[i].Nome[0] > maior.Nome[0]) maior = vetor[i];
            if (vetor[i].Nome[0] < menor.Nome[0]) menor = vetor[i];
        }
        
        numeroBaldes = (maior.Nome[0] - menor.Nome[0]) / TAM + 1;
        bd = (struct balde *) malloc (numeroBaldes * sizeof(struct balde));

        for (i = 0; i < numeroBaldes; i++) {
            bd[i].qtde = 0;
        }

        for (i = 0; i < tamanho; i++) {
            pos = (vetor[i].Nome[0] - menor.Nome[0]) / TAM;
            bd[pos].pessoas[bd[pos].qtde] = vetor[i];
            bd[pos].qtde++;
        }

        pos = 0;
        for (i = 0; i < numeroBaldes; i++) {
            selectionSort(bd[i].pessoas, bd[i].qtde, ordenacao);
            for (j = 0; j < bd[i].qtde; j++) {
                vetor[pos] = bd[i].pessoas[j];
                pos++;
            }
        }
    } else if (ordenacao == 3) {
        for (i = 1; i < tamanho; i++) {
            if (vetor[i].Nota > maior.Nota) maior = vetor[i];
            if (vetor[i].Nota < menor.Nota) menor = vetor[i];
        }
        
        numeroBaldes = (maior.Nota - menor.Nota) / TAM + 1;
        bd = (struct balde *) malloc (numeroBaldes * sizeof(struct balde));

        for (i = 0; i < numeroBaldes; i++) {
            bd[i].qtde = 0;
        }

        for (i = 0; i < tamanho; i++) {
            pos = (vetor[i].Nota - menor.Nota) / TAM;
            bd[pos].pessoas[bd[pos].qtde] = vetor[i];
            bd[pos].qtde++;
        }

        pos = 0;
        for (i = 0; i < numeroBaldes; i++) {
            selectionSort(bd[i].pessoas, bd[i].qtde, ordenacao);
            for (j = 0; j < bd[i].qtde; j++) {
                vetor[pos] = bd[i].pessoas[j];
                pos++;
            }
        }
    }

    free(bd);
}

void imprimirVetor(Pessoa vetor[], int n) {
    for (int j = 0; j < n; j++) {
        printf("Matricula: %d\nNome: %s\nNota: %.2f\n", vetor[j].Matricula, vetor[j].Nome, vetor[j].Nota);
        imprimirLinha();
    }
}

void imprimirLinha() {
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
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
        imprimirLinha();
    }

    printf("Voce quer ordenar por qual campo:\n[1] Matricula\n[2] Nome\n[3] Nota\nOpcao: ");
    scanf("%d", &ordenar);

    bucketSort(vetor, N, ordenar);
    imprimirLinha();
    
    imprimirVetor(vetor, N);

    return 1;    
}
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
* PROBLEMA 04: Usando uma linguagem de programação orientada a objetos como
* Java ou c++, implemente uma classe Aluno de atributos nome (String), nota1 e
* nota 2 (float ou double). Os atributos são privados e há métodos get/set para cada
* atributo. Depois faça um programa que cadastre 8 alunos em array. Para cada
* aluno devem ser cadastrados: nome, nota1, nota2. Usando três métodos de
* ordenação diferentes, liste todos os dados dos alunos das seguintes formas:
*
* I   - Em ordem crescente de média ponderada das notas, tendo a primeira nota
*       peso 2 e a segunda peso 3.
* II  - Em ordem crescente pela nota 1.
* III - Finalmente, considerando que para ser aprovado o aluno deve ter no
*       mínimo média 7 liste, em ordem alfabética, os alunos reprovados. 
*
* Os métodos Quick Sort, Merge Sort e Selection Sort foram utilizados para 
* resolver esse problema.
*/

#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

class Aluno {
    private:
        string nome;
        double nota1;
        double nota2;
    public:
        Aluno() = default;
        Aluno(string nome, double nota1, double nota2) {
            this->nome = nome;
            this->nota1 = nota1;
            this->nota2 = nota2;
        }

        string getNome() {
            return this->nome;
        }

        double getNota1(void) {
            return this->nota1;
        }

        double getNota2(void) {
            return this->nota2;
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        void setNota1(double nota1) {
            this->nota1 = nota1;
        }

        void setNota2(double nota2) {
            this->nota2 = nota2;
        }

        double mediaPonderada() {
            return (2 * this->getNota1() + 3 * this->getNota2()) / 5.0;
        }

};

int partition(Aluno vetor[], int low, int high) {
	int i = low;
	int j = high;
	Aluno pivot = vetor[low];
	while (i < j) {
		while (pivot.mediaPonderada() >= vetor[i].mediaPonderada())
			i++;
		while (pivot.mediaPonderada() < vetor[j].mediaPonderada())
			j--;
		if (i < j)
			swap(vetor[i], vetor[j]);
	}
	swap(vetor[low], vetor[j]);
	return j;
}

void quickSort(Aluno vetor[], int low, int high) {
	if (low < high) {
		int pivot = partition(vetor, low, high);
		quickSort(vetor, low, pivot - 1);
		quickSort(vetor, pivot + 1, high);
	}
}

void merge(Aluno vetor[], int inicio, int meio, int fim) {
    Aluno *temp;
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (Aluno *) malloc(tamanho * sizeof(Aluno));
    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if (vetor[p1].getNota1() < vetor[p2].getNota1()) {
                    temp[i] = vetor[p1++];
                } else {
                    temp[i] = vetor[p2++];
                }

                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;
            } else {
                if (!fim1) {
                    temp[i] = vetor[p1++];
                } else {
                    temp[i] = vetor[p2++];
                }
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++) {
            vetor[k] = temp[j];
        }
    }
    free(temp);
}

void mergeSort(Aluno vetor[], int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = floor((inicio + fim) / 2);
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void selectionSort(Aluno vetor[], int tamanho) {
    Aluno aux;
    int i, j, min;
    for (i = 0; i < tamanho - 1; i++) {
        min = i;
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j].getNome().compare(vetor[min].getNome()) < 0) {
                min = j;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
}

void imprimirLinha() {
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
}

void imprimirVetor(Aluno vetorAlunos[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
        cout << "Aluno 0" << i+1 << ":\n"; 
		cout << "Nome: " << vetorAlunos[i].getNome() << "\n";
        cout << "Nota 01: " << vetorAlunos[i].getNota1() << "\n";    
        cout << "Nota 02: " << vetorAlunos[i].getNota2() << "\n";
        imprimirLinha();
	}
	cout << endl;
}

int main(void) {
    string nome;
    double nota1, nota2, media;

    int tamanho = 8, qtdeAlunosReprovados = 0;
    Aluno vetorAlunos[tamanho];
    
    for (int j = 0; j < tamanho; j++) {
        cout << "Nome do " << j+1 << "º aluno: ";
        cin >> nome;
        cout << "Nota 1: ";
        cin >> nota1;
        cout << "Nota 2: ";
        cin >> nota2;
        cout << endl;

        vetorAlunos[j].setNome(nome);
        vetorAlunos[j].setNota1(nota1);
        vetorAlunos[j].setNota2(nota2);

        if (vetorAlunos[j].mediaPonderada() < 7.0) {
            qtdeAlunosReprovados++;
        }
    }

    imprimirLinha();
    cout << "Ordenar por: \n";
    cout << "[1] Media Ponderada\n[2] Nota 01\n[3] Alunos reprovados\n";
    cout << "Sua escolha: ";

    Aluno vetorAlunosReprovados[qtdeAlunosReprovados];

    for (int i = 0, pos = 0; i < tamanho; i++) {
        if (vetorAlunos[i].mediaPonderada() < 7) {
            vetorAlunosReprovados[pos] = vetorAlunos[i];
            pos++;
        }
    }

    int escolha;
    cin >> escolha;
    imprimirLinha();
    
    cout << "-=-=-=- Lista ordenada -=-=-=-\n";
    switch (escolha) {
        case 1:
            quickSort(vetorAlunos, 0, tamanho - 1);
            imprimirLinha();
            imprimirVetor(vetorAlunos, tamanho);
            break;
        case 2:
            mergeSort(vetorAlunos, 0, tamanho - 1);
            imprimirLinha();
            imprimirVetor(vetorAlunos, tamanho);
            break;
        case 3:
            selectionSort(vetorAlunosReprovados, qtdeAlunosReprovados);
            imprimirLinha();
            imprimirVetor(vetorAlunosReprovados, qtdeAlunosReprovados);
            break;
        default:
            break;
    }

    return 1;
}
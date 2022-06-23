/*
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
*/

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

class Aluno {
    private:
        string nome;
        double nota1;
        double nota2;
    public:
        string getNome() {
            return nome;
        }

        double getNota1(void) {
            return nota1;
        }

        double getNota2(void) {
            return nota2;
        }

        void setNome(string n) {
            nome = n;
        }

        void setNota1(double n1) {
            nota1 = n1;
        }

        void setNota2(double n2) {
            nota2 = n2;
        }

        double mediaPonderada() {
            return (2 * getNota1() + 3 * getNota2()) / 5.0;
        }

};


int partition(Aluno arr[], int low, int high) {
	int i = low;
	int j = high;
	Aluno pivot = arr[low];
	while (i < j) {
		while (pivot.mediaPonderada() >= arr[i].mediaPonderada())
			i++;
		while (pivot.mediaPonderada() < arr[j].mediaPonderada())
			j--;
		if (i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[low], arr[j]);
	return j;
}

void quickSort(Aluno arr[], int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

void shellSort(Aluno vetorAlunos[], int size) {
    for (int gap = size/2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i += 1) {
            Aluno temp = vetorAlunos[i];
            int j;            
            for (j = i; j >= gap && vetorAlunos[j - gap].getNota1() > temp.getNota1(); j -= gap)
                vetorAlunos[j] = vetorAlunos[j - gap];
              
            vetorAlunos[j] = temp;
        }
    }
}

void printArray(Aluno vetorAlunos[], int size) {
	for (int i = 0; i < size; i++) {
        cout << "Aluno 0" << i+1 << ":\n"; 
		cout << "Nome: " << vetorAlunos[i].getNome() << "\n";
        cout << "Nota 01: " << vetorAlunos[i].getNota1() << "\n";    
        cout << "Nota 02: " << vetorAlunos[i].getNota2() << "\n";
        cout << endl;
	}
	cout << endl;
}

int main(void) {
    string nome;
    double nota1, nota2;

    int size = 2;
    Aluno vetorAlunos[2];
    for (int j = 0; j < 2; j++) {
        cout << "Nome do " << j+1 << "º aluno: ";
        cin >> nome;
        cout << "Nota 1: ";
        cin >> nota1;
        cout << "Nota 2: ";
        cin >> nota2;

        vetorAlunos[j].setNome(nome);
        vetorAlunos[j].setNota1(nota1);
        vetorAlunos[j].setNota2(nota2);
    }

    cout << "Ordenar por: \n";
    cout << "[1] Media Ponderada\n[2] Nota 01\n[3] Alunos reprovados";
    cout << "Sua escolha: ";

    int escolha;
    cin >> escolha;

    switch (escolha) {
    case 1:
        quickSort(vetorAlunos, 0, size - 1);
        break;
    case 2:
        shellSort(vetorAlunos, size);
        break;
    case 3:
        //heapSort(vetorAlunos, size);
        break;
    default:
        break;
    }

    cout << endl;
    printArray(vetorAlunos, size);
}
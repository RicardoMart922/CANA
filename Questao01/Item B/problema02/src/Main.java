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
* PROBLEMA 02: Usando uma linguagem de programação orientada a objetos como
* Java ou C++, implemente uma classe Funcionário de atributos nome (String) e
* salário (float ou double). Os atributos são privados e há métodos get/set para cada
* atributo. Após isso, faça um programa que cadastre o nome e o salário de 5
* funcionários armazenados em um array. Usando dois métodos de ordenação
* diferentes, liste todos os dados dos funcionários das seguintes formas:
*
* I  - em ordem crescente de salário;
* II - em ordem alfabética.
*
* Os métodos de Bubble e Insertion Sort foram usados para resolver esse problema.
*/
import java.util.Scanner;

public class Main {

    public static void bubbleSort(Funcionario[] vetorFuncionarios) {
        Funcionario aux;
        for(int i = 0; i < vetorFuncionarios.length - 1; i++) {
            for(int j = 0; j < vetorFuncionarios.length - 1 - i; j++) {
                if(vetorFuncionarios[j].getNome().compareTo(vetorFuncionarios[j+1].getNome()) < 0) {
                    aux = vetorFuncionarios[j];
                    vetorFuncionarios[j] = vetorFuncionarios[j+1];
                    vetorFuncionarios[j+1] = aux;
                }
            }
        }
    }

    public static void insertionSort(Funcionario[] vetorFuncionarios) {
        int i, j;
        Funcionario aux;
        
        for (i = 1; i < vetorFuncionarios.length; i++) {
            aux = vetorFuncionarios[i];
            j = i - 1;
            while (j >= 0 && vetorFuncionarios[j].getSalario() < aux.getSalario()) {
                vetorFuncionarios[j+1] = vetorFuncionarios[j];
                j--;
            }
            vetorFuncionarios[j+1] = aux;
        }
    } 

    public static void imprimirVetor(Funcionario[] vetorFuncionarios) {
        for (int i = 4; i >= 0; i--) {
            System.out.printf("Funcionario: %s\n", vetorFuncionarios[i].getNome());
            System.out.printf("Salario: R$%.2f\n", vetorFuncionarios[i].getSalario());
            imprimirLinha();
        }
    }

    public static void imprimirLinha() {
        System.out.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    }

    public static void menu() {
        System.out.printf("Forma de ordenação\n");
        System.out.printf("[1] Ordem alfabetica\n");
        System.out.printf("[2] Ordem crescente de salario\n");
        System.out.print("Sua escolha: ");
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Funcionario funcionarios[] = new Funcionario[5];

        String nome;
        double salario;
        for (int i = 0; i < 5; i++) {
            System.out.printf("Informe o nome do %dº funcionario: ", i+1);
            nome = in.nextLine();
            System.out.printf("Informe o salario do funcionario: R$");
            salario = Double.parseDouble(in.nextLine());
            
            imprimirLinha();

            Funcionario funcionario = new Funcionario(nome, salario);
            funcionarios[i] = funcionario;
        }

        menu();
        int escolha = Integer.parseInt(in.nextLine());

        switch (escolha) {
            case 1:
                System.out.println("Vetor ordenado em ordem alfabetica");
                bubbleSort(funcionarios);
                break;
            case 2:
                System.out.println("Vetor ordenado em ordem crescente de salario");
                insertionSort(funcionarios);
                break;
        }

        imprimirVetor(funcionarios);

        in.close();
    }
}

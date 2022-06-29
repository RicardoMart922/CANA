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
* Implemente uma estrutura de dados Árvore Binária em Python ou Java ou C++
* usando conceitos de orientação a objetos. A sua classe deve ter os seguintes
* métodos:
* 
* a) getNosFolha: retorna uma lista de nós folhas;
* b) getGrau(int nó): retorna o grau de um nó;
* c) altura: retorna altura da árvore;  
* d) profundidade: retorna o valor de profundidade da árvore.
*/

import java.util.ArrayList;

public class Main {

    public static void imprimirLinha() {
        System.out.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    }

    public static void main(String[] args) {
        ArvoreBinaria arvore = new ArvoreBinaria();

        int vetorNumeros[] = {8, 4, 2, 1, 3, 6, 5, 12, 10, 11, 14, 13, 15};
        for (int i = 0; i < vetorNumeros.length; i++) {
            arvore.adicionarNo(vetorNumeros[i]);
        }

        imprimirLinha();

        System.out.print("Em ordem: ");
        arvore.inOrder(arvore.getRaiz());
        System.out.println();

        imprimirLinha();

        ArrayList<No> folhas = arvore.getNosFolha();

        System.out.print("Folhas: ");
        for (No folha : folhas)
            System.out.print(folha.getValor() + " ");
        System.out.println();

        imprimirLinha();

        for (int j = 0; j < vetorNumeros.length; j++) {
            System.out.println("Grau do no de valor " + vetorNumeros[j] + " é igual a " + arvore.getGrau(vetorNumeros[j]));
        }

        imprimirLinha();

        System.out.println("Altura da árvore: " + arvore.altura());

        imprimirLinha();

        System.out.println("Profundidade da árvore: " + arvore.profundidade());

        imprimirLinha();
    }
}
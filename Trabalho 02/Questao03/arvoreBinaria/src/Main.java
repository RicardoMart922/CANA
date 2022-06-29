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

        System.out.println("Altura: " + arvore.altura());

        imprimirLinha();

        System.out.println("Profundidade: " + arvore.profundidade());

        imprimirLinha();
    }
}
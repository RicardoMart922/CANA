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
* Implemente uma versão do HeapSort que realiza ordenação decrescente.
* Você pode implementar em C, C++, Java ou Python. Aplique essa ordenação
* em um vetor de 10 elementos gerados aleatoriamente.
*/

/**
 *
 * @author Nilson
 */
public class HeapSort {
    public static void main(String[] args) {
    
        int[] vetor = new int[10];
        
        for(int i=0; i<10;  i++){
            vetor[i] = (int) Math.floor(Math.random()*100);
        }
        System.out.println("Vetor desordenado");
        for(int i=0; i<10; i++){
            System.out.print(vetor[i]+" ");
        }
        
        //Heap sort
        int n = 10;
        for(int i = n/2-1; i>=0; i--){
            heap(vetor, n, i);
        }
        
        for(int j=n-1; j>0; j--){
            int aux = vetor[0];
            vetor[0] = vetor[j];
            vetor[j] = aux;
            heap(vetor, j, 0);
        }
        
        System.out.println("\nVetor ordenado");
        for(int i=0; i<10; i++){
            System.out.print(vetor[i]+" ");
        }
        System.out.println("");
        
    }
    
    
    public static void heap(int[] vetor, int n, int i){
    
        int raiz = i;
        int esquerda = 2*i+1;
        int direita = 2*i+2;
        
        //Se vetor[esquerda] > vetor[raiz] --ordenação crescente
        if(esquerda < n && vetor[esquerda] < vetor[raiz]){
            raiz = esquerda;
        }
        if(direita < n && vetor[direita] < vetor[raiz]){
            raiz = direita;
        }
        if(raiz != i){
            int aux = vetor[i];
            vetor[i] = vetor[raiz];
            vetor[raiz] = aux;
            
            heap(vetor, n, raiz);
        }
    }
}

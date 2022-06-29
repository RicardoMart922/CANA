import java.util.ArrayList;
import java.util.Stack;

public class ArvoreBinaria {
    private No raiz;

    public No getRaiz() {
        return this.raiz;
    }

    public void adicionarNo(int valor) {
        this.raiz = adicionarNoRecursivo(this.raiz, valor);
    }

    private No adicionarNoRecursivo(No atual, int valor) {
        if (atual == null)
            return new No(valor);
        if (valor < atual.getValor()) {
            atual.setEsquerdo(adicionarNoRecursivo(atual.getEsquerdo(), valor));
        } else if (valor > atual.getValor()) {
            atual.setDireito(adicionarNoRecursivo(atual.getDireito(), valor));
        }
        return atual;
    }

    public void inOrder(No no) {
        if (no != null) {
            inOrder(no.getEsquerdo());
            visitar(no.getValor());
            inOrder(no.getDireito());
        }
    }

    public void inOrderRecursivo() {
        Stack<No> pilha = new Stack<>();
        No atual = raiz;
        while (atual != null || !pilha.isEmpty()) {
            while (atual != null) {
                pilha.push(atual);
                atual = atual.getEsquerdo();
            }
            No top = pilha.pop();
            visitar(top.getValor());
            atual = top.getDireito();
        }
    }

    public void preOrder(No no) {
        if (no != null) {
            visitar(no.getValor());
            preOrder(no.getEsquerdo());
            preOrder(no.getDireito());
        }
    }

    public void preOrderRecursivo() {
        Stack<No> pilha = new Stack<>();
        No atual = raiz;
        pilha.push(raiz);
        while (atual != null && !pilha.isEmpty()) {
            atual = pilha.pop();
            visitar(atual.getValor());
            if (atual.getDireito() != null)
                pilha.push(atual.getDireito());
            if (atual.getEsquerdo() != null)
                pilha.push(atual.getEsquerdo());
        }
    }

    public void posOrder(No no) {
        if (no != null) {
            posOrder(no.getEsquerdo());
            posOrder(no.getDireito());
            visitar(no.getValor());
        }
    }
    
    public void posOrderRecursivo() {
        Stack<No> pilha = new Stack<>();
        No prev = raiz;
        No atual = raiz;
        pilha.push(raiz);
        while (atual != null && !pilha.isEmpty()) {
            atual = pilha.peek();
            boolean hasChild = (atual.getEsquerdo() != null || atual.getDireito() != null);
            boolean isPrevLastChild = (prev == atual.getDireito() || (prev == atual.getEsquerdo() && atual.getDireito() == null));
            if (!hasChild || isPrevLastChild) {
                atual = pilha.pop();
                visitar(atual.getValor());
                prev = atual;
            } else {
                if (atual.getDireito() != null) {
                    pilha.push(atual.getDireito());
                }
                if (atual.getEsquerdo() != null) {
                    pilha.push(atual.getEsquerdo());
                }
            }
        }   
    }

    public ArrayList<No> getNosFolha() {
        ArrayList<No> folhas = new ArrayList<No>();
        adicionarNoFolhaRecursivo(folhas, raiz);
        return folhas;
    }
    
    private void adicionarNoFolhaRecursivo(ArrayList<No> folhas, No raiz) {
        if (raiz != null) {
            if ((raiz.getDireito() == null) && (raiz.getEsquerdo() == null)) 
                folhas.add(raiz);
            else {
                adicionarNoFolhaRecursivo(folhas, raiz.getEsquerdo());
                adicionarNoFolhaRecursivo(folhas, raiz.getDireito());
            }
        }
    }

    public int getGrau(int valor) {
        if (this.raiz == null) 
            return -1;
        return getGrauRecursivo(raiz, valor);
    }

    private int getGrauRecursivo(No atual, int valor) {
        if (atual == null)
            return -1;
        if (valor == atual.getValor()) {
            if ((atual.getEsquerdo() == null) && (atual.getDireito() == null))
                return 0;
            else if ((atual.getEsquerdo() != null) && (atual.getDireito() != null))
                return 2;
            return 1;
        }   
        return valor < atual.getValor() ? 
            getGrauRecursivo(atual.getEsquerdo(), valor) :
            getGrauRecursivo(atual.getDireito(), valor);
    }

    private void visitar(int valor) {
        System.out.print(" " + valor);        
    }

    public int altura() {
        if (raiz == null)
            return -1;
        int alturaEsquerda = alturaRecursivo(raiz.getEsquerdo());
        int alturaDireita = alturaRecursivo(raiz.getDireito());
        return (alturaDireita > alturaEsquerda) ? alturaDireita : alturaEsquerda;
    }

    private int alturaRecursivo(No atual) {
        if (atual == null)
            return 0;
        int alturaEsquerda = alturaRecursivo(atual.getEsquerdo()) + 1;
        int alturaDireita = alturaRecursivo(atual.getDireito()) + 1;
        return (alturaDireita > alturaEsquerda) ? alturaDireita : alturaEsquerda;
    }

    public int profundidade() {
        return altura();
    }
}
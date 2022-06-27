# Instituo Federal do Ceará - IFCE
# Campus: Tianguá
# Curso: Bacharelado em Ciência da Computação
# Disciplina: Construção e Análise de Algoritmos
# Professor: Adonias Caetano de Oliveira
# Assunto: Métodos de Ordenação
#
# Equipe:
#       -> Francinilson Rodrigues Lima
#       -> Ricardo Martins Cordeiro
#
# PROBLEMA 05: Crie um programa que dada uma string, coloque as letras dela em 
# ordem crescente (Dica: Use C, Python ou Ruby) 

# Método do Shell Sort foi utilizado para resolver esse problema.
def shellSort(lista):
    h = 1
    n = len(lista)
    
    while h >= 1:
        for i in range(h, n):
            j = i
            while j >= h:
                if lista[j-h] > lista[j]:
                    auxiliar = lista[j]
                    lista[j] = lista[j-h]
                    lista[j-h] = auxiliar
                j -= h
        h/=3
    
    return lista


# Programa principal
palavra = str(input()).replace(' ', '')

lista = list()
for i in range(len(palavra)):
    lista.append(palavra[i:i+1])

print('Lista não ordenada: {}'.format(lista))
print('Lista ordenada:     {}'.format(shellSort(lista)))

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
# PROBLEMA 06: Faça um programa que leia N nomes e ordeno-os pelo tamanho
# (Dica: Use C, Python ou Ruby)
#
# Método de Radix Sort foi utilizado para resolver esse problema.

def countingSort(lista, place):
    tamanho = len(lista)
    saida = [0] * tamanho
    count = [0] * 10

    for i in range(0, tamanho):
        index = len(lista[i]) // place
        count[index % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = tamanho - 1
    while i >= 0:
        index = len(lista[i]) // place
        saida[count[index % 10] - 1] = lista[i]
        count[index % 10] -= 1
        i -= 1

    for i in range(0, tamanho):
        lista[i] = saida[i]


def radixSort(lista):
    maiorElemento = max(lista)

    place = 1
    while len(maiorElemento) // place > 0:
        countingSort(lista, place)
        place *= 10


qtdeNomes = int(input("Informe a quantidade de nomes: "))

lista = list()
i = 0
while i < qtdeNomes:
    lista.append(str(input("{}ª nome: ".format(i+1))))
    i += 1

radixSort(lista)
print(lista)
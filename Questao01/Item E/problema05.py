# PROBLEMA 05: Crie um programa que dada uma string, coloque as letras dela em 
# ordem crescente (Dica: Use C, Python ou Ruby) 

# Método do Merge Sort foi utilizado para resolver esse problema.

def mergeSort(lista):
    if len(lista) > 1:
        metade = len(lista) // 2
        metadeEsquerda = lista[:metade]
        metadeDireita = lista[metade:]

        mergeSort(metadeEsquerda)
        mergeSort(metadeDireita)

        i = 0
        j = 0
        k = 0
        while i < len(metadeEsquerda) and j < len(metadeDireita):
            if metadeEsquerda[i] < metadeDireita[j]:
                lista[k] = metadeEsquerda[i]
                i = i + 1
            else:
                lista[k] = metadeDireita[j]
                j = j + 1
            k = k + 1

        while i < len(metadeEsquerda):
            lista[k] = metadeEsquerda[i]
            i = i + 1
            k = k + 1

        while j < len(metadeDireita):
            lista[k] = metadeDireita[j]
            j = j + 1
            k = k + 1

# Programa principal
palavra = str(input()).replace(' ', '')

lista = list()
for i in range(len(palavra)):
    lista.append(palavra[i:i+1])

mergeSort(lista)
print(lista)

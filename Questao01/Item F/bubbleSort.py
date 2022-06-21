# PROBLEMA 06: Faça um programa que leia N nomes e ordeno-os pelo tamanho
# (Dica: Use C, Python ou Ruby)

def bubbleSort(lista):
    tamanho = len(lista)-1
    for i in range(0, tamanho):
        for j in range(tamanho):
            if (len(lista[j]) > len(lista[j+1])):
                auxiliar = lista[j]
                lista[j] = lista[j+1]
                lista[j+1] = auxiliar


qtdeNomes = int(input("Informe a quantidade de nomes: "))

lista = list()
i = 0
while i < qtdeNomes:
    lista.append(str(input("{}ª nome: ".format(i+1))))
    i += 1

bubbleSort(lista)
print(lista)
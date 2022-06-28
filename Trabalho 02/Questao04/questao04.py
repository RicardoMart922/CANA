# Instituo Federal do Ceará - IFCE
# Campus: Tianguá
# Curso: Bacharelado em Ciência da Computação
# Disciplina: Construção e Análise de Algoritmos
# Professor: Adonias Caetano de Oliveira
# Assunto: Árvores e HeapSort
#
# Equipe:
#       -> Francinilson Rodrigues Lima
#       -> Ricardo Martins Cordeiro
#
# Implemente em Python todos os dez algoritmos de ordenação ensinados em sala de aula,
# realizando experimentos que avaliem o tempo de execução para ordenar de acordo 
# com as seguintes regras:
#
# I   - Serão noves vetores com os seguintes tamanhos para cada um: 1000, 3000,
#       6000, 9000, 12000, 15000, 18000, 21000, 24000.
# II  - Os métodos de ordenação são: Bubble Sort, Insertion Sort, Selection Sort,
#       Merge Sort, Quick Sort, Counting Sort, Radix Sort, Shell Sort, Bucket Sort e
#       Heap Sort.
# III - Os valores armazenados nos noves vetores serão números inteiros gerados
#       aleatoriamente.
# IV  - Usar a biblioteca "matplotlib.pyplot".
# V   - Plotar um gráfico comparando o tempo de exucução dos algoritmos de 
#       acordo com o tamanho do vetor.

import matplotlib.pyplot as plt
import random
import timeit


def bubbleSort(lista):
    i = 0
    while i < len(lista):
        j = 0
        while j < len(lista) - 1:
            if (lista[j] > lista[j+1]):
                temp = lista[j]
                lista[j] = lista[j+1]
                lista[j+1] = temp
            j += 1
        i += 1


def insertionSort(lista):
    for i in range(1, len(lista)):
        k = lista[i]
        j = i - 1
        while j >= 0 and k < lista[j]:
            lista[j+1] = lista[j]
            j -= 1
        lista[j+1] = k


def selectionSort(lista):
    for i in range(len(lista)):
        menorIndice = i
        for j in range(i+1, len(lista)):
            if lista[j] < lista[menorIndice]:
                menorIndice = j
        (lista[i], lista[menorIndice]) = (lista[menorIndice], lista[i])


def mergeSort(lista):
    if (len(lista) > 1):
        meio = len(lista) // 2
        parteEsquerda = lista[:meio]
        parteDireita = lista[meio:]

        mergeSort(parteEsquerda)
        mergeSort(parteDireita)

        i = j = k = 0

        while i < len(parteEsquerda) and j < len(parteDireita):
            if parteEsquerda[i] < parteDireita[j]:
                lista[k] = parteEsquerda[i]
                i += 1
            else:
                lista[k] = parteDireita[j]
                j += 1
            k += 1
        
        while i < len(parteEsquerda):
            lista[k] = parteEsquerda[i]
            i += 1
            k += 1

        while i < len(parteEsquerda):
            lista[k] = parteDireita[j]
            j += 1
            k += 1


def partition(lista, inicio, fim):
    pivo = lista[fim]
    i = inicio - 1

    for j in range(inicio, fim):
        if lista[j] <= pivo:
            i += 1
            (lista[i], lista[j]) = (lista[j], lista[i])
    (lista[i+1], lista[fim]) = (lista[fim], lista[i+1])
    return i + 1


def quickSort(lista, inicio, fim):
    if inicio < fim:
        p = partition(lista, inicio, fim)
        quickSort(lista, inicio, p-1)
        quickSort(lista, p+1, fim)


def countingSort(lista):
    tamanhoLista = len(lista)
    saida = [0] * tamanhoLista

    count = [0] * (max(lista)+1)

    for i in range(0, tamanhoLista):
        count[lista[i]] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = tamanhoLista - 1
    while i >= 0:
        saida[count[lista[i]] - 1] = lista[i]
        count[lista[i]] -= 1
        i -= 1

    for i in range(0, tamanhoLista):
        lista[i] = saida[i]


def bucketSort(lista):
    maiorValor = max(lista)
    tamanho = maiorValor / len(lista)
    balde = []

    for i in range(len(lista)):
        balde.append([])

    for i in range(len(lista)):
        j = int (lista[i] / tamanho)
        if j != len (lista):
            balde[j].append(lista[i])
        else:
            balde[len(lista) - 1].append(lista[i])

    for i in range(len(lista)):
        balde[i] = sorted(balde[i])

    k = 0
    for i in range(len(lista)):
        for j in range(len(balde[i])):
            lista[k] = balde[i][j]
            k += 1
    return lista


def countingSortRadix(lista, place):
    tamanho = len(lista)
    saida = [0] * tamanho
    count = [0] * 10

    for i in range(0, tamanho):
        index = lista[i] // place
        count[index % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = tamanho - 1
    while i >= 0:
        index = lista[i] // place
        saida[count[index % 10] - 1] = lista[i]
        count[index % 10] -= 1
        i -= 1

    for i in range(0, tamanho):
        lista[i] = saida[i]


def radixSort(lista):
    maiorElemento = max(lista)

    place = 1
    while maiorElemento // place > 0:
        countingSortRadix(lista, place)
        place *= 10


def shellSort(lista, tamanho):
    interval = tamanho // 2
    while interval > 0:
        for i in range(interval, tamanho):
            temp = lista[i]
            j = i
            while j >= interval and lista[j - interval] > temp:
                lista[j] = lista[j - interval]
                j -= interval

            lista[j] = temp
        interval //= 2


def gerarLista(tamanho):
    random.seed()
    i = 0
    lista = list()
    while i < tamanho:
        lista.append(random.randint(1, tamanho))
        i += 1
    return lista


def heapify(lista, tamanho, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
  
    if l < tamanho and lista[i] < lista[l]:
        largest = l
  
    if r < tamanho and lista[largest] < lista[r]:
        largest = r
  
    if largest != i:
        lista[i], lista[largest] = lista[largest], lista[i]
        heapify(lista, tamanho, largest)
  
  
def heapSort(lista):
    tamanho = len(lista)
  
    for i in range(tamanho//2, -1, -1):
        heapify(lista, tamanho, i)
  
    for i in range(tamanho-1, 0, -1):
        lista[i], lista[0] = lista[0], lista[i]
        heapify(lista, i, 0)


tamanhos = [1000, 3000, 6000, 9000, 12000, 15000, 18000, 21000, 24000]

temposBubbbleSort = list()
for tamanho in tamanhos:
    lista = gerarLista(tamanho)

    listaTeste = list(lista)
    temposBubbbleSort.append(timeit.timeit('bubbleSort({})'.format(listaTeste), setup='from __main__ import bubbleSort', number=1))
    print('BubbleSort -> Lista de tamanho {}'.format(tamanho), ' ordenada')


temposInsertionSort = list()
for tamanho in tamanhos:
    lista = gerarLista(tamanho)

    listaTeste = list(lista)
    temposInsertionSort.append(timeit.timeit('insertionSort({})'.format(listaTeste), setup='from __main__ import insertionSort', number=1))
    print('InsertionSort -> Lista de tamanho {}'.format(tamanho), ' ordenada')


temposSelectionSort = list()
for tamanho in tamanhos:
    lista = gerarLista(tamanho)

    listaTeste = list(lista)
    temposSelectionSort.append(timeit.timeit('selectionSort({})'.format(listaTeste), setup='from __main__ import selectionSort', number=1))
    print('SelectionSort -> Lista de tamanho {}'.format(tamanho), ' ordenada')


temposMergeSort = list()
for tamanho in tamanhos:
    lista = gerarLista(tamanho)

    listaTeste = list(lista)
    temposMergeSort.append(timeit.timeit('mergeSort({})'.format(listaTeste), setup='from __main__ import mergeSort', number=1))
    print('MergeSort -> Lista de tamanho {}'.format(tamanho), ' ordenada')


temposQuickSort = list()
for tamanho in tamanhos:
    lista = gerarLista(tamanho)

    listaTeste = list(lista)
    temposQuickSort.append(timeit.timeit('quickSort({},0,{})'.format(listaTeste, len(listaTeste)-1), setup='from __main__ import quickSort', number=1))
    print('QuickSort -> Lista de tamanho {}'.format(tamanho), ' ordenada')


temposCountingSort = list()
for tamanho in tamanhos:
    lista = gerarLista(tamanho)

    listaTeste = list(lista)
    temposCountingSort.append(timeit.timeit('countingSort({})'.format(listaTeste), setup='from __main__ import countingSort', number=1))
    print('CountingkSort -> Lista de tamanho {}'.format(tamanho), ' ordenada')


temposBucketSort = list()
for tamanho in tamanhos:
    lista = gerarLista(tamanho)

    listaTeste = list(lista)
    temposBucketSort.append(timeit.timeit('bucketSort({})'.format(listaTeste), setup='from __main__ import bucketSort', number=1))
    print('BucketSort -> Lista de tamanho {}'.format(tamanho), ' ordenada')


temposRadixSort = list()
for tamanho in tamanhos:
    lista = gerarLista(tamanho)

    listaTeste = list(lista)
    temposRadixSort.append(timeit.timeit('radixSort({})'.format(listaTeste), setup='from __main__ import radixSort', number=1))
    print('RadixSort -> Lista de tamanho {}'.format(tamanho), ' ordenada')


temposShellSort = list()
for tamanho in tamanhos:
    lista = gerarLista(tamanho)

    listaTeste = list(lista)
    temposShellSort.append(timeit.timeit('shellSort({}, {})'.format(listaTeste, len(listaTeste)), setup='from __main__ import shellSort', number=1))
    print('ShellSort -> Lista de tamanho {}'.format(tamanho), ' ordenada')


temposHeapSort = list()
for tamanho in tamanhos:
    lista = gerarLista(tamanho)

    listaTeste = list(lista)
    temposHeapSort.append(timeit.timeit('heapSort({})'.format(listaTeste), setup='from __main__ import heapSort', number=1))
    print('HeapSort -> Lista de tamanho {}'.format(tamanho), ' ordenada')


plt.plot(tamanhos, temposBubbbleSort, label='Bubble Sort')
plt.plot(tamanhos, temposInsertionSort, label='Insertion Sort')
plt.plot(tamanhos, temposSelectionSort, label='Selection Sort')
plt.plot(tamanhos, temposMergeSort, label='Merge Sort')
plt.plot(tamanhos, temposQuickSort, label='Quick Sort')
plt.plot(tamanhos, temposCountingSort, label='Counting Sort')
plt.plot(tamanhos, temposBucketSort, label='Bucket Sort')
plt.plot(tamanhos, temposRadixSort, label='Radix Sort')
plt.plot(tamanhos, temposShellSort, label='Shell Sort')
plt.plot(tamanhos, temposHeapSort, label='Heap Sort')
plt.legend()
plt.show()

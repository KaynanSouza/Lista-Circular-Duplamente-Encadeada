#define _CRT_RAND_S
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipos.h"

void listaDinamica() {
    FILE *f = fopen("ListaDinamica.csv", "w");
    fprintf(f, "Tamanho; Tempo\n");

    long inicio, fim, tempo;
    char *vetor; // Alterado para um vetor de inteiros
    int tamanho;

    for (tamanho = 0; tamanho <= 100000000; tamanho += 10000) {
        vetor = criarLista(tamanho);
        vetor = inserir(vetor, tamanho);

        // Início do tempo
        inicio = clock();

        mergeSort(vetor, 0, tamanho - 1);

        // Final do tempo
        fim = clock();

        tempo = fim - inicio;

        fprintf(f, "%d; %d\n", tamanho, tempo);

        printf("%d\n", tamanho);

        free(vetor); // Libere a memória alocada dinamicamente
    }

    fclose(f);
}

char *criarLista(int tamanho) {
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Falha na alocação de memória\n");
        exit(1);
    }
    return vetor;
}

char *inserir(char *vetor, int tamanho) {
    char numero;
	int i;

    srand(time(NULL));

    for (i = 0; i < tamanho; ++i) {
        numero = rand() % 100;
        vetor[i] = numero;
    }

    return vetor;
}

void imprimir(char *vetor, int tamanho) {
    int i;
    printf("Seu vetor: \n");

    printf("[");
    for (i = 0; i < tamanho; ++i) {
        printf("%d", vetor[i]);

        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void mergeSort(char *vetor, int inicio, int fim){
    if (inicio < fim)
	{
        int meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void merge(char *vetor, int inicio, int meio, int fim) {
    int i, j, k;

    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    char *esquerda = (char *)malloc(tamanhoEsquerda * sizeof(char));
    char *direita = (char *)malloc(tamanhoDireita * sizeof(char));

    if(esquerda == NULL || direita == NULL)
	{
        printf("Falha na alocação de memória\n");
        exit(1);
    }

    for(i = 0; i < tamanhoEsquerda; i++)
	{
        esquerda[i] = vetor[inicio + i];
    }

    for (j = 0; j < tamanhoDireita; j++) {
        direita[j] = vetor[meio + 1 + j];
    }

    i = 0, j = 0, k = inicio;

    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsquerda) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita) {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    free(esquerda);
    free(direita);
}


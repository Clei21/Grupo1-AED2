#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

void radixsort(int arr[], int n);
void printaArray(int arrayPar[], int size);
int randomInteger(int numbRange);
void radixsortPrint(int vetor[], int tamanho);

 int main()
{

    int tam = 100000, metade;
    metade = tam / 2;
    int ordDec[tam], ordCresc[tam], metadeCrescDescr[tam], metadeDecCresc[tam], allRandom[tam];
    srand(time(NULL));
    double t_gasto = 0.0;
    clock_t comeco, fim;

	// vetores requisitados
    for(int i=0; i < tam; i++){
        allRandom[i] = randomInteger(30000);
        ordDec[i] = tam - i;
        ordCresc[i] = i;

        if(i < (metade -1)){
            metadeCrescDescr[i] = i;
            metadeDecCresc[i] = tam - i;
        }else{
            metadeCrescDescr[i] = ((tam + metade )  - i) ;
            metadeDecCresc[i] = i - metade;
        }
    }

    // Vetor de 10 inteiros aleatórios
    int arrayTestes[10];
    for(int j =0; j < 10; j++){ arrayTestes[j] = randomInteger(tam);}
    printf("\nVetor de 10 inteiros antes da ordenação: \n");
    printaArray(arrayTestes, 10);

    radixsortPrint(arrayTestes, 10);
    printf("\nArray ordenado: \n"); printaArray(arrayTestes, 10);
    printf("\n");

    comeco = clock();
    radixsort(allRandom, tam);
    fim = clock();
    t_gasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("\n\nVetor de todos aleatorios - Tempo gasto = %f segundos", t_gasto);

    comeco = clock();
    radixsort(metadeDecCresc, tam);
    fim = clock();
    t_gasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("\n\nMetade decrescente e metade crescente - Tempo gasto = %f segundos", t_gasto);

    comeco = clock();
    radixsort(metadeCrescDescr, tam);
    fim = clock();
    t_gasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("\n\nMetade crescente e metade decrescente - Tempo gasto = %f segundos", t_gasto);

    comeco = clock();
    radixsort(ordCresc, tam);
    fim = clock();
    t_gasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("\n\nOrdenado crescentemente - Tempo gasto = %f segundos", t_gasto);

    comeco = clock();
    radixsort(ordDec, tam);
    fim = clock();
    t_gasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("\n\nOrdenado decrescentemente - Tempo gasto = %f segundos", t_gasto);

	return 0;
}


int randomInteger(int numbRange){
    return rand() % numbRange ;
};

void radixsort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    // Maior número será a referência de dígitos das chaves
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    // Counting Sort
    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}



void radixsortPrint(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];


        printf("\n\nCounting Sort:\n[");
        printaArray(vetor, tamanho);
        printf("]\n\n");
    	exp *= 10;
    }


    free(b);
}

void printaArray(int arrayPar[], int size){
    for(int k=0; k < size; k++){
        if(k % size == 50){printf("\n");}
        printf("%d ", arrayPar[k]);
    }
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int combSort(int arr[], int tamanho);

void printaArray(int arrayPar[], int size);

int randomInteger(int numbRange);


int main(){

    int tam = 100000, metade; 
    metade = tam / 2
    ;
    int ordDec[tam], ordCresc[tam], metadeCrescDescr[tam], metadeDecCresc[tam], allRandom[tam];


    srand(time(NULL));

// vetores requisitados
    for(int i=0; i < tam; i++){
        allRandom[i] = randomInteger(999999);
        ordDec[i] = tam - i;
        ordCresc[i] = i;

        if(i < (metade -1)){
            metadeCrescDescr[i] = i;
            metadeDecCresc[i] = tam - i;
        }else{
            metadeCrescDescr[i] = tam - i;
            metadeDecCresc[i] = i - metade;
        }
    }
    //vetor de 10 números já ordenado:
    int arrayPronto[10];
    for(int k=0; k < 10; k++){ arrayPronto[k] = k; };
    printf("\nVetor já ordenado: \n"); 
    printaArray(arrayPronto, 10);
    int tPronto = combSort(arrayPronto, 10);
    printf("\nT do array pronto = %d", tPronto);


    // Vetor de 10 inteiros aleatórios
    int arrayTestes[10];
    for(int j =0; j < 10; j++){ arrayTestes[j] = randomInteger(99);}
    printf("\nVetor de 10 inteiros antes da ordenação: \n");
    printaArray(arrayTestes, 10);

    
    int totalT = combSort(arrayTestes, 10);
    //printf("\n Novo vetor ordenado: \n"); printaArray(allRandom, tam); 
    printf("\nT = %d\n", totalT);
    printf("\nArray ordenado: \n"); printaArray(arrayTestes, 10);
    printf("\n");

    printf("\nVetor de 100 mil números completamente aleatorio:\n");
    totalT = combSort(allRandom, tam);
    printf("\nT = %d\n", totalT);


    printf("\nVetor de 100 mil números ordenado decrescentemente:\n");
    totalT = combSort(ordDec, tam);
    printf("\nT = %d\n", totalT);

    printf("\nVetor de 100 mil números ordenado crescentemente:\n");
    totalT = combSort(ordCresc, tam);
    printf("\nT = %d\n", totalT);

    printf("\nVetor de 100 mil números primeira metade crescente e segunda metade decrescente:\n");
    totalT = combSort(metadeCrescDescr, tam);
    printf("\nT = %d\n", totalT);
    
    printf("\nVetor de 100 mil números primeira metade decrescente e segunda metade crescente:\n");
    totalT = combSort(metadeDecCresc, tam);
    printf("\nT = %d\n", totalT);
    return 0;

}

//Pente começa com  salto do valor igual ao tamanho do array divido pelo fator de encolhimento
int combSort(int arr[], int tamanho){
   int gap = tamanho;
   float encolhimento = 1.3;
   int ordenado = 0, t = 0;

   
   while(!ordenado){
        gap = (int)floor((float)gap / encolhimento);
        if(gap <= 1){  //Caso o intervalo de salto for valor 1 ou menor e saiu do loop de iteração interno o vetor está ordenado 
            gap = 1; 
            ordenado =1;
        }

        int i = 0;
        while((i + gap) <  tamanho){
            int iPlusGap = i + gap;
            if (arr[i] > arr[iPlusGap]){  
                //Troca de valores
                //no menor valor de salto haverá uma última iteração para confirmar a ordenação do vetor.
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                ordenado = 0;
                t++;                
            }
            i++;
             
            
        }
   }
   return t;
}

void printaArray(int arrayPar[], int size){
    for(int k=0; k < size; k++){
        if(k % size == 50){printf("\n");}
        printf("%d ", arrayPar[k]);
    }
}


int randomInteger(int numbRange){
    return (rand() % ((numbRange * 2)+1)  + (-numbRange));
};

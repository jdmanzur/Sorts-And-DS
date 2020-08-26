//MERGE SORT, RECURSIVO, TOP-DOWN
//merge sort é uma algoritmo de complexidade O(LogN*N);


#include <stdio.h>
#define MAX 1000


void merge_sort(int vetor[], int aux[], int min, int max);
void merge(int vetor[], int aux[], int min, int mid, int max);

int main(){

    int max, vetor[MAX], aux[MAX];

    scanf("%d", &max);

    for(int i = 0; i < max; i++){
        scanf("%d", &vetor[i]);
    }

    merge_sort(vetor, aux, 0, max - 1);

    return(0);
}

void merge_sort(int vetor[], int aux[], int min, int max){

    if(max <= min){
        //caso base: um unico elemento é um vetor ordenado
        return;
    }

    int mid = min + (max - min)/2;

    //recursivamente chama a função e divide o vetor em dois
    merge_sort(vetor, aux, min, mid);
    merge_sort(vetor, aux, mid + 1, max);

    //concatena os vetores ordenados
    merge(vetor, aux, min, mid, max);

}

void merge(int vetor[], int aux[], int min, int mid, int max){

    //algoritmo linear de concatenação de vetores ordenados

    int i = min;
    int j = mid + 1;

    for(int k = min; k <= max; k++){
        aux[k] = vetor[k];
    }

    for(int k = min; k <= max; k++){
        
        if(i > mid){
           //copia para o vetor[k] os elementos do vetor auxiliar j se os elementos do vetor i já acabaram
           // i vai de min até mid
            vetor[k] = aux[j++];
        
        }else if( j > max){
            //copia para vetor[k] os elementos do vetor auxiliar i se os elementos do vetor j já acabaram
            // j vai de mid + 1 até max
            vetor[k] = aux[i++];
        
        //compara os elementos a fim de saber qual possui o menor primeiro elemento, e copia para vetor[k]
        }else if(aux[j] < aux[i]){
            vetor[k] = aux[j++];
        }else{
            vetor[k] = aux[i++];
        }

    }

    return;

}

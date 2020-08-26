//QUICK SORT

#include <stdio.h>
#define MAX 10000


void swap(int* a, int* b);
void quick_sort(int vetor[], int min, int max);
int partition(int vetor[], int min, int max);

int main(){

    int max, vetor[MAX], aux[MAX];

    scanf("%d", &max);

    for(int i = 0; i < max; i++){
        scanf("%d", &vetor[i]);
    }

    quick_sort(vetor, 0, max - 1);

    for(int i = 0; i < max; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return(0);
}

void swap(int* a, int* b){
    
    int temp = *b;
    *b = *a;
    *a = temp;
}

void quick_sort(int vetor[], int min, int max){

    if (max <= min)
        return;
    
    int index = partition(vetor, min, max);
    
    quick_sort(vetor, min, index-1);
    quick_sort(vetor, index+1, max);


}

int partition(int vetor[], int min, int max){


    int i = min-1;

    int pivo = vetor[max];

    //inicio da partição
    for (int j = min; j <= max; j++)
    {
       if (vetor[j] < pivo){

            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }
    swap(&vetor[i + 1], &vetor[max]);

    return (i + 1);
}
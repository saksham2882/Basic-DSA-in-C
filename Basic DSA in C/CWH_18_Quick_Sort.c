#include <stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf(" %d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot){
            i++;
        }
        while (A[j] > pivot){
            j--;
        }
        if (i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } 
    while (i < j);

    // swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high){
    int partitionIndex;  // Index of pivot after partition

    if (low < high){
        partitionIndex = partition(A, low, high);
        printArray(A , 8);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

int main()
{
    int A[] = {3, 9, 65, 4, 23, 1, 7,19};
    // int A[] = {1, 3, 11, 55, 88, 405};
    int n = 8;

    printf("Input Array :\n");
    printArray(A, n);
    printf("Performing Quick Sort\n");
    quickSort(A, 0, n - 1);
    printf("Final Output Sorted Array :\n");
    printArray(A, n);
    return 0;
}
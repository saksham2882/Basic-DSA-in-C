#include <stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n){
    int indexOfMin;
    for (int i = 0; i < n - 1; i++){
        indexOfMin = i;

        for (int j = i + 1; j < n; j++)
        {
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }

        // Swap A[i] and A[indexOfMin]
        int temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main()
{
    int A[] = {12, 4, 65, 7, 23, 9};
    // int A[] = {1, 3, 11, 55, 88, 405};       // Sorted array
    int n = 6;

    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
    return 0;
}

#include <stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Time Complexity :- O(n^2)
void bubbleSort(int *A, int n){  
    for (int i = 0; i < n - 1; i++){ 
        printf("Working on pass number %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1]){
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// Time Complexity :- O(n)
void bubbleSortAdaptive(int *A, int n){
    int isSorted = 0;                               // for check if array is already sorted or not.
    for (int i = 0; i < n - 1; i++){
        printf("\nWorking on pass number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1]){
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted){
            return;
        }
    }
}

int main(){
    int A[] = {23, 34, 1, 55, 88, 45};
    // int A[] = {1, 3, 11, 55, 88, 405};
    int n = 6;

    printArray(A, n);
    bubbleSort(A, n);
    bubbleSortAdaptive(A, n);
    printArray(A, n);
    return 0;
}
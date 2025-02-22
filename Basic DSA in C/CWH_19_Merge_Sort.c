#include <stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf(" %d ", A[i]);
    }
    printf("\n");
}

// Merging Procedure of in a single array:
void merge(int A[] , int mid , int low , int high){
    int i ,j , k, B[10]; 
    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++ , k++;
        }
        else{
            B[k] = A[j];
            j++ , k++;
        }
    }
    while(i <= mid){              //  copy all remaining elements from left subarray
        B[k] = A[i];
        k++ , i++;
    }
    while(j <= high){             //  copy all remaining elements from right subarray
        B[k] = A[j];
        k++ , j++;
    }
    printArray(A, 8);
    for(int i=low ; i<=high ; i++){
        A[i] = B[i];
    }
}


void mergeSort(int A[] , int low , int high){
    int mid;
    if(low < high){
        mid = (low + high)/2;
        mergeSort(A , low  , mid);
        mergeSort(A , mid + 1 , high);
        merge(A , mid , low , high);
    }
}


int main()
{
    int A[] = {3, 9, 65, 4, 23, 1, 7,19};
    // int A[] = {1, 3, 11, 55, 88, 405};
    int n = 8;

    printf("Input Array :\n");
    printArray(A, n);
    printf("Performing merge Sort\n");
    mergeSort(A, 0, 7);
    printf("Final Output Sorted Array :\n");
    printArray(A, n);
    return 0;
}
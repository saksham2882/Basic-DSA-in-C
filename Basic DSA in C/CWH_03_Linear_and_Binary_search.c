#include <stdio.h>

void Display(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// Linear Search - O(n)
int LinearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++){
        if (arr[i] == element){
            printf("The Element %d Found at index %d", element, i);
            printf("\n");
        }
    }
    return -1;
}


// Binary search :- Array must be sorted. - O(log n)
int BinarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high){
        mid = (low + high) / 2;

        if (arr[mid] == element){
            return mid;
        }
        else if (arr[mid] < element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}


int main(){
    // Sorted Array for binary search
    int arr[] = {1, 6, 7, 8, 54, 89, 120, 270, 396};
    int size = sizeof(arr) / sizeof(int), element = 89;
    
    Display(arr, size);
    
    int search_index = BinarySearch(arr, size, element);

    printf("The Element %d was found at index %d \n", element, search_index);
    return 0;
}
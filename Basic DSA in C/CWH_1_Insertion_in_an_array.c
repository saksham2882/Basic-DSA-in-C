#include <stdio.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertion(int arr[], int size, int element, int capacity, int index){
    if (size >= capacity){
        printf("Insertion Not perform.Due to overflow of Array.\n");
        return -1;
    }
    else{
        for (int i = size - 1; i >= index; i--){
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        printf("Insertion is Performed. And The Element %d is Inserted at index %d\n", element, index);
        return 1;
    }
}

int main(){
    int arr[10] = {1, 5, 3, 8, 367, 23};
    int size = 6, element = 45, index = 3;
    display(arr, size);

    insertion(arr, size, element, 10, index);

    size += 1;
    display(arr, size);
    return 0;
}
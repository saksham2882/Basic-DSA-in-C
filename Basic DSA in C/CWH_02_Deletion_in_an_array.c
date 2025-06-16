#include <stdio.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deletion(int arr[], int size, int element, int index){
    for (int i = index; i < size - 1 ; i++){
        arr[i] = arr[i+1];
    }
    printf("Deletion is Performed. And The Element %d is Deleted from index %d\n", element , index);
}

int main(){
    int arr[10] = {1, 5, 3, 8, 367, 23};
    int size = 6, element = 8 , index = 3;
    display(arr, size); 

    deletion(arr, size, element , index);

    size -= 1;
    display(arr, size);
    return 0;
}
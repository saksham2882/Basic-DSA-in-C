#include<stdio.h>
#include<stdlib.h>

// Creating Stack :
struct stack{
    int size ;
    int top;
    int *arr;
};

// Condition for Empty stack :
int isEmpty(struct stack* ptr){
    if(ptr -> top == -1){
        printf("Stack is UnderFlow!!!");
        return 1;
    }
    else{
        printf("Stack is Not Empty.");
        return 0;
    }
}

// Condition for overflow (full) of stack :
int isFull(struct stack* ptr){ 
    if(ptr -> top == ptr -> size -1){
        printf("Stack is OverFlow!!!");
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    struct stack *s;
    s -> size = 20;
    s -> top = -1;
    s -> arr = (int *)malloc(s -> size * sizeof(int));
    
    // PUSHING an Element manually
    s -> arr[0] = 4;
    s -> top++;

    isEmpty(s);
    return 0;
}
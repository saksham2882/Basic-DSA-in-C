#include<stdio.h>
#include<stdlib.h>

// Creating Stack :
struct stack{
    int size;
    int top;
    int *arr;       // This pointer will help to allocate memory dynamically.
};

// Condition for Empty stack :
int isEmpty(struct stack* ptr){
    if(ptr -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}


// Condition for overflow (full) of stack :
int isFull(struct stack* ptr){ 
    if(ptr -> top == ptr -> size -1){
        return 1;
    }
    else{
        return 0;
    }
}

// PUSHING an Element in stack
void push(struct stack *ptr, int value){
    if(isFull(ptr)){
        printf("Stack is Full (overflow), Cannot PUSH %d to the stack\n", value);
    }
    else{
        ptr -> top++;
        ptr -> arr[ptr -> top] = value;
    }
}

// POP an Element from stack :
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is Empty!!\n");
        return -1;
    }
    else{
        int value = ptr -> arr[ptr -> top];
        ptr -> top--;
        return value;
    }
}

// PEEK Operation in Stack :
int peek(struct stack *sp , int i){
    int arrayInd = sp -> top -i +1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp -> arr[arrayInd];
    }
}

// StackTop :
int stackTop(struct stack *sp){
    return sp -> arr[sp -> top];
}

// StackBottom :
int stackBottom(struct stack *sp){
    return sp -> arr[0];
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s -> size = 10;
    s -> top = -1;
    s -> arr = (int *)malloc(s -> size * sizeof(int));
    printf("Stack has been created successfully\n");
    
    printf("Before Pushing, Full : %d\n", isFull(s));
    printf("Before Pushing, Empty : %d\n", isEmpty(s));

    for(int i = 1; i <= 12; i++) {
        push(s, i);
    }
    
    printf("After pushing, Full : %d\n", isFull(s));
    printf("After pushing, Empty : %d\n", isEmpty(s));

    printf("Element %d Popped from the stack\n", pop(s));

    printf("After popping, Full : %d\n", isFull(s));
    printf("After popping, Empty : %d\n", isEmpty(s));

    // Printing values from the stack :
    for (int j = 1; j <= s -> top + 1 ; j++){
        printf("The value at position %d is %d\n" , j , peek(s , j));
    }

    printf("The TopMost Value of Stack is %d\n", stackTop(s));
    printf("The BottomMost Value of Stack is %d\n", stackBottom(s));
    return 0;
}

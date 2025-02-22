#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// creating top as a global variable.
struct Node *top = NULL;

// Linked List Traversal :
void LinkedListTraversal(struct Node *ptr){
    while (ptr != NULL){
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    }
    printf(" null");
}

// Condition for isEmpty :
int isEmpty(struct Node *top){
    if (top == NULL){ 
        return 1;
    }else{
        return 0;
    }
}

// Condition for stack full :
int isFull(struct Node *top){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node)); 
    if (p == NULL){                  // This means we are not able to create a new node.
        return 1;
    }
    else{
        return 0;
    }
}

// PUSHING operation in stack :
struct Node *push(struct Node *top, int x){
    if (isFull(top)){
        printf("Stack OverFlow\n");
    }
    else{
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n -> data = x;
        n -> next = top;
        top = n;
        return top;
    }
}

// Popped the Element from the stack :
int pop(struct Node *tp){
    if (isEmpty(tp)){
        printf("Stack UnderFlow\n");
    }
    else{
        struct Node *n = tp;
        top = tp -> next;
        int x = n -> data;
        free(n);
        return x;
    }
}


//Peek operations in stack :
int peek(int position){
    struct Node* ptr = top;
    for(int i = 0; (i< position-1 && ptr != NULL); i++){
        ptr = ptr -> next;
    }
    if(ptr != NULL){
        return ptr -> data;
    }
    else{
        return -1;
    }
}

// stackTop:
int stackTop(struct Node* p){
    return p -> data;
}

int main(){
    top = push(top, 45);
    top = push(top, 7);
    top = push(top, 18);
    LinkedListTraversal(top);

    int poped_Element = pop(top);
    printf("\nPopped Element is %d\n", poped_Element);
    LinkedListTraversal(top);

    printf("\nValue at position %d is : %d\n" , 2 , peek(2));
    printf("TopMost value of stack is : %d" , stackTop(top));
    return 0;
}
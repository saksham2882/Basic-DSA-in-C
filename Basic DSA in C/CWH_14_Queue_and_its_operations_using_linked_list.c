#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

// Creating F , and R as a global variable
struct Node * F = NULL;
struct Node * R = NULL;

// Linked List Traversal
void LinkedListTraversal(struct Node *ptr){
    while (ptr != NULL){
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("null\n");
}


// Enqueue Operations :
void enqueue(int value){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){                    // Check for full condition
        printf("Queue is full");
    }
    else{
        n -> data = value;
        n -> next = NULL;

        // Special case : when no node present
        if(F == NULL){
            F = R = n;
        }
        else{
            R -> next = n;
            R = n;
        }
    }
}


// Dequeue Operations :
int dequeue(){
    int value = -1;
    struct Node * ptr = F;
    if(F == NULL){
        printf("Queue is empty\n");
    }
    else{
        F = F -> next;
        value = ptr -> data;
        free(ptr);
    }
    return value;
}

int main(){

    LinkedListTraversal(F);
  
    printf("Dequeuing Element: %d\n" , dequeue());
    enqueue(34);
    enqueue(3);
    enqueue(49);
    enqueue(74);
    enqueue(544);
    LinkedListTraversal(F);
    printf("Dequeuing Element: %d\n" , dequeue());

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void LinkedListTraversalFromStart(struct Node *ptr){
    while (ptr != NULL){
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    }
    printf(" null");
}

void LinkedListTraversalFromEnd(struct Node *tail){
    while (tail != NULL){ 
        printf("%d -> ", tail -> data);
        tail = tail -> prev;
    }
    printf(" null");
}

int main(){
    struct Node *head;
    struct Node *Second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in heap.(dynamic memory allocation)
    head = (struct Node *)malloc(sizeof(struct Node));
    Second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head -> data = 7;
    head -> prev = NULL;
    head -> next = Second;

    // Link second and third nodes
    Second -> data = 11;
    Second -> prev = head;
    Second -> next = third;

    // Link third and fourth nodes
    third -> data = 13;
    third -> prev = Second;
    third -> next = fourth;

    // terminate the list at the fourth node
    fourth -> data = 63;
    fourth -> prev = third;
    fourth -> next = NULL;

    printf("Doubly Linked List Traversal From Staring: \n");
    LinkedListTraversalFromStart(head);

    printf("\nDoubly Linked List Traversal From Ending: \n");
    LinkedListTraversalFromEnd(fourth);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr){
    while (ptr != NULL){
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    }
    printf(" null");
}

int main(){

    struct Node *head;
    struct Node *Second;
    struct Node *third;

    // Allocate memory for nodes in heap.(dynamic memory allocation)
    head = (struct Node *)malloc(sizeof(struct Node));
    Second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head -> data = 7;
    head -> next = Second;

    // Link second and third nodes
    Second -> data = 11;
    Second -> next = third;

    // terminate the list at the third node
    third -> data = 13;
    third -> next = NULL;

    LinkedListTraversal(head);
    return 0;
}
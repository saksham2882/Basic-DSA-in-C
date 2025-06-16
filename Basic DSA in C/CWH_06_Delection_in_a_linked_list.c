#include <stdio.h>
#include <stdlib.h>

// NOTE: We should not move the head; otherwise, it may get lost. Instead, we need to create a new pointer that points to the head, and we will use that for traversal.

struct Node{
    int data;
    struct Node *next;
};

// Traversal
void LinkedListTraversal(struct Node *ptr){
    while (ptr != NULL){
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    }
    printf(" null");
}

// Case 1: Deleting the first element from the linked list:-
struct Node *DeleteFirst(struct Node *head){
    struct Node *ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

// Case 2: Deleting the element At a (given) Index from the linked list:-
struct Node *DeleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head -> next;

    for (int i = 0; i < index - 1; i++){
        p = p -> next;
        q = q -> next;
    }

    p -> next = q -> next;
    free(q);
    return head;
}

// Case 3: Deleting the Last element from the linked list:-
struct Node *DeleteLast(struct Node *head){
    struct Node *p = head;
    struct Node *q = head -> next;

    while (q -> next != NULL){
        p = p -> next;
        q = q -> next;
    }

    p -> next = NULL;
    free(q);
    return head;
}

// Case 4: Deleting the element (node) with a given value from the linked list:-
struct Node *DeleteAtGivenValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head -> next;

    while (q -> data != value && q -> next != NULL){
        p = p -> next;
        q = q -> next;
    }

    if (q -> data == value){
        p -> next = q -> next;
        free(q);
    }
    return head;
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

    printf("Linked List Before Deletion:\n");
    LinkedListTraversal(head);

    // head = DeleteFirst(head);
    // head = DeleteFirst(head); 
    // head = DeleteAtIndex(head, 1);
    // head = DeleteLast(head);

    head = DeleteAtGivenValue(head, 11);

    printf("\nLinked List After Deletion:\n");
    LinkedListTraversal(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// Traversal of circular linked list
void LinkedListTraversal(struct Node *head){
    struct Node *ptr = head;

    do{
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    } while (ptr != head);
    printf(" null");
}

// Insertion in a Circular Linked List:-
struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    
    struct Node *p = head -> next; 

    while (p -> next != head){
        p = p -> next;                // Now p at last node.
    }

    // At this Point p points to the last node of circular linked list.
    p -> next = ptr;
    ptr -> next = head;
    head = ptr;
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
    third -> next = head;

    printf("Circular Linked List Before insertion :\n");
    LinkedListTraversal(head);

    head = insertAtFirst(head, 45);
    head = insertAtFirst(head, 7);
    head = insertAtFirst(head, 18);

    printf("\nCircular Linked List After insertion : \n");
    LinkedListTraversal(head);
    return 0;
}
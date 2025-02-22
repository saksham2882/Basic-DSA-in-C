#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// Linked List Traversal
void LinkedListTraversal(struct Node *ptr){
    while (ptr != NULL){
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    }
    printf(" null");
}


//  Insert At begining
struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}


// Insert At Index (in between) :-
struct Node * insertAtIndex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i!= index - 1){
        p = p -> next; 
        i++ ;
    }
    ptr -> data = data;
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}


// Insert At End :-
struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node *p = head;

    while (p -> next != NULL){
        p = p -> next;
    }
    ptr -> next = NULL;
    p -> next = ptr;
    return head;
}


// Insert After a given Node:- 
struct Node * insertAfterNode(struct Node * head, struct Node *prevNode ,  int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
     
    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;
    
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

    printf("Linked List Before Insertion :\n");
    LinkedListTraversal(head);

    // head = insertAtFirst(head, 45);
    // head = insertAtIndex(head, 28 , 2);
    // head = insertAtEnd(head, 30);
    head = insertAfterNode(head, Second ,60);

    printf("\nLinked List After Insertion :\n");
    LinkedListTraversal(head);
}
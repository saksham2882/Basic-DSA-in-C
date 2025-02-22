#include <stdio.h>
#include <malloc.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

// Creating a Node
struct Node *createNode(int data){
    struct Node *n;                                 // node pointer
    n = (struct Node *)malloc(sizeof(struct Node)); // allocate memory in the heap

    n -> data = data;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

int main(){
    struct Node *p = createNode(2);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(4);

    // linking the root node with the left and right children
    p -> left = p1;
    p -> right = p2;

    return 0;
}
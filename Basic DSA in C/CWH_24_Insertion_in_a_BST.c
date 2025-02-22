#include <stdio.h>
#include <malloc.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

// Creating a Node
struct Node *createNode(int data){
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n -> data = data;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}


// Insertion in a BST :
void insert(struct Node *root , int key){
    struct Node *prev = NULL;
    while(root != NULL){
        prev = root;
        if(key == root -> data){
            printf("Cannot insert %d , Already in BST\n", key);
            return;
        }
        else if(key < root -> data){
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }

    struct Node* new = createNode(key);
    if(key < prev -> data){
        prev -> left = new;
    }
    else{
        prev -> right = new;
    }
}

// InOrder Traversal :
void InOrder(struct Node *root){
    if (root != NULL){
        InOrder(root -> left);
        printf("%d ", root -> data);
        InOrder(root -> right);
    }
}

int main(){
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    // Binary Search Tree Looking like  this:
    //         5
    //        / \
    //       3   6
    //      / \
    //     1   4

    // linking the root node with the left and right children
    p -> left = p1;
    p -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;

    printf("InOrder Before Insertion: ");
    InOrder(p);
    
    insert(p , 2);

    printf("\nInOrder After Insertion: ");
    InOrder(p);
    return 0;
} 
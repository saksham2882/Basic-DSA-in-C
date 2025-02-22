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

// PreOrder Traversal :
void PreOrder(struct Node* root){
    if(root != NULL){
        printf("%d " , root -> data);
        PreOrder(root -> left);
        PreOrder(root -> right);
    }
}

// PostOrder Traversal :
void PostOrder(struct Node* root){
    if(root != NULL){
        PostOrder(root -> left);
        PostOrder(root -> right);
        printf(" %d" , root -> data);
    }
}

// InOrder Traversal :
void InOrder(struct Node* root){
    if(root != NULL){
        InOrder(root -> left);
        printf("%d " , root -> data);
        InOrder(root -> right);
    }
}

int main(){
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);

    // Tree Looking like  this:
    //         4
    //        / \
    //       1   6
    //      / \
    //     5   2

    //linking the root node with the left and right children
    p -> left = p1;
    p -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;

    printf("PreOrder Traversal: ");
    PreOrder(p);

    printf("\nPostOrder Traversal: ");
    PostOrder(p);

    printf("\nInOrder Traversal: ");
    InOrder(p);
    return 0;
}
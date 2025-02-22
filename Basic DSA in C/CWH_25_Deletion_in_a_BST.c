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

// InOrder Predecessor
struct Node *inOrderPredecessor(struct Node *Tnode){
    Tnode = Tnode -> left;
    while (Tnode -> right != NULL){
        Tnode = Tnode -> right;
    }
    return Tnode;
}

// Deletion in a BST:
struct Node *deleteNode(struct Node *Tnode, int value){
    struct Node *iPre;

    if (Tnode == NULL){
        return NULL;
    }
    if (Tnode -> left == NULL && Tnode -> right == NULL){
        free(Tnode);
        return NULL;
    }

    // Search for the node to be deleted
    if (value < Tnode -> data){
        Tnode -> left = deleteNode(Tnode -> left, value);
    }
    else if (value > Tnode -> data){
        Tnode -> right = deleteNode(Tnode -> right, value);
    }

    // Deletion when the node is found
    else{
        iPre = inOrderPredecessor(Tnode);
        Tnode -> data = iPre -> data;
        Tnode -> left = deleteNode(Tnode -> left, iPre -> data);
    }

    return Tnode;
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

    InOrder(p);
    deleteNode(p, 5);

    printf("\nThat Node is replaced by %d\n" , p -> data);
    InOrder(p);

    return 0;
}
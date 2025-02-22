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


// Check for BST :
int isBST(struct Node *root){
    // Made prev static so it's NULL only initially (root has no parent), but not reset later.
    static struct Node *prev = NULL;

    if (root != NULL){
        if (!isBST(root -> left)){
            return 0;
        }
        if (prev != NULL && root -> data <= prev -> data){
            return 0;
        }
        prev = root;
        return isBST(root -> right);
    }
    else{
        return 1;
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
    struct Node *p1 = createNode(3 );
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
    int result = isBST(p);
    if(result == 1){
        printf("\nIt is a Binary Search Tree\n");
    }
    else{
        printf("\nThis Binary Tree is not a Binary Search Tree\n");
    }
    return 0;
}
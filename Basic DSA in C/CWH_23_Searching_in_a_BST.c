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

// Searching Element (Iteratively) in a BST:
struct Node *search_element_Iteratively(struct Node* root , int key){
    while(root != NULL){
        if(key == root -> data){
            return root;
        }
        else if(key < root -> data){
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }
    return NULL;
}

// Searching Element (Recursively) in a BST:
struct Node *search_element(struct Node* root , int key){
    if(root == NULL){
        return NULL;
    }
    if(key == root -> data){
        return root;
    }
    else if(key < root -> data){
        return search_element(root -> left , key);
    }
    else{
        return search_element(root -> right , key);
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

    struct Node* n = search_element(p , 7);
    // struct Node* n = search_element_Iteratively(p , 4);
    
    if(n != NULL){
        printf("Element %d Found\n" , n -> data);
    }
    else{
        printf("Element not Found");
    }
    return 0;
}
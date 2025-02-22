#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int F;
    int R;
    int *arr;
};

//Check for isFull Condition :
int isFull(struct Queue *q){
    if(q -> R == q -> size-1){
        return 1;
    }
    return 0;
}

//Check for isEmpty Condition :
int isEmpty(struct Queue *q){
    if(q -> R == q -> F){
        return 1;
    }
    return 0;
}

// Enqueue operation :
void enqueue(struct Queue *q , int value){
    if(isFull(q)){
        printf("Queue is Full\n");
    }
    else{
        q -> R++;
        q -> arr[q -> R] = value;
    }
}

// Dequeue operation :
int dequeue(struct Queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
        q -> F++;
        a = q -> arr[q -> F];
    }
    return a;
}

int main(){
    struct Queue q;
    q.size = 20;
    q.F = q.R = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    // BFS Implementation
    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    int a[7][7] = {          // Adjacency matrix representation
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q , i);        // Enqueue i for exploration

    while(!isEmpty(&q)){
        int node = dequeue(&q);
        for(int j=0 ; j<7; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d " , j);
                visited[j] = 1;
                enqueue(&q , j);
            }
        }
    }

    return 0;
}
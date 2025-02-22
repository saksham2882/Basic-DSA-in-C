#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int F;
    int R;
    int *arr;
};

//Check for isFull Condition :
int isFull(struct queue *q){
    if(q -> R == q -> size-1){
        return 1;
    }
    return 0;
}

//Check for isEmpty Condition :
int isEmpty(struct queue *q){
    if(q -> R == q -> F){
        return 1;
    }
    return 0;
}

// Enqueue operation :
void enqueue(struct queue *q , int value){
    if(isFull(q)){
        printf("Queue is full\n");
    }
    else{
        q -> R++;
        q -> arr[q -> R] = value;
        printf("Enqueued Element : %d\n" , value);
    }
}

// Dequeue operation :
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        q -> F++;
        a = q -> arr[q -> F];
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 4;
    q.F = q.R = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueue(&q ,12);
    enqueue(&q , 15);
    enqueue(&q , 45);
    enqueue(&q , 18);

    printf("Dequeuing Element %d\n" , dequeue(&q));
    printf("Dequeuing Element %d\n" , dequeue(&q));

    return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct CircularQueue{
    int size;
    int F;
    int R;
    int *arr;
};

//Check for isFull Condition :
int isFull(struct CircularQueue *q){
    if((q -> R + 1)%q -> size == q -> F){
        return 1;
    }
    return 0;
}

//Check for isEmpty Condition : (same as linear queue)
int isEmpty(struct CircularQueue *q){
    if(q -> R == q -> F){
        return 1;
    }
    return 0;
}

// Enqueue operation :
void enqueue(struct CircularQueue *q , int value){
    if(isFull(q)){
        printf("CircularQueue is full\n");
    }
    else{
        q -> R = (q -> R + 1)%q -> size;
        q -> arr[q -> R] = value;
        printf("Enqueued Element : %d\n" , value);
    }
}

// Dequeue operation :
int dequeue(struct CircularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("CircularQueue is empty\n");
    }
    else{
        q -> F = (q -> F + 1)%q -> size;
        a = q -> arr[q -> F];
    }
    return a;
}

int main(){
    struct CircularQueue q;
    q.size = 4;
    q.F = q.R = 0;           // zero; otherwise, the circular queue will never be full (means it will never satisfy the full condition. so, I have reserved one place, "0" in the queue).
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueue(&q ,12);
    enqueue(&q , 45);

    printf("Dequeuing Element %d\n" , dequeue(&q));
    printf("Dequeuing Element %d\n" , dequeue(&q));
    enqueue(&q , 455);
    enqueue(&q , 55);

    return 0;
}
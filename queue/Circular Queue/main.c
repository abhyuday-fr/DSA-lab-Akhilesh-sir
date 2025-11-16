#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


struct queue{
    int item[SIZE];
    int front;
    int rear;
};

struct queue q;

void Initialize(){
    q.front=SIZE-1;
    q.rear=SIZE-1;
}

void Enqueue(int x){
    if((q.rear+1)%SIZE==q.front){
        printf("Queue Overflow\n");
        exit(1);
    }
    else{
        q.rear=(q.rear+1)%SIZE;
        q.item[q.rear]=x;
    }
}

int Dequeue(){
    if(q.front==q.rear){
        printf("Queue Underflow");
        exit(1);
    }
    else{
        int x;
        q.front=(q.front+1)%SIZE;
        x=q.item[q.front];
        return x;
    }
}

int main(){
    Enqueue(1);
    Enqueue(2);
    Enqueue(2);
    Enqueue(2);
    Enqueue(2);
    printf("%d ",Dequeue());
    printf("%d ",Dequeue());
    printf("%d ",Dequeue());
    Enqueue(2);
    Enqueue(2);
    Enqueue(6);
    Enqueue(3);
    printf("%d ",Dequeue());
    printf("%d ",Dequeue());
    printf("%d ",Dequeue());
    printf("%d ",Dequeue());
    printf("%d ",Dequeue());
    printf("%d ",Dequeue());
    
    
    return 0;
}
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
    q.front=0;
    q.rear=-1;
}

void Enqueue(int x){
    if(q.rear==SIZE-1){
        printf("Queue Overflow\n");
        exit(1);
    }
    else{
        q.rear+=1;
        q.item[q.rear]=x;
    }
}

int Dequeue(){
    if(q.rear-q.front+1==0){
        printf("Queue underflow\n");
        exit(1);
    }
    else{
        int x=q.item[q.front];
        q.front+=1;
        return x;
    }
}

int main(){
    Initialize();
    Enqueue(5);
    Enqueue(2);
    printf("%d ",Dequeue());
    printf("%d ",Dequeue());
    printf("%d ",Dequeue());
    
    return 0;
}
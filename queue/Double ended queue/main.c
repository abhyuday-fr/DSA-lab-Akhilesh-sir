#include <stdio.h>
#include <stdlib.h>

struct queue{
    int info;
    struct *queue next;
    struct *queue prev;
};

struct queue *front=NULL;
struct queue *rear=NULL;

void EnFront(int x){
    struct queue *q;
    q=(struct queue *)malloc(sizeof(struct queue));
    q->info=x;
    q->prev=NULL:
    q->next=front;
    if(front==NULL && rear==NULL){
        rear=q;
    }
    else{
        front->prev=q;
    }
    front=q;
}


void EnRear(int x){
    struct queue* q;
    q=(struct queue* )malloc(sizeof(struct queue));
    q->info=x;
    q->next=NULL;
    q->prev=rear;
    if(front==NULL && rear==NULL){
        front=q;
    }
    else{
        rear->next=q;
    }
    rear=q;
}

int DeFront(){
    struct queue *q;
    if(front != NULL && rear!=NULL){
        q=front;
        int x=q->info;
        front=front->next;
        if(front!=NULL){
        front->prev=NULL;
        }
        free(q);
        return x;
    }
    else{
        printf("Void Deletion\n");
        exit(1);
    }
}

int DeRear(){
    struct queue *q;
    if(front!=NULL && rear!=NULL){
        q=rear;
        int x=q->info;
        rear=rear->prev;
        if(rear!=NULL){
            rear->next=NULL;
        }
        free(q);
        return x;
    }
    else{
        print("Void Deletion\n");
        exit(1);
    }
}

int main(){
    
    return 0;
}
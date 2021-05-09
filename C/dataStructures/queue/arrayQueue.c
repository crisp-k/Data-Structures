#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int *queueList;
    int front;
    int noe;
    int size;
} queue;

queue *createQueue(int size)
{
    queue *newQueue = (queue*) malloc(sizeof(queue));

    newQueue->queueList = (int *) malloc(size * sizeof(int));
    newQueue->front = 0;
    newQueue->noe = 0;
    newQueue->size = size;

    return newQueue;
}

void enQueue(queue *q, int data)
{
    if(q->noe == q->size)
        printf("Error! Queue full\n");
    else
    {
        q->queueList[(q->noe + q->front) % q->size] = data;
        q->noe++; 
    }
}

void printQueue(queue *q)
{
    for(int i = 0; i < q->size; i++)
        printf("%d ", q->queueList[i]);

    printf("\n");
}

int main(void)
{
    queue *q = createQueue(10);

    for(int i = 0; i <= 10; i++)
    {
        enQueue(q, i);
        printQueue(q);
    }
        

    
}
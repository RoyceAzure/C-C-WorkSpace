#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define true 1
#define false 0

typedef unsigned char boolean;
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *pre;
} *QNodeptr;
typedef struct queue
{
    QNodeptr front, end;
    unsigned int length ;
} *Mqueue;

boolean isQueueEmpty(Mqueue queue)
{
    if(queue->front == NULL)
        return true;
    return false;
}
Mqueue PushQueue(Mqueue queue, int data)
{
    QNodeptr Nnode = (QNodeptr)calloc(1, sizeof(struct Node));
    Nnode->data = data;
    if(isQueueEmpty(queue))   //Queue 初始化
    {
        queue->front = queue->end = Nnode;
        queue->length = 1;
    }
    else
    {
        (queue->end)->next = Nnode;
        Nnode->pre = queue->end;
        queue->end = Nnode;
        (queue->length)++;
    }
    return queue;
}

int PopQueue(Mqueue queue)
{
    int data;
    QNodeptr temp = NULL;
    if(isQueueEmpty(queue))   //Queue 初始化
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        temp = queue->front;
        data = queue->front->data;
        if(queue->front == queue->end)
        {
            queue->front = queue->end = NULL;
        }
        else
        {
            queue->front->next->pre = NULL;
            queue->front = queue->front->next;
        }
        free(temp);
        (queue->length)--;
    }
    return data;
}
void printQ(Mqueue q)
{
    QNodeptr front = q->front, end = q->end;
    printf("Order Queue : ");
    while(front)
    {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
    printf("Reverse Queue : ");
    while(end)
    {
        printf("%d ", end->data);
        end = end->pre;
    }
    printf("\n");
}

void printMenu()
{
    puts("1.Push data into queue");
    puts("2.Pop data from queue");
    puts("3. exit");
}

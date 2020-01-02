#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define true 1
#define false 0

typedef unsigned char bool;
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

bool isQueueEmpty(Mqueue queue)
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

Mqueue PopQueue(Mqueue queue)
{
    int data;
    QNodeptr temp = NULL;
    if(isQueueEmpty(queue))   //Queue 初始化
    {
        printf("Queue is empty\n");
        return queue;
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
    return queue;
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
int main()
{
    int data;
    unsigned int choice = 0;
    srand(time(NULL));
    Mqueue queue = (Mqueue)calloc(1, sizeof(struct queue));

    while(choice !=3)
    {
        printMenu();
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("input number:\n");
                scanf("%d", &data);
                PushQueue(queue, data);
                printQ(queue);
                break;
            case 2:
                PopQueue(queue);
                printQ(queue);
                break;
            case 3:
                break;
        }
    }
    // while(scanf("%d", &data) == 1)
    // {
    //     printf("push:\n");
    //     PushQueue(queue, data);
    //     printQ(queue);
    // }
    // while(queue)
    // {
    //     printf("pop:\n");
    //     PushQueue(queue, data);
    //     printQ(queue);
    // }

    return 0;
}
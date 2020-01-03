#ifndef MDATASTRUCT_H
#define MDATASTRUCT_H
#define true 1
#define false 0
typedef struct node
{
	int data;
    unsigned int height;
    struct node *left;
	struct node *right;
} Node;
typedef Node *Nptr;

typedef unsigned char boolean;
typedef struct QNode
{
    int data;
    struct QNode *next;
    struct QNode *pre;
} *QNodeptr;
typedef struct queue
{
    QNodeptr front, end;
    unsigned int length ;
} *Mqueue;

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} * TreeNodePtr;
typedef struct TreeQueue
{
    TreeNodePtr front, end;
    unsigned int length ;
} * MTreeQueue;


#endif

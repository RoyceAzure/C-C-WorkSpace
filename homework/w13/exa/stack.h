#include "space.h"

typedef struct node
{
    void *dataPtr;
    struct node *next;
    struct node *prev;
}tNode;

typedef struct nodeInfo
{
    int count;
    tNode *head;
}tList;

tList *createList(void); 
void handlePutOperation (tList *pList); 
void handleRemoveOperation(tList *pList, int choose); 
void printListContent(tList *pList); 

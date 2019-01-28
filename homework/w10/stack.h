#include "space.h"

typedef struct node
{
    tTypeScore *dataPtr;
    struct node *next;
}tNode;

typedef struct nodeInfo
{
    int count;
    tNode *head;
}tStack;

tStack *createStack(void);  //Create a stack
void handlePushOperation (tStack *pStack); //push a dataPtr to a specific stack
void handlePopOperation (tStack *pStack); //pop a specific stack and return a void* dataPtr
void printStackContent(tStack *pStack); //print all content in stack

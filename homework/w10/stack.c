#include "stack.h"

tStack *createStack(void)
{
	tStack *nStack = (tStack*)calloc(1,sizeof(tStack));
	return nStack;
}

void handlePushOperation(tStack *pStack)
{
	if(pStack->count == N)
	{
		printf ("  handlePushOperation(): space full \n");
		return;
	}
	
	int score;  
    printf("  handlePushOperation(): enter score value: ");
    scanf("%d", &score);
    
    tTypeScore *pScore;
    getScoreSpace(&pScore);
	
	tNode *NewNode = (tNode*)calloc(1,sizeof(NewNode));
	NewNode->dataPtr = pScore;
	NewNode->dataPtr->score = score;
	NewNode->next = pStack->head;
	pStack->head = NewNode;
    pStack->count++;
    return; 
}

void handlePopOperation(tStack *pStack)
{
	if(pStack->count == 0 )
		{
			printf ("	handlePopOperation(): nothing in stack  \n");
			return;	
		}
	
	tNode *current = pStack->head;
	pStack->head = current->next;
	tTypeScore *dataptr = current->dataPtr;
	free(current);
	
	pStack->count--;
	printf("	handlePopOperation(): poped value: %d\n",dataptr->score );
	returnScoreSpace(dataptr->loc);
}

void printStackContent(tStack *pStack)
{
	printf("	printStackContent(): stack items -> ");
	tNode *current = pStack->head;
	while(current)
	{
		printf("%d ",current ->dataPtr->score);
		current = current->next;
	}
}



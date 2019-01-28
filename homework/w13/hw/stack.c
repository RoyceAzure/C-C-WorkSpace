#include "stack.h"

tList * createList(void) {
	tList *pList;
	pList = (tList *) malloc (sizeof(tList));
	pList->count = 0;
	pList->head = NULL;
	return pList;
}

void handlePutOperation (tList *pList) {
	int choose;
	printf("  handlePutOperation(): which type do you want (1) score (2) ID: ");
	scanf("%d",&choose);
	void *pMem;
	if (choose == 1) {
		if (checkFreeScoreSpace()) {
			printf("  handlePutOperation(): enter score value: ");
			int score;
			pMem = (void*)scoreBuf;
			scanf("%d",&score);
			getScoreSpace(&pMem); //already cast and point to empty space
			
			((tTypeScore*)pMem)->score = score ;
			tNode *newN = (tNode*)calloc(1,sizeof(tNode));
			newN->dataPtr = pMem;
			
			if( pList->count ==0)
			{
				pList->head = newN;	
			}
			else
			{
				newN->next = pList->head;
				pList->head = pList->head->prev = newN;
				
			}	
			pList->count++;		
			
		} else {
			printf ("  handlePutOperation(): score space full \n");
			return;
		}
	} 
	else if (choose == 2) 
	{
		if (checkFreeIdSpace()) 
		{
			int id;
			printf("  handlePutOperation(): enter ID value: ");
			scanf("%d",&id);
			pMem = (void*)idBuf;
			getIdSpace(&pMem);
			
			((tTypeId*)pMem)->id = id;
			tNode *newN = (tNode*)calloc(1,sizeof(tNode));
			newN->dataPtr = pMem;
			
			if( pList->count ==0)
			{
				pList->head = newN;	
			}
			else
			{
				newN->next = pList->head;
				pList->head = pList->head->prev = newN;
				
			}	
			pList->count++;


		} 
		else 
		{
			printf ("  handlePutOperation(): id space full \n");
			return;
		}
	} 
	else 
	{
		printf("  handlePutOperation(): no such type \n");
		return;
	}

	return;
}

void handleRemoveOperation(tList *pList, int choose) {
	tNode *pNode;
	tTypeScore *pScore;
	tTypeId *pId;
	void* pre;
	int i;

	if (pList->count == 0) 
	{
		printf ("  handlePopOperation(): nothing in list = \n");
		return;
	}
	if (choose > pList->count) 
	{
		printf ("  handlePopOperation(): exceed range = \n");
		return;
	}
	pNode = pList->head;
	if (choose == 1 && pList->count!=1) 
	{
		pNode->next->prev = NULL;
		pList->head = pNode->next;
	} 
	else if(choose == 1)
	{
		pList->head = NULL;
	}
	else
	{
		int i=0;
		for(i; i<choose-1; i++)
		{
			pNode = pNode->next;
		}
		
		if(choose == pList->count)
		{
			pNode->prev = pNode->prev->next = NULL; 
		}
		else
		{
			pNode->prev->next = pNode->next;
			pNode->next->prev = pNode->prev;
		}
	}
	pScore = (tTypeScore*)(pNode->dataPtr);
	free(pNode);
	pList->count--;
	if ( pScore->type == 1) 
	{ //tTypeScore
		returnScoreSpace(pScore->loc);
		printf("  handleRemoveOperation(): removed type 1, value %d\n", pScore->score);
	} 
	else 
	{
		pId = (tTypeId*)pScore;
		returnIdSpace (pId->loc);
		printf("  handleRemoveOperation(): removed type 2, value %d\n", pId->id);
	}
}

void printListContent(tList *pList) {
	int i;
	tNode *pNode = pList->head;
	printf("   printListContent(): list items -> ");
	for (i=0; i<pList->count; i++) 
	{
		int type = ((tTypeScore *)pNode->dataPtr)->type;
		printf("type%d ", type);
		if(type == 1)
		{
			printf("score:%d ", ((tTypeScore *)pNode->dataPtr)->score);
		}
		else
		{
			printf("id:%d ", ((tTypeScore *)pNode->dataPtr)->score);
		}
		pNode = pNode->next;
	}
	printf("\n");
}


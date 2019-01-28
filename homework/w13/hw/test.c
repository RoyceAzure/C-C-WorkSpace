#include <stdio.h>
#include <stdlib.h>
#define N 8
#define TEST_BIT(target,bit) ((target >> bit) & (0x01))
#define SET_BIT(target,bit) (target |= (0x01 << bit))
#define CLEAR_BIT(target,bit) (target &= (~(0x01 << bit)))




typedef struct Score
{   
	int type;
    int score;
    int loc;    
}tTypeScore;

typedef struct Id
{   
	int type;
    short id;
    int loc;    
}tTypeId;

tTypeScore scoreBuf[N]; //preallocated memory space
unsigned char scoreBitmap = 0xFF;

tTypeId idBuf[N]; //preallocated memory space
unsigned char idBitmap = 0xFF;

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

int checkFreeScoreSpace(void)
{
	return  scoreBitmap != 0;
}
int checkFreeIdSpace(void)
{
	return  idBitmap != 0;
}
int checkBit(unsigned char map) //return i as index
{
	int i=0;
	for(i; i<8; i++)
	{
		if(TEST_BIT(map,i))
		{
			return i;
		}
	}
}
void set_bit(unsigned char *target, unsigned char bit, int flag)  //flag 1 : set 1,  flag 0: set 0
{
	if(flag)
	{
		SET_BIT(*target,bit);	
	}
	else
	{
		CLEAR_BIT(*target,bit);
	}
}

void getScoreSpace(void **ppScore)
{	
	int free = checkBit(scoreBitmap);
	set_bit(&scoreBitmap, free, 0);
    printf("     getScoreSpace(): giving space numbered %d, result bitmap 0x%x\n", free, scoreBitmap);
    *ppScore = (tTypeScore*)*ppScore + free;
    ((tTypeScore*)*ppScore)->type = 1;
    ((tTypeScore*)*ppScore)->loc = free;  //??
    return;
}
void getIdSpace(void **ppId)
{
	int free = checkBit(idBitmap);
	set_bit(&idBitmap, free, 0);
    printf("     getScoreSpace(): giving space numbered %d, result bitmap 0x%x\n", free, idBitmap);
    *ppId = (tTypeId*)*ppId + free;
    ((tTypeId*)*ppId)->type = 2;
    ((tTypeId*)*ppId)->loc = free;  //??
    return;
}
void returnScoreSpace (int loc)
{
	set_bit(&scoreBitmap, loc, 1);
    printf("     returnScoreSpace(): return space numbered %d, result bitmap 0x%x\n", loc, scoreBitmap);
}

void returnIdSpace (int loc)
{
	set_bit(&idBitmap, loc, 1);
    printf("     returnIdSpace(): return space numbered %d, result bitmap 0x%x\n", loc, idBitmap);
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

tList * createList(void) {
	tList *pList;

	pList = (tList *) malloc (sizeof(tList));
	pList->count = 0;
	pList->head = NULL;

	return pList;
}
void printListContent(tList *pList) {
	int i;
	tNode *pNode = pList->head;

	printf("   printListContent(): list items -> ");
	for (i=0; i<pList->count; i++) {
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

void handleRemoveOperation(tList *pList, int choose) {
	tNode *pNode;
	tTypeScore *pScore;
	tTypeId *pId;
	void* pre;
	int i;

	if (pList->count == 0) {
		printf ("  handlePopOperation(): nothing in list = \n");
		return;
	}
	if (choose > pList->count) {
		printf ("  handlePopOperation(): exceed range \n");
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
	if ( pScore->type == 1) { //tTypeScore
		returnScoreSpace(pScore->loc);
		printf("  handleRemoveOperation(): removed type 1, value %d\n", pScore->score);

	} else {
		pId = (tTypeId*)pScore;
		returnIdSpace (pId->loc);
		printf("  handleRemoveOperation(): removed type 2, value %d\n", pId->id);

	}


}


int main(void) {
 	tList *pList = createList();
    int choose;

    while (1)
    {
        //menu 
        printf("\n(0) put or (1~x) remove a item from list:  ");
        scanf("%d", &choose);

    	if (choose == 0)
    	{
            handlePutOperation(pList);
        }
        else
        {
            handleRemoveOperation(pList, choose);
        }
        
        printListContent(pList);
        
    }
    
	return 0;
}

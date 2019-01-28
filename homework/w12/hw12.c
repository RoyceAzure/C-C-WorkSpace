#include <stdio.h>
#include <stdlib.h>


#define N 5
//---------------------stack.h-------------------------------------------

typedef struct Score
{   
    int score;
    int loc;
    int used;      // to record if the space is used    
}tTypeScore;


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
tTypeScore scoreBuf[N];
int rear;
tStack *createStack(void);  //Create a stack
void handlePushOperation (tStack *pStack); //push a dataPtr to a specific stack
void handlePopOperation (tStack *pStack); //pop a specific stack and return a void* dataPtr
void printStackContent(tStack *pStack); //print all content in stack
void getScoreSpace (tTypeScore **ppScore); //get the space from scoreBuf, return the allocated number
void returnScoreSpace (int location);  //return the space of the used scoreBuf


//---------------------stack.h-------------------------------------------

//---------------------space.h-------------------------------------------






//---------------------space.h-------------------------------------------

//---------------------space.c-------------------------------------------
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
	NewNode->dataPtr->loc = rear;
	NewNode->dataPtr->used = 1;
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

	tNode *current = pStack->head->next;
	tTypeScore *dataptr = pStack->head->dataPtr;
	pStack->head->next = pStack->head->dataPtr = NULL;
	free(pStack->head);
	pStack->head =current; 
//	pStack->head = current->next;
//	tTypeScore *dataptr = current->dataPtr;
//	current->next = current->dataPtr = NULL;
//	free(current);
	
	dataptr->used = 0;
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
		printf("%d ",current->dataPtr->score);
		current = current->next;
	}
}
//-----------------------stack.c------------------------------

//-----------------------space.c------------------------------

 //preallocated memory space

void getScoreSpace(tTypeScore **ppScore)
{
	*ppScore = scoreBuf;
	
	int i;
	for(i=0; i<N; i++)
	{
		if((*ppScore+rear)->used == 1)
		{
			rear = (rear+1) % N;
		}
		else
		{
			*ppScore = *ppScore+rear;
			return;
		}
	}		
}

void returnScoreSpace (int loc)
{
	scoreBuf[loc].used = 0;
    printf("	returnScoreSpace(): return space numbered %d\n", loc);
    
}

void printMem()
{
	int i;
	printf("Data in memory:\n");
	for(i =0; i<N; i++)
	{
		printf("%d ",scoreBuf[i].score);
	}
}
//-----------------------space.c------------------------------


int main(void) {

    tStack *pStack = createStack();
    tTypeScore *pScore;
    int choose;
	rear=0;
    while (1)
    {
        //menu 
        printf("\n(1) push or (2) pop a item to/from stack: ");
        scanf("%d", &choose);

    	if (choose == 1)
    	{
            handlePushOperation(pStack);
        }
        else if (choose == 2)
        {
            handlePopOperation(pStack);
        }
        
        printStackContent(pStack);
        printf("\n");
        printMem();
    }
    
	return 0;
}

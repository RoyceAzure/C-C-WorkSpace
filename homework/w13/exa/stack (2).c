#include "stack.h"

tList *createList(void)
{
    tList *pList;
    
    pList = (tList *) malloc (sizeof(tList));
	  pList->count = 0;
	  pList->head = NULL;
	  
	  return pList;
}

void handlePutOperation (tList *pList)
{





	  
    printf("  handlePutOperation(): which type do you want (1) score (2) ID: ");
    scanf("%d",&choose);
	  
	  if (choose == 1)
	  {
	      if (checkFreeScoreSpace())
	      {
            printf("  handlePutOperation(): enter score value: ");
            scanf("%d",&score);

            getScoreSpace(xxxxx);


	      }
	      else
	      {
    	      printf ("  handlePutOperation(): score space full \n");
	          return;	      	
	      }
	  }
	  else if (choose == 2)
	  {
	      if (checkFreeIdSpace())
	      {
            printf("  handlePutOperation(): enter ID value: ");
            scanf("%d",&id);

            getIdSpace(xxxxxxx);


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

void handleRemoveOperation(tList *pList, int choose)
{
	  tNode *pNode;
	  tTypeScore *pScore;
	  tTypeId *pId;
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
	  

	  if (choose == 1)
	  {





	  }
	  else
	  {









	  }
	  
    if (  ->type == 1) //tTypeScore
    {

	      printf("  handleRemoveOperation(): removed type 1, value %d\n", pScore->score);

    }
    else
    {

	      printf("  handleRemoveOperation(): removed type 2, value %d\n", pId->id);

    }    


}

void printListContent(tList *pList)
{
    int i;
    tNode *pNode = pList->head;
    
    printf("   printListContent(): list items -> ");
    for (i=0; i<pList->count; i++)
    {
        printf("type%d ", ((tTypeScore *)pNode->dataPtr)->type);
        pNode = pNode->next;
    }
    printf("\n");
}


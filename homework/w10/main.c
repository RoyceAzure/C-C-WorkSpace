#include "stack.h"

void printMem()
{
	int i;
	for(i=0; i<N; i++)
	{
		printf("%d ",scoreBuf[i].score);
	}
	printf("\n");
	printf("Myindex %d\n",Myindex);
}


int main(void) {

    tStack *pStack = createStack();
    tTypeScore *pScore;
    int choose;
	
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


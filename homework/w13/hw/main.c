#include "stack.h"

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

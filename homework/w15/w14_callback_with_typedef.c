#include <stdio.h>
#include <stdlib.h>

#define TOTAL 5

typedef int Int32;
typedef Int32 Buf[TOTAL];


Int32 CompInc (Int32 x, Int32 y)
{
	if(x>y)
	{
		return 1;	
	}
	else
	{
		return 0;
	}
}
Int32 CompDec (Int32 x, Int32 y)
{
	if(x<y)
	{
		return 1;	
	}
	else
	{
		return 0;
	}
}

void bubbleSort(Buf *buf, Int32 (bsort)(Int32 , Int32))
{
    Int32 i, j;
    Int32 tmp;

//	int n = sizeof(buf) / sizeof(int);
//	printf("%d",n );
    for (i = TOTAL-1; i > 0; i--)
    {
        for (j = 0; j <= i - 1; j++)
        {
			if(bsort(*(buf)[j],*(buf)[j+1]))
			{
				tmp = *(buf)[j];
				*(buf)[j]= *(buf)[j+1];
				*(buf)[j+1] = tmp;
			}
        
		}
	
	}
}

void printfSortedBuf (Buf *buf)
{
    Int32 i;
    for (i=0 ;i<TOTAL; i++)
    {
        printf("%d ", *(buf)[i]);
    }
}

Int32 main (void)
{
    Int32 i, flag;
    Buf *buf = (Buf *) malloc (sizeof(Int32) * TOTAL);
    
    while (1)
    {        
        //menu 
        printf("Please enter (0) increasing or (1) descesing sort: ");
        scanf("%d", &flag);
        if (flag < 0 || flag > 1)
        {
            printf("ERROR: no such option! \n\n");
            continue;
        }
        
        printf("  Please enter %d integers: ", TOTAL);
        for (i = 0; i< TOTAL; i++)
        {
            scanf("%d", *(buf+i));
        }
        printf("%d", *(buf)[2]);
        if (flag == 0)
        {
        	  bubbleSort(buf, CompInc);
        }
        else if (flag == 1)
        {
            bubbleSort(buf, CompDec);
        }
        
        printf("    Result: ");
        printfSortedBuf(buf);
        printf("\n\n");  
    }
}

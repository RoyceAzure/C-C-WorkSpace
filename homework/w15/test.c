#include <stdio.h>
#include <stdlib.h>
#define TOTAL 5

typedef int Int32;
typedef Int32 Buf[TOTAL];
void printfSortedBuf (Buf *buf)
{
    int i;
    for (i=0 ;i<TOTAL; i++)
    {
        printf("%d ", *(*buf+i));
    }
}

int main()
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
//        printf("%d", (*(buf)+1));
		printfSortedBuf(buf);
	}
	return 0;
}

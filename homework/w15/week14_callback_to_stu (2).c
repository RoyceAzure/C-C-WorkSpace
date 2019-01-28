#include <stdio.h>
#include <stdlib.h>

#define TOTAL 5

int CompInc (int x, int y)
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
int CompDec (int x, int y)
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

void bubbleSort(int *buf, int (*Bsort)(int , int ))
{
    int i, j;
    int tmp;
//	int n = sizeof(buf) / sizeof(int);
//	printf("%d",n );
    for (i = 4; i > 0; i--)
    {
        for (j = 0; j <= i - 1; j++)
        {
			if(Bsort(buf[j], buf[j+1]))
			{
				tmp = buf[j];
				buf[j] = buf[j+1];
				buf[j+1] = tmp;
			}
        
		}
	
	}


}

void printfSortedBuf (int *buf)
{
    int i;
    for (i=0 ;i<TOTAL; i++)
    {
        printf("%d ", buf[i]);
    }
}

int main (void)
{
    int i, flag;
    int *buf = (int *) malloc (sizeof(int)*TOTAL);
    
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
            scanf("%d", &buf[i]);
        }
        
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


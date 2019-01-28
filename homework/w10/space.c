#include "space.h"

tTypeScore scoreBuf[N]; //preallocated memory space

void getScoreSpace(tTypeScore **ppScore)
{
	*ppScore = &scoreBuf[Myindex];
	if((*ppScore)->used == 0)
	{
		(*ppScore)->loc = Myindex;
		(*ppScore)->used = 1;
		printf("	getScoreSpace(): giving space numbered %d\n",Myindex );
		Myindex = (Myindex + 1);
		if(Myindex == 5)
		{
			Myindex =0;
		}
	}
	else
	{
		printf("	NO enough space!!\n");
	}
			
    return;	
}

void returnScoreSpace (int loc)
{
	scoreBuf[loc].used = 0;
    printf("	returnScoreSpace(): return space numbered %d\n", loc);
    Myindex = (Myindex - 1);
	if(Myindex <0)
	{
		Myindex =4;
	}
}


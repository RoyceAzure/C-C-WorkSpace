#include "space.h"

tTypeScore scoreBuf[N]; //preallocated memory space
unsigned char scoreBitmap = 0xFF;

tTypeId idBuf[N]; //preallocated memory space
unsigned char idBitmap = 0xFF;


int checkFreeScoreSpace(void)
{
	return  scoreBitmap != 0;
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
}}

void returnScoreSpace (int loc)
{
	set_bit(&scoreBitmap, loc, 1);
    printf("     returnScoreSpace(): return space numbered %d, result bitmap %x\n", loc, scoreBitmap);
}

int checkFreeIdSpace(void)
{
	return  idBitmap != 0;
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
void returnIdSpace (int loc)
{
	set_bit(&idBitmap, loc, 1);
    printf("     returnIdSpace(): return space numbered %d, result bitmap %x\n", loc, idBitmap);
}


#include "space.h"

tTypeScore scoreBuf[N]; //preallocated memory space
unsigned char scoreBitmap = 0xFF;

tTypeId idBuf[N]; //preallocated memory space
unsigned char idBitmap = 0xFF;


int checkFreeScoreSpace(void)
{

}

void getScoreSpace(void **ppScore)
{










    printf("     getScoreSpace(): giving space numbered %d, result bitmap 0x%x\n", free, scoreBitmap);


    return;
}

void returnScoreSpace (int loc)
{

    printf("     returnScoreSpace(): return space numbered %d, result bitmap %x\n", loc, scoreBitmap);
}

int checkFreeIdSpace(void)
{

}

void getIdSpace(void **ppId)
{
	
	
	
	
	
	
	
	
	
    printf("     getIdSpace(): giving space numbered %d, result bitmap 0x%x\n", free, idBitmap);
	
	
	
	
    return;
}

void returnIdSpace (int loc)
{

    printf("     returnIdSpace(): return space numbered %d, result bitmap %x\n", loc, idBitmap);
}


#include <stdio.h>
#include <stdlib.h>


#define N 5



typedef struct Score
{   
    int score;
    int loc;
    int used;      // to record if the space is used    
}tTypeScore;
tTypeScore scoreBuf[N];


void change(tTypeScore **pp)
{
	*pp+=2;
	(*pp)->score = 1000;
}

void test2(int *p)
{	
	printf("%p\n",p);
	printf("%x\n",&p);
	*p = 200;
}
int main()
{
	int a = 100;
//	tTypeScore *p = scoreBuf;
	int *p = &a;
	test2(p);
	printf("%d",*p);
//	(p+2)->score = 100;
//	printf("%d",(p+2)->score);
//	change(&p);
//	printf("%d",(p+2)->score);




	return 0;
}

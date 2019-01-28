#include <stdio.h>


typedef struct base{
	int loc;
	int type;
    int score;
    
}tbase;
typedef struct base2{
	int type;
    short id;
    int loc;
}tbase2;


int main()
{
	tbase b1;
	tbase2 b2;
	b1.type = 1;
	b2.type = 2;
	b1.score = 10;
	b2.id = 200;
	b1.loc = 20;
	b2.loc = 30;

	tbase *ptr1 = &b1;
	tbase2 *ptr2 = &b2;
	ptr1 = (tbase*)ptr2;
	printf("%d",ptr1->type);
	return 0;
	
}

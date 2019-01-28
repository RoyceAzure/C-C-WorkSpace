#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define N 8
#define TEST_BIT(target,bit) ((target >> bit) & (0x01))
#define SET_BIT(target,bit) (target |= (0x01 << bit))
#define CLEAR_BIT 

typedef struct Score
{   
	  int type;
    int score;
    int loc;    
}tTypeScore;

typedef struct Id
{   
	  int type;
    short id;
    int loc;    
}tTypeId;

void getScoreSpace (void **ppScore);  
void returnScoreSpace (int location);   
int checkFreeScoreSpace(void);
void getIdSpace (void **ppScore);  
void returnIdSpace (int location);   
int checkFreeIdSpace(void);

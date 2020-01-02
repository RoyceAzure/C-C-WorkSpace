#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define CMAX 20

int main()
{
	srand(time(NULL));
	char buffer[CMAX];
	fgets(buffer, CMAX, stdin);
	int trans = atoi(buffer);
//	printf("%d\n", trans);
	printf("%d\n", (atoi(buffer))+30);	
	return 0;
}

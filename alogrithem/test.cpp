# include <stdio.h>
# include <ctype.h> /* isspace() */
# include <stdlib.h>


enum {a,b,c}test;

int main()
{
	test = a;
	printf("%d", test);
	return 0;
}

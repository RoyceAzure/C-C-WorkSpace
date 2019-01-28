#include <stdio.h>


int main()
{
	char s[2000],g[200];
// 	scanf("%5s%s", s, g);
 	scanf("%[abz;]%s", s, g);
 	
 	scanf("%[a-z ]%s", s, g);
 	
 	scanf("%[a-zA-Z0-9]%s", s, g);
 	
 	scanf("%[^,]%s", s, g);
 	
 	 scanf("%*[^@]@%[^.]%s", s, g);
 	
 	printf("s=%s, g=%s\n", s, g);
	return 0;
}

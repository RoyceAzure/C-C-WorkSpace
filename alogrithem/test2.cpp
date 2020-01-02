# include <stdio.h>
# include <ctype.h> /* isspace() */
# include <stdlib.h>
# define MAX 100

enum {a,b,c}test;


void Input2Token()
{

	char buff[MAX];
	printf("input sentence :\n");
	scanf("%s", buff);
	printf("%s",buff);
}
void test2Token()
{
	int op;
	scanf("%c",&op);
	printf("%c",op);
}


void test3()
{
	char str[] = "1ld"; 
  
    int alphabet = 0, number = 0, i; 
    for (i=0; str[i]!= '\0'; i++) 
    { 
        // check for alphabets 
        if (isalpha(str[i]) != 0) 
            alphabet++; 
  
        // check for decimal digits 
        else if (isdigit(str[i]) != 0) 
            number++; 
    } 
  
    printf("Alphabetic_letters = %d, "
           "Decimal_digits = %d\n", alphabet, number); 
  

}

int main()
{
	test3();
	return 0;
}

# include <stdio.h>
# include <ctype.h> /* isspace() */
# include <stdlib.h>
# include <string.h>

/*
E -> E+T
	| E-T
	| T
T -> T*F
	|T/F
	|F
F -> (E)
	| id
	|num

*/

void expresion();
void Term();
void Factor();


int j = 0;
char p[] = {"(3+4)*5-6/(7-8)"};

void Factor()
{
	printf(" factor!! \n");
	if( p[j] == '(')
	{
		printf(" ( \n");
		j++;
		expresion();   //after exp(() chain, except to see ')'
		if(p[j] == ')')
		{
			printf("  )\n");
			j++;	
		}
		else
			printf("\terror!!");	
	}
	else
	{
		if ( isdigit(p[j]))
			printf("\t %c\n", p[j++]);
		else
			printf("\terror!!");
	}
	if(p[j] == '*')
	{
		printf("\t*\n");
		j++;
	}
	else if(p[j] == '/')
	{
		printf("\t/\n");
		j++;
	}
	
}

void Term()
{
	printf("term!!\n");
	Factor();
	if( p[j] == '(' || isdigit(p[j]))
	{
		if(p[j] == '(')
			printf("(");
		Term();
	}
}



void expresion()
{
	printf(" exp!!\n");
	Term();
	if ( p[j] == '+')
	{
		++j;
		printf(" \t+\n");
		expresion();
	}
	else if ( p[j] == '-')
	{
		++j;
		printf(" \t-\n");
		expresion();
	} 
}


int main()
{
	int len = strlen(p);
	printf("top down start for %s :\n",p);
	expresion();
	if( j == len)
		printf("success!!\n");
	else
		printf("failed!!\n");


	return 0;


}

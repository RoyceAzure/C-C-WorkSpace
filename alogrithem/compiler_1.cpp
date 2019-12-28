# include <stdio.h>
# include <ctype.h> /* isspace() */
# include <stdlib.h>
# include <string.h>
char next_tok;
void S(void);
void E(void);
void T(void);

typedef struct ast_node{
	enum {numExp, varExp, binopExp}kind;
	union{
		double num;
		char *var_p;
		struct{
			int op;
			struct ast_node *left_p;
			struct ast_node *right_p;
		}binExp;
	}body;
}ast_node;


ast_node *mk_numNode(double num, int numExp) {
	ast_node *node_p = (ast_node*)malloc(sizeof(ast_node)); //terminial
	node_p ->kind = numExp;
	node_p ->body.num = num;
	return node_p;
}
ast_node *mk_varNode(char *id_p) {
	ast_node *node_p = (ast_node *)malloc(sizeof(ast_node)); //terminial
	node_p ->kind = varExp;
	node_p ->body.var_p = id_p;
	return node_p;
}
ast_node *mk_binExp(char bin_op,ast_node *lchild_p,ast_node *rchild_p) { //non-terminal 
	ast_node *node_p = (ast_node *) malloc(sizeof(ast_node));
	node_p ->kind = binopExp;
	node_p ->body.binExp.op = bin_op;
	node_p ->body.binExp.left_p = lchild_p;
	node_p ->body.binExp.right_p = rchild_p;
	return node_p;
}
void expresion();
void Term();
void Factor();


int j = 0;
char p[] = {"(3+4)*5"};

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
//	char c;
//	while( (c = getchar()) == '.')
//	{
//		printf("c == %c", c);
//		printf("FUCK U");
//		
//	}

	return 0;


}

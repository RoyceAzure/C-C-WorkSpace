# include <stdio.h>
# include <ctype.h> /* isspace() */
# include <stdlib.h>
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


ast_node *mk_numNode(double num, char numExp) {
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



int error(const char *msg){ 
	fprintf(stderr ,"error: %s\n",msg);
	return(1);
}
void get_tok(void){
	while (isspace(next_tok = getchar())) ;
}
void S(void) { E(); }
void E(void) {
	T();
	while (next_tok == '+' || next_tok =='-') {
		get_tok(); E();
	}
}
void T(void) {
	if(next_tok == '(' ) { /* first token */  //T-->(E) 
		get_tok(); E();
		if(next_tok == ')' ) get_tok();	
			else error("ERROR!");
	} 
	else if(isdigit(next_tok) ) {  //accpet number 
		get_tok(); /* second token */
		if(next_tok == '*'|| next_tok =='/' ) {
			get_tok(); T();
		}
	}
}
int main(void) {
	get_tok(); S();
	if (next_tok != '#') error("ERROR!");
	else printf("Parsed successfully!");
}



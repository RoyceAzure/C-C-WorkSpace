#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char bs[]="                                                                 ";
char sym,pre_sym; 
char term_operator,expr_operator;
int level=0;
int term_result,expr_result,term_left,expr_left=0;


void levelUp() {
	bs[3*level]=' ';
	bs[++level*3]='\0';
}

void levelDown() {
	bs[3*level]=' ';
	bs[--level*3]='\0';
}

void enter(const char *msg) {
	levelUp();
	printf("%s+%d entering %s\n", bs, level, msg);
}

void leave(const char *msg) {
	printf("%s-%d leaving %s\n", bs, level, msg);
	levelDown();
}

void error(const char* msg) {
	printf("\n%s, token=%c\n", msg, sym);
	system("pause");
	exit(1);
}

void nextsym() {  // end the input with a $
	pre_sym=sym;
	while ((sym = getchar()) != EOF) {
		if (isspace(sym))
			continue;
		return;
	}
	sym = '$';
	return;
}
	
int accept(const char* s) {
    if (strchr(s, sym) != NULL) { 
        printf("%s   accepting -------------------- %c\n", bs, sym);
        if(sym=='+'||sym=='-'){
    		expr_operator=sym;
    		//printf(" %c accept_expr_operator ",expr_operator);	//debug
		}
		if(sym=='*'||sym=='/'){
    		term_operator=sym;
    		//printf(" %c accept_expr_operator ",term_operator);	//debug
		}
        nextsym();
        return 1;
    }
    return 0;
}

int expect(const char* s) {
    if (accept(s))
        return 1;
    error("expect: unexpected symbol");
    return 0;
}

void S();

int main() {
	bs[0]='\0';
	nextsym();
	S();
	if(sym == '$')
		printf("Parsing successful\n");
	else
		printf("Parsing failed, unexpected token %c\n", sym);	
	system("pause");
	return 0;
}

// Add your parser functions here


// Grammar expr3
// S -> expr
// expr -> term ( [+-] term )*
// term -> factor ( [*/] factor ) *
// factor --> [a-z] | '(' expr ')'

void expr();
void term();
void factor();
void while_calculates(int right,char operator){
	if(operator=='+'){
		expr_left += right;
	}
	if(operator=='-'){
		expr_left -= right;
	}	
	if(operator=='*'){
		term_left *= right;
	}
	if(operator=='/'){
		term_left /= right;
	}
};
void S() {
    expr();
    printf("%s   expr()return = %d \n",bs , expr_result); 
}

void expr() {
    enter("expr");
    term();
    printf("%s   term()return = %d \n",bs , term_result); 
	expr_left=term_result;//�qterm���X��Aterm_result�N�Oexpr_left���ƭȡC 
    //expr_operator=sym; //����expr_��operator�C��ΤFaccept()�h�����A�G���ܳƵ��C 
    int expr_whilecount=0;
    while (accept("+-")){
    	int expr_right=0; 
    	term();
    	printf("%s   term()return = %d \n",bs , term_result); 
    	expr_right=term_result;
    	//���槹term()�N�|�ܦ��U�@�Ӧr�ŤF�C
		while_calculates(expr_right,expr_operator);//expr_left+-=expr_right; 
		printf("%s   expr_calculates()return = %d \n",bs , expr_left);//-----------debug
	//	printf("%s   expr_calculates_operator()return = %c \n",bs , expr_operator);---------debug
	//	printf("%s   expr_calculates_term_right()return = %d \n",bs , expr_right);-----------debug
		expr_whilecount++;
	}
		expr_result=expr_left;//�p�G�S���i�Jwhile�j��Aexpr_reulst=exp_left; 
    leave("expr");
}

void term() {
    enter("term");
    factor();//�]��factor,sym�N�|�ܦ�operator�F�A(+-*/)�����i��C
	printf("%s   factor()return = %c \n",bs , pre_sym); 
    term_left=pre_sym-'0';
	//term_operator=sym; //(���o+-*/) ��ΤFaccept()�h�����A�G���ܳƵ��C 
	//int term_whilecount=0;
    while (accept("*/")){//��accept���A(*/)��operator�N�|�����Asym�N�|�ܤU�@�Ӧr�ŤF�C 
    	int term_right=0;
		//printf("arfter accept*/ sym=%c", sym);//�o�̷|���Dterm_right���r�� 
		 
		printf("%s   term_while_operator()return = %c \n",bs , expr_operator);
    	factor();
    	printf("%s   factor()return = %c \n",bs , pre_sym); 
    	term_right=pre_sym-'0'; //�g�Lfactor���ҧ��A�A���oterm_right��factor�C 
		//���槹facotr,�o�̴N�|�ܦ��U�@�Ӧr��,���Ooperator�F�C  
		while_calculates(term_right,term_operator);//�H���e�����U��term_operator�A��term_right�Mnew_term_right�@�X�p��C//term_left*/=term_right;
		printf("%s   term_calculates()return = %d \n",bs , term_left);
		//printf("%s   term_calculates_operator()return = %c \n",bs , term_operator);----debug 
		//printf("%s   term_calculates_term_right()return = %d \n",bs , term_right);-----debug
		//term_whilecount++;	
	}
		term_result=term_left; //�p�G�S�i�Jwhile�j��Aterm_left�N�Oterm_result;�ζi�J�j���A�̫᪺���G�]�O�֥[�bterm_left(���Fterm_right��`���A�ΡC 
    leave("term");
}

void factor() {
    enter("factor");
    if (accept("0123456789")) {
        ;
    } else if (accept("(")) {
        expr();
        expect(")");
    } else {
        error("factor: syntax error");
    }
    leave("factor");
}

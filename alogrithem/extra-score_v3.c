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
	expr_left=term_result;//從term走出後，term_result就是expr_left的數值。 
    //expr_operator=sym; //紀錄expr_的operator。改用了accept()去偵測，故此變備註。 
    int expr_whilecount=0;
    while (accept("+-")){
    	int expr_right=0; 
    	term();
    	printf("%s   term()return = %d \n",bs , term_result); 
    	expr_right=term_result;
    	//執行完term()就會變成下一個字符了。
		while_calculates(expr_right,expr_operator);//expr_left+-=expr_right; 
		printf("%s   expr_calculates()return = %d \n",bs , expr_left);//-----------debug
	//	printf("%s   expr_calculates_operator()return = %c \n",bs , expr_operator);---------debug
	//	printf("%s   expr_calculates_term_right()return = %d \n",bs , expr_right);-----------debug
		expr_whilecount++;
	}
		expr_result=expr_left;//如果沒有進入while迴圈，expr_reulst=exp_left; 
    leave("expr");
}

void term() {
    enter("term");
    factor();//跑完factor,sym就會變成operator了，(+-*/)都有可能。
	printf("%s   factor()return = %c \n",bs , pre_sym); 
    term_left=pre_sym-'0';
	//term_operator=sym; //(取得+-*/) 改用了accept()去偵測，故此變備註。 
	//int term_whilecount=0;
    while (accept("*/")){//當accept完，(*/)的operator就會消失，sym就會變下一個字符了。 
    	int term_right=0;
		//printf("arfter accept*/ sym=%c", sym);//這裡會知道term_right的字符 
		 
		printf("%s   term_while_operator()return = %c \n",bs , expr_operator);
    	factor();
    	printf("%s   factor()return = %c \n",bs , pre_sym); 
    	term_right=pre_sym-'0'; //經過factor驗證完，再取得term_right的factor。 
		//執行完facotr,這裡就會變成下一個字符,不是operator了。  
		while_calculates(term_right,term_operator);//以之前紀錄下的term_operator，讓term_right和new_term_right作出計算。//term_left*/=term_right;
		printf("%s   term_calculates()return = %d \n",bs , term_left);
		//printf("%s   term_calculates_operator()return = %c \n",bs , term_operator);----debug 
		//printf("%s   term_calculates_term_right()return = %d \n",bs , term_right);-----debug
		//term_whilecount++;	
	}
		term_result=term_left; //如果沒進入while迴圈，term_left就是term_result;及進入迴圈後，最後的結果也是累加在term_left(為了term_right能循環再用。 
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

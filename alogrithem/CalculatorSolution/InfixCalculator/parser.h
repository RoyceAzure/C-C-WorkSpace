#pragma once

#include "lexer.h"

namespace Parser
{
	/*
		Recursive Descent Parse Tree

		// root of the descent parse tree
		calculator:
			end // end of stream, or eof
			expr_list end

		expr_list:
			expr ';' // print symbol ';'
			expr_list expr ';' // left recursion

		expr:
			term (O)
			expr '+' term (O)
			expr '-' term (O)
		
		term:
			prim (O)
			term '*' prim (O)
			term '/' prim (O)

		prim:
			number (O)
			variable (O)
			variable '=' expr (O)
			'-' prim (O)
			'(' expr ')' (O)
	*/

	using namespace Lexer;

	class ClassParser
	{
	private:
		ClassLexer m_lexer;
		variable_t m_variable;

	public:
		// handle addition and subtraction
		double expr(bool bNextToken);

		// handle multiplication and division
		double term(bool bNextToken);

		// extract number from the stream token
		// assign expression to a variable
		// handle unary minus '-'
		// handle parentheses '(' expr ')'
		double prim(bool bNextToken);

		void calculate();


	};
}
#include "parser.h"
#include "../lexer/lexer.h"
#include <vector>

namespace jaguar::parser
{
	int currentToken = 0;

	int yylex(jaguar::parser::parser::semantic_type* yylval)
	{
		using enum jaguar::parser::parser::token::token_kind_type;

		if(currentToken >= tokens_.size())
		{
			return YYEOF;
		}

		auto& tok = tokens_[currentToken];

		switch(tok.type)
		{
			case(IDENTIFIER): {
				yylval->strval = &tok.str_val;
				break;
			}
			case(L_INT): {
				yylval->ival = tok.i_val;
				break;
			}
		}
		
		printf("current token %d, type %d\n", currentToken, tok.type);
		currentToken++;
		return tok.type;
	}

	void parser::error(const std::string &msg)
	{
		std::cerr << "Parse error: " << msg << std::endl;
	}
}
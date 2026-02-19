#include "parser.h"
#include "../lexer/lexer.h"
#include <vector>

namespace jaguar::parser
{
	int currentToken = 0;

	int yylex(parser::semantic_type* yylval, parser::location_type* yylloc)
	{
		using enum parser::token::token_kind_type;

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
			case(L_FLOAT): {
				yylval->fval = tok.f_val;
				break;
			}
			case(L_STRING): {
				yylval->strval = &tok.str_val;
				break;
			}
			case(L_BOOL): {
				yylval->ival = tok.i_val;
				break;
			}
		}
		
		yylloc->begin.line = tok.line;
		yylloc->begin.column = tok.column;
		currentToken++;
		return tok.type;
	}

	//syntax error handling
	void parser::error(const location_type& loc, const std::string& msg)
	{
		printf("Parser error : line : %d, column : %d. Error detail : %s\n", loc.begin.line, loc.begin.column, msg.c_str());
	}
}
#include "parser.h"
#include "../lexer/lexer.h"
#include <vector>

namespace jaguar::parser
{
	int currentToken = 0;

	int yylex(jaguar::parser::parser::semantic_type* yylval, jaguar::parser::parser::location_type* yylloc)
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
			case(L_STRING): {
				yylval->strval = &tok.str_val;
				break;
			}
		}
		
		printf("current token %d, type %d\n", currentToken, tok.type);
		yylloc->begin.line = tok.line;
		yylloc->begin.column = tok.column;
		currentToken++;
		return tok.type;
	}

	using namespace jaguar::parser;

	void parser::error(const location_type& loc, const std::string& msg)
	{
		printf("Parser error : line : %d, column : %d. Error detail : %s", loc.begin.line, loc.begin.column, msg.c_str());
	}

	/*void jaguar::parser::parser::error(const std::string &msg)
	{
		std::cerr << "Parse error: " << msg << std::endl;
	}*/
}
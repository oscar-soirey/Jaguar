#include "parser.h"
#include "../lexer/lexer.h"
#include <vector>

namespace jaguar::parser
{
	int currentToken = 0;

	int yylex(jaguar::parser::parser::semantic_type* yylval)
	{
		using namespace lexer;

		if(currentToken >= tokens_.size())
		{
			return 0;
		}

		auto& tok = tokens_[currentToken];

		switch(tok.type)
		{
			case(IDENTIFIER): {
				yylval->strval = &tok.value;
				printf("current token %d, type %d", currentToken, IDENTIFIER);
				currentToken++;
				return IDENTIFIER;
			}
			case(LITERAL_INT): {
				yylval->ival = 0; //&tok.value;
				printf("current token %d, type %d", currentToken, LITERAL_INT);
				currentToken++;
				return LITERAL_INT;
			}
			case(OPERATOR): {
				currentToken++;
				return OPERATOR;
			}

			default: {
				currentToken++;
				return 0;
			}
		}
	}

	void parser::error(const std::string &msg)
	{
		std::cerr << "Parse error: " << msg << std::endl;
	}
}
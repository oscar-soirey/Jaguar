#ifndef JAGUAR_PARSER_H
#define JAGUAR_PARSER_H

#include "../generated/parser.tab.hpp"
#include "../lexer/lexer.h"

namespace jaguar::parser
{
	inline std::vector<lexer::token_t> tokens_;

	/**
	 * This function is automatically called by Bison,
	 * It iterate around tokens_ variable, which needs to be initialized using the tokenizer
	 */
	int yylex(parser::semantic_type* yylval, parser::location_type* yylloc);
}

#endif
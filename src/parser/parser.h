#ifndef JAGUAR_PARSER_H
#define JAGUAR_PARSER_H

#include "../generated/parser.tab.hpp"
#include "../lexer/lexer.h"

namespace jaguar::parser
{
	inline std::vector<jaguar::lexer::token_t> tokens_;
	
	int yylex(jaguar::parser::parser::semantic_type* yylval, jaguar::parser::parser::location_type* yylloc);
}

#endif
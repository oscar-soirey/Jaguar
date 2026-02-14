#ifndef JAGUAR_LEXER_H
#define JAGUAR_LEXER_H

#include <string>
#include <vector>
#include "../generated/parser.tab.hpp"

namespace jaguar::lexer
{
	typedef struct {
		jaguar::parser::parser::token::token_kind_type type;
		std::string str_val;
		int i_val;
		float f_val;
		int line;
		int column;
	}token_t;

	//const char* TokenToString(parser::parser::token t);

	std::vector<token_t> Tokenize(const std::string& _data, size_t _size);
}

#endif
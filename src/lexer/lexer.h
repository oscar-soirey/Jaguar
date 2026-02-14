#ifndef JAGUAR_LEXER_H
#define JAGUAR_LEXER_H

#include <string>
#include <vector>

namespace jaguar::lexer
{
	typedef enum {
		KEYWORD,
		IDENTIFIER,

		OPERATOR,

		LPAREN,
		RPAREN,
		LBRACE,
		RBRACE,
		SEMICOLON,
		COMMA,

		DECORATOR,
		DOLLAR,
		PREPROCESSOR,

		LITERAL_INT,
		LITERAL_FLOAT,
		LITERAL_STRING
	}token_e;

	typedef struct {
		token_e type;
		std::string value;
		int line;
		int column;
	}token_t;

	const char* TokenToString(token_e t);

	std::vector<token_t> Tokenize(const std::string& _data, size_t _size);
}

#endif
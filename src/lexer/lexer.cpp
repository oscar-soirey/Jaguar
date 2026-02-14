#include "lexer.h"

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cctype>
#include <iostream>

#include "../logger/compile_time_logger.h"

namespace jaguar::lexer
{
	const char* tokenNames[] = {
		"KEYWORD",
		"IDENTIFIER",
		"OPERATOR",
		"LPAREN",
		"RPAREN",
		"LBRACE",
		"RBRACE",
		"SEMICOLON",
		"COMMA",
		"DECORATOR",
		"DOLLAR",
		"PREPROCESSOR",
		"LITERAL_INT",
		"LITERAL_FLOAT",
		"LITERAL_STRING"
	};

	const char* TokenToString(token_e t)
	{
		return tokenNames[t];
	}

	namespace data
	{
		const std::unordered_set<std::string> keywords = { "auto", "int", "float", "double", "string", "void", "new", "for_loop", "for_each", "for_map", "break", "while", "if", "else", "register", "struct", "class" };
		const std::unordered_set<char> operatorChars = { '+', '-', '*', '/', '=', '&', '|', ':', '.'};
		const std::unordered_set<std::string> operators = { "=", "+", "-", "*", "/", "==", "&&", "||", "+=", "-=", "*=", "/=", "++", "--", ":", "::", "." };
		const std::unordered_map<char, token_e> separators = {
			{';', SEMICOLON},
			{'(', LPAREN},
			{')', RPAREN},
			{'{', LBRACE},
			{'}', RBRACE},
			{',', COMMA}
		};
	}

	//ajouter des detections, comme les decorateurs et preprocesseurs

	std::vector<token_t> Tokenize(const std::string& data, size_t _size)
	{
		int line = 1;
		int column = 1;
		int i = 0;

		std::vector<token_t> tokens;
		while(i < data.size())
		{
			//is line comment
			if (data[i] == '/' && data[i+1] == '/')
			{
				while (i < data.size() && data[i] != '\n')
				{
					i++;
				}
				column = 1;
				line++;
				i++;
			}
			//is multi-line comment
			else if (data[i] == '/' && i + 1 < data.size() && data[i + 1] == '*')
			{
				i += 2; // on saute le /*

				while (i < data.size() && !(data[i] == '*' && i + 1 < data.size() && data[i + 1] == '/'))
				{
					if (data[i] == '\n')
					{
						line++;
						column = 1;
					}
					else
					{
						column++;
					}
					i++;
				}

				if (i + 1 < data.size())
				{
					i += 2; // on saute le */
					column += 2;
				}
			}
			//is word (identifier or keyword)
			else if (std::isalpha(data[i]) || data[i] == '_')
			{
				//start of a token
				int start = i;
				token_t token;
				token.line = line;
				token.column = column;
				while (i < data.size() && (std::isalnum(data[i]) || data[i] == '_'))
				{
					i++;
					column++;
				}

				std::string word = data.substr(start, i - start);

				if (data::keywords.contains(word))
				{
					token.type = KEYWORD;
					token.value = word;
				}
				else
				{
					token.type = IDENTIFIER;
					token.value = word;
				}
				tokens.emplace_back(token);
			}
			//is number
			else if (std::isxdigit(data[i]))
			{
				int start = i;
				token_t token;
				token.type = LITERAL_INT;
				token.line = line;
				token.column = column;

				while (i < data.size() && (std::isdigit(data[i]) || data[i] == '.'))
				{
					if (data[i] == '.')
					{
						if (token.type == LITERAL_FLOAT)
						{
							//if type is already a float, there is mutliple dots in the number, error
							logger::LogError(logger::LITERAL_FLOAT_ERROR, "Multiple dots in a literal float declaration");
							return{};
						}
						//if dot in the literal, set type to decimal number
						token.type = LITERAL_FLOAT;
					}
					i++;
					column++;
				}

				std::string num = data.substr(start, i - start);

				token.value = num;
				tokens.emplace_back(token);
			}
			//is string literal
			else if (data[i] == '"')
			{
				i++;
				column++;
				int start = i;

				token_t token;
				token.type = LITERAL_STRING;
				token.line = line;
				token.column = column;

				while (i < data.size() && data[i] != '"')
				{
					i++;
					column++;
				}
				if (i >= data.size())
				{
					logger::LogError(logger::QUOTE_NEVER_CLOSED, "");
					return{};
				}
				std::string str = data.substr(start, i - start);

				token.value = str;
				tokens.emplace_back(token);

				i++;
				column++;
			}
			//is separator
			else if (data::separators.contains(data[i]))
			{
				token_t token;
				token.type = data::separators.at(data[i]);
				token.value = data[i];
				token.line = line;
				token.column = column;
				tokens.emplace_back(token);
				i++;
				column++;
			}
			//is operator
			else if (data::operatorChars.contains(data[i]))
			{
				int start = i;
				token_t token;
				token.type = OPERATOR;
				token.line = line;
				token.column = column;

				//multi-sized operators
				while (i < data.size() && data::operatorChars.contains(data[i]))
				{
					i++;
					column++;
				}

				std::string opeStr = data.substr(start, i - start);
				if (!data::operators.contains(opeStr))
				{
					logger::LogError(logger::OPERATOR_ERROR, "");
					return {};
				}

				token.value = opeStr;
				tokens.emplace_back(token);
			}
			//is decorator
			else if(data[i] == '@')
			{
				token_t token;
				token.type = DECORATOR;
				token.value = "@";
				token.line = line;
				token.column = column;
				tokens.emplace_back(token);
				i++;
				column++;
			}
			//is dollar identifier
			else if (data[i] == '$')
			{
				token_t token;
				token.type = DOLLAR;
				token.value = "$";
				token.line = line;
				token.column = column;
				tokens.emplace_back(token);
				i++;
				column++;
			}
			//is line jump
			else if (data[i] == '\n')
			{
				column = 1;
				line++;
				i++;
			}
			//not knowed or space
			else
			{
				i++;
				column++;
			}
		}

		return std::move(tokens);
	}
}
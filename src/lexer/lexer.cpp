#include "lexer.h"

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cctype>
#include <iostream>

#include "../logger/compile_time_logger.h"

//"void", "new", "for_loop", "for_each", "for_map", "break", "while", "if", "else", "register", "struct", "class"
//"&&", "||", "+=", "-=", "*=", "/=", "++", "--", ":", "::", "."

namespace jaguar::lexer
{
	using enum jaguar::parser::parser::token::token_kind_type;

	namespace data
	{
		const std::unordered_map<std::string, jaguar::parser::parser::token::token_kind_type> keywords = {
			{"int", K_INT},
			{"float", K_FLOAT},
			{"string", K_STRING},
			{"void", K_VOID},
			{"bool", K_BOOL},
			{"true", L_BOOL},
			{"false", L_BOOL},
			{"if", K_IF},
			{"else", K_ELSE},
			{"while", K_WHILE}
		};
		const std::unordered_set<char> operatorChars = { '+', '-', '*', '/', '=', '&', '|', ':', '.', '!' };
		const std::unordered_map<std::string, jaguar::parser::parser::token::token_kind_type> operators = { 
			{"=", ASSIGN},
			{"+", PLUS},
			{"-", MINUS},
			{"*", STAR},
			{"/", SLASH},
			{"&&", AND},
			{"||", OR},
			{"==", EQ},
			{"!=", NE}
		};
		const std::unordered_map<char, jaguar::parser::parser::token::token_kind_type> separators = {
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
			//is word (identifier, keyword or bool literal)
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

				auto it = data::keywords.find(word);

				//the word is a knowed keyword
				if (it != data::keywords.end())
				{
					token.type = it->second;
					if (it->second == L_BOOL)
					{
						token.i_val = word == "true";
					}
				}
				else
				{
					token.type = IDENTIFIER;
					token.str_val = word;
				}
				tokens.emplace_back(token);
			}
			//is number
			else if (std::isxdigit(data[i]))
			{
				int start = i;
				token_t token;
				token.type = L_INT;
				token.line = line;
				token.column = column;

				while (i < data.size() && (std::isdigit(data[i]) || data[i] == '.'))
				{
					if (data[i] == '.')
					{
						//if yes, there is multiple dots in the literal, error
						if (token.type == L_FLOAT)
						{
							//if type is already a float, there is mutliple dots in the number, error
							logger::LogError(logger::LITERAL_FLOAT_ERROR, "Multiple dots in a literal float declaration");
							return{};
						}
						//if dot in the literal, set type to decimal number
						token.type = L_FLOAT;
					}
					i++;
					column++;
				}

				std::string num = data.substr(start, i - start);

				//try convert the value from string to int or float
				try {
						if (token.type == L_FLOAT)
								token.f_val = std::stof(num);
						else
								token.i_val = std::stoi(num);
				} catch (std::exception& e) {
						std::cerr << "String to float or int convertion error: " << e.what() << "\n";
				}

				tokens.emplace_back(token);
			}
			//is string literal
			else if (data[i] == '"')
			{
				i++;
				column++;
				int start = i;

				token_t token;
				token.type = L_STRING;
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

				token.str_val = str;
				tokens.emplace_back(token);

				i++;
				column++;
			}
			//is separator
			else if (data::separators.contains(data[i]))
			{
				token_t token;
				token.type = data::separators.at(data[i]);
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
				token.line = line;
				token.column = column;

				//multi-sized operators
				while (i < data.size() && data::operatorChars.contains(data[i]))
				{
					i++;
					column++;
				}

				std::string opeStr = data.substr(start, i - start);
				auto it = data::operators.find(opeStr);
				if (it == data::operators.end())
				{
					logger::LogError(logger::OPERATOR_ERROR, "operator is not knowed");
					return {};
				}

				token.type = it->second;
				tokens.emplace_back(token);
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
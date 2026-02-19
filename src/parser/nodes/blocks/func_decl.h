#pragma once

#include "block_statement.h"
#include "../expressions/expression.h"

namespace jaguar::parser
{
	class FuncDecl : public BlockStatement {
	public:
    std::string func_name;
    std::string return_type;
    Expression* condition;

		FuncDecl(std::string n, std::string r, StatementList* body, int line, int column) : func_name(n), return_type(r), BlockStatement(body, line, column) {}

		void Print(int indent = 0) override
		{
			std::string i(indent, ' ');
      printf("%sFunction declaration, func name : %s, Return type : %s\n", i.c_str(), func_name.c_str(), return_type.c_str());
			for (const auto& s : body->statements)
			{
				s->Print(indent + 4);
			}
		}
	};
}
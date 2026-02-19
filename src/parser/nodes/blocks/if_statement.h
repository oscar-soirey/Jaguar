#pragma once

#include "block_statement.h"
#include "../expressions/expression.h"

namespace jaguar::parser
{
	class IfStatement : public BlockStatement {
	public:
    Expression* condition;

		IfStatement(StatementList* body, Expression* expr, int line, int column) : BlockStatement(body, line, column), condition(expr) {}

		void Print(int indent = 0) override
		{
			std::string i(indent, ' ');
      printf("%sIf statement, condition : %s\n", i.c_str(), condition->GetExpressionString().c_str());
			for (const auto& s : body->statements)
			{
				s->Print(indent + 4);
			}
		}
	};
}
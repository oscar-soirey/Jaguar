#pragma once

#include "expression.h"

namespace jaguar::parser
{
  class BinaryOp : public Expression {
	public:
		Expression* lexpr;
		Expression* rexpr;
    char operator_;

		BinaryOp(Expression* le, Expression* re, char op, int line, int col) : lexpr(le), rexpr(re), operator_(op), Expression(line, col) {}

		std::string GetExpressionString() override
		{
			return {lexpr->GetExpressionString() + operator_ + rexpr->GetExpressionString()};
		}
	};
}
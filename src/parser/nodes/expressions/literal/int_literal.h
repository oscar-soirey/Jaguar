#pragma once

#include "../expression.h"

namespace jaguar::parser
{
  class IntLiteral : public Expression {
	public:
		int value;
		IntLiteral(int v, int line, int col) : value(v), Expression(line, col) {}

		std::string GetExpressionString() override
		{
			return { "IntLiteral(" + std::to_string(value) + ")" };
		}
	};
}
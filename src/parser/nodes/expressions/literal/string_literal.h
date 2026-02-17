#pragma once

#include "../expression.h"
#include <string>

namespace jaguar::parser
{
  class StringLiteral : public Expression {
	public:
		std::string value;
		StringLiteral(std::string v, int line, int col) : value(v), Expression(line, col) {}
		
		std::string GetExpressionString() override
		{
			return { "StringLiteral(" + value + ")" };
		}
	};
}
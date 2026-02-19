#pragma once

#include "../expression.h"

namespace jaguar::parser
{
  class BoolLiteral : public Expression {
	public:
		bool value;
		BoolLiteral(bool v, int line, int col) : value(v), Expression(line, col) {}
		
		std::string GetExpressionString() override
		{
			std::string val;
			if (value == true) val = "true";
			else val = "false";
			return { "BoolLiteral(" + val + ")" };
		}
	};
}
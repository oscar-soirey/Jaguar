#pragma once

#include "../expression.h"

namespace jaguar::parser
{
  class BoolLiteral : public Expression {
	public:
		bool value;
		BoolLiteral(bool v, int line, int col);
		
		std::string GetExpressionString() override;
	};
}
#pragma once

#include "expression.h"

namespace jaguar::parser
{
  class BinaryOp : public Expression {
  public:
  	typedef enum {
  		PLUS, MINUS, STAR, SLASH,
  		AND, OR,
  		EQ, NE, LT, LE, GT, GE
		}operator_e;

		Expression* lexpr;
		Expression* rexpr;
  	operator_e operator_;

		BinaryOp(Expression* le, Expression* re, operator_e op, int line, int col) : lexpr(le), rexpr(re), operator_(op), Expression(line, col) {}

		std::string GetExpressionString() override
		{
			return {lexpr->GetExpressionString() + " " + operators_str[operator_] + " " + rexpr->GetExpressionString()};
		}

  private:
  	const char* operators_str[12] = {  //useful for print the operator type
  		"+", "-", "*", "/",
  		"And", "Or",
  		"==", "!=", "<", "<=", ">", ">="
  	};
	};
}
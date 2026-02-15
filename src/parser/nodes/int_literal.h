#pragma once

#include "expression.h"

namespace jaguar::parser
{
  class IntLiteral : public Expression {
	public:
		int value;
		IntLiteral(int v, int line, int col) : value(v), Expression(line, col) {}
		
		void Print(int indent = 0) override {}
		void CheckSemantics() override {}

		LLVMValue* Codegen() override { return nullptr; }
	};
}
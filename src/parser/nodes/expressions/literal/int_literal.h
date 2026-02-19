#pragma once

#include "../expression.h"
#include <llvm/IR/Constants.h>
#include "../../../../llvm/mng.h"

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

  	llvm::Value* Codegen(codegen::CodegenContext *c) override
		{
			return llvm::ConstantInt::get(
				c->GetLLVMType("int"),
				value,
				false //signed
				);
		}
	};
}
#pragma once

#include "../expression.h"
#include <llvm/IR/Constants.h>

namespace jaguar::parser
{
  class FloatLiteral : public Expression {
	public:
		float value;
		FloatLiteral(float v, int line, int col) : value(v), Expression(line, col) {}

		std::string GetExpressionString() override
		{
			return { "FloatLiteral(" + std::to_string(value) + ")" };
		}

  	llvm::Value* Codegen(codegen::CodegenContext *c) override
		{
			return llvm::ConstantFP::get(
				c->GetLLVMType("float"),
				value   //float or double auto
			);
		}
	};
}
#pragma once

#include "../expression.h"
#include <llvm/IR/Constants.h>

namespace jaguar::parser
{
  class FloatLiteral : public Expression {
	public:
		float value;
		FloatLiteral(float v, int line, int col);

		std::string GetExpressionString() override;

  	llvm::Value* Codegen(codegen::CodegenContext *c) override;
	};
}
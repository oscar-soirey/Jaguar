#pragma once

#include "../expression.h"
#include <llvm/IR/Constants.h>
#include "../../../../llvm/mng.h"

namespace jaguar::parser
{
  class IntLiteral : public Expression {
	public:
		int value;
		IntLiteral(int v, int line, int col);

		std::string GetExpressionString() override;

  	llvm::Value* Codegen(codegen::CodegenContext *c) override;
	};
}
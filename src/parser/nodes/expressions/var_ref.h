#pragma once

#include "expression.h"
#include <string>

namespace jaguar::parser
{
  class VarRef : public Expression {
  public:
    std::string var_name;

    VarRef(std::string _name, int _line, int _column);

  	llvm::Value* Codegen(codegen::CodegenContext *c) override;

    std::string GetExpressionString() override;
  };
}
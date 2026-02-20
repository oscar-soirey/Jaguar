#pragma once

#include "../expressions/expression.h"
#include "statement.h"

#include <string>

namespace jaguar::parser
{
  class VarAssign : public Statement {
  public:
    std::string var_name;
    Expression* expr;

    VarAssign(std::string _name, Expression* _expr, int _line, int _column);
		
		void Print(int indent) override;
		void CheckSemantics() override;

		llvm::Value* Codegen(codegen::CodegenContext* c) override;
  };
}
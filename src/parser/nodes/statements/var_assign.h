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

    VarAssign(std::string n, Expression* e, int l, int c) : var_name(n), expr(e), Statement(l, c) {}
		
		void Print(int indent = 0) override
    {
      std::string i(indent, ' ');
      printf("%sVar assignement, var name : %s, expression : %s\n", i.c_str(), var_name.c_str(), expr->GetExpressionString().c_str());
    }
		void CheckSemantics() override {}

		llvm::Value* Codegen(codegen::CodegenContext* c) override { return nullptr; }
  };
}
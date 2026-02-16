#pragma once

#include "../ast_node.h"
#include "expression.h"

#include <string>

namespace jaguar::parser
{
  class VarAssign : public Statement {
  public:
    std::string var_name;
    Expression* expr;

    VarAssign(std::string n, Expression* e, int l, int c) : var_name(n), expr(e), Statement(VariableAssignement, l, c) {}
		
		void Print(int indent = 0) override
    {
      printf("Var assignement, var name : %s, expression : %s\n", var_name.c_str(), expr->GetExpressionString().c_str());
    }
		void CheckSemantics() override {}

		LLVMValue* Codegen() override { return nullptr; }
  };
}
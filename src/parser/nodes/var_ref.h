#pragma once

#include "expression.h"
#include <string>

namespace jaguar::parser
{
  class VarRef : public Expression {
  public:
    std::string var_name;

    VarRef(std::string n, int l, int c) : var_name(n), Expression(l, c) {}

    virtual std::string GetExpressionString() { return { "VarRef(" + var_name + ")" }; }
  };
}
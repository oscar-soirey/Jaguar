#ifndef JAGUAR_DRIVER_H
#define JAGUAR_DRIVER_H

#include "nodes/statements/statement_list.h"
#include <vector>
#include <memory>

//AST example : 
/**
 * Driver
 └─ root (StatementList of the program)
      ├─ VarDecl(int x = 5)
      ├─ ExpressionStatement(x + 1)
      └─ IfStatement
           └─ StatementList of the IfStatement
                ├─ VarDecl(int y = x)
                └─ ExpressionStatement(sys::print(y))
 */

namespace jaguar::parser
{
  struct Driver {
    //root statement list of the program
    StatementList* root;
  };
}

#endif
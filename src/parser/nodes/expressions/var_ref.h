#pragma once

#include "expression.h"
#include <llvm/mng.h>
#include <string>
#include <logger/compile_time_logger.h>

namespace jaguar::parser
{
  class VarRef : public Expression {
  public:
    std::string var_name;

    VarRef(std::string n, int l, int c) : var_name(n), Expression(l, c) {}

  	llvm::Value* Codegen(codegen::CodegenContext *c) override
    {
			auto it = c->symbolTable.find(var_name);
    	if (it == c->symbolTable.end())
    	{
    		//variable not found in the symbol table
    		std::string e("Variable " + var_name + " was not found in the statement");
				logger::LogError(logger::SYMBOL_NOT_FOUND, e.c_str());
    		return nullptr;
    	}
    	llvm::AllocaInst* alloca_inst = it->second;
			return c->builder->CreateLoad(
				c->GetLLVMType("int"),
				alloca_inst,
				var_name.c_str()
			);
    }

    virtual std::string GetExpressionString() { return { "VarRef(" + var_name + ")" }; }
  };
}
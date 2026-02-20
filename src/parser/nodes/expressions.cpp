#include <llvm/mng.h>
#include <logger/compile_time_logger.h>

#include "expressions/expression.h"
#include "expressions/var_ref.h"

namespace jaguar::parser
{
	//base expression
	Expression::Expression(int _line, int _column) : ASTNode(_line, _column) {}

	Jaguar_Type_e Expression::GetType() const
	{
		return type_;
	}


	//var_ref
	VarRef::VarRef(std::string _name, int _line, int _column):
	var_name(_name),
	Expression(_line, _column)
	{}

	llvm::Value *VarRef::Codegen(codegen::CodegenContext *c)
	{
		codegen::VarSymbol* var_symbol = c->GetVarSymbol(var_name);
		if (!var_symbol)
		{
			//variable not found in the symbol table
			const std::string e("Variable " + var_name + " was not found in the statement");
			logger::LogError(logger::SYMBOL_NOT_FOUND, e.c_str());
			return nullptr;
		}
		llvm::AllocaInst* alloca_inst = var_symbol->alloca_inst;
		return c->builder->CreateLoad(
			c->GetLLVMType(var_symbol->type),
			alloca_inst,
			var_name.c_str()
		);
	}

	std::string VarRef::GetExpressionString()
	{
		return { "VarRef(" + var_name + ")" };
	}



	//binary_operator

}

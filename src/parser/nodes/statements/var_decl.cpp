#include "var_decl.h"

#include "../../../llvm/mng.h"
#include <llvm/IR/Value.h>

#include <iostream>


namespace jaguar::parser
{
	VarDecl::VarDecl(std::string n, std::string t, Expression* i, int l, int c) :
		Statement(l, c),
		init(i),
		var_name(n),
		var_type(t)
	{  }

	void VarDecl::Print(int indent)
	{
		std::string i(indent, ' ');
		if (init)
		{
			printf("%sVar Declaration, name : %s, type : %s, init value : %s\n",
				i.c_str(),
				var_name.c_str(),
				var_type.c_str(),
				init->GetExpressionString().c_str()
			);
		}
		else
		{
			printf("%sVar Declaration, name : %s, type : %s, init value : %s\n",
				i.c_str(),
				var_name.c_str(),
				var_type.c_str(),
				"None"
			);
		}
	}

	void VarDecl::CheckSemantics()
	{
		/* vérification de type */
	}

	llvm::Value* VarDecl::Codegen(codegen::CodegenContext *c)
	{
		//Create int variable
		llvm::AllocaInst* aAlloca = c->builder->CreateAlloca(c->GetLLVMType(var_type), nullptr, var_name);
		if (init)
		{
			c->builder->CreateStore(init->Codegen(c), aAlloca);
		}
		return nullptr;
	}
}

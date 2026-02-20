#pragma once

#include "block_statement.h"
#include "../expressions/expression.h"
#include <llvm/mng.h>

namespace jaguar::parser
{
	class FuncDecl : public BlockStatement {
	public:
    std::string func_name;
    std::string return_type;
    Expression* condition;

		FuncDecl(std::string n, std::string r, StatementList* body, int line, int column) : func_name(n), return_type(r), BlockStatement(body, line, column) {}

		void Print(int indent = 0) override
		{
			std::string i(indent, ' ');
      printf("%sFunction declaration, func name : %s, Return type : %s\n", i.c_str(), func_name.c_str(), return_type.c_str());
			for (const auto& s : body->statements)
			{
				s->Print(indent + 4);
			}
		}

		llvm::Value* Codegen(codegen::CodegenContext *c) override
		{
			//create signature
			llvm::FunctionType* funcType = llvm::FunctionType::get(
				c->GetLLVMType(return_type.c_str()),
				{},
				false
			);
			//create function
			llvm::Function* func = llvm::Function::Create(
				funcType,
				llvm::GlobalValue::ExternalLinkage,
				func_name,
				c->module
			);
			//create entry point
			llvm::BasicBlock* entry = llvm::BasicBlock::Create(*c->context, "entry", func);
			c->builder->SetInsertPoint(entry);

			//function body
			for (const auto& s : body->statements)
			{
				s->Codegen(c);
			}

			//modifier ca pour éviter d'écrire la suite des instructions dans la fonction
			//c->builder->SetInsertPoint(nullptr);

			c->func_symbols.emplace(func_name.c_str(), func);

			return func;
		}
	};
}
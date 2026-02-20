#include <llvm/mng.h>
#include <logger/compile_time_logger.h>

#include "ast_node.h"
#include "statements/statement.h"
#include "statements/statement_list.h"
#include "statements/var_assign.h"
#include "statements/var_decl.h"
#include "statements/func_call.h"

namespace jaguar::parser
{
	//Base Node Class
	ASTNode::ASTNode(int _line, int _column) : line(_line), column(_column) {}


	//Statements
	//statement list
	StatementList::StatementList(int l, int c) : Statement(l,c) {}

	//var_assign
	VarAssign::VarAssign(std::string n, Expression *e, int l, int c) :
	var_name(n),
	expr(e),
	Statement(l, c)
	{}

	void VarAssign::Print(int indent)
	{
		std::string i(indent, ' ');
		printf("%sVar assignement, var name : %s, expression : %s\n", i.c_str(), var_name.c_str(), expr->GetExpressionString().c_str());
	}

	void VarAssign::CheckSemantics()
	{
		//check semantics
	}

	llvm::Value *VarAssign::Codegen(codegen::CodegenContext *c)
	{
		codegen::VarSymbol* symbol_ = c->GetVarSymbol(var_name.c_str());
		if (!symbol_)
		{
			logger::LogError(logger::SYMBOL_NOT_FOUND, "line : ");
			return nullptr;
		}
		llvm::AllocaInst* alloc = symbol_->alloca_inst;
		return c->builder->CreateStore(expr->Codegen(c), alloc);
	}


	//var decl
	VarDecl::VarDecl(std::string _name, Jaguar_Type_e _type, Expression* _initExpr, int _line, int _column) :
		Statement(_line, _column),
		initExpr(_initExpr),
		var_name(_name),
		var_type(_type)
	{}

	void VarDecl::Print(int indent)
	{
		std::string i(indent, ' ');
		if (initExpr)
		{
			printf("%sVar Declaration, name : %s, type : %s, init value : %s\n",
				i.c_str(),
				var_name.c_str(),
				types_str[var_type],
				initExpr->GetExpressionString().c_str()
			);
		}
		else
		{
			printf("%sVar Declaration, name : %s, type : %s, init value : %s\n",
				i.c_str(),
				var_name.c_str(),
				types_str[var_type],
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
		c->AddVarSymbol(var_name.c_str(), codegen::VarSymbol(aAlloca, var_type));
		if (initExpr)
		{
			c->builder->CreateStore(initExpr->Codegen(c), aAlloca);
		}
		return nullptr;
	}


	//func_call
	FuncCall::FuncCall(std::string _funcName, int _line, int _column):
	func_name(_funcName),
	Statement(_line, _column)
	{}

	void FuncCall::Print(int indent)
	{
		std::string i(indent, ' ');
		printf("%sFunc call, func name : %s\n", i.c_str(), func_name.c_str());
	}

	void FuncCall::CheckSemantics()
	{
		//check semantics
	}

	llvm::Value *FuncCall::Codegen(codegen::CodegenContext *c)
	{
		codegen::FuncSymbol* func_symbol = c->GetFuncSymbol(func_name);
		if (!func_symbol)
		{
			logger::LogError(logger::SYMBOL_NOT_FOUND, "line : ");
			return nullptr;
		}
		llvm::Function* funcRef = func_symbol->func;
		llvm::Value* call = c->builder->CreateCall(funcRef, {}, "calltmp");
		return call;
	}
}

#include <llvm/mng.h>
#include <logger/compile_time_logger.h>

#include "expressions/expression.h"
#include "expressions/var_ref.h"
#include "expressions/binary_op.h"

#include "expressions/literal/int_literal.h"
#include "expressions/literal/float_literal.h"
#include "expressions/literal/bool_literal.h"
#include "expressions/literal/string_literal.h"

namespace jaguar::parser
{
	//base expression
	Expression::Expression(int _line, int _column):
	ASTNode(_line, _column)
	{}

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
	BinaryOp::BinaryOp(Expression *le, Expression *re, operator_e op, int line, int col):
	lexpr(le),
	rexpr(re),
	operator_(op),
	Expression(line, col)
	{}

	std::string BinaryOp::GetExpressionString()
	{
		return {lexpr->GetExpressionString() + " " + operators_str[operator_] + " " + rexpr->GetExpressionString()};
	}

	llvm::Value* BinaryOp::Codegen(codegen::CodegenContext *c)
	{
		//Int
		return c->builder->CreateAdd(lexpr->Codegen(c), rexpr->Codegen(c), "iaddtmp");
		//float
		return c->builder->CreateFAdd(lexpr->Codegen(c), rexpr->Codegen(c), "faddtmp");
	}



	//int_literal
	IntLiteral::IntLiteral(int v, int line, int col):
	Expression(line, col),
	value(v)
	{}

	std::string IntLiteral::GetExpressionString()
	{
		return { "IntLiteral(" + std::to_string(value) + ")" };
	}

	llvm::Value* IntLiteral::Codegen(codegen::CodegenContext *c)
	{
		return llvm::ConstantInt::get(
			c->GetLLVMType(INT),
			value,
			false //signed
			);
	}


	//float_literal
	FloatLiteral::FloatLiteral(float v, int line, int col):
	Expression(line, col),
	value(v)
	{}

	std::string FloatLiteral::GetExpressionString()
	{
		return { "FloatLiteral(" + std::to_string(value) + ")" };
	}

	llvm::Value* FloatLiteral::Codegen(codegen::CodegenContext *c)
	{
		return llvm::ConstantFP::get(
			c->GetLLVMType(FLOAT),
			value   //auto float or double
		);
	}

	BoolLiteral::BoolLiteral(bool v, int line, int col):
	Expression(line, col),
	value(v)
	{}

	std::string BoolLiteral::GetExpressionString()
	{
		std::string val;
		if (value == true) val = "true";
		else val = "false";
		return { "BoolLiteral(" + val + ")" };
	}

	StringLiteral::StringLiteral(std::string v, int line, int col):
	value(v),
	Expression(line, col)
	{}

	std::string StringLiteral::GetExpressionString()
	{
		return { "StringLiteral(" + value + ")" };
	}
}

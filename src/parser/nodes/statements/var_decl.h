#ifndef JAGUAR_VAR_DECL_NODE_H
#define JAGUAR_VAR_DECL_NODE_H

#include "statement.h"
#include "../expressions/expression.h"

#include <string>

namespace jaguar::parser
{
	class VarDecl : public Statement {
	public:
		std::string var_name;
		Jaguar_Type_e var_type;

		Expression* initExpr;

		//pass the strings by value to copy (so we can delete string* just after call to this function)
		VarDecl(std::string _name, Jaguar_Type_e _type, Expression* _initExpr, int _line, int _column);

		void Print(int indent) override;
		void CheckSemantics() override;

		llvm::Value* Codegen(codegen::CodegenContext *c) override;
	};
}

#endif
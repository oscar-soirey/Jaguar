#ifndef JAGUAR_VAR_DECL_NODE_H
#define JAGUAR_VAR_DECL_NODE_H

#include "statement.h"
#include "../expressions/expression.h"
#include <memory>
#include <string>

namespace jaguar::parser
{
	class VarDecl : public Statement {
	public:
		std::string var_name;
		std::string var_type;

		Expression* init;

		//pass the strings by value to copy (so we can delete string* just after call to this function)
		VarDecl(std::string n, std::string t, Expression* i, int l, int c);

		void Print(int indent) override;
		void CheckSemantics() override;

		LLVMValue* Codegen(codegen::CodegenContext *c) override;
	};
}

#endif
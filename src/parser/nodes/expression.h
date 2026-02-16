#ifndef JAGUAR_EXPRESSION_H
#define JAGUAR_EXPRESSION_H

#include "../ast_node.h"
#include <string>

namespace jaguar::parser
{
	class Expression : public ASTNode {
	public:
		Expression(int line, int column) : ASTNode(Expr, line, column) {}
		virtual ~Expression()=default;

		virtual std::string GetExpressionString() { return {}; }
		
		void Print(int indent = 0) override {}
		void CheckSemantics() override {}

		LLVMValue* Codegen() override { return nullptr; }
	};
}

#endif
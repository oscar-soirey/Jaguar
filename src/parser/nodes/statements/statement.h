#ifndef JAGUAR_STATEMENT_NODE_H
#define JAGUAR_STATEMENT_NODE_H

#include "../ast_node.h"

namespace jaguar::parser
{
	class Statement : public ASTNode {
	public:
		Statement(int l, int c) : ASTNode(l,c) {}

		void Print(int indent = 0) override {}
		void CheckSemantics() override {}

		llvm::Value* Codegen(codegen::CodegenContext* c) override { return nullptr; }
	};
}

#endif
#ifndef JAGUAR_STATEMENT_NODE_H
#define JAGUAR_STATEMENT_NODE_H

#include "../ast_node.h"

namespace jaguar::parser
{
	class Statement : public ASTNode {
	public:
		Statement(node_type_e t, int l, int c) : ASTNode(t,l,c) {}

		void Print(int indent = 0) override {}
		void CheckSemantics() override {}

		LLVMValue* Codegen(codegen::CodegenContext* c) override { return nullptr; }
	};
}

#endif
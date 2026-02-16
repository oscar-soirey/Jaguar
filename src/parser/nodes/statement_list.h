#pragma once

#include "statement.h"
#include <vector>
#include <memory>

namespace jaguar::parser
{
	class StatementList : public Statement {
	public:
		std::vector<ASTNode*> statements;

		StatementList(node_type_e t, int l, int c);

		void Add(ASTNode* n);
		
		void Print(int indent = 0) override {}
		void CheckSemantics() override {}

		LLVMValue* Codegen() override { return nullptr; }
	};
}
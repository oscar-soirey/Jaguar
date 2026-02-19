#pragma once

#include "statement.h"
#include <vector>
#include <memory>

namespace jaguar::parser
{
	class StatementList : public Statement {
	public:
		std::vector<ASTNode*> statements;

		StatementList(int l, int c);

		void Add(ASTNode* n);
		
		void Print(int indent = 0) override {}
		void CheckSemantics() override {}

		llvm::Value* Codegen(codegen::CodegenContext* c) override { return nullptr; }
	};
}
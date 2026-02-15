#pragma once

#include "statement.h"
#include <vector>
#include <memory>

namespace jaguar::parser
{
	class StatementList : public Statement {
	public:
		std::vector<std::unique_ptr<ASTNode>> statements;

		StatementList(node_type_e t, int l, int c);

		template<typename T>
		void Add(std::unique_ptr<T> n)
		{
			static_assert(std::is_base_of_v<ASTNode, T>, "Cast error : StatementList::Add, template is not a class of ASTNode");
			statements.emplace_back(std::move(n));
		}
		
		void Print(int indent = 0) override {}
		void CheckSemantics() override {}
	};
}
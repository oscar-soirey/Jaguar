#pragma once

#include "../statements/statement.h"
#include "../statements/statement_list.h"

namespace jaguar::parser
{
	class BlockStatement : public Statement {
	public:
		//what the bloc contains
		StatementList* body;

		BlockStatement(StatementList* body, int line, int column) : Statement(line, column), body(body) {}

		void Print(int indent = 0) override
		{
			for (const auto& s : body->statements)
			{
				s->Print(indent + 4);
			}
		}
	};
}
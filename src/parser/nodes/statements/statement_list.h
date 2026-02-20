#pragma once

#include "statement.h"
#include <vector>

namespace jaguar::parser
{
	class StatementList : public Statement {
	public:
		std::vector<ASTNode*> statements;

		StatementList(int _line, int _column);
	};
}
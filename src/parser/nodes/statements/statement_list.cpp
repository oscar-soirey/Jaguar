#include "statement_list.h"

namespace jaguar::parser
{
	StatementList::StatementList(int l, int c) : Statement(l,c) {}

	void StatementList::Add(ASTNode* n)
	{
		statements.emplace_back(n);
	}
}
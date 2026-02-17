#include "statement_list.h"

namespace jaguar::parser
{
	StatementList::StatementList(node_type_e t, int l, int c) : Statement(t,l,c) {}

	void StatementList::Add(ASTNode* n)
	{
		statements.emplace_back(n);
	}
}
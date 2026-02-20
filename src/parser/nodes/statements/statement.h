#ifndef JAGUAR_STATEMENT_NODE_H
#define JAGUAR_STATEMENT_NODE_H

#include "../ast_node.h"

namespace jaguar::parser
{
	class Statement : public ASTNode {
	public:
		Statement(int _line, int _column) : ASTNode(_line,_column) {}
	};
}

#endif
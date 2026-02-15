#ifndef JAGUAR_EXPRESSION_H
#define JAGUAR_EXPRESSION_H

#include "../ast_node.h"

namespace jaguar::parser
{
	class Expression : public ASTNode {
	public:
		Expression(int line, int column) : ASTNode(Expr, line, column) {}
		virtual ~Expression()=default;
	};
}

#endif
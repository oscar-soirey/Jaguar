#ifndef JAGUAR_VAR_DECL_NODE_H
#define JAGUAR_VAR_DECL_NODE_H

#include "ast_node.h"
#include <string>

namespace jaguar::parser
{
	class VarDeclNode : public ASTNode {
	public:
		std::string var_name;
		std::string var_type;

		VarDeclNode(const std::string& n, const std::string& t, int l, int c);

		void Print(int indent) override;
		void CheckSemantics() override;
	};
}

#endif
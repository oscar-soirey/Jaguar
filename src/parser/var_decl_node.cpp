#include "var_decl_node.h"

#include <iostream>

namespace jaguar::parser
{
	VarDeclNode::VarDeclNode(const std::string& n, const std::string& t, int l, int c) :
		ASTNode(VarDecl, l, c),
		var_name(n),
		var_type(t)
	{  }

	void VarDeclNode::Print(int indent)
	{
		std::cout << std::string(indent, ' ') << var_type << " " << var_name << "\n";
	}

	void VarDeclNode::CheckSemantics()
	{
		/* vérification de type */
	}
}
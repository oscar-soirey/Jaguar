#include "var_decl.h"

#include <iostream>

namespace jaguar::parser
{
	VarDecl::VarDecl(const std::string& n, const std::string& t, std::unique_ptr<Expression> i, int l, int c) :
		Statement(VariableDeclation, l, c),
		init(std::move(i)),
		var_name(n),
		var_type(t)
	{  }

	void VarDecl::Print(int indent)
	{
		std::cout << std::string(indent, ' ') << var_type << " " << var_name << "\n";
	}

	void VarDecl::CheckSemantics()
	{
		/* vérification de type */
	}
}
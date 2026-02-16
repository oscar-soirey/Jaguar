#include "var_decl.h"

#include <iostream>

namespace jaguar::parser
{
	VarDecl::VarDecl(std::string n, std::string t, Expression* i, int l, int c) :
		Statement(VariableDeclation, l, c),
		init(i),
		var_name(n),
		var_type(t)
	{  }

	void VarDecl::Print(int indent)
	{
		if (init)
		{
			std::string i(indent, ' ');
			printf("%sVar Declaration, name : %s, type : %s, init value : %s\n",
				i.c_str(),
				var_name.c_str(),
				var_type.c_str(),
				init->GetExpressionString().c_str()
			);
		}
		else
		{
			std::string i(indent, ' ');
			printf("%sVar Declaration, name : %s, type : %s, init value : %s\n",
				i.c_str(),
				var_name.c_str(),
				var_type.c_str(),
				"None"
			);
		}
	}

	void VarDecl::CheckSemantics()
	{
		/* vérification de type */
	}
}
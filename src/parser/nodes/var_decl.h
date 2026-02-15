#ifndef JAGUAR_VAR_DECL_NODE_H
#define JAGUAR_VAR_DECL_NODE_H

#include "statement.h"
#include "expression.h"
#include <memory>
#include <string>

namespace jaguar::parser
{
	class VarDecl : public Statement {
	public:
		std::string var_name;
		std::string var_type;

		std::unique_ptr<Expression> init;

		VarDecl(const std::string& n, const std::string& t, std::unique_ptr<Expression> i, int l, int c);

		void Print(int indent) override;
		void CheckSemantics() override;
	};
}

#endif
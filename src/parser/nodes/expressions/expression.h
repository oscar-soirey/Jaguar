#ifndef JAGUAR_EXPRESSION_H
#define JAGUAR_EXPRESSION_H

#include "../ast_node.h"

#include <string>
#include <map>
#include <optional>

#include <llvm/IR/Value.h>

namespace jaguar::parser
{
	typedef enum {
		Int, Float, Bool, String
	}type_kind_e;

	//useful for type verification, eg., int+float okay. int+string error.
	using TypePair = std::pair<type_kind_e, type_kind_e>;
	struct OperatorInfo
	{
		std::map<TypePair, type_kind_e> rules;

		std::optional<type_kind_e> getResult(type_kind_e left, type_kind_e right) const
		{
			auto it = rules.find({left, right});
			if (it != rules.end())
				return it->second;
			return std::nullopt;  //not compatible
		}
	};

	/** plus tard, utiliser comme ca :
	 * //définir les types
	OperatorInfo plusOp;
	plusOp.rules[{TypeKind::Int, TypeKind::Int}] = TypeKind::Int;
	plusOp.rules[{TypeKind::Int, TypeKind::Float}] = TypeKind::Float;
	plusOp.rules[{TypeKind::Float, TypeKind::Int}] = TypeKind::Float;
	plusOp.rules[{TypeKind::Float, TypeKind::Float}] = TypeKind::Float;

//trouver si c'est bon
	auto result = plusOp.getResult(left->getType(), right->getType());
	if (result)
			return *result;
	throw std::runtime_error("Types incompatibles pour '+'");
	*/

	class Expression : public ASTNode {
	public:
		Expression(int line, int column) : ASTNode(line, column) {}
		virtual ~Expression()=default;

		virtual std::string GetExpressionString() { return {}; }
		
		void Print(int indent = 0) override {}
		void CheckSemantics() override {}

		type_kind_e GetType() const
		{
			return type_;
		}

	protected:
		type_kind_e type_;
	};
}

#endif
#ifndef JAGUAR_EXPRESSION_H
#define JAGUAR_EXPRESSION_H

#include "../ast_node.h"

#include <string>
#include <map>
#include <optional>

#include "../../../types.h"

namespace jaguar::parser
{
	//useful for type verification, eg., int+float okay. int+string error.
	using TypePair = std::pair<Jaguar_Type_e, Jaguar_Type_e>;
	struct OperatorInfo
	{
		std::map<TypePair, Jaguar_Type_e> rules;

		std::optional<Jaguar_Type_e> getResult(Jaguar_Type_e left, Jaguar_Type_e right) const
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
		Expression(int _line, int _column);

		virtual std::string GetExpressionString()=0;

		Jaguar_Type_e GetType() const;

	protected:
		Jaguar_Type_e type_;
	};
}

#endif
#ifndef JAGUAR_AST_NODE_H
#define JAGUAR_AST_NODE_H

struct LLVMValue;

namespace jaguar::parser
{
	typedef enum {
		VariableDeclation,
		FunctionDeclation,
		ClassDeclaration,
		Expr,
		Literal,
		RootStatement,
		IfStatement,
		WhileStatement
	}node_type_e;

	class ASTNode {
	public:
		int line;
		int column;
		node_type_e type;

		ASTNode(node_type_e t, int l, int c) : type(t), line(l), column(c) {}
		virtual ~ASTNode()=default;

		//Debugging
		virtual void Print(int indent=0)=0;

		//Semantics verifications
		virtual void CheckSemantics()=0;

		//IR Generation
		virtual LLVMValue* Codegen() { return nullptr; }
	};
}

#endif
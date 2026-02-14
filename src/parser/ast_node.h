#ifndef JAGUAR_AST_NODE_H
#define JAGUAR_AST_NODE_H

struct LLVMValue;

namespace jaguar::parser
{
	typedef enum {
		VarDecl,
		FuncDecl,
		ClassDecl,
		Expr,
		Literal
	}node_type_e;

	class ASTNode {
	public:
		int line;
		int column;
		node_type_e type;

		ASTNode(node_type_e t, int l, int c) : type(t), line(l), column(c) {}
		virtual ~ASTNode()=default;

		virtual void Print(int indent=0)=0;
		virtual void CheckSemantics()=0;
		virtual LLVMValue* Codegen() { return nullptr; }
	};
}

#endif
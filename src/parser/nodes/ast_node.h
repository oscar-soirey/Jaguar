#ifndef JAGUAR_AST_NODE_H
#define JAGUAR_AST_NODE_H

//forward declarations
struct LLVMValue;
namespace jaguar::codegen
{
	struct CodegenContext;
}


namespace jaguar::parser
{
	typedef enum {
		None,
		VariableDeclation,
		VariableAssignement,
		FunctionDeclation,
		ClassDeclaration,
		Expr,
		Literal,
		RootStatement
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
		virtual LLVMValue* Codegen(codegen::CodegenContext* c) { return nullptr; }
	};
}

#endif
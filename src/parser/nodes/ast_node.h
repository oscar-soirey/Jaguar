#ifndef JAGUAR_AST_NODE_H
#define JAGUAR_AST_NODE_H

//do not remove
#include "../types.h"

//forward declarations
namespace llvm
{
	class Value;
}
namespace jaguar::codegen
{
	struct CodegenContext;
}


namespace jaguar::parser
{
	class ASTNode {
	protected:
		int line;
		int column;

	public:
		ASTNode(int _line, int _column);
		virtual ~ASTNode()=default;

		//Debugging the AST
		virtual void Print(int indent)=0;

		//Semantics verifications
		virtual void CheckSemantics()=0;

		//IR Generation
		virtual llvm::Value* Codegen(codegen::CodegenContext* c)=0;
	};
}

#endif
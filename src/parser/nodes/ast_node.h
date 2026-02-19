#ifndef JAGUAR_AST_NODE_H
#define JAGUAR_AST_NODE_H

#include <llvm/IR/Value.h>

//forward declarations
struct LLVMValue;
namespace jaguar::codegen
{
	struct CodegenContext;
}


namespace jaguar::parser
{
	class ASTNode {
	public:
		int line;
		int column;

		ASTNode(int l, int c) : line(l), column(c) {}
		virtual ~ASTNode()=default;

		//Debugging
		virtual void Print(int indent=0)=0;

		//Semantics verifications
		virtual void CheckSemantics()=0;

		//IR Generation
		virtual llvm::Value* Codegen(codegen::CodegenContext* c) { return nullptr; }
	};
}

#endif
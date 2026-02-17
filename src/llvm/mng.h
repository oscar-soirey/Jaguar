#ifndef JAGUAR_LLVM_MNG_H
#define JAGUAR_LLVM_MNG_H

//basics llvm headers
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>

#include <unordered_map>

namespace jaguar::codegen
{
	struct CodegenContext {
		llvm::LLVMContext* context;
		llvm::Module* module;
		llvm::IRBuilder<>* builder;
		std::unordered_map<std::string, llvm::Value*> symbolTable;

		CodegenContext();
		~CodegenContext();

		//returns 0 for no errors, -1 for one or more llvm member not initialized
		int VerifyMembers() const;

		void RegisterMainFunc();
		void AddStandardSymbols();

		llvm::Type* GetLLVMType(const std::string& t) const;

		llvm::Value* GetSymbol(const char* s);
		void AddSymbol(const char* s, llvm::Value* v);
	};
}

#endif
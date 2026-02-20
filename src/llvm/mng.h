#ifndef JAGUAR_LLVM_MNG_H
#define JAGUAR_LLVM_MNG_H

//basics llvm headers
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include "../types.h"

#include <unordered_map>

namespace jaguar::codegen
{
	//useful for store symbols during compilation
	struct VarSymbol {
		llvm::AllocaInst* alloca_inst;
		Jaguar_Type_e type;

		VarSymbol(llvm::AllocaInst* _alloca, Jaguar_Type_e _type):
		alloca_inst(_alloca),
		type(_type)
		{}
	};

	struct FuncSymbol {
		llvm::Function* func;

		FuncSymbol(llvm::Function* _func):
		func(_func)
		{}
	};

	struct CodegenContext {
		llvm::LLVMContext* context;
		llvm::Module* module;
		llvm::IRBuilder<>* builder;

		std::unordered_map<std::string, VarSymbol> var_symbols;
		std::unordered_map<std::string, FuncSymbol> func_symbols;

		CodegenContext();
		~CodegenContext();

		void AddStandardSymbols();

		//get builder type
		llvm::Type* GetLLVMType(Jaguar_Type_e t) const;

		VarSymbol* GetVarSymbol(const std::string& _name);
		void AddVarSymbol(const std::string& _name, VarSymbol _symbol);

		FuncSymbol* GetFuncSymbol(const std::string& _name);
		void AddFuncSymbol(const std::string& _name, FuncSymbol _symbol);
	};
}

#endif
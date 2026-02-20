#include "mng.h"
#include <llvm/IR/Module.h>


namespace jaguar::codegen
{
	//init every llvm objects
	CodegenContext::CodegenContext() :
		context(new llvm::LLVMContext()),
		module(new llvm::Module("my_module", *context)),
		builder(new llvm::IRBuilder<>(*context))
	{
	}

	//destructor
	CodegenContext::~CodegenContext()
	{
		//this order
		delete builder;
		delete module;
		delete context;
	}

	void CodegenContext::AddStandardSymbols()
	{
		//print
		llvm::FunctionType* printfType =
			llvm::FunctionType::get(
				llvm::IntegerType::getInt32Ty(*context),
				{ llvm::PointerType::get(llvm::Type::getInt8Ty(*context), 0) },
				true //varargs
			);
		llvm::Function* printfFunc =
			llvm::Function::Create(printfType,
													 llvm::Function::ExternalLinkage,
													 "printf", module);
		AddFuncSymbol("print", FuncSymbol(printfFunc));
	}

	llvm::Type* CodegenContext::GetLLVMType(Jaguar_Type_e t) const
	{
		switch (t)
		{
			case(INT): return builder->getInt32Ty();
			case(FLOAT): return builder->getFloatTy();
		}
		return nullptr;
	}

	VarSymbol* CodegenContext::GetVarSymbol(const std::string& _name)
	{
		auto it = var_symbols.find(_name);
		if (it == var_symbols.end())
		{
			return nullptr;
		}
		return &it->second;
	}

	void CodegenContext::AddVarSymbol(const std::string& _name, VarSymbol _symbol)
	{
		auto it = var_symbols.find(_name);
		if (it == var_symbols.end())
		{
			//symbol does not exist
			var_symbols.emplace(_name, _symbol);
		}
		//error handling
	}

	FuncSymbol *CodegenContext::GetFuncSymbol(const std::string &_name)
	{
		auto it = func_symbols.find(_name);
		if (it == func_symbols.end())
		{
			return nullptr;
		}
		return &it->second;
	}

	void CodegenContext::AddFuncSymbol(const std::string &_name, FuncSymbol _symbol)
	{
		auto it = func_symbols.find(_name);
		if (it == func_symbols.end())
		{
			//name does not exist
			func_symbols.emplace(_name, _symbol);
		}
		//error handling
	}
}

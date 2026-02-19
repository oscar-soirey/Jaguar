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

	int CodegenContext::VerifyMembers() const
	{
		if (!context) return -1;
		if (!module) return -1;
		if (!builder) return -1;
		return 0;
	}

	void CodegenContext::RegisterMainFunc()
	{
		llvm::FunctionType* mainType = llvm::FunctionType::get(
		llvm::Type::getInt32Ty(*context),
		false
			);
		llvm::Function* mainFunc = llvm::Function::Create(
				mainType,
				llvm::Function::ExternalLinkage,
				"main",
				module
		);

		llvm::BasicBlock* entry = llvm::BasicBlock::Create(*context, "entry", mainFunc);
		builder->SetInsertPoint(entry);
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
		AddSymbol("print", printfFunc);
	}

	llvm::Type* CodegenContext::GetLLVMType(const std::string& t) const
	{
		if (t == "int")
		{
			return builder->getInt32Ty();
		}
		if (t == "float")
		{
			return builder->getFloatTy();
		}
		return nullptr;
	}

	llvm::Value* CodegenContext::GetSymbol(const char *s)
	{
		auto it = symbolTable.find(s);
		if (it == symbolTable.end())
		{
			return nullptr;
		}
		return it->second;
	}

	void CodegenContext::AddSymbol(const char *s, llvm::Value *v)
	{
		auto it = symbolTable.find(s);
		if (it == symbolTable.end())
		{
			//symbol does not exist
			symbolTable.emplace(s, v);
		}
		//error handling
	}
}

#include "jit.h"

#include <logger/compile_time_logger.h>

//init
#include <llvm/Support/TargetSelect.h>

//execution
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/ExecutionEngine/Orc/ThreadSafeModule.h>

//bytecode
#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/IR/LLVMContext.h>

namespace jaguar::jit
{
	void InitJIT()
	{
		//Register my machine architecture
		llvm::InitializeNativeTarget();
		llvm::InitializeNativeTargetAsmPrinter();
		llvm::InitializeNativeTargetAsmParser();
	}

	int ExecuteFromContext(codegen::CodegenContext *c)
	{
		llvm::ExitOnError ExitOnErr;

		//create the JIT object
		auto JIT = ExitOnErr(llvm::orc::LLJITBuilder().create());

		//thread-safe module
		llvm::orc::ThreadSafeModule TSM(std::unique_ptr<llvm::Module>(c->module), std::make_unique<llvm::LLVMContext>());

		//add module to JIT
		ExitOnErr(JIT->addIRModule(std::move(TSM)));

		//search for main function
		auto Sym = ExitOnErr(JIT->lookup("main"));

		//convert to native C function
		using FuncType = int (*)();
		FuncType mainFunc = Sym.toPtr<FuncType>();

		int result = mainFunc();
		return result;
	}

	int ExecuteFromBytecode(const char *_path)
	{
		llvm::LLVMContext context;
		auto buffer = llvm::MemoryBuffer::getFile(_path);
		if (!buffer)
		{
			logger::LogError(logger::FILE_OPEN_ERROR, _path);
			return 1;
		}

		//read the module from bytecode
		auto moduleOrErr = llvm::parseBitcodeFile(buffer->get()->getMemBufferRef(), context);
		if (!moduleOrErr)
		{
			logger::LogError(logger::JIT_ERROR, _path);
			return 1;
		}
		//create module object from bc
		std::unique_ptr<llvm::Module> module = std::move(*moduleOrErr);

		llvm::ExitOnError ExitOnErr;

		//create the JIT object
		auto JIT = ExitOnErr(llvm::orc::LLJITBuilder().create());

		//thread-safe module
		llvm::orc::ThreadSafeModule TSM(std::move(module), std::make_unique<llvm::LLVMContext>());

		//add module to JIT
		ExitOnErr(JIT->addIRModule(std::move(TSM)));

		//search for main function
		auto Sym = ExitOnErr(JIT->lookup("main"));

		//convert to native C function
		using FuncType = int (*)();
		FuncType mainFunc = Sym.toPtr<FuncType>();

		int result = mainFunc();
		return result;
	}
}

#include "src/filesystem/filesystem.h"
#include "src/lexer/lexer.h"
#include "src/parser/parser.h"
#include "src/parser/driver.h"
#include "src/generated/parser.tab.hpp"


#include <llvm/IR/Module.h>
#include <llvm/Support/FileSystem.h>

#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/Support/raw_ostream.h>

#include "src/llvm/mng.h"

//#define PrintTokens
#define CompileToLLVM

int main()
{
  //Read file
	size_t fileSize;
	std::string file = jaguar::filesystem::ReadFile("file.ja", &fileSize);

  //Tokenizing
	jaguar::parser::tokens_ = jaguar::lexer::Tokenize(file, fileSize);

#ifdef PrintTokens
	for (const auto& t : jaguar::parser::tokens_)
	{
		printf("Token : %d, value : %d\n", t.type, t.i_val);
	}
#endif

  //Build the AST
	jaguar::parser::Driver driver{};
	jaguar::parser::parser p(driver);
	int result = p.parse();

#ifdef CompileToLLVM
	//create llvm context and register standard library
	auto codegen_context = new jaguar::codegen::CodegenContext();
	codegen_context->RegisterMainFunc();
	codegen_context->AddStandardSymbols();
#endif


  //Print the AST
	for (const auto& s : driver.root->statements)
	{
		s->Print();
#ifdef CompileToLLVM
		s->Codegen(codegen_context);
#endif
	}

#ifdef CompileToLLVM
	std::error_code EC;
	llvm::raw_fd_ostream dest("output.ll", EC, llvm::sys::fs::OF_None);
	if (EC) {
		std::cerr << "Could not open file: " << EC.message() << "\n";
		return -1;
	}
	codegen_context->module->print(dest, nullptr);
	dest.close();


	std::error_code ECBC;
	llvm::raw_fd_ostream destBC("output.bc", ECBC, llvm::sys::fs::OF_None);
	if (ECBC) {
		std::cerr << "Could not open file: " << ECBC.message() << "\n";
		return -1;
	}

	// Écriture du bytecode
	llvm::WriteBitcodeToFile(*codegen_context->module, destBC);
	destBC.close();


	//delete context after llvm use
	delete codegen_context ;

#endif

	return result;
}

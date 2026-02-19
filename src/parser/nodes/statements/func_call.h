#pragma once

#include "statement.h"

#include <string>

namespace jaguar::parser
{
	class FuncCall : public Statement {
	public:
		std::string func_name;

		FuncCall(std::string n, int l, int c) : func_name(n), Statement(l, c) {}

		void Print(int indent = 0) override
		{
			std::string i(indent, ' ');
			printf("%sFunc call, func name : %s\n", i.c_str(), func_name.c_str());
		}
		void CheckSemantics() override {}

		llvm::Value* Codegen(codegen::CodegenContext* c) override { return nullptr; }
	};
}
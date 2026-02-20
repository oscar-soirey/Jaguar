#pragma once

#include "statement.h"

#include <string>

namespace jaguar::parser
{
	class FuncCall : public Statement {
	public:
		std::string func_name;

		FuncCall(std::string _funcName, int _line, int _column);

		void Print(int indent) override;
		void CheckSemantics() override;

		llvm::Value* Codegen(codegen::CodegenContext* c) override;
	};
}
#ifndef JAGUAR_JIT_H
#define JAGUAR_JIT_H

#include <string>
#include "../llvm/mng.h"

namespace jaguar::jit
{
	void InitJIT();
	int ExecuteFromContext(codegen::CodegenContext* c);
	int ExecuteFromBytecode(const char* _path);
}

#endif
#include "compile_time_logger.h"

#include <iostream>

namespace jaguar::logger
{
	void Log(const char* _message)
	{
		std::cout << _message << std::endl;
	}

	void LogError(errors_e _error, const char* _message)
	{
		printf("Compile error : %d, %s\n", _error, _message);
	}
}
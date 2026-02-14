#ifndef JAGUAR_COMPILE_TIME_LOGGER_H
#define JAGUAR_COMPILE_TIME_LOGGER_H

#include "errors.h"

namespace jaguar::logger
{
	void Log(const char* _message);
	void LogError(errors_e _error, const char* _message);
}

#endif
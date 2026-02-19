#ifndef JAGUAR_ERRORS_H
#define JAGUAR_ERRORS_H

namespace jaguar::logger
{
	typedef enum {
		NO_ERROR,
		FILE_OPEN_ERROR,
		SYMBOL_NOT_FOUND,
		TYPE_ERROR,
		VALUE_ERROR,
		QUOTE_NEVER_CLOSED,
		LITERAL_FLOAT_ERROR,
		OPERATOR_ERROR
	}errors_e;
}

#endif
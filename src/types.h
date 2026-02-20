#pragma once

namespace jaguar
{
	typedef enum {
		INT,
		FLOAT,
		BOOL,
		STRING
	}Jaguar_Type_e;

	inline const char* types_str[4] = {
		"INT", "FLOAT", "BOOL", "STRING"
	};
}
#ifndef JAGUAR_FILESYSTEM_H
#define JAGUAR_FILESYSTEM_H

#include <string>

namespace jaguar::filesystem
{
	std::string ReadFile(const char* _path, size_t* _outSize);
}

#endif
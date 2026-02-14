#include <filesystem>
#include <istream>
#include <fstream>
#include <sstream>

#include "../logger/compile_time_logger.h"

namespace jaguar::filesystem
{
	std::string ReadFile(const char* _path, size_t* _outSize)
	{
		//open file
		std::ifstream file(_path);
		if (!file.is_open())
		{
			logger::LogError(logger::FILE_OPEN_ERROR, "Failed to read file : ");
			return "";
		}

		//file content
		std::stringstream buffer;
		buffer << file.rdbuf();
		std::string content = buffer.str();

		//file size
		std::uintmax_t size = std::filesystem::file_size(_path);
		*_outSize = size;

		return content;
	}
}
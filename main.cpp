#include "src/filesystem/filesystem.h"
#include "src/lexer/lexer.h"
#include "src/parser/parser.h"
#include "src/parser/driver.h"
#include "src/generated/parser.tab.hpp"

#include <iostream>

int main()
{
	size_t fileSize;
	std::string file = jaguar::filesystem::ReadFile("file.ja", &fileSize);


	for (const auto& t : jaguar::lexer::Tokenize(file, fileSize))
	{
		std::cout << t.line << ":" << t.column << ", " << jaguar::lexer::TokenToString(t.type) << "(" << t.value << ")" << std::endl;
	}

	jaguar::parser::tokens_ = jaguar::lexer::Tokenize(file, fileSize);
	jaguar::parser::Driver driver;
	jaguar::parser::parser p(driver);
	int result = p.parse();

	return result;
}

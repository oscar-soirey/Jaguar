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

	jaguar::parser::tokens_ = jaguar::lexer::Tokenize(file, fileSize);
	jaguar::parser::Driver driver;
	jaguar::parser::parser p(driver);
	int result = p.parse();

	printf("root statement size : %zu\n", driver.root->statements.size());

	for (const auto& s : driver.root->statements)
	{
		s->Print();
	}

	return result;
}

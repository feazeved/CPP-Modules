#pragma once

#include <string>

class ScalarConverter {
public:
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static void	convert(std::string str);

private:
	ScalarConverter();
};

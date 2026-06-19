#pragma once

#include <string>

class ScalarConverter {
public:
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	enum printable_types {

	};

	static void	convert(const std::string& str);

private:
	ScalarConverter();
	static const std::string	digits;
};

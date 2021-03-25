#ifndef STRING_CALC_HPP
#define STRING_CALC_HPP

#include <string>
#include <vector>

class StringCalc
{
public:
    StringCalc();

	~StringCalc();
	
    int Add(const std::string& numbers) const;

private:
    std::vector<std::string> split(const std::string& s) const;
    std::string processDelimiters(const std::string& s) const;

    const char default_delimiter = ',';
};

#endif


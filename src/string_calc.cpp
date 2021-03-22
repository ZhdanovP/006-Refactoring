#include "string_calc.hpp"
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}

bool StringCalc::hasNegatives(const std::string& str)
{
    return (str.find('-') != std::string::npos);
}

std::vector<int> StringCalc::convertStringToIntVect(const std::string& str)
{
    std::stringstream ss(str);
    std::vector<int> integers_vector;

    while(ss.good())
    {
        std::string substr;
        std::getline(ss, substr, ',');
        integers_vector.push_back(std::stoi(substr));
    }

    return integers_vector;
}

bool StringCalc::moreThanTwoOperands(const std::vector<int>& vec)
{
    return (vec.size() > 2);
}

int StringCalc::Add(string numbers)
{
    // zero for empty string
    if(numbers.empty())
        return 0;

    // no negative values are allowed
    if(hasNegatives(numbers))
        return -1;

    std::vector<int> integers = convertStringToIntVect(numbers);

    // -1 for more two operands
    if(moreThanTwoOperands(integers))
        return -1;

    // add one or two operands
    int result = 0;
    for(auto& in : integers)
        result += in;
    return result;
}

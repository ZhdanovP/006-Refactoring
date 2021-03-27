#include "gtest/gtest.h"
#include "string_calc.hpp"
#include <iostream>

/**
 * @brief: UNIT-TESTS for class StringCalc's "add" method
 *
 * Positive tests:
 *  [done] empty string
 *  [done] zero as input
 *  [done] one positive integer
 *  [done] two positive integers
 *  [done] comma delimits three positive integers
 *  [done] new-line delimits two positive integers
 *  [done] new-line and comma delimit three positive integers
 *  [done] comma and new-line delimit three positive integers
 *  [done] new-line delimits three positive integers
 *  [done] user-defined separator delimits two positive integers
 *  [done] user-defined separator delimits three positive integers
 *  [done] catch exception for invalid arguments: no prefix for user defined separator
 *  [....] catch exception for invalid arguments: no slashes in prefix for user defined separator
 *  [....] catch exception for invalid arguments: single slash in prefix for user defined separator
 *  [....] catch exception for invalid arguments: no new-line in prefix for user defined separator
 *  [....] catch exception for invalid arguments: no separator in prefix for user defined separator
 *  [....] catch exception for invalid arguments: characters in digit sequence
 *  [....] catch exception for invalid arguments: characters before separator
 *  [....] catch exception for invalid arguments: characters after separator
 *  [....] catch exception for invalid arguments: symbols in digit sequence
 *  [....] catch exception for invalid arguments: symbols before separator
 *  [....] catch exception for invalid arguments: symbols after separator
 *  [done] ignore operands above limit
 *  [done] multi-character separator
 *  [....] special regex characters in user-defined separator
 *
 * Negative tests:
 *  [done] one negative integer
 *  [done] one negative integer and one positive integer
 *  [done] one positive integer and one negative integer
 *  [....] other delimiters
 *  [....] white space
 *
 */

TEST(CalculatorTest, EmptyString) {
   StringCalc c;
   const std::string input = "";
   const int expected = 0;
   int actual = c.add(input);
   ASSERT_EQ(expected, actual);
}

TEST(CalculatorTest, ZeroInput) {
   StringCalc c;
   const std::string input = "0";
   const int expected = 0;
   int actual = c.add(input);
   ASSERT_EQ(expected, actual);
}

 TEST(CalculatorTest, OnePositiveInteger) {
    StringCalc c;
    const std::string input = "1";
    const int expected = 1;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, TwoPositiveIntegers) {
    StringCalc c;
    const std::string input = "1,2";
    const int expected = 3;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, CommaDelimitsThreePositiveIntegers) {
    StringCalc c;
    const std::string input = "1,2,3";
    const int expected = 6;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, NewLineDelimitsTwoPositiveIntegers) {
    StringCalc c;
    const std::string input = "1\n2";
    const int expected = 3;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, NewLineAndCommaDelimitThreePositiveIntegers) {
    StringCalc c;
    const std::string input = "1\n2,3";
    const int expected = 6;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, CommaAndNewLineDelimitThreePositiveIntegers) {
    StringCalc c;
    const std::string input = "1,2\n3";
    const int expected = 6;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }


 TEST(CalculatorTest, NewLineDelimitsThreePositiveIntegers) {
    StringCalc c;
    const std::string input = "1\n2\n3";
    const int expected = 6;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, UserDefinedSeparatorDelimitsTwoPositiveIntegers) {
    StringCalc c;
    const std::string input = "//;\n1;2";
    const int expected = 3;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, UserDefinedSeparatorDelimitsThreePositiveIntegers) {
    StringCalc c;
    const std::string input = "//;\n1;2;3";
    const int expected = 6;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, InvalidPrefixNoPrefixForUserDefinedSeparator) {
    StringCalc c;
    const std::string input = "1;2;3";
    ASSERT_THROW(c.add(input), std::invalid_argument);
 }

 TEST(CalculatorTest, IgnoreOperandsAboveLimit) {
    StringCalc c;
    const std::string input = "1001,2";
    const int expected = 2;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, MultiCharacterSeparator) {
    StringCalc c;
    const std::string input = "//[;;;]\n1;;;2;;;3";
    const int expected = 6;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, ErrorOneNegativeInteger) {
    StringCalc c;
    const std::string input = "-2";
    const int expected = -1;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, ErrorOneNegativeIntegerAndOnePositiveInteger) {
    StringCalc c;
    const std::string input = "-1,2";
    const int expected = -1;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

 TEST(CalculatorTest, ErrorOnePositiveIntegerAndOneNegativeInteger) {
    StringCalc c;
    const std::string input = "1,-3";
    const int expected = -1;
    int actual = c.add(input);
    ASSERT_EQ(expected, actual);
 }

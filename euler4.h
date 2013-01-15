#ifndef EULER4_H
#define EULER4_H
/*
 * Title: Largest palindrome product
 *
 * Problem #: 4
 *
 * Description: A palindromic number reads the same both ways. The largest 
 * palindrome made from the product of two 2-digit numbers is 9009 = 91 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * Started: 1/13/2013
 * Completed: 1/13/2013
 * Author: epicoxymoron
 * Language: C99
 */

#include <stdbool.h>
#include <stdlib.h>

/*
 * Determines how many digits are in the number num.
 *
 * Examples:
 *
 * num_digits(1) == 1
 * num_digits(9) == 1
 * num_digits(1000) == 4
 *
 * @param num
 * 		the number
 * @returns the number of digits in num
 */
size_t num_digits(unsigned long num);

/*
 * Isolates a single digit out of a number, using math.
 *
 * @param num
 * 		the number
 * @param digit_index
 * 		the 0-based index of the digit to pull (0 for the 1's place)
 */
int isolate_digit(unsigned long num, size_t digit_index);

/*
 * Converts an unsigned long to a char*.
 *
 * @param num
 * 		the number
 * @param digits
 * 		the size of the character buffer
 * @returns a char* describing the number
 */
char* lu_to_str(unsigned long num, size_t digits);

/*
 * Determines whether the argument is a palindrome using mathematical
 * operations.
 *
 * @param num
 * 		the number to check for palindrome-ness
 * @returns true if num is a palindrome, false otherwise.
 */
bool is_palindrome_math(unsigned long num);

/*
 * Determines whether the argument is a palindrome using character
 * operations.
 *
 * @param num
 * 		the number to check for palindrome-ness
 * @returns true if num is a palindrome, false otherwise.
 */
bool is_palindrome_char(char* str, size_t len);

/*
 * Prints the largest palindrome made up of the product X * Y, where X and 
 * Y both range based on the arguments to the function, inclusive.
 *
 * For example, check_palindromes_with_factors_between(10, 99) will return
 * the largest palindrome made up of the product of two numbers X and Y
 * where X and Y are both between 10 and 99, inclusive.
 *
 * @param from
 * 		the lower bound of the range of factors (inclusive)
 * @param to
 * 		the upper bound of the range of factors (inclusive)
 */
void check_palindromes_with_factors_between(unsigned long from, unsigned long to);

#endif

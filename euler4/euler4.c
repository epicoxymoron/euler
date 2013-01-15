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
 * Author: epicoxymoron
 * Language: C99
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "euler4.h"

size_t num_digits(unsigned long num) {
	return ceil(log10(num + 1));
}

int isolate_digit(unsigned long num, size_t digit_index) {
	/* 12345 is 4=1, 3=2, 2=3, 4=1, 5=0 
	 * position 0: 12345 % 10 = 5
	 * position 1: 12345 % 100 == 45, 45 / 10
	 * position 2: 12345 % 1000 == 345, 345 / 100
	 * ...
	 */
	unsigned long hi_div;
	unsigned long lo_div;

	if (digit_index == 0) {
		return num % 10;
	}

	hi_div = (unsigned long) pow(10, digit_index + 1);
	lo_div = (unsigned long) pow(10, digit_index);

	return (num % hi_div) / lo_div;
}

char* ltoa(unsigned long num, size_t digits) {
	int result;
	char* buf;

	buf = (char*) malloc(sizeof(char) * digits + 1);
	result = snprintf(buf, digits + 1, "%lu", num);
	return buf;
}

bool is_palindrome_char(char* str, size_t len) {
	int hi_index;
	int lo_index;
	char lo_value;
	char hi_value;

	if (len == 1) {
		return true;
	}

	hi_index = len - 1;
	lo_index = 0;

	while (hi_index >= lo_index) {
		lo_value = *(str + lo_index);
		hi_value = *(str + hi_index);

		if (lo_value != hi_value) {
			return false;
		}
		
		--hi_index;
		++lo_index;
	}

	return true;
}

bool is_palindrome_math(unsigned long num) {
	int digits;
	int hi_index;
	int lo_index;
	int lo_value;
	int hi_value;

	digits = num_digits(num);
	if (digits == 1) {
		return true;
	}

	hi_index = digits - 1;
	lo_index = 0;

	while (hi_index >= lo_index) {
		lo_value = isolate_digit(num, lo_index);
		hi_value = isolate_digit(num, hi_index);

		if (lo_value != hi_value) {
			return false;
		}
		
		--hi_index;
		++lo_index;
	}

	return true;
}

void check_palindromes_with_factors_between(unsigned long from, unsigned long to) {
	unsigned long largest_palindrome = 0;
	unsigned long num = 0;
	unsigned long x = 0;
	unsigned long y = 0;
	unsigned long chosen_x = 0;
	unsigned long chosen_y = 0;

	for (x = to; x >= from; x--) {
		for (y = to; y >= x; y--) {
			num = x * y;
			/*if (num > largest_palindrome && is_palindrome_math(num)) {*/
			if (num > largest_palindrome && is_palindrome_char(ltoa(num, 100), num_digits(num))) {
				largest_palindrome = num;
				chosen_x = x;
				chosen_y = y;
			}
		}
	}
	printf("%lu is the largest palindrome made up of two factors between %lu and %lu, which is %lu * %lu\n", largest_palindrome, from, to, chosen_x, chosen_y);	
}

int main(int argc, char** argv) {
	check_palindromes_with_factors_between(100, 999);

	return 0;
}

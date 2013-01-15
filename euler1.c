/*
 * Title: Multiples of 3 and 5
 *
 * Problem #: 1
 * 
 * Description: If we list all the natural numbers below 10 that are 
 * multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 
 * 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * Started: 1/14/2013
 * Completed: 
 * Author: epicoxymoron
 * Language: C99
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "euler1.h"

#define MAX_NUM 1000

unsigned long sum(unsigned long arr[], size_t arr_len) {
	size_t i;
	long s = 0;

	for (i = 0; i < arr_len; ++i) {
		s += arr[i];
	}

	return s;
}

void generate_sequence(unsigned long buf[], unsigned long max) {
	size_t i;

	for (i = 0; i < max; ++i) {
		buf[i] = i+1;
	}
}

bool is_multiple_of_any(int multiples[], size_t arr_len, unsigned long num) {
	size_t i;

	for (i = 0; i < arr_len; ++i) {
		if (num % multiples[i] == 0) {
			return true;
		}
	}
	return false;
}

unsigned long simple() {
	long sum;
	size_t i;
	
	sum = 0;
	for (i = 1; i < MAX_NUM; ++i) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	return sum;
}

unsigned long complex() {
	unsigned long MAX = MAX_NUM - 1;
	unsigned long sum;
	size_t i;
	unsigned long arr[MAX];
	int multiples[2] = {3, 5};
	
	generate_sequence(arr, MAX);
	sum = 0;

	for (i = 0; i < MAX; ++i) {
		if (is_multiple_of_any(multiples, 2, arr[i])) {
			sum += arr[i];
		}
	}

	return sum;
}

int main(int argc, char** argv) {

	printf("%ld\n", simple());
	printf("%ld\n", complex());

	return 0;
}

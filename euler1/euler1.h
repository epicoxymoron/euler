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
 * Completed: 1/14/2013
 * Author: epicoxymoron
 * Language: C99
 */

#include <stdbool.h>

/*
 * Sums the elements in an array
 *
 * @param arr
 * 		the array
 * @param arr_len
 * 		the number of elements in the array
 * @returns the sum of the elements in the array
 */
unsigned long sum(unsigned long arr[], size_t arr_len);

/*
 * Generates a sequence from 1 to max, inclusive, and stores the elements
 * in an array allocated by the caller.
 *
 * @param buf
 * 		the pre-allocated array to store the elements in
 * @param max
 * 		the highest number to include in the sequence
 */
void generate_sequence(unsigned long buf[], unsigned long max);

/*
 * Returns whether a number is evenly divided by at least one number in a
 * list.
 *
 * @param multiples
 * 		the list of possible divisors
 * @param arr_len
 * 		the size of the possible divisor list
 * @param num
 * 		the number to check
 * @returns true if num can evenly divided at least one of the numbers in 
 * 	multiples
 */
bool is_multiple_of_any(int multiples[], size_t arr_len, unsigned long num);

/*
 * The quick and dirty way to do it.
 */
unsigned long simple();

/* 
 * The fancy way to do it.
 */
unsigned long complex();


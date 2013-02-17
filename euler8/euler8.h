#ifndef EULER8_H
#define EULER8_H
/*
 * Title: Largest product in a series
 *
 * Problem #: 8
 * 
 * Description: Find the greatest product of five consecutive digits in 
 * the 1000-digit number.
 * 73167176531330624919225119674426574742355349194934
 * 96983520312774506326239578318016984801869478851843
 * 85861560789112949495459501737958331952853208805511
 * 12540698747158523863050715693290963295227443043557
 * 66896648950445244523161731856403098711121722383113
 * 62229893423380308135336276614282806444486645238749
 * 30358907296290491560440772390713810515859307960866
 * 70172427121883998797908792274921901699720888093776
 * 65727333001053367881220235421809751254540594752243
 * 52584907711670556013604839586446706324415722155397
 * 53697817977846174064955149290862569321978468622482
 * 83972241375657056057490261407972968652414535100474
 * 82166370484403199890008895243450658541227588666881
 * 16427171479924442928230863465674813919123162824586
 * 17866458359124566529476545682848912883142607690042
 * 24219022671055626321111109370544217506941658960408
 * 07198403850962455444362981230987879927244284909188
 * 84580156166097919133875499200524063689912560717606
 * 05886116467109405077541002256983155200055935729725
 * 71636269561882670428252483600823257530420752963450
 *
 * Author: epicoxymoron
 * Language: C99
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <assert.h>

/*
 * Product of n characters, treated as integers, in a string.
 *
 * @param str
 * 		the string
 * @param start_pos
 * 		the starting index in the string to start the product from
 * @param product_len
 * 		the number of consecutive characters (substring size) to multiply
 * @return
 * 		the product of the product_len characters of str, starting at start_pos
 */
int product_of(const char* str, size_t start_pos, size_t product_len);

/*
 * Find the position of the max fixed-size consecutive substring product in 
 * a string.
 *
 * @param str
 * 		the string
 * @param str_len
 * 		the number of characters in str
 * @param product_len
 * 		the number of consecutive characters (substring size) to multiply
 * @param val
 * 		the actual computed product of the substring
 * @return
 * 		the index of the first character of the max substring
 */
int max_product_pos(const char* str, size_t str_len, size_t product_len, int *val);

/*
 * Prints the details of the max substring
 *
 * @param str
 * 		the string
 * @param str_len
 * 		the number of characters in str
 * @param start_pos
 * 		the starting index in the string to start the product from
 * @param val
 * 		the actual computed product of the substring
 * @param verbose
 * 		whether to include details about the position of the substring, or 
 * 		simply print the value of the product
 */
void print_results(const char *str, size_t product_len, size_t start_pos, int val, bool verbose);

#endif
